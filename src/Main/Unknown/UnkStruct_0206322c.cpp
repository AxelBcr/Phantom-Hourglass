#include "Unknown/UnkStruct_0206322c.hpp"
#include "global.h"
#include "types.h"
#include <stdarg.h>

void func_02027ab4(unk32, Screen *, UNK_PTR, UNK_PTR, unk32, unk32, unk32, unk32);

extern "C" {
unk32 *MountCompressedNarc(char *, char *, unk8 *, unk32, unk32);
unk8 data_020691a0[0xCC00];
UNK_PTR func_02032054(char *, unk32);
UNK_PTR func_0203206c(char *, unk32);
void func_02016fcc(unk32 *);

void GX_LoadBG0Scr(u16 *data, unk32, u32 size);
void GXS_LoadBG0Scr(u16 *data, unk32, u32 size);
void CleanAndInvalidateDataCacheLines(void *, u32 size); // DC_FlushRange?
void Fill16(unk32, void *, u32 size);
int vsnprintf(char *s, size_t n, const char *format, va_list arg);
}

THUMB void UnkStruct_0206322c::func_02030354(bool doTopScreen, bool doBottomScreen) {
    Screen *pScreen;
    unk32 *uVar1;

    uVar1         = MountCompressedNarc("BGF", "Menu/UI_main/DbgFntM.bin", data_020691a0, sizeof(data_020691a0), 1);
    this->mUnk_00 = func_02032054("BGF:DbgFntM.ncgr", 1);
    this->mUnk_04 = func_0203206c("BGF:UIM.nclr", 1);

    if (doTopScreen) {
        pScreen          = &this->topScreen;
        pScreen->mUnk_00 = 0x100;
        pScreen->mUnk_02 = 0xC0;
        pScreen->mUnk_04 = 0;
        pScreen->mUnk_06 = 0;
        pScreen->mUnk_08 = 0xC00;
        func_02027ab4(0, pScreen, this->mUnk_00, this->mUnk_04, 0, 0, 0, 2);
    }

    if (doBottomScreen) {
        pScreen          = &this->bottomScreen;
        pScreen->mUnk_00 = 0x100;
        pScreen->mUnk_02 = 0xC0;
        pScreen->mUnk_04 = 0;
        pScreen->mUnk_06 = 0;
        pScreen->mUnk_08 = 0xC00;
        func_02027ab4(4, pScreen, this->mUnk_00, this->mUnk_04, 0, 0, 0, 2);
    }

    func_02016fcc(uVar1);
}

THUMB void *UnkStruct_0206322c::func_02030408(void) {
    this->mUnk_00 = NULL;
    this->mUnk_04 = NULL;
    this->func_020304a8(true, true);
    return this;
}

THUMB void UnkStruct_0206322c::func_02030464(bool doTopScreen, bool doBottomScreen) {
    if (doTopScreen) {
        CleanAndInvalidateDataCacheLines(&this->topScreen.data, sizeof(this->topScreen.data));
        GX_LoadBG0Scr(this->topScreen.data, 0, sizeof(this->topScreen.data));
    }

    if (doBottomScreen) {
        CleanAndInvalidateDataCacheLines(&this->bottomScreen.data, sizeof(this->bottomScreen.data));
        GXS_LoadBG0Scr(this->bottomScreen.data, 0, sizeof(this->bottomScreen.data));
    }
}

THUMB void UnkStruct_0206322c::func_020304a8(bool doTopScreen, bool doBottomScreen) {
    if (doTopScreen) {
        Fill16(0, this->topScreen.data, sizeof(this->topScreen.data));
    }

    if (doBottomScreen) {
        Fill16(0, this->bottomScreen.data, sizeof(this->bottomScreen.data));
    }
}

