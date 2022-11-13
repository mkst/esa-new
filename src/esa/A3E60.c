#include "common.h"

__asm__(
  ".comm D_800E5E64,4\r\n" \
  ".comm D_800E5EC8,4\r\n" \
  ".comm D_800E5ECC,4\r\n" \
  ".comm D_800E5E78,2\r\n" \
  ".comm D_800E5E7C,2\r\n" \
);

// struct013 *D_800E5E64 ;

// .sdata
// s16        D_800E5E78 = 0; // sdata?
// s16        D_800E5E7A = 0; // padding?
// s16        D_800E5E7C = 0;
// extern D_800E5E7C;

// .sbss
struct013 *D_800E5EC8;
struct013 *D_800E5ECC;


void *func_800B628C(s32 size);

#if 0
void func_800B3860(s16 num) {
    struct013 *next, *curr;
    s32 i;

    curr = (struct013 *) func_800B628C(num * sizeof(struct013));
    D_800E5E64 = D_800E5EC8 = curr;
    curr->prev = NULL;

    for (i = 0; i < (num - 1); i++) {
        // point to next node
        curr->next = curr + 1;
        // increment current
        curr++;
        // point to previous node
        curr->prev = curr - 1;
    }

    D_800E5E7C = num;
    curr->next = NULL;
    D_800E5ECC = NULL;
    D_800E5E78 = 0;
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/A3E60", func_800B3860);
#endif

// delete_actor
#if 0
void func_800B38D4(struct013 *arg0) {
    u16 used;
    struct013 *tmp;

    if (arg0->prev != NULL) {
        arg0->prev->next = arg0->next;
    }
    if (arg0->next != NULL) {
        arg0->next->prev = arg0->prev;
    } else {
        D_800E5ECC = 0;
    }
    if (D_800E5EC8 != NULL) {
        D_800E5EC8->prev = arg0;
    }

    tmp = D_800E5EC8;
    arg0->prev = NULL;
    D_800E5EC8 = arg0;
    arg0->next = tmp;

    used = D_800E5E78;
    D_800E5E78 = used + 1;
    arg0->unk18 = used;
    D_800E5E7C += 1;
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/A3E60", func_800B38D4);
#endif

char D_800E4C2C[] = "bugger, out of actors\nactors left %d\n"; // .data

#if 0
void *func_800B395C(void) {
    struct013 *temp_2_3;
    struct013 *temp_3;
    struct013 *actor;

    if (D_800E5EC8 != NULL) {
        if (D_800E5EC8->next != NULL) {
            D_800E5EC8->next->prev = NULL;
        }
        actor = D_800E5EC8;
        temp_2_3 = D_800E5EC8->next;
        actor->prev = NULL;
        actor->next = NULL;
        D_800E5EC8 = temp_2_3;
        if (D_800E5ECC != NULL) {
            D_800E5ECC->prev = actor;
            actor->next = D_800E5ECC;
        }
        D_800E5ECC = actor;
        actor->unk14 = 0;
        actor->unk10 = 0;
        actor->unkC = 0;
        actor->unk8 = 0;
        D_800E5E7C -= 1;
        return actor;
    } else {
        printf(&D_800E4C2C, D_800E5E7C);
        return NULL;
    }
}
#else
INCLUDE_ASM("asm/esa/nonmatchings/A3E60", func_800B395C);
#endif

void func_800B39F4(struct013 *arg0, struct013 *arg1) {
    if (arg0->unk8 != NULL) {
        arg0->unk8->unk14 = arg1;
    }
    arg1->unk10 = arg0->unk8;
    arg0->unk8 = arg1;
    arg1->unkC = arg0;
}

void func_800B3A20(struct013 *arg0) {
    if ((arg0->unkC != NULL) && (arg0 == arg0->unkC->unk8)) {
        arg0->unkC->unk8 = arg0->unk10;
    }
    if (arg0->unk10 != NULL) {
        arg0->unk10->unk14 = arg0->unk14;
    }
    if (arg0->unk14 != NULL) {
        arg0->unk14->unk10 = arg0->unk10;
    }
    // delete current link?
    arg0->unkC = arg0->unk10 = arg0->unk14 = NULL;
}
