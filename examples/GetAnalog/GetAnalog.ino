#include <Gamepad.h>
Gamepad gb;

#define ANA_Y A0
#define ANA_X A1
int lowestX = 0; int lowestY = 0;
int highestX = 0; int highestY = 0;

/**
 * Once this program is burnt to the arduino, open the serial monitor and move your joystick to the far edges in all direction
 * Easiest way is to do round the border, until the values that the terminal gives you are static.
 * You can then use them in the map function for the gameboy
 */

void setup() {
  Serial.begin(9600);
  pinMode(ANA_Y, INPUT_PULLUP);
  pinMode(ANA_X, INPUT_PULLUP);
  lowestX = analogRead(ANA_X);
  highestX = analogRead(ANA_X);

  lowestY = analogRead(ANA_Y);
  highestY = analogRead(ANA_Y);
}


void loop() {
  int currX = analogRead(ANA_X);
  int currY = analogRead(ANA_Y);

  if (currX < lowestX) {
    lowestX = currX;
  }

  if (currX > highestX) {
    highestX = currX;
  }

  if (currY < lowestY) {
    lowestY = currY;
  }

  if (currY > highestY) {
    highestY = currY;
  }

  Serial.print("Lowest X: ");
  Serial.print(lowestX);
  Serial.print(" Highest X: ");
  Serial.println(highestX);
  
  Serial.print("Lowest Y: ");
  Serial.print(lowestY);
  Serial.print(" Highest Y: ");
  Serial.println(highestY);
  Serial.println("");

  delay(500);
}
