#include <Gamepad.h>
Gamepad gb;

#define USE_JOYSTICK false

// HELDER BOARD CONFIG
/*
#define BTN_DOWN 0
#define BTN_UP 1
#define BTN_LEFT 2
#define BTN_RIGHT 3
#define BTN_A 4
#define BTN_START 5
#define BTN_Y 6
#define BTN_L1 7
#define BTN_X 8
#define BTN_R1 9
#define BTN_R2 10
#define BTN_L2 11
#define BTN_B 12
#define BTN_SELECT 13*/
// If you are using the Analog Joystick from the PSP 2000, check theses too
#define ANA_Y A0
#define ANA_X A1

// STANDALONE ARDUINO PRO MINI CONFIG
/*
#define BTN_DOWN 4
#define BTN_UP 2
#define BTN_LEFT 3
#define BTN_RIGHT 5
#define BTN_A 6
#define BTN_START 8
#define BTN_Y 0
#define BTN_L1 0
#define BTN_X 0
#define BTN_R1 0
#define BTN_R2 0
#define BTN_L2 0
#define BTN_B 7
#define BTN_SELECT 9*/


void setup() {
  Serial.begin(9600);
  for (int x = 0; x < 13; x++) {
    pinMode(x, INPUT_PULLUP);
  }
  #if USE_JOYSTICK
  pinMode(ANA_Y, INPUT_PULLUP);
  pinMode(ANA_X, INPUT_PULLUP);
  #endif
}


void loop() {
  
    bool downSet  = digitalRead(BTN_DOWN);
    bool upSet    = digitalRead(BTN_UP); // No pun intended
    bool leftSet  = digitalRead(BTN_LEFT);
    bool rightSet = digitalRead(BTN_RIGHT);

    #if USE_JOYSTICK
      /** REPLACE VALUE WITH THE ONES FOR YOUR ANALOG STICK ! **/
      int x = map(analogRead(ANA_X), 263, 919, -127, 127);
      int y = map(analogRead(ANA_Y), 230, 891, -127, 127);
      gb.setLeftXaxis(x);
      gb.setLeftYaxis(y);
    #else
      gb.setLeftYaxis(!/*Don't be*/ upSet ? -127 : !downSet ? 127 : 0); //hahaha chill
      gb.setLeftXaxis(!leftSet ? -127 : !rightSet ? 127 : 0);
    #endif
    gb.setButtonState(1, !digitalRead(BTN_A));
    gb.setButtonState(2, !digitalRead(BTN_B));
    gb.setButtonState(3, !digitalRead(BTN_X));
    gb.setButtonState(4, !digitalRead(BTN_Y));
    gb.setButtonState(5, !digitalRead(BTN_SELECT));
    gb.setButtonState(6, !digitalRead(BTN_START));
    gb.setButtonState(7, !digitalRead(BTN_L1));
    gb.setButtonState(8, !digitalRead(BTN_R1));
    gb.setButtonState(9, !digitalRead(BTN_L2));
    gb.setButtonState(10, !digitalRead(BTN_R2));
    #if USE_JOYSTICK
      gb.setButtonState(11, !digitalRead(BTN_DOWN));
      gb.setButtonState(12, !digitalRead(BTN_UP));
      gb.setButtonState(13, !digitalRead(BTN_LEFT));
      gb.setButtonState(14, !digitalRead(BTN_RIGHT));
    #endif

    gb.sendUpdate();
}
