#include "common.h"

#if 0
extern s16 D_800E5290;
void func_8006013C(void) {
    func_800849B8(0);
    memset((s8*)&D_800E73A8.animals, 0, sizeof(D_800E73A8.animals)); // 30 * 8, D_800EAF28
    memset((s8*)&D_800E73A8.state, 0, sizeof(D_800E73A8.state)); // 30 * 0x3F4, D_800EAF28  + 0xF0
    D_800E5290 = 0;
    func_8005F8F8();
    gCurrentAnimalIndex = 0;
    func_8007F278();
    spawn_animal(0, 0, 0, 0, 0x7F, EVO_MICROCHIP, 1);
    D_800E73A8.animals[gCurrentAnimalIndex].animal->unk4A = 1;
    D_800E73A8.animals[gCurrentAnimalIndex].animal->unk322 = (D_80111C74.unk4E * 256) / 360;
    D_800E73A8.animals[gCurrentAnimalIndex].animal->unk2C = (D_80111C74.unk4E * 256) / 360;
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/5073C", func_8006013C);
#endif

#if 0
extern s16 D_800E5290;
extern s16 D_801129B8[];
extern s32 D_8005865C;
extern s16 D_800E53B8;
extern struct013 *D_801125B8[];
extern u8  D_800E5100;
extern s32 D_800E40DC;
extern s32 D_800E40D8;

void printf(char*, ...);
struct013 *func_800B5584(s32, s32, s32, s32, s32);
struct013 *func_800B395C(void);
void func_800B39F4(struct013*, struct013*);

void func_80060264(void) {
    struct000 *temp_7;
    struct013 *temp_2_2;

    if (D_80111C74.unk1A != EVO_MICROCHIP) {
        gCurrentAnimalIndex = D_800E5290;
        spawn_animal(
          D_800E73A8.animals[0].animal->unk6,
          D_800E73A8.animals[0].animal->unkA,
          D_800E73A8.animals[0].animal->unkE,
          0,
          0x7F,
          D_80111C74.unk1A,
          1);
        printf(" ANIMAL S %d: %d\n", D_80111C74.unk1A, D_801129B8[D_80111C74.unk1A]); //*((temp_5 * 2) + &D_801129B8));

        temp_2_2 = func_800B5584(D_801129B8[D_80111C74.unk1A], 0, &D_800E40D8, 0, 0); // *((D_80111C74.unk1A * 2) + &D_801129B8)
        temp_2_2->unk1B |= 4; // bitfield?
        temp_2_2->unk40 = &D_8005865C;
        temp_2_2->unk18 = D_800E53B8;

        D_801125B8[D_800E53B8] = func_800B395C();
        D_801125B8[D_800E53B8]->unk1A = 7;
        D_801125B8[D_800E53B8]->unk1B = 3;
        D_801125B8[D_800E53B8]->unk40 = 0;
        D_801125B8[D_800E53B8]->unk44 = 0;

        // linked list
        func_800B39F4(D_801125B8[D_800E53B8], temp_2_2);
        func_800B39F4(D_800E40DC, D_801125B8[D_800E53B8]); // *(((s16) D_800E53B8 * 4) + &));

        D_800E73A8.animals[0].animal->unk386 = 3;
        D_800E73A8.animals[0].unk0 = &D_800E73A8.unk0[0x3E];
        D_800E73A8.animals[0].animal->unk16C = &D_800E73A8.unk0[0x3E];
        D_800E73A8.animals[gCurrentAnimalIndex].animal->unk4A = (s8) 1;
        D_800E73A8.animals[0].animal->unk4A = 0;
    }

    temp_7 = D_800E73A8.animals[gCurrentAnimalIndex].animal;
    temp_7->unk322 = (D_80111C74.unk4E << 8) / 360;
    temp_7->unk2C = (D_80111C74.unk4E << 8) / 360;
    D_800E5100 = 0;
    D_800E73A8.unkB308 = (D_80111C74.unk4E << 8) / 360;
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/5073C", func_80060264);
#endif

#if 0
void func_80060508(void) {

}
#else
INCLUDE_ASM("asm/esa/nonmatchings/5073C", func_80060508);
#endif

#if 0
void func_80060510(void) {
    s32 temp_4_3;
    s32 temp_5_5;
    s32 temp_6_4;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    struct000 *temp_2;
    struct000 *temp_5_2;
    struct002 *temp_3;
    struct002 *temp_4_2;
    struct002 *temp_4_4;
    struct004 *temp_3_3;
    struct004 *temp_4_8;
    struct005 *temp_2_2;
    struct005 *temp_4;
    struct005 *temp_5_4;
    struct006 *temp_6;
    struct006 *temp_6_3;
    struct008 *temp_6_2;
    u16 temp_3_2;
    u16 temp_4_5;
    u16 temp_5;
    u16 var_17;
    u16 var_17_2;
    u8 temp_4_6;
    u8 temp_4_7;
    void *temp_5_3;

    temp_5 = (u16) gCurrentAnimalIndex;
    D_800E52D8 = 0;
    temp_3 = (gCurrentAnimalIndex * 8) + &D_800EAF28;
    temp_6 = temp_3->unk0;
    temp_4 = temp_3->animal;
    D_800E525C = 1;
    D_800E5284 = temp_3;
    D_800E52C8 = temp_5;
    D_800E529C = temp_6;
    D_800E52A8 = temp_4;
    D_800E5274 = temp_4;
    D_800E527C = (struct004 *) temp_4;

    // var_17 = 0;
    func_8007F0E0(temp_4, temp_5, temp_6);
    func_8007CE7C();
    for (var_17 = 0; var_17< D_800E5290; var_17++) {
        // do {
            temp_5_2 = D_800E73A8.animals[var_17].animal;
            if ((temp_5_2 != NULL) && (temp_4_2 = &D_800E73A8.animals[var_17], temp_6_2 = temp_4_2->unk0, (temp_6_2->unk90 != 0x3E))) {
                if (temp_5_2->unk386 != 6) {
                    temp_2 = temp_4_2->animal;
                    D_800E5284 = temp_4_2;
                    D_800E529C = (struct006 *) temp_6_2;
                    D_800E52A8 = (struct005 *) temp_2;
                    D_800E5274 = (struct005 *) temp_2;
                    D_800E527C = (struct004 *) temp_2;
                    if (var_17 == gCurrentAnimalIndex) {
                        D_800E525C = 1;
                    } else {
                        D_800E525C = 0;
                    }
                    D_800E52C8 = var_17;
                    D_800E52D8 = 0;
                    func_80053A0C(D_800E527C, temp_5_2, (struct006 *) temp_6_2);
                    if (D_800E73A8.animals[var_17].animal != NULL) {
                        temp_3_2 = D_800E73A8.animals[var_17].unk0->unk90;
                        if (temp_3_2 < 0x44U) {
                            temp_4_3 = *((temp_3_2 * 4) + &jtbl_800150C4);
                            switch (temp_3_2) {
                            case 0x1:
                                func_800969CC(temp_4_3);
                                break;
                            case 0x2:
                                func_80097868(temp_4_3);
                                break;
                            case 0x3:
                                func_80097C20(temp_4_3);
                                break;
                            case 0x4:
                                func_8008DA54(temp_4_3);
                                break;
                            case 0x5:
                                func_8008E150(temp_4_3);
                                break;
                            case 0x6:
                                func_8008AA34(temp_4_3);
                                break;
                            case 0x7:
                                func_8008B2D0(temp_4_3);
                                break;
                            case 0x8:
                                func_8009F8D4(temp_4_3);
                                break;
                            case 0xA:
                                func_800919D4(temp_4_3);
                                break;
                            case 0xB:
                                func_80091DCC(temp_4_3);
                                break;
                            case 0xE:
                            case 0xF:
                                func_800A0324(temp_4_3);
                                break;
                            case 0x12:
                                func_8008F7DC(temp_4_3);
                                break;
                            case 0x11:
                                func_8008FB50(temp_4_3);
                                break;
                            case 0x16:
                                func_8008CF98(temp_4_3);
                                break;
                            case 0x17:
                                func_8008D3FC(temp_4_3);
                                break;
                            case 0x18:
                                func_8008D62C(temp_4_3);
                                break;
                            case 0x1A:
                                func_8008B3B4(temp_4_3);
                                break;
                            case 0x1B:
                                func_800951B4(temp_4_3);
                                break;
                            case 0x1C:
                                func_800952B0(temp_4_3);
                                break;
                            case 0x1D:
                            case 0x41:
                                func_8009568C(temp_4_3);
                                break;
                            case 0x1F:
                                func_8008E88C(temp_4_3);
                                break;
                            case 0xD:
                            case 0x20:
                                func_8008A0AC(temp_4_3);
                                break;
                            case 0x21:
                            case 0x22:
                                func_8008BFE8(temp_4_3);
                                break;
                            case 0x23:
                            case 0x24:
                                func_8008C3F8(temp_4_3);
                                break;
                            case 0x25:
                            case 0x40:
                                func_80090370(temp_4_3);
                                break;
                            case 0x9:
                            case 0x26:
                                func_800934AC(temp_4_3);
                                break;
                            case 0x27:
                                func_80093D28(temp_4_3);
                                break;
                            case 0x28:
                            case 0x29:
                                func_800911D4(temp_4_3);
                                break;
                            case 0x2A:
                                func_800910B4(temp_4_3);
                                break;
                            case 0x2C:
                                func_80092068(temp_4_3);
                                break;
                            case 0x13:
                            case 0x2D:
                                func_8009D970(temp_4_3);
                                break;
                            case 0x2E:
                            case 0x2F:
                                func_80098E70(temp_4_3);
                                break;
                            case 0x32:
                                func_80099C7C(temp_4_3);
                                break;
                            case 0x31:
                                func_8009A794(temp_4_3);
                                break;
                            case 0x33:
                            case 0x34:
                                func_8009CA0C(temp_4_3);
                                break;
                            case 0x35:
                                func_8009B26C(temp_4_3);
                                break;
                            case 0x36:
                                func_80096CA8(temp_4_3);
                                break;
                            case 0x38:
                                func_80094540(temp_4_3);
                                break;
                            case 0x39:
                                func_80096028(temp_4_3);
                                break;
                            case 0x3A:
                                func_80095F8C(temp_4_3);
                                break;
                            case 0x3B:
                            case 0x3C:
                                func_80098450(temp_4_3);
                                break;
                            case 0x3D:
                            case 0x3F:
                                func_8001D3D4(temp_4_3);
                                break;
                            case 0x0:
                            case 0x19:
                                func_8009FC48(temp_4_3);
                                break;
                            case 0x1E:
                                func_800966A8(temp_4_3);
                                break;
                            case 0x42:
                                func_8009801C(temp_4_3);
                                break;
                            case 0x37:
                                func_8009D048(temp_4_3);
                                break;
                            case 0x43:
                                func_8009E114(temp_4_3);
                                goto block_57;
                            }
                        } else {
                            goto block_57;
                        }
                    }
                }
            } else {
            case 0xC:
            case 0x10:
            case 0x14:
            case 0x15:
            case 0x2B:
            case 0x30:
            case 0x3E:
block_57:
                var_3 = var_17 + 1;
            }
            // var_17 = var_3 & 0xFFFF;
        } //while ((s32) var_17 < D_800E5290);
    }
    if (D_800E4FB0 == 0) {
        D_800E5264 = (D_800E5264 + 1) & 0xFF;
        D_800E52C0 += 1;
        D_800E5268 = (D_800E5268 + 1) % 360;
    }
    // var_17_2 = 0;
    for (var_17_2 = 0; var_17_2 < D_800E5290; var_17_2++) {
        var_3_2 = 0U * 8;
        // do {
            temp_5_3 = D_800E73A8.unk0[0].pad0[var_3_2].unk3B84;
            temp_4_4 = var_3_2 + D_800E73A8.animals;
            if ((temp_5_3 != NULL) && (temp_6_3 = temp_4_4->unk0, (temp_6_3->unk90 != 0x3E))) {
                var_3_3 = var_17_2 + 1;
                if (temp_5_3->unk386 != 6) {
                    temp_2_2 = temp_4_4->animal;
                    D_800E5284 = temp_4_4;
                    D_800E529C = temp_6_3;
                    D_800E52A8 = temp_2_2;
                    D_800E5274 = temp_2_2;
                    D_800E527C = (struct004 *) temp_2_2;
                    if (var_17_2 == gCurrentAnimalIndex) {
                        D_800E525C = 1;
                    } else {
                        D_800E525C = 0;
                    }
                    D_800E52C8 = var_17_2;
                    D_800E52D8 = 0;
                    if (D_800E4FB0 == 0) {
                        temp_3_3 = D_800E527C;
                        if (temp_3_3->unk4A == 0) {
                            if (var_17_2 == gCurrentAnimalIndex) {
                                func_800818D8(temp_4_4, temp_5_3, temp_6_3);
                                temp_5_4 = D_800E5274;
                                if (temp_5_4->unk386 != 2) {
                                    temp_4_5 = D_800E529C->unk90;
                                    if (temp_4_5 != 0x3F) {
                                        if (D_800E4FB0 == 0) {
                                            func_8003BF7C(temp_4_5, temp_5_4);
                                            func_8003EBC8();
                                        }
                                    } else if ((D_800E4FB0 == 0) && (temp_5_4->unk385 != 0xA)) {
                                        func_8003E5CC(temp_4_5, temp_5_4);
                                    }
                                } else {
                                    goto block_86;
                                }
                            } else if ((temp_3_3->xVel != 0) || (temp_3_3->zVel != 0) || (temp_3_3->yVel != 0) || (temp_3_3->unk68 != 0) || (temp_3_3->unk70 != 0) || (temp_3_3->unk162 != 1)) {
                                temp_4_6 = D_800E5274->unk386;
                                if (temp_4_6 == 5) {
block_86:
                                    func_8003E3D0();
                                } else {
                                    func_8007C508(temp_4_6, temp_5_3, temp_6_3);
                                    func_8003D794();
                                    func_8003E300();
                                }
                            } else {
                                temp_4_7 = D_800E5274->unk386;
                                if (temp_4_7 != 5) {
                                    func_8007C508(temp_4_7, temp_5_3, temp_6_3);
                                    func_8003D794();
                                    func_8003E300();
                                }
                            }
                            temp_4_8 = D_800E527C;
                            temp_5_5 = temp_4_8->zVel;
                            temp_6_4 = temp_4_8->yVel;
                            temp_4_8->unk10 = (s32) (temp_4_8->unk4 + temp_4_8->xVel);
                            temp_4_8->unk14 = (s32) (temp_4_8->unk8 + temp_5_5);
                            temp_4_8->unk18 = (s32) (temp_4_8->unkC + temp_6_4);
                            func_8007F7F4(temp_4_8, temp_5_5, temp_6_4);
                        }
                    }
                    var_3_3 = var_17_2 + 1;
                    if (D_800E5274->unk386 != 6) {
                        func_800628F4(D_800E527C);
                        goto block_93;
                    }
                }
            } else {
block_93:
                var_3_3 = var_17_2 + 1;
            }
            var_17_2 = var_3_3 & 0xFFFF;
            var_3_2 = var_17_2 * 8;
        } //while ((s32) var_17_2 < D_800E5290);
    }
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/5073C", func_80060510);
#endif