extern "C" THUMB void func_02030420(UnkStruct_0206322c *self, unk32 x, unk32 y, unk32 tile, u8 doBottom, unk32 palette) {
    if (!doBottom) {
        ((u16 *)&self->topScreen)[y * SCREEN_WIDTH + x + 6] = (palette << 12) | tile;
    } else {
        ((u16 *)&self->bottomScreen)[y * SCREEN_WIDTH + x + 6] = (palette << 12) | tile;
    }
}

extern "C" {
int func_02030758(unk32);
int func_020307dc(unk32);
int func_02030730(unk32);
}

extern "C" THUMB int func_020305ac(unk32 x, unk32 y, unk32 palette, unk32 charCode, unk32 doBottom) {
    unk32 secondChar;
    int i;
    int ret;

    secondChar = 0;
    ret        = 0;

    if (charCode >= 0x8000) {
        if (func_02030758(charCode)) {
            charCode -= 1;
            secondChar = 0x814A;
        } else if (func_020307dc(charCode)) {
            secondChar = 0x814B;
            charCode -= 2;
        }
        charCode = func_02030730(charCode);
    }

    i = 0;
    do {
        charCode -= 0x20;
        func_02030420(&data_0206322c, x, y, charCode, doBottom, palette);
        if (i != 0) {
            break;
        }
        if (secondChar == 0) {
            break;
        }
        charCode = func_02030730(secondChar);
        ret      = 1;
        i++;
        x++;
    } while (i < 2);

    return ret;
}

extern "C" int func_020306c0(char *str, int charIdx);

THUMB void DisplayDebugText(unk32 x, unk32 y, unk32 align, unk32 unkVal2, char *str, unk32 param6) {
    u8 *cursor;
    int charIdx;
    int col;
    int curChar;
    int curX;

    cursor  = (u8 *)str;
    charIdx = 0;
    curX    = x;
    col     = -1;

    if (*cursor == 0) {
        return;
    }

    do {
        if (col < 0x20) {
            if (func_02030758(curChar)) {
                if (col > 0x1e) {
                    y++;
                    col = -1;
                }
            }
        }

        if (col < 0) {
            switch (align) {
                case 1:
                    curX = x - (func_020306c0(str, charIdx) >> 1);
                    if (curX < 0) {
                        curX = 0;
                    }
                    break;
                case 2:
                    curX = x - func_020306c0(str, charIdx);
                    if (curX < 0) {
                        curX = 0;
                    }
                    break;
                case 0:
                    curX = x;
                    break;
            }
            col = curX;
        }

        curChar = *cursor;
        cursor++;
        charIdx++;
        if (curChar >= 0x80 && *cursor != 0) {
            curChar = (curChar << 8) | *cursor;
            cursor++;
            charIdx++;
        }

        if (curChar == 0xA) {
            y++;
            col = -1;
        } else {
            if (func_020305ac(col, y, unkVal2, curChar, param6) == 1) {
                col++;
            }
            col++;
        }
    } while (*cursor != 0);
}

THUMB void DisplayDebugTextFormat(unk32 param1, unk32 x, unk32 y, unk32 unkVal1, unk32 unkVal2, char *fmt, va_list args) {
    char buffer[0x100];

    vsnprintf(buffer, sizeof(buffer), fmt, args);
    DisplayDebugText(x, y, unkVal1, unkVal2, buffer, param1);
}

THUMB void DisplayDebugTextFormat_thunk(unk32 param1, unk32 param2, unk32 param3, unk32 param4, unk32 param5, char *fmt, ...) {
    va_list args;

    va_start(args, fmt);
    DisplayDebugTextFormat(param1, param2, param3, param4, param5, fmt, args);
    va_end(args);
}

THUMB void DisplayDebugTextF(unk32 x, unk32 y, unk32 unkVal1, unk32 unkVal2, char *fmt, ...) {
    va_list args;

    va_start(args, fmt);
    DisplayDebugTextFormat(0, x, y, unkVal1, unkVal2, fmt, args);
    va_end(args);
}
