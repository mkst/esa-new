#include "common.h"

int D_800E4154 = 174823885; //0x0a6b99cd

#if 0
void func_8001CE60(void) {
    u32 temp_3 = D_800E4154 << 2;
    D_800E4154 = ((temp_3 + 2) * (temp_3 + 3)) >> 2;
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/D460", func_8001CE60);
#endif


void func_8001CE8C(s32 arg0) {
    if (arg0 == 0) {
        arg0 = rand();
    }
    D_800E4154 = arg0;
}
