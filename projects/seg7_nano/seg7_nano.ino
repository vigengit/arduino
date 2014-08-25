/*
  Oscar's project

  how to use 7-seg LED display

*/

#include "Seven_Seg_LED_Display.h"
#include <EEPROM.h>

const int buttonPin = 1;    // the number of the pushbutton pin
// Variables will change:
const int buttonPin_rst = 0;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
LEDDisplay disp;             // I made a mistake declaring this inside 'loop', but in which case, it can't remember what it displayed previously
//float meter = 0;
unsigned long meter = 0;
unsigned long num = 0;
int rst = 1;
int rst_count = 0;


void write_eeprom(unsigned long number)
{
 unsigned long temp;
    // determine the digits of the number
   unsigned long tenthousand = number/10000;
        temp = number%10000;
   unsigned long thousand = temp/1000;
        temp = temp%1000;
   unsigned long hundred = temp/100;
        temp = temp%100;
   unsigned long ten = temp/10 ;
        temp = temp%10;
   unsigned long unit = temp;
    EEPROM.write(0, unit);
    EEPROM.write(1, ten);
    EEPROM.write(2, hundred);
    EEPROM.write(3, thousand);
    EEPROM.write(4, tenthousand);
}
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin_rst, INPUT_PULLUP);
  int unit = EEPROM.read(0);
  int ten = EEPROM.read(1);
  int hundred = EEPROM.read(2);
  int thousend = EEPROM.read(3);
  int tenthousand = EEPROM.read(4);
  meter = unit + 10*ten + 100*hundred + 1000*thousend + 10000*tenthousand;
  num = (unsigned long)meter/10;
}

void loop() {

buttonState = digitalRead(buttonPin);
rst = digitalRead(buttonPin_rst);
if (rst == 0) {
  ++rst_count;
} else {
  rst_count = 0;
} 

disp.DisplayNumber(num);
//delay(1);

  // compare the buttonState to its previous state
  if (rst_count > 15+
  01
  ]
  ) {
      meter = 0; 
      num = 0;
      write_eeprom(0);
  }
  else if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW && lastButtonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
       if (num == 9999){
          meter = 0;
          num = 0;
       }
       else {
         meter = meter + 55;
         num = (unsigned long)meter/10;
       }
       write_eeprom((unsigned long)(meter));
    }
    else {
 
    }
  }
  lastButtonState = buttonState;

}
