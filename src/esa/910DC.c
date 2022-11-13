#include "common.h"

extern s32 D_800E54B4;
extern s32 D_800E54B8;
extern s32 D_800E54BC;
extern u8  D_800E54CC;
extern u8  D_800E54D0;
extern s16 D_800E54D8;
extern s16 D_800E54F4;

__asm__(
    ".comm D_800E54B4,4\r\n"
    ".comm D_800E54B8,4\r\n"
    ".comm D_800E54BC,4\r\n"
    ".comm D_800E54C0,4\r\n"
    ".comm D_800E54C4,4\r\n"
    ".comm D_800E54C8,4\r\n"
    ".comm D_800E54CC,1\r\n"
    ".comm D_800E54D0,1\r\n"
    ".comm D_800E54D8,2\r\n"
    ".comm D_800E54DC,2\r\n"
    ".comm D_800E54E0,4\r\n"
    ".comm D_800E54E8,2\r\n"
    ".comm D_800E54EC,1\r\n"
    ".comm D_800E54F4,2\r\n"
    ".comm D_800E54F8,1\r\n"
    ".comm D_800E54E4,4\r\n"
    ".comm D_800E54F0,2\r\n"
);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A0ADC);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A0F84);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A0F8C);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A1294);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A15BC);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A1754);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A186C);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A1A20);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A1BD4);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A1D78);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A1E80);

INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A2074);

#if 1
// looks alright, need to match remaining funcs
// sssv:func_802DC854_6EDF04
void func_800A21B0(s16 arg0, u16 arg1) {
    s16 var_6;
    u16 temp_5_2;

    temp_5_2 = (arg0 << 7) / arg1;
    if (temp_5_2 < 96) {
        var_6 = (temp_5_2 << 2) / 3;
    } else {
        var_6 = (128 - temp_5_2) << 2;
    }
    D_800E54C0 += var_6 * (D_800CA604[(temp_5_2 << 3) & 0xFF] >> 7);
    D_800E54C4 += var_6 * (D_800CA604[(temp_5_2 << 2) & 0xFC] >> 7);
    D_800E54C8 -= var_6 * (D_800CA604[(temp_5_2 << 3) & 0xFF] >> 7);
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A21B0);
#endif

#if 0
// tbd
// sssv:func_802DC968_6EE018
void func_800A22B0(u16 arg0, s16 arg1) {
    u16 tmp = D_800E52C0 - D_800E5274->unk354;
    if (arg0 < tmp) {
        D_800E5274->unk384 = 0;
    } else {
        D_800E54D8 = (arg1 * (D_800CA604[(s16)((tmp << 7) / arg0) & 0xFF] >> 7)) >> 8;
    }
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A22B0);
#endif

// sssv:func_802DCCAC_6EE35C
#if 0
// tbd
void func_800A2344(u16 arg0) {
    s16 temp_lo;
    u16 temp_2;

    temp_2 = D_800E52C0 - D_800E5274->unk34A;
    if (temp_2 >= arg0) {
        D_800E5274->unk385 = 0;
        D_800E54F4 = 0;
    } else {
        temp_lo = (temp_2 << 7) / arg0;
        if (temp_lo < 32) {
            D_800E54F4 = temp_lo;
        } else {
            D_800E54F4 = 32 - ((temp_lo - 32) / 3);
        }
    }
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A2344);
#endif

// sssv:func_802DCD70_6EE420
#if 0
void func_800A23EC(u16 arg0, u8 arg1) {
    s32 temp_6;
    s16 temp_8;
    u32 var_9;
    u16 temp_11;

    temp_11 = (D_800E52C0 - D_800E5274->unk354);

    var_9 = (temp_11 << 0xA) / arg0;
    if (var_9 > 512) {
        var_9 = 1024 - var_9;
    }

    if (var_9 < 325) {
        D_800E54B4 = FTOFIX32(1.0) + (var_9 * (D_800CA604[var_9 & 0xFF] >> 9));
        D_800E54B8 = FTOFIX32(1.0) + (var_9 * (D_800CA604[((s16) (var_9 * 2) + 64) & 0xFF] >> 9));
        D_800E54BC = FTOFIX32(1.0) - (var_9 * (D_800CA604[((var_9 * 3) - 30) & 0xFF] >> 9));
    } else if (var_9 < 375) {
        temp_6 = (var_9 - 325);
        temp_8 = (temp_6 << 0xA) - FTOFIX32(1.0);
        D_800E54B4 = ((D_800CA604[var_9 & 0xFF] >> 9) * 325) - temp_8;
        D_800E54B8 = ((D_800CA604[((s16) (var_9 * 2) + 0x40) & 0xFF] >> 9) * 325) - temp_8;
        D_800E54BC = ((temp_6 << 0xC) + FTOFIX32(1.0)) - (var_9 * ((D_800CA604[((var_9 * 3) - 30) & 0xFF]) >> 9));
        D_800E54D0 = 0;
    } else {
        D_800E54D0 = 0;
        D_800E54CC = 0;
        D_800E54BC = 0;
        D_800E54B8 = 0;
        D_800E54B4 = 0;
    }
    if ((arg1 != 0) && (temp_11 >= (arg0 >> 1))) {
        D_800E5274->unk354 += 1;
    }

    if (temp_11 >= arg0) {
        D_800E5274->unk384 = 0;
    }
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/910DC", func_800A23EC);
#endif

// sssv:func_802DD004_6EE6B4
void func_800A2660(u16 arg0) {
    u16 tmp = D_800E52C0 - D_800E5274->unk354;
    if (arg0 < tmp) {
        D_800E5274->unk384 = 0;
    }
}
