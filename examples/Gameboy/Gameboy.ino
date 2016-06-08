#include <Gamepad.h>
Gamepad gb;

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
#define BTN_SELECT 13

void setup() {
  for (int x = 0; x<13; x++){
      pinMode(x, INPUT_PULLUP);
  }
}

void loop() {

  bool downSet  = digitalRead(BTN_DOWN);
  bool upSet    = digitalRead(BTN_UP); // No pun intended
  bool leftSet  = digitalRead(BTN_LEFT);
  bool rightSet = digitalRead(BTN_RIGHT);
 
  gb.setLeftXaxis(!leftSet ? -127 : !rightSet ? 127 : 0);
  gb.setLeftYaxis(!downSet ? 127 : !upSet ? -127 : 0);

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

  gb.sendUpdate();
}
