#include "Player/LinkStateBase.hpp"
#include "Player/LinkStateItem.hpp"
#include "Unknown/UnkStruct_0202e1a0.hpp"

extern Vec3p gPlayerPos;
extern Vec3p gPlayerVel;
extern u16 gPlayerAngle;

extern u8 data_027e0fb0;
extern "C" unk32 func_ov000_020c0d68(unk32 param1);
extern "C" void func_ov000_020c0e24(unk32 param1, unk32 param2);
extern LinkStateId data_ov000_020dc510[];
extern u8 data_ov000_020e5650[];
extern u8 data_ov000_020e5674[];
extern "C" void data_ov020_02178354(PlayerLinkBase *link);

void LinkStateBase::vfunc_00() {}
ARM void LinkStateBase::OnStateEnter() {}
ARM void LinkStateBase::OnStateLeave(s32 param1) {}
ARM bool LinkStateBase::vfunc_20(s32 param1) {
    return false;
}
bool LinkStateBase::vfunc_24(s32 param1) {}
ARM bool LinkStateBase::vfunc_28() {
    return true;
}
ARM bool LinkStateBase::vfunc_34(Vec3p *param1) {
    return false;
}
ARM void LinkStateBase::GiveControlToLink() {
    data_ov020_02178354(mLink);
}
ARM void LinkStateBase::SetPlayerCharacter(PlayerCharacter character) {
    mLink->SetPlayerCharacter(character);
}
ARM void LinkStateBase::ChangeLinkState(LinkStateId id) {
    mLink->ChangeLinkState(id);
}
ARM void LinkStateBase::ChangeLinkSubState(LinkStateId id, s32 subState) {
    mLink->SetLinkSubState(id, subState);
}
ARM void LinkStateBase::EquipItem_vfunc_28() {
    for (s32 i = 0; i < ItemFlag_EQUIP_COUNT; i++) {
        EquipItem *equip = gItemManager->GetEquipItem(i);
        if (equip != NULL) {
            equip->UpdateInUse(0);
        }
    }
}
ARM void LinkStateBase::UpdateSwordShieldInUse() {
    gItemManager->UpdateSwordShieldInUse();
}
void LinkStateBase::func_ov00_020a81b8(unk32 param1, Vec3p *param2) {
    GetLinkItemState()->func_ov005_02106980(0, param1, (s32 *)param2);
}
ARM LinkStateItem *LinkStateBase::GetLinkItemState() {
    return (LinkStateItem *)GetLinkState(LinkStateId_Item);
}
ARM void LinkStateBase::LookAt(Vec3p *target) {
    mLink->LookAt(target);
}
ARM void LinkStateBase::func_ov00_020a81fc(Vec3p *param1, unk32 param2) {
    mLink->func_ov000_020bb810(param1, param2);
}
void LinkStateBase::AddHealth(s16 amount) {
    ((PlayerBase *)mLink)->AddHealth(amount);
}
ARM void LinkStateBase::func_ov00_020a8224(unk32 param1) {
    mLink->func_ov000_020bbbd0(param1, 1);
}
void LinkStateBase::TurnTo(s16 angle, unk32 param2, unk32 speed) {}
ARM void LinkStateBase::func_ov00_020a827c(s32 param1, u32 param2) {
    gPlayerControlData->func_ov000_020b4558(param1, param2);
}
ARM void LinkStateBase::func_ov00_020a8294(s32 param1, u32 param2) {
    gPlayerControlData->func_ov000_020b44d4(param1, param2);
}
void LinkStateBase::func_ov00_020a82ac() {
    mLink->GetPlayerControlData(0)->func_ov000_020b45e0();
}
void LinkStateBase::ApplyImpulse(s32 angle, s32 power) {}
void LinkStateBase::func_ov00_020a8360(unk32 param1) {}
void LinkStateBase::func_ov00_020a8390(unk32 param1, void *param2) {}
void LinkStateBase::func_ov00_020a84bc(s32 param1) {}
void LinkStateBase::func_ov00_020a8508() {}
void LinkStateBase::func_ov00_020a853c(Vec3p *param1) {}
ARM void LinkStateBase::Teleport(Vec3p *pos, s16 angle, unk32 param3, bool param4, bool param5) {
    mLink->Teleport(pos, 0, 0, false, true);
}
void LinkStateBase::PlayerBase_vfunc_38(Vec3p *pos) {
    mLink->TeleportToEntrance((unk32)pos, 0);
}
void LinkStateBase::PlayerLinkBase_vfunc_74() {
    mLink->vfunc_74();
}
void LinkStateBase::PlayerLinkBase_vfunc_88() {}
ARM u16 LinkStateBase::Get_PlayerLinkBase_Unk48() {
    return *(u16 *)&mLink->mUnk_48;
}
ARM bool LinkStateBase::func_ov00_020a8638(unk32 param1) {
    s32 local[2];
    local[0] = -1;
    local[1] = -1;
    return mLink->func_ov000_020bd3b0(param1, (unk32)local, 0, 0);
}
ARM void LinkStateBase::Clear_PlayerLinkBase_Unk48(u16 flags) {
    PlayerLinkBase *link = mLink;
    *(u16 *)&link->mUnk_48 = *(u16 *)&link->mUnk_48 & ~flags;
}
void LinkStateBase::func_ov00_020a8680(unk32 param1, unk16 param2, bool param3) {}
ARM void LinkStateBase::PlayerLinkBase_func_ov00_020bccc8() {
    mLink->func_ov000_020bccc8();
}
bool LinkStateBase::PlayerLinkBase_vfunc_58(unk32 param1, ActorRef *param2) {}
bool LinkStateBase::func_ov00_020a8704(s16 *pAngle) {}
bool LinkStateBase::func_ov00_020a8774(Vec3p *param1, s32 angle) {}
void LinkStateBase::func_ov00_020a8844(Vec3p *param1, bool param2, bool param3) {}
ARM void LinkStateBase::func_ov00_020a8954(bool param1, unk32 *param2) {
    if (param1) {
        *(s32 *)(data_ov000_020e5650 + 0x24) = 0x29;
    } else {
        *(s32 *)(data_ov000_020e5650 + 0x24) = 0x27;
    }
    func_ov00_020a8a4c(data_ov000_020e5674, 1);
    *param2 = 0;
}
void LinkStateBase::func_ov00_020a8994() {
    ChangeLinkState(data_ov000_020dc510[func_ov00_020a8d40()->mUnk_05a]);
}
void LinkStateBase::func_ov00_020a89bc(LinkStateBase_UnkStruct1 *param1, unk32 param2) {}
void LinkStateBase::func_ov00_020a8a08(unk32 param1) {
    switch (func_ov00_020a8d40()->mUnk_05a) {
    case 1:
    case 2:
        func_ov005_0211097c(param1, 0, 1);
        break;
    default:
        func_ov00_020a8a90(param1);
        break;
    }
}
void LinkStateBase::func_ov00_020a8a4c(const void *param1, unk32 param2) {}
ARM void LinkStateBase::func_ov00_020a8a90(unk32 param1) {
    gPlayerControlData->func_ov000_020b45f8((unk32 *)param1, 0, 1);
}
ARM void LinkStateBase::func_ov00_020a8ab0(unk32 param1) {
    gPlayerControlData->func_ov000_020b464c((unk32 *)param1, 1, 1);
}
void LinkStateBase::func_ov00_020a8ad0(unk32 param1) {
    func_ov000_020c0e24(gPlayerControlData->mUnk_118, param1);
    func_ov000_020c0e24(gPlayerControlData->mUnk_138, param1);
}
ARM void LinkStateBase::func_ov00_020a8b04(s32 param1, bool param2) {
    PlayerControlData *pcd = gPlayerControlData;
    if (param2) {
        ((UnkStruct_0202e1a0 *)(pcd->mUnk_118 + 0xc))->func_0202e310(param1);
    } else {
        ((UnkStruct_0202e1a0 *)(pcd->mUnk_138 + 0xc))->func_0202e310(param1);
    }
}
ARM unk32 LinkStateBase::func_ov00_020a8b3c(s32 param1) {
    PlayerControlData *pcd = gPlayerControlData;
    unk32 result = 0;
    unk32 base = param1 ? pcd->mUnk_118 : pcd->mUnk_138;
    if (((UnkStruct_0202e1a0 *)(base + 0xc))->func_0202e58c() && (*(u16 *)(base + 0xe) & 5) == 0) {
        result = 1;
    }
    return result;
}
ARM bool LinkStateBase::func_ov00_020a8b80() {
    return data_027e0fd4->mUnk_0c6 >= 0;
}
ARM bool LinkStateBase::HasFlags_PlayerLinkBase_Unk48(u16 flags) {
    return (*(u16 *)&mLink->mUnk_48 & flags) != 0;
}
ARM u8 LinkStateBase::Get_PlayerLinkBase_Unk5e() {
    return *(u8 *)&mLink->mUnk_5c[2];
}
ARM unk32 LinkStateBase::Get_PlayerControlData_Unk004() {
    return (unk32)&gPlayerControlData->mUnk_004;
}
ARM PlayerCharacter LinkStateBase::GetCurrentCharacter() {
    return mLink->GetCurrentCharacter();
}
ARM PlayerControlData *LinkStateBase::GetPlayerControlData() {
    return gPlayerControlData;
}
ARM LinkStateId LinkStateBase::GetStateId() {
    return mLink->GetStateId();
}
ARM s32 LinkStateBase::GetHealth() {
    return mLink->mHealth;
}
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
ARM unk8 *LinkStateBase::func_ov00_020a8c64() {
    return (unk8 *)&data_027e0fd4->mUnk_090;
}
ARM u16 *LinkStateBase::GetPlayerAngle() {
    return &gPlayerAngle;
}
ARM void *LinkStateBase::GetPlayer_Unk18() {
    return &data_027e0fb0;
}
ARM s32 LinkStateBase::Get_PlayerControlData_Unk32() {
    return gPlayerControlData->mUnk_032;
}
ARM Actor *LinkStateBase::GetGrabActor() {
    return gActorManager->GetActor(&mLink->mGrabActor);
}
ARM ActorRef *LinkStateBase::GetGrabActorRef() {
    return &mLink->mGrabActor;
}
ARM unk32 LinkStateBase::Grab() {
    return mLink->Grab();
}
ARM s32 *LinkStateBase::Get_PlayerLinkBase_Unk44() {
    return &mLink->mUnk_44;
}
ARM bool LinkStateBase::IsEquipBeingUsed(ItemFlag id) {
    EquipItem *equip = gItemManager->GetEquipItem(id);
    return equip != NULL && equip->IsInUse();
}
ARM EquipItem *LinkStateBase::GetEquipItem(ItemFlag id) {
    return gItemManager->GetEquipItem(id);
}
ARM UnkStruct_027e0fd4 *LinkStateBase::func_ov00_020a8d40() {
    return data_027e0fd4;
}
ARM unk32 LinkStateBase::func_ov00_020a8d50() {
    return func_ov000_020c0d68(gPlayerControlData->mUnk_138);
}
ARM unk32 LinkStateBase::func_ov00_020a8d6c() {
    return func_ov000_020c0d68(gPlayerControlData->mUnk_118);
}
s32 LinkStateBase::PlayerControlData_vfunc_14(s32 param1) {}
ARM unk32 LinkStateBase::Get_PlayerControlData_Unk100() {
    return gPlayerControlData->mUnk_100;
}
ARM unk32 LinkStateBase::Get_PlayerControlData_Unk120() {
    return gPlayerControlData->mUnk_120;
}
ARM s32 *LinkStateBase::Get_PlayerLinkBase_Unk38() {
    return &mLink->mUnk_38;
}
ARM Bhio *LinkStateBase::GetBhio0() {
    return mLink->mBhio_0;
}
ARM Bhio *LinkStateBase::GetBhio1() {
    return mLink->mBhio_1;
}
