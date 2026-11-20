#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;
volatile bool run = false;
const int buttonPin = 0;
const int ledPin = 15;
int buttonState = 1;

//CONFIG
const int regWait = 250;
//END CONFIG

void setup(){
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeState, FALLING);

  Keyboard.begin();

  USB.begin();
}

void loop(){
    //buttonState = digitalRead(buttonPin);

    if(run){
      keyPressNWait(KEY_MENU); //popup
      
      keyPressNWait(KEY_RETURN,5000); //enter code 353 (KEY_SELECT)

      keyPressNWait(KEY_DOWN_ARROW); //code 108 (KEY_DOWN)
      keyPressNWait(KEY_DOWN_ARROW);
      keyPressNWait(KEY_DOWN_ARROW);
      keyPressNWait(KEY_F10,9000); //B
      
      /*popup enter wait 3s down x3 B/f10 wait 7s */
    }
  }
void keyPressNWait(uint8_t k){
  Keyboard.write(k);
  delay(regWait);
}

 void keyPressNWait(uint8_t k, uint32_t wait){
    Keyboard.write(k);
    delay(wait);
 } 



void changeState(){
    delay(1000);
    run = !run;
}
