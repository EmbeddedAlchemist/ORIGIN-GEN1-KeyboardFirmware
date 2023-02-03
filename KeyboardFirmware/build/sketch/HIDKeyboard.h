#line 1 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\HIDKeyboard.h"
#pragma once

#include "KeyboardKeyCode.h"

#define HIDKeyboard_ReportID 0x07
extern const char HIDKeyboard_ReportDescriptor_ConflictFree[45];

class Keyboard {
  private:
  public:
    Keyboard();
    void scan();
    void method();
};

class HIDKeyboard {
  public:
    // virtual void begin();
    // virtual void end();
    // virtual void press(Keyboard_KeyCode_Typedef key);
    // virtual void release(Keyboard_KeyCode_Typedef key);
    // virtual void report();
};
