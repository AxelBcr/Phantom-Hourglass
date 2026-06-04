#include "Game/GameModePlay.hpp"

#include "DTCM/UnkStruct_027e0c54.hpp"

extern "C" void func_02036074(UnkStruct_027e0c54 *param1);
extern "C" void func_0201823c(void *param1);
extern "C" void func_0201825c();

extern GameModePlay *data_027e0d40;
extern unk32 data_027e0934;

THUMB GameModePlay::GameModePlay(unk32 param1) :
    GameMode(param1) {
    data_027e0d40 = this;
    func_0201823c(&data_027e0934);
}
THUMB GameModePlay::~GameModePlay() {
    func_0201825c();
    data_027e0d40 = NULL;
}
THUMB void GameModePlay::vfunc_1c() {
    func_02036074(&data_027e0c54);
}
THUMB void GameModePlay::vfunc_20() {}
