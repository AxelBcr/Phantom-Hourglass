#include "Unknown/UnkStruct_02035064.hpp"
#include "Message/MsgProc.hpp"
#include "Game/Game.hpp"

struct UnkEntry_02035064 {
    /* 00 */ unk32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ unk16 mUnk_06;
};

extern "C" u32 *func_02023ac8(u32 *param1, s32 param2);
extern "C" void func_02028610(void *param1, u32 *param2, u32 param3);
extern "C" void func_0202864c(void *param1, u32 *param2);
extern "C" void func_02028664(void *param1, u16 param2);

ARM UnkStruct_02035064::UnkStruct_02035064() {
    this->mUnk_74 = NULL;
    this->mUnk_78 = NULL;
    this->mUnk_7c = 0;
    this->mUnk_80 = 0;
    this->mUnk_82 = 0;
    this->mUnk_84 = 0;
    this->mUnk_86 = 0;
    this->mUnk_87 = 0;
}

ARM UnkStruct_02035064::~UnkStruct_02035064() {}

ARM void UnkStruct_02035064::func_020350b0() {}

ARM void UnkStruct_02035064::func_020350b4(s32 param1, unk32 param2, unk8 param3, unk16 param4, unk16 param5) {
    u32 *entry;
    u32 *p;
    s32 i;
    s32 count;

    this->mUnk_87 = param3;
    entry = ((u32 ***)&data_027e0cbc)[1][param1];
    this->mUnk_78 = (s32 *)entry[2];
    p = func_02023ac8((u32 *)((u32 *)this->mUnk_78)[1], 0);
    func_02028610(&this->mUnk_04, p, entry[1]);
    p = func_02023ac8((u32 *)((u32 *)this->mUnk_78)[1], param2);
    this->mUnk_74 = (u16 *)p;
    func_0202864c(&this->mUnk_04, (u32 *)this->mUnk_74);
    count = *(u16 *)this->mUnk_74;
    this->mUnk_7c = 0;
    for (i = 0; i < count; i++) {
        this->mUnk_7c += ((UnkEntry_02035064 *)((u32 **)this->mUnk_74)[3])[i].mUnk_04 << 12;
    }
    this->mUnk_82 = param4;
    this->mUnk_84 = param5;
}

ARM void UnkStruct_02035064::func_0203516c() {
    if (this->mUnk_78 != 0x0) {
        if (this->mUnk_86 == false) {
            this->mUnk_5c.func_0202e1e8();
            this->func_020352d8();
        } else {
            this->mUnk_86 = false;
        }
    }
}

ARM s32 UnkStruct_02035064::vfunc_00() {
    return this->mUnk_4c;
}

ARM s32 UnkStruct_02035064::vfunc_04() {
    return this->mUnk_4e;
}

ARM void UnkStruct_02035064::func_020351b8(bool param1, bool param2, bool param3, bool param4) {
    s32 i;
    s32 count;
    s32 saved;

    this->mUnk_7c = 0;
    count = *(u16 *)this->mUnk_74;
    for (i = 0; i < count; i++) {
        this->mUnk_7c += ((UnkEntry_02035064 *)((u32 **)this->mUnk_74)[3])[i].mUnk_04 << 12;
    }
    if (param1 != false) {
        this->mUnk_7c -= 0x1000;
    }
    saved = this->mUnk_5c.mUnk_08;
    this->mUnk_5c.func_0202e1c4(this->mUnk_7c);
    this->mUnk_5c.mUnk_00 = param1;
    if (param2 != false) {
        this->mUnk_5c.func_0202e670();
    }
    if (param3 != false) {
        this->mUnk_5c.mUnk_08 = saved;
        this->func_020352d8();
        this->mUnk_86 = false;
    } else {
        if (param4 != false) {
            this->mUnk_5c.func_0202e5cc();
        } else {
            this->mUnk_5c.mUnk_08 = 0;
            this->func_020352d8();
        }
        this->mUnk_86 = true;
    }
    this->mUnk_5c.mUnk_04 = gGame.mUnk_0f2 << 12;
    if (param2 != false) {
        this->mUnk_1c = !param1 ? 4 : 3;
    } else {
        this->mUnk_1c = !param1 ? 2 : 1;
    }
    this->func_020352d8();
}
ARM void UnkStruct_02035064::func_020352d8() {
    s32 target;
    s32 acc;
    s32 idx;
    UnkEntry_02035064 *e;
    s32 count;
    u16 v;
    s32 hi;

    if (this->mUnk_5c.mUnk_08 < 0) {
        this->mUnk_80 = 0;
        return;
    }
    target = this->mUnk_5c.mUnk_08;
    e = (UnkEntry_02035064 *)this->mUnk_20[3];
    count = *this->mUnk_74;
    acc = 0;
    idx = 0;
    if (count > 0) {
        do {
            v = e->mUnk_04;
            hi = acc + (v << 12);
            if (acc <= target && target < hi) {
                break;
            }
            acc += v << 12;
            if (idx == count - 1) {
                idx--;
                e--;
                acc -= v;
            }
            idx++;
            e++;
        } while (idx < count);
    }
    this->mUnk_80 = (s16)idx;
    func_02028664(&this->mUnk_04, (u16)this->mUnk_80);
    this->mUnk_14 = target - acc;
}
