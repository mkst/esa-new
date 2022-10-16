#include "common.h"

// -- camel -- //

// load_camel
INCLUDE_ASM("asm/esa/nonmatchings/camel", func_80098E70);

// sssv:func_8036F3AC_780A5C
INCLUDE_ASM("asm/esa/nonmatchings/camel", func_800998D4);

// sssv:func_8036F404_780AB4
INCLUDE_ASM("asm/esa/nonmatchings/camel", func_80099920);

// sssv:func_8036F4CC_780B7C
#if 0
void func_800999CC(void) {
    D_800E5274->unk34A = (u16) D_800E52C0;
    D_800E5274->unk385 = 0x17;
    func_8004688C();
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/camel", func_800999CC);
#endif

// sssv:func_8036F50C_780BBC
INCLUDE_ASM("asm/esa/nonmatchings/camel", func_80099A04);

// sssv:func_8036F404_780AB4
INCLUDE_ASM("asm/esa/nonmatchings/camel", func_80099AF0);

// sssv:func_8036F4CC_780B7C
INCLUDE_ASM("asm/esa/nonmatchings/camel", func_80099C2C);

INCLUDE_ASM("asm/esa/nonmatchings/camel", func_80099C7C);

INCLUDE_ASM("asm/esa/nonmatchings/camel", func_8009A0D4);
