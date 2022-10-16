#include "common.h"

void recharge_skill(s16 arg0) {
    D_800E5274->skillAEnergy[arg0].unk0 += D_800E529C->unkCE[arg0][0];
}
