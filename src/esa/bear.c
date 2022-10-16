#include "common.h"

INCLUDE_ASM("asm/esa/nonmatchings/bear", func_8008D3FC);

INCLUDE_ASM("asm/esa/nonmatchings/bear", func_8008D62C);

INCLUDE_ASM("asm/esa/nonmatchings/bear", func_8008D654);

INCLUDE_ASM("asm/esa/nonmatchings/bear", func_8008D708);

INCLUDE_ASM("asm/esa/nonmatchings/bear", func_8008D77C);

INCLUDE_ASM("asm/esa/nonmatchings/bear", func_8008D7B4);

INCLUDE_ASM("asm/esa/nonmatchings/bear", func_8008D888);

#if 0
void func_8008DA10(s16 arg0) {
    D_800E5274->unk30C = arg0;
    if (D_800E529C->unk90 == BEAR) {
        load_animal(CRAZY_BEAR);
    }
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/bear", func_8008DA10);
#endif
