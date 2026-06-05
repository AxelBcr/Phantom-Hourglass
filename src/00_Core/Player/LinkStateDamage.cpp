#include "Player/LinkStateDamage.hpp"
#include "Player/LinkStateItem.hpp"
#include "Player/EquipBombchu.hpp"
#include "Game/Game.hpp"
#include "Item/ItemManager.hpp"
#include "Save/AdventureFlags.hpp"
#include "DTCM/UnkStruct_027e0e58.hpp"
#include "Unknown/UnkStruct_020eec9c.hpp"
#include "Unknown/UnkStruct_020e9360.hpp"
#include "Unknown/UnkStruct_ov000_020e9c88.hpp"

extern "C" unk32 func_0201e388(void *param1, const char *param2);
extern "C" void func_02019534(void *model, unk32 param1, unk32 param2);
extern "C" void func_0202d95c(Vec3p *param1, q20 param2);
void func_ov000_020b7e6c(s32 *param1);

static char *gShipParts[8] = {"brg", "anc", "pdl", "hul", "can", "dco", "bow", "fnl"};

THUMB void LinkStateDamage::vfunc_00() {}

LinkStateBase_UnkStruct1 LinkStateDamage::data_ov000_020e5acc = {74, {0x1000, 0, 0x3E000}};
LinkStateBase_UnkStruct1 LinkStateDamage::data_ov000_020e5adc = {43, {0x1000, 0, 0x5000}};
unk32 LinkStateDamage::data_ov000_020e5aec                    = 6;
LinkStateBase_UnkStruct1 LinkStateDamage::data_ov000_020e5af0 = {12, {0x1800, 0, 0xa000}};
LinkStateBase_UnkStruct1 LinkStateDamage::data_ov000_020e5b00 = {13, {0x1800, 0, 0xa000}};
LinkStateBase_UnkStruct1 LinkStateDamage::data_ov000_020e5b10 = {12, {0x1000, 0, 0xa000}};
LinkStateBase_UnkStruct1 LinkStateDamage::data_ov000_020e5b20 = {13, {0x1000, 0, 0xa000}};
LinkStateBase_UnkStruct1 LinkStateDamage::data_ov000_020e5b30 = {39, {0x1000, 0, 0x2000}};
LinkStateBase_UnkStruct1 LinkStateDamage::data_ov000_020e5b40 = {10, {0x800, 0, 0x4000}};
LinkStateBase_UnkStruct1 LinkStateDamage::data_ov000_020e5b50 = {84, {0x1000, 0, 0x19000}};

THUMB void LinkStateDamage::LoadBhio() {
    s32 unk1 = this->PlayerControlData_vfunc_14(data_ov000_020e5af0.mUnk_00);

    // Front minor damage regeneration speed
    this->GetBhio0()->GetField2(true, 'LDMG', "前小ダメ再生速度", &data_ov000_020e5af0.mUnk_04.x, 8, 0, 0x2000);

    // Front minor damage start frame
    this->GetBhio0()->GetField2(true, 'LDMG', "前小ダメ開始フレーム", &data_ov000_020e5af0.mUnk_04.y, 8, 0, unk1 / 2);

    // Front minor damage end frame
    this->GetBhio0()->GetField2(true, 'LDMG', "前小ダメ終了フレーム", &data_ov000_020e5af0.mUnk_04.z, 8, unk1 / 2, unk1);

    unk1 = this->PlayerControlData_vfunc_14(data_ov000_020e5b00.mUnk_00);

    // Back minor damage regeneration speed
    this->GetBhio0()->GetField2(true, 'LDMG', "後小ダメ再生速度", &data_ov000_020e5b00.mUnk_04.x, 8, 0, 0x2000);

    // Back minor damage start frame
    this->GetBhio0()->GetField2(true, 'LDMG', "後小ダメ開始フレーム", &data_ov000_020e5b00.mUnk_04.y, 8, 0, unk1 / 2);

    // Back minor damage end frame
    this->GetBhio0()->GetField2(true, 'LDMG', "後小ダメ終了フレーム", &data_ov000_020e5b00.mUnk_04.z, 8, unk1 / 2, unk1);

    // Number of tears [verb]
    this->GetBhio0()->GetField2(false, 'LDMG', "ビリビリ回数", &data_ov000_020e5aec, 6, 0, 0x14);

    // Tear [verb] playback speed
    this->GetBhio0()->GetField2(true, 'LDMG', "ビリビリ再生速度", &data_ov000_020e5adc.mUnk_04.x, 8, 0, 0x2000);

    this->GetBhio0();
    this->GetBhio0();
    this->GetBhio0();
    this->GetBhio0();
    this->GetBhio0();
    this->GetBhio1();
}

ARM void LinkStateDamage::OnStateEnter() {
    this->func_ov00_020a8a4c(&data_ov000_020e5b10, 1);
    this->func_ov00_020a8a4c(&data_ov000_020e5b20, 1);
    this->func_ov00_020a8a4c(&data_ov000_020e5b30, 1);
    this->func_ov00_020a8a4c(&data_ov000_020e5b40, 1);
    this->func_ov00_020a8a4c(&data_ov000_020e5b50, 1);
}

