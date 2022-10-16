#include "common.h"

#if 0
void printf(s32 arg0, ...) {
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/90D0C", printf);
#endif

#if 0
// another printf?
void func_800A0720(s32 arg0, ...) {
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/90D0C", func_800A0720);
#endif

INCLUDE_ASM("asm/esa/nonmatchings/90D0C", func_800A0734);

INCLUDE_ASM("asm/esa/nonmatchings/90D0C", func_800A085C);

INCLUDE_ASM("asm/esa/nonmatchings/90D0C", func_800A0AD0);
