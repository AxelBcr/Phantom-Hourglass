#include "Player/LinkStateRoll.hpp"
#include "Player/PlayerControl.hpp"
#include "DTCM/UnkStruct_027e0e58.hpp"
#include "Game/Game.hpp"

extern "C" void func_ov000_0207c444(UnkStruct_027e0e58 *param1, unk32 *param2);
extern "C" void func_ov023_021720f0(LinkStateRoll *param1);
extern "C" bool func_ov023_021712fc(LinkStateRoll *param1, s32 param2);
extern void func_ov000_020b7e6c(s32 *param1);

void LinkStateRoll::vfunc_00() {}
ARM LinkStateId LinkStateRoll::GetId() {
    return LinkStateId_Roll;
}
THUMB void LinkStateRoll::LoadBhio() {
    this->GetBhio0();
}
void LinkStateRoll::OnStateEnter() {}
ARM void LinkStateRoll::OnStateLeave(s32 param1) {
    UnkStruct_027e0e58 *temp;
    u32 i;

    LinkStateBase::OnStateLeave(param1);
    switch (mSubState) {
        case 1:
            this->Clear_PlayerLinkBase_Unk48(1);
            temp = data_027e0e58;
            for (i = 0; i < 5; i++) {
                func_ov000_0207c444(temp, &mUnk_2c[i]);
            }
            break;

        case 6:
            this->func_ov00_020a84bc(1);
            break;

        case 3:
            this->func_ov00_020a8d40()->mUnk_05a = 0;
            break;

        case 9:
            func_ov023_021720f0(this);
            break;
    }

    {
        s32 *p;
        for (p = (s32 *) mUnk_2c; p != (s32 *) &mUnk_40; p++) {
            func_ov000_020b7e6c(p);
        }
    }
}
ARM bool LinkStateRoll::vfunc_20(s32 param1) {
    PlayerControl *pc;

    if (this->GetGrabActor() == NULL) {
        if (this->mUnk_12 >= 7) {
            this->mSubState = 1;
            return true;
        }
        if (this->func_ov00_020a8b80()) {
            pc = gPlayerControl;
            if (pc->func_ov00_020b12d0((s16 *) this->GetPlayerAngle()) &&
                this->func_ov00_020a8d40()->mUnk_05a == 0 &&
                !this->HasFlags_PlayerLinkBase_Unk48(0x3f)) {
                if (!(gGame.mModeId == 2 &&
                      this->GetCurrentCharacter() == PlayerCharacter_Gongoron)) {
                    this->mSubState = 0;
                    return true;
                }
            }
        }
    }

    if (gGame.mModeId == 2) {
        if (this->GetGrabActor() == NULL) {
            if (this->GetCurrentCharacter() == PlayerCharacter_Gongoron) {
                return func_ov023_021712fc(this, param1);
            }
            if (this->func_ov00_020a8b80() && this->func_ov00_020a8d40()->mUnk_0dc >= 0x99a &&
                (s32) gPlayerControl->func_ov00_020b034c() > 0) {
                this->func_ov005_0210f808(gPlayerControl->func_ov00_020b034c(), NULL, 0);
                this->mSubState = 2;
                return true;
            }
        }
        return this->func_ov005_02108094();
    }
    return false;
}
ARM bool LinkStateRoll::vfunc_24(s32 param1) {
    switch (param1) {
        case 1:
            switch (mSubState) {
                case 5:
                case 6:
                case 7:
                    return false;
            }
            break;

        case 2:
        case 3:
            break;

        case 4:
            if (mSubState != 0) {
                return false;
            }
            break;

        case 5:
            switch (mSubState) {
                case 0:
                case 3:
                case 8:
                    return false;
            }
            break;

        case 7:
            if (mSubState == 0 && !LinkStateBase::func_ov005_0211139c() &&
                PlayerControl::func_ov00_020aeeac()) {
                return true;
            }
            break;

        default:
            return false;
    }
    return LinkStateBase::vfunc_24(param1);
}
ARM void LinkStateRoll::func_ov00_020aee58(s16 param1, u16 param2) {
    if (this->mUnk_16 != param2) {
        this->mUnk_12 = 0;
    }
    this->mUnk_12 = this->mUnk_12 + param1;
    this->mUnk_14 = 15;
    this->mUnk_16 = param2;
}
ARM void LinkStateRoll::func_ov00_020aee84() {
    if (this->mUnk_14 > 0) {
        this->mUnk_14--;
    } else if (this->mUnk_12 > 0) {
        this->mUnk_12--;
    }
}
bool LinkStateRoll::func_ov00_020aeeac() {}
