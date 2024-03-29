#pragma once
#ifndef _KEYBOARD_KEY_CODE_H_
#define _KEYBOARD_KEY_CODE_H_

typedef enum Keyboard_KeyCode_Typedef {
    Keyboard_KeyCode_A = 4,
    Keyboard_KeyCode_B = 5,
    Keyboard_KeyCode_C = 6,
    Keyboard_KeyCode_D = 7,
    Keyboard_KeyCode_E = 8,
    Keyboard_KeyCode_F = 9,
    Keyboard_KeyCode_G = 10,
    Keyboard_KeyCode_H = 11,
    Keyboard_KeyCode_I = 12,
    Keyboard_KeyCode_J = 13,
    Keyboard_KeyCode_K = 14,
    Keyboard_KeyCode_L = 15,
    Keyboard_KeyCode_M = 16,
    Keyboard_KeyCode_N = 17,
    Keyboard_KeyCode_O = 18,
    Keyboard_KeyCode_P = 19,
    Keyboard_KeyCode_Q = 20,
    Keyboard_KeyCode_R = 21,
    Keyboard_KeyCode_S = 22,
    Keyboard_KeyCode_T = 23,
    Keyboard_KeyCode_U = 24,
    Keyboard_KeyCode_V = 25,
    Keyboard_KeyCode_W = 26,
    Keyboard_KeyCode_X = 27,
    Keyboard_KeyCode_Y = 28,
    Keyboard_KeyCode_Z = 29,
    Keyboard_KeyCode_1 = 30,
    Keyboard_KeyCode_2 = 31,
    Keyboard_KeyCode_3 = 32,
    Keyboard_KeyCode_4 = 33,
    Keyboard_KeyCode_5 = 34,
    Keyboard_KeyCode_6 = 35,
    Keyboard_KeyCode_7 = 36,
    Keyboard_KeyCode_8 = 37,
    Keyboard_KeyCode_9 = 38,
    Keyboard_KeyCode_0 = 39,
    Keyboard_KeyCode_Enter = 40,
    Keyboard_KeyCode_ESC = 41,
    Keyboard_KeyCode_Backspace = 42,
    Keyboard_KeyCode_Tab = 43,
    Keyboard_KeyCode_Space = 44,
    Keyboard_KeyCode_Minus = 45,
    Keyboard_KeyCode_Equal = 46,
    Keyboard_KeyCode_OpenSquareBrack = 47,
    Keyboard_KeyCode_CloseSquareBrack = 48,
    Keyboard_KeyCode_Backslash = 49,
    Keyboard_KeyCode_Semicolon = 51,
    Keyboard_KeyCode_QuotationMarks = 52,
    Keyboard_KeyCode_GraveAccent = 53,
    Keyboard_KeyCode_Comma = 54,
    Keyboard_KeyCode_Peroid = 55,
    Keyboard_KeyCode_Shash = 56,
    Keyboard_KeyCode_CapsLock = 57,
    Keyboard_KeyCode_F1 = 58,
    Keyboard_KeyCode_F2 = 59,
    Keyboard_KeyCode_F3 = 60,
    Keyboard_KeyCode_F4 = 61,
    Keyboard_KeyCode_F5 = 62,
    Keyboard_KeyCode_F6 = 63,
    Keyboard_KeyCode_F7 = 64,
    Keyboard_KeyCode_F8 = 65,
    Keyboard_KeyCode_F9 = 66,
    Keyboard_KeyCode_F10 = 67,
    Keyboard_KeyCode_F11 = 68,
    Keyboard_KeyCode_F12 = 69,
    Keyboard_KeyCode_PrintScreen = 70,
    Keyboard_KeyCode_ScrollLock = 71,
    Keyboard_KeyCode_Pause = 72,
    Keyboard_KeyCode_Insert = 73,
    Keyboard_KeyCode_Home = 74,
    Keyboard_KeyCode_PageUp = 75,
    Keyboard_KeyCode_DEL = 76,
    Keyboard_KeyCode_End = 77,
    Keyboard_KeyCode_PageDown = 78,
    Keyboard_KeyCode_RightArrow = 79,
    Keyboard_KeyCode_LeftArrow = 80,
    Keyboard_KeyCode_DownArrow = 81,
    Keyboard_KeyCode_UpArrow = 82,
    Keyboard_KeyCode_NumLock = 83,
    Keyboard_KeyCode_Keypad_Slash = 84,
    Keyboard_KeyCode_Keypad_Asterisk = 85,
    Keyboard_KeyCode_Keypad_Minus = 86,
    Keyboard_KeyCode_Keypad_Plus = 87,
    Keyboard_KeyCode_Keypad_Enter = 88,
    Keyboard_KeyCode_Keypad_1 = 89,
    Keyboard_KeyCode_Keypad_2 = 90,
    Keyboard_KeyCode_Keypad_3 = 91,
    Keyboard_KeyCode_Keypad_4 = 92,
    Keyboard_KeyCode_Keypad_5 = 93,
    Keyboard_KeyCode_Keypad_6 = 94,
    Keyboard_KeyCode_Keypad_7 = 95,
    Keyboard_KeyCode_Keypad_8 = 96,
    Keyboard_KeyCode_Keypad_9 = 97,
    Keyboard_KeyCode_Keypad_0 = 98,
    Keyboard_KeyCode_Keypad_Peroid = 99,
    Keyboard_KeyCode_Application = 101,
    Keyboard_KeyCode_Power = 102,
    Keyboard_KeyCode_Keypad_Equal = 103,
    Keyboard_KeyCode_F13 = 104,
    Keyboard_KeyCode_F14 = 105,
    Keyboard_KeyCode_F15 = 106,
    Keyboard_KeyCode_F16 = 107,
    Keyboard_KeyCode_F17 = 108,
    Keyboard_KeyCode_F18 = 109,
    Keyboard_KeyCode_F19 = 110,
    Keyboard_KeyCode_F20 = 111,
    Keyboard_KeyCode_F21 = 112,
    Keyboard_KeyCode_F22 = 113,
    Keyboard_KeyCode_F23 = 114,
    Keyboard_KeyCode_F24 = 115,
    Keyboard_KeyCode_Execute = 116,
    Keyboard_KeyCode_Help = 117,
    Keyboard_KeyCode_Menu = 118,
    Keyboard_KeyCode_Select = 119,
    Keyboard_KeyCode_Stop = 120,
    Keyboard_KeyCode_Again = 121,
    Keyboard_KeyCode_Undo = 122,
    Keyboard_KeyCode_Cut = 123,
    Keyboard_KeyCode_Copy = 124,
    Keyboard_KeyCode_Paste = 125,
    Keyboard_KeyCode_Find = 126,
    Keyboard_KeyCode_Mute = 127,
    Keyboard_KeyCode_VolumeUp = 128,
    Keyboard_KeyCode_NumComma = 133,
    Keyboard_KeyCode_NumEqual = 134,
    Keyboard_KeyCode_International1 = 135,
    Keyboard_KeyCode_International2 = 136,
    Keyboard_KeyCode_International3 = 137,
    Keyboard_KeyCode_International4 = 138,
    Keyboard_KeyCode_International5 = 139,
    Keyboard_KeyCode_International6 = 140,
    Keyboard_KeyCode_International7 = 141,
    Keyboard_KeyCode_International8 = 142,
    Keyboard_KeyCode_International9 = 143,
    Keyboard_KeyCode_LANG1 = 144,
    Keyboard_KeyCode_LANG2 = 145,
    Keyboard_KeyCode_LANG3 = 146,
    Keyboard_KeyCode_LANG4 = 147,
    Keyboard_KeyCode_LANG5 = 148,
    Keyboard_KeyCode_LANG6 = 149,
    Keyboard_KeyCode_LANG7 = 150,
    Keyboard_KeyCode_LANG8 = 151,
    Keyboard_KeyCode_LANG9 = 152,
    Keyboard_KeyCode_AlternateErase = 153,
    Keyboard_KeyCode_SysReqAttention = 154,
    Keyboard_KeyCode_Cancel = 155,
    Keyboard_KeyCode_Clear = 156,
    Keyboard_KeyCode_Prior = 157,
    Keyboard_KeyCode_Return = 158,
    Keyboard_KeyCode_Separator = 159,
    Keyboard_KeyCode_Out = 160,
    Keyboard_KeyCode_Oper = 161,
    Keyboard_KeyCode_ClearAgain = 162,
    Keyboard_KeyCode_CrSelProps = 163,
    Keyboard_KeyCode_ExSel = 164,
    Keyboard_KeyCode_Keypad_00 = 176,
    Keyboard_KeyCode_Keypad_000 = 177,
    Keyboard_KeyCode_ThousandsSeparator = 178,
    Keyboard_KeyCode_DecimalSeparator = 179,
    Keyboard_KeyCode_CurrencyUnit = 180,
    Keyboard_KeyCode_CurrencySubunit = 181,
    Keyboard_KeyCode_Keypad_OpenBrack = 182,
    Keyboard_KeyCode_Keypad_CloseBrack = 183,
    Keyboard_KeyCode_Keypad_OpenCurlyBrack = 184,
    Keyboard_KeyCode_Keypad_CloseCurlyBrack = 185,
    Keyboard_KeyCode_Keypad_Tab = 186,
    Keyboard_KeyCode_Keypad_Backspace = 187,
    Keyboard_KeyCode_Keypad_A = 188,
    Keyboard_KeyCode_Keypad_B = 189,
    Keyboard_KeyCode_Keypad_C = 190,
    Keyboard_KeyCode_Keypad_D = 191,
    Keyboard_KeyCode_Keypad_E = 192,
    Keyboard_KeyCode_Keypad_F = 193,
    Keyboard_KeyCode_Keypad_XOR = 194,
    Keyboard_KeyCode_Keypad_Caret = 195,
    Keyboard_KeyCode_Keypad_Percent = 196,
    Keyboard_KeyCode_Keypad_OpenAngelBracket = 197,
    Keyboard_KeyCode_Keypad_CloseAngelBracket = 198,
    Keyboard_KeyCode_KeyPad_Ampersand = 199,
    Keyboard_KeyCode_Keypad_DoubleAmpersand = 200,
    Keyboard_KeyCode_Keypad_VerticalBar = 201,
    Keyboard_KeyCode_Keypad_DoubleVerticalBar = 202,
    Keyboard_KeyCode_Keypad_Colon = 203,
    Keyboard_KeyCode_Keypad_NumberSign = 204,
    Keyboard_KeyCode_Keypad_Space = 205,
    Keyboard_KeyCode_Keypad_AtSign = 206,
    Keyboard_KeyCode_Keypad_ExclamationMark = 207,
    Keyboard_KeyCode_Keypad_MemoryStore = 208,
    Keyboard_KeyCode_Keypad_MemoryRecall = 209,
    Keyboard_KeyCode_Keypad_MemoryClear = 210,
    Keyboard_KeyCode_Keypad_MemoryAdd = 211,
    Keyboard_KeyCode_Keypad_MemorySubtract = 212,
    Keyboard_KeyCode_Keypad_MemoryMultiply = 213,
    Keyboard_KeyCode_Keypad_MemoryDivide = 214,
    Keyboard_KeyCode_Keypad_PlusOrMinus = 215,
    Keyboard_KeyCode_Keypad_Clear = 216,
    Keyboard_KeyCode_Keypad_ClearEntry = 217,
    Keyboard_KeyCode_Keypad_Binary = 218,
    Keyboard_KeyCode_Keypad_Octal = 219,
    Keyboard_KeyCode_Keypad_Decimal = 220,
    Keyboard_KeyCode_Keypad_Hexadecimal = 221,
    Keyboard_KeyCode_LeftControl = 224,
    Keyboard_KeyCode_LeftShift = 225,
    Keyboard_KeyCode_LeftAlt = 226,
    Keyboard_KeyCode_LeftGUI = 227,
    Keyboard_KeyCode_RightControl = 228,
    Keyboard_KeyCode_RightShift = 229,
    Keyboard_KeyCode_RightAlt = 230,
    Keyboard_KeyCode_RightGUI = 231

} Keyboard_KeyCode_Typedef;



#endif