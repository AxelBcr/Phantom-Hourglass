#include "Player/LinkStateBase.hpp"

extern Vec3p gPlayerPos;
extern Vec3p gPlayerVel;
extern u16 gPlayerAngle;

void LinkStateBase::vfunc_00() {}
void LinkStateBase::OnStateEnter() {}
void LinkStateBase::OnStateLeave(s32 param1) {}
bool LinkStateBase::vfunc_20(s32 param1) {}
bool LinkStateBase::vfunc_24(s32 param1) {}
bool LinkStateBase::vfunc_28() {}
bool LinkStateBase::vfunc_34(Vec3p *param1) {}
void LinkStateBase::GiveControlToLink() {}
void LinkStateBase::SetPlayerCharacter(PlayerCharacter character) {}
void LinkStateBase::ChangeLinkState(LinkStateId id) {}
void LinkStateBase::ChangeLinkSubState(LinkStateId id, s32 subState) {}
void LinkStateBase::EquipItem_vfunc_28() {}
void LinkStateBase::UpdateSwordShieldInUse() {}
void LinkStateBase::func_ov00_020a81b8(unk32 param1, Vec3p *param2) {}
LinkStateItem *LinkStateBase::GetLinkItemState() {}
void LinkStateBase::LookAt(Vec3p *target) {}
void LinkStateBase::func_ov00_020a81fc(Vec3p *param1, unk32 param2) {}
void LinkStateBase::AddHealth(s16 amount) {}
void LinkStateBase::func_ov00_020a8224(unk32 param1) {}
void LinkStateBase::TurnTo(s16 angle, unk32 param2, unk32 speed) {}
void LinkStateBase::func_ov00_020a827c(s32 param1, u32 param2) {}
void LinkStateBase::func_ov00_020a8294(s32 param1, u32 param2) {}
void LinkStateBase::func_ov00_020a82ac() {}
void LinkStateBase::ApplyImpulse(s32 angle, s32 power) {}
void LinkStateBase::func_ov00_020a8360(unk32 param1) {}
void LinkStateBase::func_ov00_020a8390(unk32 param1, void *param2) {}
void LinkStateBase::func_ov00_020a84bc(s32 param1) {}
void LinkStateBase::func_ov00_020a8508() {}
void LinkStateBase::func_ov00_020a853c(Vec3p *param1) {}
void LinkStateBase::Teleport(Vec3p *pos, s16 angle, unk32 param3, bool param4, bool param5) {}
void LinkStateBase::PlayerBase_vfunc_38(Vec3p *pos) {}
void LinkStateBase::PlayerLinkBase_vfunc_74() {}
void LinkStateBase::PlayerLinkBase_vfunc_88() {}
ARM u16 LinkStateBase::Get_PlayerLinkBase_Unk48() {
    return *(u16 *)&mLink->mUnk_48;
}
bool LinkStateBase::func_ov00_020a8638(unk32 param1) {}
void LinkStateBase::Clear_PlayerLinkBase_Unk48(u16 flags) {}
void LinkStateBase::func_ov00_020a8680(unk32 param1, unk16 param2, bool param3) {}
void LinkStateBase::PlayerLinkBase_func_ov00_020bccc8() {}
bool LinkStateBase::PlayerLinkBase_vfunc_58(unk32 param1, ActorRef *param2) {}
bool LinkStateBase::func_ov00_020a8704(s16 *pAngle) {}
bool LinkStateBase::func_ov00_020a8774(Vec3p *param1, s32 angle) {}
void LinkStateBase::func_ov00_020a8844(Vec3p *param1, bool param2, bool param3) {}
void LinkStateBase::func_ov00_020a8954(bool param1, unk32 *param2) {}
void LinkStateBase::func_ov00_020a8994() {}
void LinkStateBase::func_ov00_020a89bc(LinkStateBase_UnkStruct1 *param1, unk32 param2) {}
void LinkStateBase::func_ov00_020a8a08(unk32 param1) {}
void LinkStateBase::func_ov00_020a8a4c(const void *param1, unk32 param2) {}
void LinkStateBase::func_ov00_020a8a90(unk32 param1) {}
void LinkStateBase::func_ov00_020a8ab0(unk32 param1) {}
void LinkStateBase::func_ov00_020a8ad0(unk32 param1) {}
void LinkStateBase::func_ov00_020a8b04(s32 param1, bool param2) {}
unk32 LinkStateBase::func_ov00_020a8b3c(s32 param1) {}
bool LinkStateBase::func_ov00_020a8b80() {}
bool LinkStateBase::HasFlags_PlayerLinkBase_Unk48(u16 flags) {}
ARM u8 LinkStateBase::Get_PlayerLinkBase_Unk5e() {
    return *(u8 *)&mLink->mUnk_5c[2];
}
unk32 LinkStateBase::Get_PlayerControlData_Unk004() {}
ARM PlayerCharacter LinkStateBase::GetCurrentCharacter() {
    return mLink->GetCurrentCharacter();
}
ARM PlayerControlData *LinkStateBase::GetPlayerControlData() {
    return gPlayerControlData;
}
ARM LinkStateId LinkStateBase::GetStateId() {
    return mLink->GetStateId();
}
s32 LinkStateBase::GetHealth() {}
ARM s32 LinkStateBase::GetCurrentCharacterHealth() {
    PlayerLinkBase *link = mLink;
    return link->GetHealth(link->GetCurrentCharacter());
}
bool LinkStateBase::func_ov00_020a8c34() {}
ARM Vec3p *LinkStateBase::GetPlayerPos() {
    return &gPlayerPos;
}
ARM Vec3p *LinkStateBase::GetPlayerVel() {
    return &gPlayerVel;
}
unk8 *LinkStateBase::func_ov00_020a8c64() {}
ARM u16 *LinkStateBase::GetPlayerAngle() {
    return &gPlayerAngle;
}
void *LinkStateBase::GetPlayer_Unk18() {}
s32 LinkStateBase::Get_PlayerControlData_Unk32() {}
ARM Actor *LinkStateBase::GetGrabActor() {
    return gActorManager->GetActor(&mLink->mGrabActor);
}
ARM ActorRef *LinkStateBase::GetGrabActorRef() {
    return &mLink->mGrabActor;
}
unk32 LinkStateBase::Grab() {}
ARM s32 *LinkStateBase::Get_PlayerLinkBase_Unk44() {
    return &mLink->mUnk_44;
}
bool LinkStateBase::IsEquipBeingUsed(ItemFlag id) {}
ARM EquipItem *LinkStateBase::GetEquipItem(ItemFlag id) {
    return gItemManager->GetEquipItem(id);
}
UnkStruct_027e0fd4 *LinkStateBase::func_ov00_020a8d40() {}
unk32 LinkStateBase::func_ov00_020a8d50() {}
unk32 LinkStateBase::func_ov00_020a8d6c() {}
s32 LinkStateBase::PlayerControlData_vfunc_14(s32 param1) {}
unk32 LinkStateBase::Get_PlayerControlData_Unk100() {}
unk32 LinkStateBase::Get_PlayerControlData_Unk120() {}
ARM s32 *LinkStateBase::Get_PlayerLinkBase_Unk38() {
    return &mLink->mUnk_38;
}
ARM Bhio *LinkStateBase::GetBhio0() {
    return mLink->mBhio_0;
}
ARM Bhio *LinkStateBase::GetBhio1() {
    return mLink->mBhio_1;
}
