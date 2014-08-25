#include "Seven_Seg_LED_Display.h"


LEDDisplay::LEDDisplay () {

  displaying = NOTHING;

  for (int outputPin = 2; outputPin <= 8; outputPin++)
    pinMode(outputPin, OUTPUT);

  // LED pin
  aPin = 2;
  bPin = 3;
  cPin = 4;
  dPin = 5;
  ePin = 6;
  fPin = 7;
  gPin = 8;
  dpPin = 13;

  for (int yPin = 9; yPin <= 13; yPin++)
    pinMode(yPin, OUTPUT);
  // control to display which digit
  y1Pin = 12;
  y2Pin = 11;
  y3Pin = 10;
  y4Pin = 9;

}

LEDDisplay::LEDDisplay(int a, int b, int c, int d, int e, int f, int g, int dp, int y1, int y2, int y3, int y4) {
  displaying = NOTHING;

  pinMode(aPin = a, OUTPUT);
  pinMode(bPin = b, OUTPUT);
  pinMode(cPin = c, OUTPUT);
  pinMode(dPin = d, OUTPUT);
  pinMode(ePin = e, OUTPUT);
  pinMode(fPin= f, OUTPUT);
  pinMode(gPin = g, OUTPUT);
  pinMode(dpPin = dp, OUTPUT);
  pinMode(y1Pin = y1, OUTPUT);
  pinMode(y2Pin = y2, OUTPUT);
  pinMode(y3Pin = y3, OUTPUT);
  pinMode(y4Pin = y4, OUTPUT);


}

void LEDDisplay::DisplayDigit (Num digit, bool dp){

  displaying = digit;

  switch (digit) {
    case ZERO:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, HIGH);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);
   
      break;
    case ONE:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);  
      break;
    case TWO:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, LOW);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);
      break;
    case THREE:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, LOW);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);
      break;
    case FOUR:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);
      break;
    case FIVE:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);
      break;
    case SIX:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);
      break;
    case SEVEN:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);
      break;
    case EIGHT:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);
      break;
    case NINE:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      if (dp)
      	digitalWrite(dpPin, HIGH);
      else
      	digitalWrite(dpPin, LOW);
      break;
    case DECIMAL_POINT:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      digitalWrite(dpPin, LOW);
      break;
    default:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      digitalWrite(dpPin, HIGH);
 
  }
}

void LEDDisplay::DisplayNumber (int number){
 
    int temp;
 
    // determine the digits of the number

    int thousand = number/1000;
        temp = number%1000;
    int hundred = temp/100;
        temp = temp%100;
    int ten = temp/10 ;
        temp = temp%10;
    int unit = temp;
 
    // determine what to display (note I cast int to Num)
 /*
    if (thousand == 11){
      if (hundred == 0){
        if (ten == 0){
          digitalWrite(y1Pin, LOW);
          digitalWrite(y2Pin, LOW);
          digitalWrite(y3Pin, LOW);
          digitalWrite(y4Pin, HIGH);
          DisplayDigit((Num)unit);
          //delay(5);
        }
        else {
          digitalWrite(y1Pin, LOW);
          digitalWrite(y2Pin, LOW);
          digitalWrite(y3Pin, HIGH);
          DisplayDigit((Num)ten);
          //delay(5);
          digitalWrite(y3Pin, LOW);
          digitalWrite(y4Pin, HIGH);
          DisplayDigit((Num)unit);
          //delay(5);
          digitalWrite(y4Pin, LOW);
        }
      }
      else{
        digitalWrite(y1Pin, LOW);
        digitalWrite(y2Pin, HIGH);
        DisplayDigit((Num)hundred);
        //delay(5);
        digitalWrite(y2Pin, LOW);
        digitalWrite(y3Pin, HIGH);
        DisplayDigit((Num)ten);
        //delay(5);
        digitalWrite(y3Pin, LOW);
        digitalWrite(y4Pin, HIGH);
        DisplayDigit((Num)unit);
        //delay(5);
        digitalWrite(y4Pin, LOW);
      }
    }
    else{
    */
      digitalWrite(y1Pin, HIGH);
      DisplayDigit((Num)thousand, true);
      delay(5);
      digitalWrite(y1Pin, LOW);
      digitalWrite(y2Pin, HIGH);
      DisplayDigit((Num)hundred, true);
      delay(5);
      digitalWrite(y2Pin, LOW);
      digitalWrite(y3Pin, HIGH);
      DisplayDigit((Num)ten, false);
      delay(5);
      digitalWrite(y3Pin, LOW);
      digitalWrite(y4Pin, HIGH);
      DisplayDigit((Num)unit, true);
      delay(5);
      digitalWrite(y4Pin, LOW);
//    }

}