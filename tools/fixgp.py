import sys
import re
import struct
from pathlib import Path

VRAM_OFFSET = 0x80010200 - 0x00000800
BSS_OFFSET = 0xd5510

SIZES = {
    "w": 4,
    "h": 2,
    "b": 1,
}

def generate_sdata(rom, offset, var, size):
    ret = []

    size_to_struct = {
        4: "I",
        2: "H",
        1: "B",
    }
    types = {
        4: ".word",
        2: ".half",
        1: ".byte",
    }
    var_size = SIZES[size]
    value, = struct.unpack(f"<{size_to_struct[var_size]}", rom[offset:offset+var_size])
    ret.append(f".globl {var}")
    ret.append(".sdata")
    ret.append(f".align {var_size}")
    ret.append(f"{var}:")
    ret.append(f"{types[var_size]} {value}")
    return ret


def map_op(op):
    if op == "lw" or op == "sw":
        return "w"
    if op == "lh" or op == "lhu" or op == "sh":
        return "h"
    if op == "lb" or op == "lbu" or op == "sb":
        return "b"
    if op == "addiu":
        return "w"
    else:
        raise Exception(f"Unknown op: {op}")

with open("esa.dat", "rb") as f:
    ROM_DATA = f.read()

def fixgp(asm_file, tu_vars):
    print(f"Processing {asm_file}")

    with open(asm_file, "r") as f:
        lines = f.readlines()

    res = []
    funcs = {}
    func_vars = {}

    in_func = False
    current_func = None
    need_noat = False

    for line in lines:
        line = line.strip()
        if line.find("$1,") > -1 or line.find("($1)") > -1:
            need_noat = True
        if in_func:
            # .end func_8001CE60
            if match := re.match(rf"^.end {current_func}", line):
                funcs[current_func] = (res, func_vars, need_noat, need_at)
                in_func = False
                res.append(line)
                continue
            # lw         $3, %gp_rel(D_800E4154)($28)
            if ((match := re.match(r"^(\w+)\s+(\$\d+), *%gp_rel\(([^\)]+)\).*$", line)) or
                (match := re.match(r"^(\w+)\s+(\$\d+), *\$\d+, *%gp_rel\(([^\)]+)\).*$", line))):
                op = match.group(1)
                reg = match.group(2)
                var = match.group(3)
                res.append(f"{op:10} {reg}, {var}")

                if var in tu_vars:
                    # print(f"Skipping {var} as already defined in TU...")
                    continue
                tu_vars.append(var)
                need_at = True
                # --
                func_vars[var] = map_op(op) # e.g. take 'w' from 'lw'
                continue
            # --
            res.append(line)
        else:
            # .globl func_8001CE60
            if match := re.match(r"^\.globl (\w+)", line):
                current_func = match.group(1)
                in_func = True
                need_noat = False
                need_at = False
                func_vars = {}
                res = []

    return funcs

def write_funcs_to_file(asm_file, funcs, symbol_map):
    out_lines = []

    rdata_start = 0x80010200 - VRAM_OFFSET
    rdata_end = 0x800169CC - VRAM_OFFSET
    data_start = 0x800C7684 - VRAM_OFFSET
    data_end = 0x800E4090 - VRAM_OFFSET
    sdata_start = 0x800E4090 - VRAM_OFFSET
    sdata_end = 0x800E4F1C - VRAM_OFFSET
    sbss_start = 0x800E4F1C - VRAM_OFFSET
    sbss_end = 0x8012BDDC - VRAM_OFFSET
    # bss_start =
    # bss_end = 0x8012BDDC

    for name, (lines, vars, need_noat, need_at) in funcs.items():
        out_lines.append(".set noreorder")
        if need_noat:
            out_lines.append(".set noat")
        elif need_at:
            out_lines.append(".set at")
        out_lines.append(f".globl {name}")
        # --
        keys = sorted(list(vars.keys()), key=lambda x: symbol_map.get(x) or int(x, 16))
        for var in keys:
            size = vars[var]
            vram_offset = symbol_map.get(var) or int(var, 16)
            rom_offset = vram_offset - VRAM_OFFSET
            var_size = SIZES[size]
            # TODO: fix sdata
            # if rom_offset < sbss_start:
            #     out_lines += generate_sdata(ROM_DATA, rom_offset, var, size)
            out_lines.append(f".comm {var},{var_size}")
        # add preamble
        out_lines.append(f".ent {name}")
        out_lines.append(f"{name}:")
        # skip over the original .ent & func:
        out_lines += lines[2:]
        if need_at:
            out_lines.append(".set noat")
        out_lines.append("")

    with open(asm_file, "w") as f:
        f.write("\r\n".join(out_lines))
        f.write("\r\n")

def main():
    symbol_map = {}

    if len(sys.argv) > 1:
        asm_files = sys.argv[1:]

        with open("symbol_addrs.esa.txt") as f:
            symbol_addrs = f.readlines()

        for line in symbol_addrs:
            line = line.strip()
            if line.startswith("//"):
                continue
            if len(line) == 0:
                continue
            good, *_ = line.split(";")
            func, addr = good.split("=")
            symbol_map[func.strip()] = int(addr.strip(), 16)

        tu_vars = []
        last_parent = None
        for asm_file in asm_files:
            current_parent = Path(asm_file).parent
            if current_parent != last_parent or asm_file.find("nonmatchings") == -1:
                tu_vars = []
            funcs = fixgp(asm_file, tu_vars)
            write_funcs_to_file(asm_file, funcs, symbol_map)
            last_parent = current_parent


if __name__ == '__main__':
    main()
