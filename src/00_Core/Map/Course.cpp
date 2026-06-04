#include "Map/Course.hpp"

extern "C" char *strcpy(char *dst, const char *src);

void Course::GetDungeonProgress(CourseProgress *param_2) {
    param_2->flags = mFlags1[0];
    if (mType == CourseType_TempleOfTheOceanKing) {
        return;
    }
    param_2->numKeys = mNumKeys;
    param_2->blueWarpOpen = mBlueWarpOpen;
}
void Course::func_ov00_0207ca28(s32 param_2, unk32 param_3, unk32 param_4) {}
char *Course::SetCourseName(char *src) {
    return strcpy(mName, src);
}
void Course::func_ov00_0207ca78(unk32 param_2, unk8 param_3, unk32 param_4) {}
bool Course::func_ov00_0207caa8(s32 param_2, unk32 *param_3, unk8 *param_4) {}
unk32 Course::func_ov00_0207cb30(s32 param_2) {}
TilePos Course::FindMapGridPos(u32 map) {
    s32 i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (map == mMapGrid[i][j]) {
                return TilePos(i, j);
            }
        }
    }
    return TilePos(mCurrMapPos.x, mCurrMapPos.y);
}
Vec3p *Course::FindMapCenter(unk32 map) {
    return &FindMapData(map)->mCenter;
}
void Course::func_ov00_0207cbe8(s32 param_2) {}
unk8 Course::func_ov00_0207cc24(s32 param_2) {}
unk32 Course::FindMapData_Unk_08(unk32 map) {
    MapData *data = FindMapData(map);
    if (data == NULL) {
        return 0;
    }
    return data->mUnk_08;
}
void Course::GetMCSFilePath(unk32 buf, s32 fileIndex, unk32 fileType) {}
void Course::GetMRCFilePath(unk32 param_2, unk32 buf, unk32 param_4) {}
void Course::func_ov00_0207ce20(unk32 param_2, unk32 param_3, char *param_4, unk32 param_5) {
    func_ov00_0207ce4c(mIndex, param_2, param_3, param_4, param_5);
}
void Course::func_ov00_0207ce4c(s32 param_2, s32 param_3, unk32 param_4, char *param_5, unk32 param_6) {}
bool Course::func_ov00_0207d404(s32 param_2, unk32 param_3, unk32 param_4, unk32 param_5) {}
bool Course::IsCurrentMapInMainGrid() {
    return IsInMainGrid(mCurrMapPos.x, mCurrMapPos.y);
}
bool Course::IsInMainGrid(s32 x, s32 y) {
    if (!mUnk_25c) {
        return true;
    }
    if (mMainGrid.x <= x && x < mMainGrid.x + mMainGridSize.x && mMainGrid.y <= y &&
        y < mMainGrid.y + mMainGridSize.y) {
        return true;
    }
    return false;
}
bool Course::IsMapInMainGrid(u32 map) {
    TilePos pos = FindMapGridPos(map);
    return IsInMainGrid(pos.x, pos.y);
}
bool Course::GetMapScreenPos(s32 map, s32 *x, s32 *y) {
    if (map == 0xff) {
        return false;
    }
    TilePos pos = FindMapGridPos(map);
    if (!IsInMainGrid(pos.x, pos.y)) {
        return false;
    }
    u8 size = mMainGridSize.x;
    if (mMainGridSize.y > size) {
        size = mMainGridSize.y;
    }
    *x = (0x100 / size) * (pos.x - mMainGrid.x) + mScreenMapOffsetX;
    *y = (0xc0 / size) * (pos.y - mMainGrid.y) + mScreenMapOffsetY;
    return true;
}
u32 Course::GetScreenMapCellSizeX() {
    u8 size = mMainGridSize.x;
    if (mMainGridSize.y > size) {
        size = mMainGridSize.y;
    }
    return CoDivide64By32(CoDivide64By32(0x100000, size << 0xc), 0x40000);
}
u32 Course::GetScreenMapCellSizeY() {
    u8 size = mMainGridSize.y;
    if (mMainGridSize.x > size) {
        size = mMainGridSize.x;
    }
    return CoDivide64By32(CoDivide64By32(0xc0000, size << 0xc), 0x30000);
}
unk32 Course::Get_Unk_c8_00() {
    return mUnk_0c8->mUnk_00;
}
unk32 Course::Get_Unk_c8_04() {
    return mUnk_0c8->mUnk_04;
}
bool Course::IsAdjacentMapOnMainGrid(unk32 dir) {
    s32 x = mCurrMapPos.x;
    s32 y = mCurrMapPos.y;
    switch (dir) {
        case 0:
            x++;
            break;
        case 1:
            x--;
            break;
        case 2:
            y++;
            break;
        case 3:
            y--;
            break;
    }
    if (!IsInMainGrid(x, y)) {
        return false;
    }
    return HasGridMap(x, y);
}
bool Course::HasGridMap(s32 x, s32 y) {
    if (x < 0 || y < 0 || x >= 10 || y >= 10) {
        return false;
    }
    return mMapGrid[x][y] != 0xff;
}
u8 Course::GetAdjacentMap(unk32 dir) {
    if (!IsAdjacentMapOnMainGrid(dir)) {
        return 0xff;
    }
    s32 y = GetAdjacentMapY(dir);
    s32 x = GetAdjacentMapX(dir);
    return mMapGrid[x][y];
}
u32 Course::GetAdjacentMapX(s32 ir) {
    u8 x = mCurrMapPos.x;
    if (ir != 0) {
        if (ir == 1) {
            return x - 1;
        }
        return x;
    }
    return x + 1;
}
u32 Course::GetAdjacentMapY(s32 dir) {
    u8 y = mCurrMapPos.y;
    if (dir != 2) {
        if (dir == 3) {
            return y - 1;
        }
        return y;
    }
    return y + 1;
}
u16 Course::FindCurrentMapData_Unk_04() {
    return FindCurrentMapData()->mUnk_04;
}
u32 Course::FindMapData_Unk_04(unk32 param_2) {
    MapData *data = FindMapData(param_2);
    if (data == NULL) {
        return 0xFFFF;
    }
    return data->mUnk_04;
}
unk32 Course::FindMapData_Unk_0c(unk32 map) {
    MapData *data = FindMapData(map);
    if (data == NULL) {
        return 0;
    }
    return data->mUnk_0c;
}
void Course::func_ov00_0207d7bc() {}
void Course::SetFlag0(u32 index, bool value) {
    if (value) {
        mFlags0[index >> 5] |= 1 << (index & 0x1f);
    } else {
        mFlags0[index >> 5] &= ~(1 << (index & 0x1f));
    }
}
bool Course::GetFlag0(u32 index) {
    return (mFlags0[index >> 5] & (1 << (index & 0x1f))) != 0;
}
void Course::SetFlag1(u32 index, bool value) {
    if (value) {
        mFlags1[index >> 5] |= 1 << (index & 0x1f);
    } else {
        mFlags1[index >> 5] &= ~(1 << (index & 0x1f));
    }
}
bool Course::SetFlag1(u32 index) {
    return (mFlags1[index >> 5] & (1 << (index & 0x1f))) != 0;
}
void Course::SetMapDataFlag0(unk32 index, bool value) {
    FindCurrentMapData()->SetFlag0(index, value);
}
bool Course::GetMapDataFlag0(unk32 param_2) {
    return FindCurrentMapData()->GetFlag0(param_2);
}
void Course::SetMapDataFlag1(unk32 param_2, bool param_3) {
    FindCurrentMapData()->SetFlag1(param_2, param_3);
}
bool Course::GetMapDataFlag1(unk32 param_2) {
    return FindCurrentMapData()->GetFlag1(param_2);
}
void Course::SetMapDataFlag2(unk32 param_2, bool param_3) {
    FindCurrentMapData()->SetFlag2(param_2, param_3);
}
bool Course::GetMapDataFlag2(unk32 param_2) {
    return FindCurrentMapData()->GetFlag2(param_2);
}
void Course::SetMapDataFlag3(unk32 param_2, bool param_3) {
    FindCurrentMapData()->SetFlag3(param_2, param_3);
}
bool Course::GetMapDataFlag3(unk32 param_2) {
    return FindCurrentMapData()->GetFlag3(param_2);
}
void Course::SetMapDataFlag4(unk32 param_2, bool param_3) {
    FindCurrentMapData()->SetFlag4(param_2, param_3);
}
bool Course::GetMapDataFlag4(unk32 param_2) {
    return FindCurrentMapData()->GetFlag4(param_2);
}
MapData *Course::FindMapData(u32 map) {}
MapData *Course::FindCurrentMapData() {
    return FindMapData(mMapGrid[mCurrMapPos.x][mCurrMapPos.y]);
}
