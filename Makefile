ESA_BASENAME    := esa

BUILD_DIR       := build
TOOLS_DIR       := tools


ESA_DIR         := $(ESA_BASENAME)

ESA_ASM_DIR     := asm/$(ESA_DIR)
ESA_ASM_DIRS    := $(ESA_ASM_DIR) $(ESA_ASM_DIR)/data \
                   $(ESA_ASM_DIR)/libapi $(ESA_ASM_DIR)/libc $(ESA_ASM_DIR)/libc2 $(ESA_ASM_DIR)/libcd $(ESA_ASM_DIR)/libetc $(ESA_ASM_DIR)/libgpu $(ESA_ASM_DIR)/libgte $(ESA_ASM_DIR)/libmath $(ESA_ASM_DIR)/libspu $(ESA_ASM_DIR)/libsnd $(ESA_ASM_DIR)/libpad

ESA_C_DIR       := src/$(ESA_DIR)
ESA_C_DIRS      := $(ESA_C_DIR)

ESA_ASSETS_DIR  := assets/$(ESA_DIR)
ESA_BIN_DIRS    := $(ESA_ASSETS_DIR)

ESA_TARGET      := $(BUILD_DIR)/$(ESA_BASENAME)

ESA_S_FILES     := $(foreach dir,$(ESA_ASM_DIRS),$(wildcard $(dir)/*.s))
ESA_C_FILES     := $(foreach dir,$(ESA_C_DIRS),$(wildcard $(dir)/*.c))
ESA_BIN_FILES   := $(foreach dir,$(ESA_BIN_DIRS),$(wildcard $(dir)/*.bin))

ESA_O_FILES     := $(foreach file,$(ESA_S_FILES),$(BUILD_DIR)/$(file).o) \
                   $(foreach file,$(ESA_C_FILES),$(BUILD_DIR)/$(file).o) \
                   $(foreach file,$(ESA_BIN_FILES),$(BUILD_DIR)/$(file).o)


MAKE            := make
PYTHON          := python3
WINE            := wine
SED             := sed
UNIX2DOS        := unix2dos
GREP            := grep

CPP             := cpp -P

CROSS           := mips-linux-gnu-
CROSS_AS        := $(CROSS)as -EL

LD              := $(CROSS)ld -EL
OBJCOPY         := $(CROSS)objcopy

CC_PSYQ_40      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.0/CC1PSX.EXE -quiet
CC_PSYQ_41      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.1/CC1PSX.EXE -quiet
CC_PSYQ_43      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.3/CC1PSX.EXE -quiet
CC_PSYQ_46      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.6/CC1PSX.EXE -quiet

AS_PSYQ_40      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.0/ASPSX.EXE -quiet
AS_PSYQ_41      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.1/ASPSX.EXE -quiet
AS_PSYQ_43      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.3/ASPSX.EXE -quiet
AS_PSYQ_46      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.6/ASPSX.EXE -quiet

AS_PSYQ         := $(AS_PSYQ_46)
AS              := $(AS_PSYQ)

PSYQ2ELF        := $(TOOLS_DIR)/psyq/psyq-obj-parser

CC              := $(CC_PSYQ_46)

SPLAT           := $(PYTHON) $(TOOLS_DIR)/splat/split.py


CROSS_AS_FLAGS  := -G0 -march=r3000 -mtune=r3000 -Iinclude/
PSYQ_AS_FLAGS   := -G8 -Iinclude/
AS_FLAGS         := $(PSYQ_AS_FLAGS)


CPP_INCLUDES    := -Iinclude
CPP_FLAGS       := -undef -Wall -lang-c
CPP_FLAGS       += -Dmips -D__GNUC__=2 -D__OPTIMIZE__ -D__mips__ -D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D__EXTENSIONS__ -D_MIPSEL -D__CHAR_UNSIGNED__ -D_LANGUAGE_C -DLANGUAGE_C
CPP_FLAGS       += $(CPP_INCLUDES)

ifdef PERMUTER
CPP_FLAGS       += -DPERMUTER
endif

CC_FLAGS        := -G8 -fno-builtin -fsigned-char
OPT_FLAGS       := -O2

UNDEFINED_SYMS := memmove strlen

LD_FLAGS_EXTRA  = -Llib -letc -lc
#-lc2 -lcd -lmath
LD_FLAGS_EXTRA += $(foreach sym,$(UNDEFINED_SYMS),-u $(sym))

ESA_LD_FLAGS    := -Map $(ESA_TARGET).map -T $(ESA_BASENAME).ld \
                   -T undefined_syms_auto.$(ESA_BASENAME).txt -T undefined_funcs_auto.$(ESA_BASENAME).txt -T undefined_syms.$(ESA_BASENAME).txt \
                   --no-check-sections $(LD_FLAGS_EXTRA)

OBJCOPY_FLAGS   := -O binary

# overrides

$(BUILD_DIR)/asm/esa/header.s.o: AS := $(CROSS_AS)
$(BUILD_DIR)/asm/esa/header.s.o: AS_FLAGS := $(CROSS_AS_FLAGS)

# needs 0x10 alignment, otherwise might be a quick win

$(BUILD_DIR)/asm/esa/data/%.rodata.s.o: AS := $(CROSS_AS)
$(BUILD_DIR)/asm/esa/data/%.rodata.s.o: AS_FLAGS := $(CROSS_AS_FLAGS)

# $(BUILD_DIR)/src/esa/4346C.c.o: AS := $(CROSS_AS)
# $(BUILD_DIR)/src/esa/4346C.c.o: AS_FLAGS := $(CROSS_AS_FLAGS)

# recipes

default: all

all: dirs verify

dirs:
	$(foreach dir,$(ESA_ASM_DIRS) $(ESA_BIN_DIRS) $(ESA_C_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))


check: $(ESA_BASENAME).ok
verify: $(ESA_TARGET).ok

extract: $(ESA_BASENAME).yaml
	$(SPLAT) $<

fixgp:
	@echo "Stripping %got & %gp_rel from assembly..."
	grep -rlE '%(got|gp_rel)' asm/esa/nonmatchings | xargs sed -i -E -s 's/%(got|gp_rel)\(([^)]+)\)\(\$$28\)/\2/' 2>/dev/null || true
	grep -rlE '%(got|/gp_rel)' asm/esa/nonmatchings | xargs sed -i -E -s 's/\$$28, %(got|gp_rel)\(([^)]+)\)/\2/' 2>/dev/null || true
	grep -rlEZ '%(got|gp_rel)' asm/esa | xargs --null python3 tools/fixgp.py || true

clean:
	rm -rf $(BUILD_DIR) $(ESA_ASM_DIR) $(ESA_ASSETS_DIR)


$(ESA_TARGET).dat: $(ESA_TARGET).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

$(ESA_TARGET).elf: $(ESA_O_FILES) $(LIBETC)
	$(LD) $(ESA_LD_FLAGS) -o $@

$(BUILD_DIR)/%.s.o: %.s
	$(UNIX2DOS) -q $<
	$(AS) $(AS_FLAGS) $< -o $@.obj
	if [[ "$$(head -c3 $@.obj)" = "LNK" ]] ; then $(PSYQ2ELF) $@.obj -o $@ >/dev/null ; else cp $@.obj $@; fi

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/%.c.o: %.c
	$(CPP) $(CPP_FLAGS) $(CPP_TARGET) $< | $(UNIX2DOS) | $(CC) $(CC_FLAGS) $(OPT_FLAGS) -o $@.s
	$(AS) $(AS_FLAGS) $@.s -o $@.obj
	if [[ "$$(head -c3 $@.obj)" = "LNK" ]] ; then $(PSYQ2ELF) $@.obj -o $@ >/dev/null ; else cp $@.obj $@; fi

%.ok: %.dat
	@echo "$$(cat $(notdir $(<:.dat=)).sha1)  $<" | sha1sum --check
	@touch $@

$(BUILD_DIR)/%.a: %.a
	@mkdir -p $$(dirname $@)
	@cp $< $@

# keep .obj files
.SECONDARY:

.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
