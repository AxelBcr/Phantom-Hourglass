#include "Actor/Character/ActorCharacter.hpp"

extern "C" void func_ov014_021460b8(ActorCharacter_1d8 *param1);

#define static

ActorGenericCharacter::ActorGenericCharacter() {}
bool ActorGenericCharacter::Init() {}
void ActorGenericCharacter::vfunc_68(unk32 param1, UnkStruct_020397f8 *param2) {}
bool ActorGenericCharacter::vfunc_c0() {
    return ActorCharacterBase::vfunc_c0() || mUnk_484 == 5;
}
void ActorGenericCharacter::vfunc_c4() {}
void ActorGenericCharacter::func_ov014_02147940() {
    mVisible = false;
    mUnk_12c = 0;
}
void ActorGenericCharacter::func_ov014_02147950() {}
void ActorGenericCharacter::vfunc_80() {}
void ActorGenericCharacter::vfunc_84() {}

void ActorGenericCharacter::func_ov014_02147ae8() {}
bool ActorGenericCharacter::func_ov014_02147b18() {}
ARM void ActorGenericCharacter::func_ov014_02147ba0() {
    func_ov014_021453f4(mUnk_020.mUnk_0c);
}
bool ActorGenericCharacter::func_ov014_02147bb0() {
    func_ov014_02145414(mUnk_460, 0xaab);
    return func_01fffd04(0);
}
unk32 ActorGenericCharacter::func_ov014_02147bd8() {
    func_ov014_02145414(mUnk_460, 0xaab);
    func_ov00_020c3094();
    return 0;
}
void ActorGenericCharacter::func_ov014_02147c00() {
    Vec3p vel;
    if (mUnk_430.func_ov000_020c66e4(&mPos, mAngle, mUnk_020.mUnk_0c)) {
        if (mUnk_430.func_ov000_020c6e30(&vel)) {
            mPos = vel;
        }
    }
}

ActorGenericCharacter::~ActorGenericCharacter() {}
void ActorGenericCharacter::vfunc_f8() {}

void ActorGenericCharacter::func_ov014_02147c98() {}
void ActorGenericCharacter::func_ov014_02147ce8(unk32 param1) {}
void ActorGenericCharacter::func_ov014_02147d44(unk32 param1) {}
ARM static void func_ov014_02147df0(ActorGenericCharacter *actor) {
    actor->func_ov014_02147940();
}

void ActorGenericCharacter::func_ov014_02147dfc() {
    if (func_ov014_02144e74()) {
        func_ov014_02147950();
    }
}
void ActorGenericCharacter::func_ov014_02147e1c() {
    if (mUnk_488 == 2) {
        mUnk_1d8.func_ov014_02145f0c(0);
    } else {
        mUnk_1d8.func_ov014_02145e48(0);
        mUnk_1d8.mUnk_10->mUnk_0c.mUnk_04 = 0x1000;
    }
    vfunc_b4();
}
void ActorGenericCharacter::func_ov014_02147e64() {}
void ActorGenericCharacter::func_ov014_02147ebc() {
    if (mUnk_488 == 2) {
        func_ov014_021460b8(&mUnk_1d8);
    }
}
ARM static void func_ov014_02147ed8(ActorGenericCharacter *actor) {
    actor->func_ov014_0214591c();
}

void ActorGenericCharacter::func_ov014_02147ee4() {}
void ActorGenericCharacter::func_ov014_02147fbc() {
    mUnk_1d8.mUnk_020.mUnk_70.Reset();
}
void ActorGenericCharacter::func_ov014_02147fcc() {}
void ActorGenericCharacter::func_ov014_021480dc() {}
ARM void ActorGenericCharacter::func_ov014_02148130() {
    mUnk_490 = 0;
}
void ActorGenericCharacter::func_ov014_0214813c() {
    mUnk_1d8.func_ov014_02145e48(1);
    mUnk_1d8.mUnk_10->mUnk_0c.mUnk_04 = 0x1000;
    func_ov014_02147ba0();
}
void ActorGenericCharacter::func_ov014_02148168() {}
void ActorGenericCharacter::func_ov014_02148198() {
    mUnk_1d8.func_ov014_02145e48(1);
    mUnk_1d8.mUnk_10->mUnk_0c.mUnk_04 = 0x1000;
    func_ov014_02147ba0();
    func_ov014_02144d94();
}
void ActorGenericCharacter::func_ov014_021481cc() {}
void ActorGenericCharacter::func_ov014_021481fc() {
    mUnk_1d8.func_ov014_02145e48(0);
    mUnk_1d8.mUnk_10->mUnk_0c.mUnk_04 = 0x1000;
    func_ov014_02147c00();
}
ARM static void func_ov014_02148228(ActorGenericCharacter *actor) {
    actor->func_ov014_021452b0();
}