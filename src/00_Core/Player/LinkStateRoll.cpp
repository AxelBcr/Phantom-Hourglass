#include "Player/LinkStateRoll.hpp"

void LinkStateRoll::vfunc_00() {}
ARM LinkStateId LinkStateRoll::GetId() {
    return LinkStateId_Roll;
}
void LinkStateRoll::LoadBhio() {}
void LinkStateRoll::OnStateEnter() {}
void LinkStateRoll::OnStateLeave(s32 param1) {}
bool LinkStateRoll::vfunc_20(s32 param1) {}
bool LinkStateRoll::vfunc_24(s32 param1) {}
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
