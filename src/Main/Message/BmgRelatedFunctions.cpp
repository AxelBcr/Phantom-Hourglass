extern "C" {
#include <string.h>
}

#include "global.h"
#include "types.h"
#include "Unknown/UnkStruct_02063220.hpp"

struct astruct_3 {
    u8 mUnk_00[0x24];
    u32 mUnk_24;
    u32 mUnk_28;
    u8 mUnk_2C[0x1c];
};

extern "C" {
void func_02041ca8(astruct_3 *);
bool func_02041e7c(astruct_3 *, char *);
void func_02041ea8(astruct_3 *);
int func_02041fa4(astruct_3 *, u32, u32);
u32 func_0202d23c(astruct_3 *, int, unsigned int *, int, int, u32, int, int, int);
u32 func_0202d1c4(int, unsigned int *, u32, int);
void func_0202d21c(u32);
}

THUMB int func_0202d3bc(int param_1, unsigned int *param_2, char *path, int param_4, int param_5, bool param_6,
                        int param_7, int param_8) {
    u32 dVar2;
    u32 uVar5;
    int local_64;
    astruct_3 aStack_60;

    data_02063220.path = path;
    local_64           = 0;
    if (param_4 != 0) {
        *(int *)param_4 = 0;
    }
    func_02041ca8(&aStack_60);
    if (func_02041e7c(&aStack_60, path)) {
        uVar5 = aStack_60.mUnk_28 - aStack_60.mUnk_24;
        if (uVar5 != 0) {
            if (param_6) {
                local_64 = func_0202d23c(&aStack_60, param_1, param_2, param_5, 0, uVar5, param_4, param_7, param_8);
            } else {
                dVar2 = 0;
                if (param_7 == 0) {
                    dVar2 = func_0202d1c4(param_1, param_2, uVar5, param_5);
                } else {
                    if (uVar5 <= param_8) {
                        dVar2 = param_7;
                    }
                }
                if (dVar2 != 0) {
                    if (func_02041fa4(&aStack_60, dVar2, uVar5) == -1) {
                        if (param_7 == 0) {
                            func_0202d21c(dVar2);
                        }
                    } else {
                        local_64 = dVar2;
                        if (param_4 != 0) {
                            *(u32 *)param_4 = uVar5;
                        }
                    }
                }
            }
        }
        func_02041ea8(&aStack_60);
    }
    return local_64;
}

THUMB int func_0202d550(int param_1, unsigned int *param_2, char *path, int param_4, int param_5, int param_6) {
    return func_0202d3bc(param_1, param_2, path, param_4, param_5, *(bool *)&param_6, 0, 0);
}