ARM void LinkStateDamage::OnStateLeave(s32 param1) {
    this->LinkStateBase::OnStateLeave(param1);

    switch (this->mUnk_1c) {
        case 5: {
            for (s32 *p = (s32 *) this->mUnk_34; p != (s32 *) &this->mUnk_3c; p++) {
                func_ov000_020b7e6c(p);
            }
            break;
        }
        case 6: {
            *((u8 *) this->GetPlayerControlData() + 0x14b) = 0;
            func_ov000_020b7e6c((s32 *) &this->mUnk_9c);
            UnkStruct_027e0e58 *p1 = data_027e0e58;
            p1->func_ov000_0207c1b0(0x21, this->GetPlayerPos(), 1, 0, 0);
            UnkStruct_027e0e58 *p2 = data_027e0e58;
            p2->func_ov000_0207c1b0(0x22, this->GetPlayerPos(), 1, 0, 0);
            data_ov000_020eec9c.func_ov000_020d7a84(0xd9, this->GetPlayerPos());
            break;
        }
        case 0xd: {
            for (s32 *p = (s32 *) this->mUnk_a0; p != (s32 *) &this->mUnk_ac; p++) {
                func_ov000_020b7e6c(p);
            }
            func_ov000_020b7e6c((s32 *) &this->mUnk_ac);
            this->func_ov00_020a84bc(1);
            *((u8 *) this->GetPlayerControlData() + 0x14d) = 0;
            this->func_ov005_021113c4(false);
            break;
        }
        default:
            break;
    }

    *(u16 *) this->GetPlayer_Unk18() = 0;
    this->mUnk_22 = 0;
    this->mUnk_31 = 0;
    if (gGame.mModeId == 2 && this->GetCurrentCharacterHealth() <= 0 && this->mUnk_18 != 0xd &&
        this->mUnk_18 != 0xf && !gItemManager->HasItem((ItemFlag) 0) &&
        gAdventureFlags->Get((AdventureFlag) 0xff)) {
        gAdventureFlags->Set((AdventureFlag) 0xf, true);
    }
    if (param1 != 5) {
        this->mUnk_18 = 0;
    }
}

ARM void LinkStateDamage::func_ov00_020ac9e4(unk32 param1) {
    if (!this->func_ov005_02110f50(this->mUnk_30, param1, this->mUnk_22, (u32 *) this->mUnk_b0)) {
        this->ChangeLinkState(LinkStateId_Move);
    } else {
        s32 unkInt                 = mUnk_2c;
        UnkStruct_027e0fd4 *unkPtr = this->func_ov00_020a8d40();
        unkPtr->mUnk_09c           = unkInt;
        if (data_027e0d38->mUnk_0c.func_ov000_020a5e9c() == 47) {
            this->func_ov005_0210f7b8();
        }
    }
}

ARM void RespawnLink(LinkStateDamage *linkState) {
    Vec3p new_pos;

    PlayerControlData *ctrlData = linkState->GetPlayerControlData();
    Vec3p *pos                  = linkState->GetPlayerPos();
    Vec3p_Add(pos, &ctrlData->mLastJumpLocation, &new_pos);
    linkState->mUnk_3c.SetTranslation(&new_pos);
}

#pragma readonly_strings on
ARM void LinkStateDamage::SetLinkFrozenMaterial() {
    void *model         = mUnk_3c.GetLcdcAddress();
    u32 materialsOffset = *(u32 *) ((u32) model + 8);
    void *materialList  = (void *) ((u32) model + materialsOffset + 4);
    unk32 unkVar1       = func_0201e388(materialList, "link_ice1");
    unk32 unkVar2       = data_ov000_020e9360.func_ov000_02079e68(1);
    void *model2        = mUnk_3c.GetLcdcAddress();
    func_02019534(model2, unkVar1, unkVar2);
}
#pragma readonly_strings reset

ARM void LinkStateDamage::vfunc_30(unk32 param1) {
    if (mUnk_18 == 6) {
        Vec3p *playerPos = this->GetPlayerPos();
        Vec3p unkPos;
        unkPos.x = playerPos->x;
        unkPos.y = playerPos->y;
        unkPos.z = playerPos->z;
        unkPos.y += 0x999;
        data_ov000_020e9c88.func_ov000_0207b89c(param1, &unkPos, (void (*)(void *)) &RespawnLink, this);
    }
}

