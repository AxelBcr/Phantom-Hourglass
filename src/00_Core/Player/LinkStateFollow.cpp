#include "Player/LinkStateFollow.hpp"
#include "Map/MapManager.hpp"
#include "Player/PlayerControl.hpp"

extern "C" void Vec3p_Lerp(Vec3p *a, Vec3p *b, q20 t);
extern "C" void func_0202d95c(Vec3p *param1, q20 param2);

void LinkStateFollow::vfunc_00() {}

ARM LinkStateId LinkStateFollow::GetId() {
    return LinkStateId_Follow;
}

ARM void LinkStateFollow::MoveTowardTarget() {
    if (this->func_ov00_020a8d40()->mUnk_0c0 != 0x1e) {
        return;
    }

    unk32 *tile = gMapManager->MapData_vfunc_78((TilePos *) &this->func_ov00_020a8d40()->mUnk_0c4);
    if (tile == NULL) {
        return;
    }

    Vec3p sp;
    Vec3p_Sub((Vec3p *) ((u32) tile + 0x18), this->GetPlayerPos(), &sp);
    sp.y = 0;
    if (Vec3p_Length(&sp) < 0x155) {
        return;
    }

    func_0202d95c(&sp, 0x155);
    Vec3p_Lerp(this->GetPlayerVel(), &sp, 0x2000);
}
void LinkStateFollow::OnStateLeave(s32 param1) {}

ARM bool LinkStateFollow::vfunc_24(s32 param1) {
    switch (param1) {
        case 4:
            if (mSubState == 1 || mSubState == 6) {
                break;
            }
            return false;

        case 5:
            if (mSubState == 5) {
                return LinkStateBase::vfunc_24(param1);
            }
            break;

        case 1:
        case 2:
        case 3:
            break;

        default:
            return false;
    }

    switch (mSubState) {
        case 1:
        case 6:
        case 0xa:
            return LinkStateBase::vfunc_24(param1);

        default:
            return false;
    }
}

ARM bool LinkStateFollow::vfunc_28() {
    return GetLinkStateCutscene()->mUnk_38 < 0;
}

ARM LinkStateCutscene *LinkStateFollow::GetLinkStateCutscene() {
    return (LinkStateCutscene *) GetLinkState(LinkStateId_Cutscene);
}

ARM bool LinkStateFollow::vfunc_34(Vec3p *param1) {
    if (mSubState != 2) {
        return false;
    }
    param1->y += 0x1200;
    return true;
}
ARM s32 LinkStateFollow::func_ov00_020a9180(Vec3p *param1) {
    void *followObject = gPlayerControl->mFollowObject;
    if (followObject == NULL) {
        TilePos sp;
        sp.x = 0;
        sp.y = 0;
        if (gPlayerControl->func_ov00_020af01c(&sp) == 0) {
            return false;
        }
        gMapManager->func_ov00_02083c7c(param1, sp);
        return true;
    }

    return this->func_ov00_020a9210(param1, (Actor *) followObject) ? *(s8 *) ((u32) followObject + 0x12) : 0;
}

bool LinkStateFollow::func_ov00_020a9210(Vec3p *param1, Actor *param2) {}
