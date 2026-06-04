#include "Actor/Character/ActorItemSeller.hpp"

#include "Actor/ActorManager.hpp"
#include "Actor/ActorShopItem.hpp"
#include "Message/MsgProc.hpp"
#include "System/SysNew.hpp"
#include "Unknown/UnkStruct_027e0dbc.hpp"
#include "Unknown/UnkStruct_ov000_020e8b08.hpp"

extern u32 **data_027e0fe0[];

extern "C" bool func_ov031_0217bd88(UnkStruct_ov031_02183e80 *param1);
extern "C" s32 func_ov003_020f3d9c(UnkStruct_027e0dbc *param1);
extern "C" void func_ov003_020f3db0(UnkStruct_027e0dbc *param1);
extern "C" void func_ov003_020f3da4(UnkStruct_027e0dbc *param1);
extern "C" void func_ov001_020f3d94(UnkStruct_027e0dbc *param1, u8 param2);
extern "C" void *func_ov000_020c4588(void *param1);
extern "C" unk32 func_0201e388(void *param1, const char *param2);
extern "C" void func_02019570(void *param1, unk32 param2, unk32 param3);
extern "C" bool HasFreebieCard();

extern const ActorCharacter_1d8_230 data_ov031_02181ad4[];
extern const unk32 data_ov031_02181ac8[];
extern const unk32 data_ov031_02181abc[];
extern const char data_ov031_02181b10[];
extern u32 **data_027e0fec[];

ARM ActorBeedle *ActorBeedle::Create() {
    return new (*data_027e0fe0[0], 4) ActorBeedle();
}

ARM bool ActorBeedle::Init() {
    mUnk_1d8.func_ov014_02145a74(0x9f, 0x9f);
    mUnk_1d8.mUnk_230 = data_ov031_02181ad4;
    if (gActorManager->mUnk_29) {
        mUnk_470 = 1;
        this->func_ov014_021451f0(data_ov031_02181ac8);
        s32 unk = func_ov003_020f3d9c(&data_027e0dbc);
        if (unk < 0) {
            func_ov003_020f3db0(&data_027e0dbc);
        } else if (unk >= 9) {
            func_ov003_020f3da4(&data_027e0dbc);
        }
    } else {
        mUnk_470 = 0;
        this->func_ov014_021451f0(data_ov031_02181abc);
        void *pModel = func_ov000_020c4588((u8 *)*data_027e0fec + 0x22c8);
        unk32 mat    = func_0201e388((u8 *)pModel + *(u32 *)((u8 *)pModel + 8) + 4, data_ov031_02181b10);
        func_02019570(pModel, mat, 0);
    }
    *(u32 *)((u8 *)this + 0x484) = data_027e0dbc.GetUnk_24()->mUnk_0b;
    *(u8 *)((u8 *)this + 0x490)  = 0;
    return ActorItemSellerBase::Init();
}

void ActorBeedle::vfunc_c4() {}

unk32 ActorBeedle::vfunc_114(unk32 param1) {}

static ARM unk32 func_ov031_02180e44(unk32 param1, unk32 param2) {
    return param2 | (param1 << 16);
}

ARM unk32 ActorBeedle::vfunc_d4() {
    if (mUnk_474 == 4 || mUnk_474 == 6) {
        return func_ov031_02180e44(6, 0xa);
    }
    if (mUnk_470 == 1) {
        return func_ov031_02180e44(6, 0xb);
    }
    *(u32 *)((u8 *)this + 0x484) = data_027e0dbc.GetUnk_24()->mUnk_0b;
    return func_ov031_02180e44(6, 6);
}

unk32 ActorBeedle::GetPromptMessage() {}
unk32 ActorBeedle::GetPurchaseMessage() {}
unk32 ActorBeedle::GetNotEnoughMoneyMessage() {}
unk32 ActorBeedle::GetGoodbyeMessage() {}
unk32 ActorBeedle::GetInventoryFullMessage() {}
unk32 ActorBeedle::vfunc_d8(unk32 param1) {}
unk32 ActorBeedle::vfunc_dc(unk32 param1) {}
unk32 ActorBeedle::vfunc_e0(unk32 param1) {}
bool ActorBeedle::vfunc_70() {}
bool ActorBeedle::vfunc_6c() {}

ARM void ActorBeedle::vfunc_108() {
    this->vfunc_ec(3);
}

void ActorBeedle::vfunc_10c(bool param1) {}

ARM void ActorBeedle::vfunc_110() {
    bool unk;
    if (data_ov000_020e8b08 != NULL) {
        unk = mRef.id == data_ov000_020e8b08->mUnk_20[data_ov000_020e8b08->mUnk_55].id;
    } else {
        unk = true;
    }
    this->vfunc_f0(unk, 0);
}

unk32 ActorBeedle::func_ov031_021812e4(unk32 param1) {
    s32 val = param1;
    if (val < 0) {
        val = *(s32 *)((u8 *)ActorItemSellerBase::GetCurrentSeller() + 0x484);
    }
    if (val < 0x14) {
        return 0;
    }
    if (val < 0x32) {
        return 1;
    }
    if (val < 0x64) {
        return 2;
    }
    if (val < 0xc8) {
        return 3;
    }
    return 4;
}
void ActorBeedle::func_ov031_0218132c(unk32 param1) {
    s32 v = data_027e0dbc.GetUnk_24()->mUnk_0b;
    s32 q;
    if (func_ov031_0217bd88(UnkStruct_ov031_02183e80::GetInstance())) {
        q = (s32)param1 / 20;
    } else {
        q = (s32)param1 / 100;
    }
    v += q;
    if (v == data_027e0dbc.GetUnk_24()->mUnk_0b) {
        v++;
    }
    if (v > 0xc8) {
        v = 0xc8;
    }
    func_ov001_020f3d94(&data_027e0dbc, v);
    ActorItemSellerBase::GetCurrentSeller()->mUnk_47c = v;
}

ARM bool ActorBeedle::vfunc_11c() {
    if (ActorItemSellerBase::GetCurrentSeller()->mUnk_470 != 0) {
        return false;
    }
    return *(s32 *)((u8 *)this + 0x484) != data_027e0dbc.GetUnk_24()->mUnk_0b;
}

ARM bool ActorBeedle::vfunc_118() {
    *(u8 *)((u8 *)this + 0x490) = 0;
    return data_027e0e28.func_ov018_02160a54(3);
}

ARM ActorBeedle::~ActorBeedle() {}
