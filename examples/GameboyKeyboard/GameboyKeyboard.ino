#include "Keyboard.h"

// HELDER BOARD CONFIG
/*#define BTN_DOWN 0
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

// STANDALONE ARDUINO PRO MINI CONFIG
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
#define BTN_SELECT 9

void setup() {
  for (int x = 0; x < 13; x++) {
    pinMode(x, INPUT_PULLUP);
  }
  Keyboard.begin();
}

void loop() {
  checkInput(BTN_DOWN, KEY_DOWN_ARROW);
  checkInput(BTN_UP, KEY_UP_ARROW);
  checkInput(BTN_LEFT, KEY_LEFT_ARROW);
  checkInput(BTN_RIGHT, KEY_RIGHT_ARROW);
  
  checkInput(BTN_A, 'a');
  checkInput(BTN_B, 'b');
  checkInput(BTN_X, 'x');
  checkInput(BTN_Y, 'y');
  checkInput(BTN_START, KEY_RETURN);
  checkInput(BTN_SELECT, KEY_BACKSPACE);
  checkInput(BTN_L1, 'l');
  checkInput(BTN_L2, 'm');
  checkInput(BTN_R1, 'r');
  checkInput(BTN_R2, 's');
}

void checkInput(int pin, char key){
    if (digitalRead(pin) == LOW){
        Keyboard.press(key);
    } else {
      Keyboard.release(key);
    }
}

