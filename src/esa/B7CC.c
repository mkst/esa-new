#include "common.h"

char  D_800E4FB0;
unsigned int   D_800E4FB4;
unsigned int   D_800E4FB8;
unsigned int   D_800E4FBC;

INCLUDE_ASM("asm/esa/nonmatchings/B7CC", func_8001B1CC);

void func_8001B3FC(void) {
    s32 var_2;

    if (D_800E4FB0 == 0) {
        var_2 = D_800E5274->unk378 - 1;
        if (var_2 < 0) {
            var_2 = 0;
        }
        D_800E5274->unk378 = var_2;
        if ((var_2 << 16) <= 0) {
            D_800E5274->unk383 = 0;
        }
    }
}
