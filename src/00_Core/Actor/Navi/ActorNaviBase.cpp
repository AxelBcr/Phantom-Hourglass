#include "Actor/Navi/ActorNaviBase.hpp"
#include "Actor/ActorRef.hpp"
#include "Item/ItemManager.hpp"
#include "Player/PlayerLinkBase.hpp"
#include "Player/PlayerBase.hpp"
#include "Physics/Cylinder.hpp"
#include "Unknown/UnkStruct_ov000_020beba8.hpp"

extern "C" bool func_ov000_02087e8c();
extern "C" u16 func_ov000_020b8790(FairyId fairyId);
extern "C" u16 func_ov000_020b87cc(FairyId fairyId);
extern "C" bool Lerp(s32 *pValue, s32 dest, s32 factor, unk32 param4, u32 step);
extern "C" bool func_0202b2e8(Vec3p *param1, Vec3p *param2, q20 param3);
extern "C" void Vec3p_RotateY(s16 angle, Vec3p *vec);
extern Vec3p data_ov000_020dc83c;
extern Vec3p data_ov000_020dc848;

ARM u16 ActorNaviBase::vfunc_c4() {
    if (*(u8 *)&this->mUnk_28d) {
        return 0x6318;
    }
    return func_ov000_020b8790(this->GetFairyId());
}
ARM u16 ActorNaviBase::vfunc_c8() {
    if (*(u8 *)&this->mUnk_28d) {
        return 0x739c;
    }
    return func_ov000_020b87cc(this->GetFairyId());
}
ARM unk32 ActorNaviBase::vfunc_30() {
    return 1;
}
ARM s32 ActorNaviBase::vfunc_b8() {
    return -1;
}
bool ActorNaviBase::vfunc_cc(unk32 *param1) {}
ARM void ActorNaviBase::GetOffsetPos(Vec3p *pos) {
    *pos = this->mOffsetPos;
}
ARM unk32 ActorNaviBase::vfunc_38() {
    if (func_ov000_02087e8c()) {
        return 0x22;
    }
    return 0x20;
}
ARM void ActorNaviBase::vfunc_d0() {
    Vec3p local;
    this->GetLinkPos(&local);
    switch (this->mUnk_130) {
        case 1:
            this->mOffsetPos = local;
            this->mOffsetPos.y += 0x199a;
            break;
        case 6:
            this->mOffsetPos = local;
            this->mOffsetPos.y += 0x800;
            break;
    }
}
ARM void ActorNaviBase::func_ov000_020b8c50(unk32 param1) {
    Vec3p local = this->mPos;
    func_0202b2e8(&local, &this->mOffsetPos, param1);
    Vec3p_Sub(&local, &this->mPos, &this->mVel);
}
ARM void ActorNaviBase::func_ov000_020b8c98(unk32 param1, unk32 param2, unk32 param3) {
    this->mVel.x = 0;
    this->mVel.y = 0;
    this->mVel.z = 0;
    Vec3p local = this->mPos;
    Lerp(&local.x, this->mOffsetPos.x, param1, param2, param3);
    Lerp(&local.y, this->mOffsetPos.y, 0x400, 0, 0x7FFFFFFF);
    Lerp(&local.z, this->mOffsetPos.z, param1, param2, param3);
    Vec3p_Sub(&local, &this->mPos, &this->mVel);
}
void ActorNaviBase::vfunc_d4() {}
ARM void ActorNaviBase::vfunc_d8() {}
void ActorNaviBase::SetActive(unk32 active) {}
ARM void ActorNaviBase::TeleportAboveLink() {
    Vec3p local;
    this->GetLinkPos(&local);
    local.y += 0x800;
    this->mPos = local;
    this->mPrevPos = local;
}
void ActorNaviBase::func_ov000_020b9770(s32 param1) {}
void ActorNaviBase::vfunc_e0() {}
ARM void ActorNaviBase::vfunc_e4() {
    this->vfunc_e0();
}
void ActorNaviBase::vfunc_e8() {}
void ActorNaviBase::vfunc_14(u32 param1) {}
void ActorNaviBase::vfunc_18(u32 param1) {}
ARM void ActorNaviBase::func_ov000_020b9fdc() {
    func_ov000_020b9fe8();
}
void ActorNaviBase::func_ov000_020b9fe8() {}
void ActorNaviBase::vfunc_20(bool param1) {}
ARM void ActorNaviBase::vfunc_10(u32 param1) {
    if (this->mUnk_130 == 0 && gItemManager->GetEquippedFairy() == this->GetFairyId()) {
        this->SetActive(1);
        return;
    }
    this->TeleportAboveLink();
    if (this->vfunc_cc(0) != 0) {
        this->SetActive(0);
    }
}
unk32 ActorNaviBase::func_ov000_020ba204(Vec3p *param1, Vec3p *param2, s32 param3) {}
ARM unk32 func_ov000_020ba350(unk32 param1) {
    UnkStruct_ov000_020beba8 *self = (UnkStruct_ov000_020beba8 *)param1;
    self->UnkStruct_ov000_020beba8::~UnkStruct_ov000_020beba8();
    return param1;
}
ARM bool ActorNaviBase::vfunc_c0(Vec3p *param1) {
    this->mOffsetPos = *param1;
    s32 state = this->mUnk_130;
    if (state != 4) {
        this->SetActive(4);
        return state != 5;
    }
    return false;
}
ARM unk32 ActorNaviBase::func_ov000_020ba3b4() {
    if (gItemManager->GetEquippedFairy() == this->GetFairyId()) {
        this->SetActive(1);
    } else {
        this->SetActive(6);
    }
    return 1;
}
ARM void ActorNaviBase::func_ov000_020ba414(Vec3p *param1) {
    Cylinder local;
    gPlayer->vfunc_10(&local);
    Vec3p_Add(param1, &local.pos, &this->mOffsetPos);
}
ARM bool ActorNaviBase::func_ov000_020ba458() {
    if (gItemManager->GetEquippedFairy() == this->GetFairyId()) {
        if (this->vfunc_cc(0) == 0) {
            s32 state = this->mUnk_130;
            if (state != 8 && state != 9) {
                this->SetActive(5);
                this->func_ov000_020ba53c();
                return true;
            }
        }
    }
    return false;
}
ARM void ActorNaviBase::func_ov000_020ba4e4() {
    Vec3p local = data_ov000_020dc83c;
    if ((s16)gPlayerAngle < 0) {
        local.x = -local.x;
    }
    Vec3p_RotateY(gPlayerAngle, &local);
    this->func_ov000_020ba414(&local);
}
ARM void ActorNaviBase::func_ov000_020ba53c() {
    Vec3p local = data_ov000_020dc848;
    s16 angle = gPlayerAngle;
    if ((angle > 0 && angle < 0x4000) || angle < -0x4000) {
        local.x = -local.x;
    }
    Vec3p_RotateY(angle, &local);
    this->func_ov000_020ba414(&local);
}
ARM void ActorNaviBase::vfunc_80() {
    this->func_ov000_020ba4e4();
    this->SetActive(8);
}
ARM void ActorNaviBase::vfunc_84() {
    this->SetActive(5);
}
bool ActorNaviBase::vfunc_78() {}
bool ActorNaviBase::vfunc_bc(unk32 param1, unk8 param2, s32 param3) {}
ARM void ActorNaviBase::vfunc_74(ActorRef *ref) {
    if (ref->id == this->mRef.id) {
        this->SetActive(8);
    } else {
        this->mUnk_28a = 0;
    }
}
ARM void ActorNaviBase::func_ov000_020baca8(Vec3p *param1, unk32 param2) {
    if (this->mUnk_11c || *(u8 *)&this->mUnk_291) {
        return;
    }
    if (gPlayerLink->GetCurrentCharacter() != PlayerCharacter_Link) {
        return;
    }
    this->mOffsetPos = *param1;
    this->mUnk_164 = param2;
    this->SetActive(7);
}
ARM void ActorNaviBase::func_ov000_020bad18() {
    this->mUnk_164 = 0;
    if (this->mUnk_130 == 7) {
        this->SetActive(5);
    }
}
bool ActorNaviBase::vfunc_90(unk32 param1, unk32 param2) {}
void ActorNaviBase::vfunc_94(unk32 param1, unk32 param2) {}
ARM void ActorNaviBase::func_ov000_020bb0ac() {
    for (FairyId i = 0; i < FairyId_COUNT; i++) {
        *(u8 *)&gItemManager->GetFairy(i)->mUnk_290 = 1;
    }
}
ARM void ActorNaviBase::func_ov000_020bb0e0() {
    for (FairyId i = 0; i < FairyId_COUNT; i++) {
        *(u8 *)&gItemManager->GetFairy(i)->mUnk_290 = 0;
    }
}
ARM void ActorNaviBase::vfunc_ec() {}