ARM void LinkStateDamage::func_ov00_020acb6c(Vec3p *param1, unk32 param2) {
    Vec3p sp;

    if (gGame.mModeId == 2 && gItemManager->GetEquipItem(ItemFlag_BombchuBag) != NULL) {
        LinkStateItem::GetEquipBombchu()->func_ov014_0213ec64();
    }

    this->mUnk_18 = param2;

    q20 pz = param1->z;
    q20 px = param1->x;
    sp.x   = px;
    sp.y   = 0;
    sp.z   = pz;

    s16 groundAngle = FX_Atan2Idx(px, pz);

    s16 diff      = groundAngle - *(s16 *) this->GetPlayerAngle();
    if (diff < 0) {
        diff = -diff;
    }
    this->mUnk_30 = diff < 0x4000;

    switch (this->mUnk_18) {
        case 1:
        case 4:
        case 5:
        case 6:
            func_0202d95c(&sp, 0x28f);
            this->ApplyImpulse((s16) *this->GetPlayerAngle(), 0x28f);
            *this->GetPlayerAngle() = groundAngle;
            if (!this->mUnk_30) {
                *(s16 *) this->GetPlayerAngle() -= 0x8000;
            }
            break;
        case 3:
            func_0202d95c(&sp, 0x4cd);
            *this->GetPlayerAngle() = groundAngle;
            if (!this->mUnk_30) {
                *(s16 *) this->GetPlayerAngle() -= 0x8000;
            }
            break;
        case 9: {
            Vec3p *vel = this->GetPlayerVel();
            vel->x     = param1->x;
            vel->y     = param1->y;
            vel->z     = param1->z;
            s16 a                   = FX_Atan2Idx(sp.x, sp.z);
            *this->GetPlayerAngle() = a;
            *(s16 *) this->GetPlayerAngle() -= 0x8000;
            break;
        }
        case 2:
        case 8:
            func_0202d95c(&sp, 0x400);
            sp.y                    = (this->mUnk_18 == 2) ? 0x548 : 0x19a;
            *this->GetPlayerAngle() = groundAngle;
            if (!this->mUnk_30) {
                *(s16 *) this->GetPlayerAngle() -= 0x8000;
            }
            if (this->mUnk_18 == 8) {
                this->func_ov00_020a82ac();
            }
            break;
        case 7: {
            s32 halfX, halfZ;
            halfZ      = this->GetPlayerVel()->z / 2;
            halfX      = this->GetPlayerVel()->x / 2;
            Vec3p *vel = this->GetPlayerVel();
            vel->x     = halfX;
            vel->y     = 0;
            vel->z     = halfZ;
            func_0202d95c(&sp, 0x266);
            sp.y           = 0x333;
            s16 diff2      = groundAngle - *(s16 *) this->GetPlayerAngle();
            if (diff2 < 0) {
                diff2 = -diff2;
            }
            this->mUnk_30 = diff2 < 0x4000;
            this->mUnk_22 = 2;
            break;
        }
        case 11:
            func_0202d95c(&sp, 0x266);
            break;
        case 12:
            break;
        case 13:
            return;
        default:
            return;
    }

    Vec3p_Add(this->GetPlayerVel(), &sp, this->GetPlayerVel());
}

ARM void LinkStateDamage::Knockback(Vec3p *knockbackVec, unk32 param2) {
    this->mUnk_18     = 2;
    Vec3p *playerVel  = this->GetPlayerVel();
    playerVel->x      = knockbackVec->x;
    playerVel->y      = knockbackVec->y;
    playerVel->z      = knockbackVec->z;
    s16 groundAngle   = FX_Atan2Idx(knockbackVec->x, knockbackVec->z);
    u16 *playerAngle  = this->GetPlayerAngle();
    *playerAngle      = groundAngle - 0x8000;
    this->mUnk_24[12] = 0;
    this->mUnk_22     = param2;
}

ARM bool LinkStateDamage::vfunc_24(s32 param1) {
    switch (param1) {
        case 3:
            return false;
        case 2:
            return mUnk_18 != 0xd;
        default:
            break;
    }

    return false;
}

ARM bool LinkStateDamage::vfunc_20(s32 param1) {
    if (this->func_ov00_020a8b80()) {
        if (this->GetCurrentCharacterHealth() <= 0) {
            if (gGame.mModeId == 2) {
                if (this->GetPlayerVel()->y <= 0) {
                    if (gItemManager->HasPurplePotion()) {
                        mUnk_18 = 0xe;
                    } else {
                        mUnk_18 = 0xf;
                    }
                    this->func_ov00_020a82ac();
                } else {
                    return false;
                }
            } else {
                this->func_ov00_020a82ac();
                mUnk_18 = 0xe;
            }
            return true;
        }
        if (mUnk_32 > 0) {
            this->func_ov00_020a82ac();
            mUnk_18 = 0xe;
            return true;
        }
    }
    return false;
}

ARM void LinkStateDamage::func_ov00_020acfe8(bool param1) {
    if (param1) {
        this->func_ov00_020a8a4c(&data_ov000_020e5b00, 1);
    } else {
        this->func_ov00_020a8a4c(&data_ov000_020e5af0, 1);
    }
}

ARM LinkStateId LinkStateDamage::GetId() {
    return LinkStateId_Damage;
}
