#include "Game/GameModeBattle.hpp"

extern "C" void func_ov012_0211fe08(void *param1);
extern "C" void func_ov012_0211feac(void *param1);
extern "C" void func_ov012_0211fe30(void *param1);
extern "C" void func_ov012_0211ce44(void *param1);
extern "C" void func_ov012_021132d4(void *param1);
extern "C" u8 data_ov012_02137c60[];

GameModeBattle *GameModeBattle::Create(unk32 param1) {}
GameModeBattle::GameModeBattle(unk32 param1) :
    GameModePlay(param1) {}
GameModeBattle::~GameModeBattle() {}
ARM void GameModeBattle::vfunc_24() {
    func_ov012_021132d4(*(void **)(data_ov012_02137c60 + 4));
}
unk32 GameModeBattle::vfunc_08(unk32 param1) {}
ARM void GameModeBattle::vfunc_0c(u16 *param1) {
    func_ov012_0211fe08((u8 *)this + 0x7f0);
}
void GameModeBattle::vfunc_10(u16 *param1) {
    func_ov012_0211fe30((u8 *)this + 0x7f0);
    func_ov012_0211ce44((u8 *)this + 0xd4);
}
ARM void GameModeBattle::vfunc_14(u16 *param1) {
    func_ov012_0211feac((u8 *)this + 0x7f0);
}
ARM void GameModeBattle::vfunc_18() {
    void *obj = *(void **)((u8 *)this + 0xd8);
    (*(void (**)(void *))(*(u32 *)obj + 0x1c))(obj);
}
