// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "sylvain"
#endif


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for storing the keymap in EEPROM
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"

// Support for communicating with the host via a simple Serial protocol
#include "Kaleidoscope-FocusSerial.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
#include "Kaleidoscope-NumPad.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"

// Support for an LED mode that prints the keys you press in letters 4px high
#include "Kaleidoscope-LED-AlphaSquare.h"

// Support for shared palettes for other plugins, like Colormap below
#include "Kaleidoscope-LED-Palette-Theme.h"

// Support for an LED mode that lets one configure per-layer color maps
#include "Kaleidoscope-Colormap.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-HardwareTestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"

// add qukeys plugin
#include "Kaleidoscope-Qukeys.h"

// define list of macros
enum { MACRO_VERSION_INFO,
       MACRO_ANY,
       MACRO_TOGGLE_QUKEYS
     };


// layers

enum { PRIMARY, NUMPAD, FUNCTION };

// *INDENT-OFF*

KEYMAPS(

// primary layer

  [PRIMARY] = KEYMAP_STACKED(
    ___,           Key_1,  Key_2,  Key_3,  Key_4,  Key_5,  Key_LEDEffectNext,
    Key_Backtick,  Key_Q,  Key_W,  Key_E,  Key_R,  Key_T,  Key_Tab,
    Key_PageUp,    Key_A,  Key_S,  Key_D,  Key_F,  Key_G,  /*---*/
    Key_PageDown,  Key_Z,  Key_X,  Key_C,  Key_V,  Key_B,  Key_Escape,
    //
    Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
    //
    ShiftToLayer(FUNCTION),
    //============================================================================================
    M(MACRO_TOGGLE_QUKEYS),  Key_6,  Key_7,  Key_8,      Key_9,       Key_0,          LockLayer(NUMPAD),
    Key_Enter,               Key_Y,  Key_U,  Key_I,      Key_O,       Key_P,          Key_Equals,
    /*---*/                  Key_H,  Key_J,  Key_K,      Key_L,       Key_Semicolon,  Key_Quote,
    Key_RightAlt,            Key_N,  Key_M,  Key_Comma,  Key_Period,  Key_Slash,      Key_Minus,
    //
    Key_RightShift,  Key_LeftAlt,  Key_Spacebar,  Key_RightControl,
    //
    ShiftToLayer(FUNCTION)),

// numpad

  [NUMPAD] =  KEYMAP_STACKED(
    ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,  ___,  ___,  ___,  ___,  ___,  /*---*/
    ___,  ___,  ___,  ___,  ___,  ___,  ___,
    //
    ___, ___, ___, ___,
    //
    ___,
    //============================================================================================
    M(MACRO_VERSION_INFO),  ___,  Key_7,  Key_8,       Key_9,               Key_KeypadSubtract,  ___,
    ___,                    ___,  Key_4,  Key_5,       Key_6,               Key_KeypadAdd,       ___,
    /*---*/                 ___,  Key_1,  Key_2,       Key_3,               Key_Equals,          ___,
    ___,                    ___,  Key_0,  Key_Period,  Key_KeypadMultiply,  Key_KeypadDivide,    Key_Enter,
    //
    ___, ___, ___, ___,
    //
    ___),

// fn layer

  [FUNCTION] =  KEYMAP_STACKED(
    ___,       Key_F1,           Key_F2,       Key_F3,      Key_F4,         Key_F5,            Key_CapsLock,
    Key_Tab,   ___,              Key_mouseUp,  ___,         Key_mouseBtnR,  Key_mouseWarpEnd,  Key_mouseWarpNE,
    Key_Home,  Key_mouseL,       Key_mouseDn,  Key_mouseR,  Key_mouseBtnL,  Key_mouseWarpNW,   /*---*/
    Key_End,   Key_PrintScreen,  Key_Insert,   ___,         Key_mouseBtnM,  Key_mouseWarpSW,   Key_mouseWarpSE,
    //
    ___,  Key_Delete,  ___,  ___,
    //
   ___,
    //============================================================================================
    Consumer_ScanPreviousTrack,  Key_F6,                  Key_F7,                    Key_F8,                    Key_F9,           Key_F10,           Key_F11,
    Consumer_PlaySlashPause,     Consumer_ScanNextTrack,  Key_LeftCurlyBracket,      Key_RightCurlyBracket,     Key_LeftBracket,  Key_RightBracket,  Key_F12,
    /*---*/                      Key_LeftArrow,           Key_DownArrow,             Key_UpArrow,               Key_RightArrow,   ___,               ___,
    Key_PcApplication,           Consumer_Mute,           Consumer_VolumeDecrement,  Consumer_VolumeIncrement,  ___,              Key_Backslash,     Key_Pipe,
    //
    ___,  ___,  Key_Enter,  ___,
    //
    ___)
) // KEYMAPS

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  bool toggledOn = false;
  if (keyToggledOn(keyState)) {
    lastKey.setKeyCode(Key_A.getKeyCode() + (uint8_t)(millis() % 36));
    toggledOn = true;
  }

  if (keyIsPressed(keyState))
    Kaleidoscope.hid().keyboard().pressKey(lastKey, toggledOn);
}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;

  case MACRO_TOGGLE_QUKEYS:
    if (keyToggledOn(keyState))
      Qukeys.toggle();
    break;
  }
  return MACRO_NONE;
}



// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.enable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE,
  // Enter test mode
  COMBO_ENTER_TEST_MODE
};

/** Wrappers, to be used by MagicCombo. **/

/**
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/**
 *  This enters the hardware test mode
 */
static void enterHardwareTestMode(uint8_t combo_index) {
  HardwareTestMode.runTests();
}


/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
}, {
  .action = enterHardwareTestMode,
  // Left Fn + Prog + LED
  .keys = { R3C6, R0C0, R0C6 }
});

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(

  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusSettingsCommand,
  FocusEEPROMCommand,
  BootGreetingEffect,
  HardwareTestMode,

  // led effects
  LEDControl,
  LEDOff,
  LEDRainbowEffect,
  LEDRainbowWaveEffect,
  LEDChaseEffect,
  LEDBreatheEffect,
  StalkerEffect,
  LEDPaletteTheme,
  ColormapEffect,
  NumPad, // TODO : remove

  // The macros plugin adds support for macros
  Macros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,

  HostPowerManagement,
  MagicCombo,
  USBQuirks
);

void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

// TODO remove
  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  // Set the action key the test mode should listen for to Left Fn
  HardwareTestMode.setActionKey(R3C6);

  StalkerEffect.variant = STALKER(BlazingTrail);

  // start with LEDs off
  LEDOff.activate();

  EEPROMKeymap.setup(5);

  ColormapEffect.max_layers(5);
}

void loop() {
  Kaleidoscope.loop();
}
