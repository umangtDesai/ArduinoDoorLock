#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

const String password = "rgbb";
String userPassword = "";

const int redButtonPin = 3;
const int blueButtonPin = 9;
const int greenButtonPin = 6;
const int yellowButtonPin = 7;

const int ledPin = 12;

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(4, 1);
  lcd.setRGB(colorR, colorG, colorB);
    
  pinMode(redButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  pinMode(blueButtonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  attachInterrupt(digitalPinToInterrupt(redButtonPin), redPin_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(greenButtonPin), greenPin_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(blueButtonPin), bluePin_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(yellowButtonPin), yellowPin_ISR, CHANGE);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("UPASS = ");
  //Serial.print(userPassword);
  if(counter == 4 && userPassword != password) {
    // Someone tried to enter your room
    Serial.println("breakin");
  }
  if(userPassword == password) {
    for(int i = 0; i < 5; i++) {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
    }
  }
  // at this point, paswords wont match
  if(counter >= 4){
    userPassword = "";
    counter =0;
   }
}

void redPin_ISR() {
    userPassword = userPassword + "r";
    counter++;
     lcd.print(userPassword);
     lcd.print(" ");
     lcd.clear();
}
void greenPin_ISR() {
    userPassword = userPassword + "g";
    counter++;
    lcd.print(userPassword);
    lcd.print(" ");
    lcd.clear();
}

void bluePin_ISR() {
    userPassword = userPassword + "b";
    counter++;
    lcd.print(userPassword);
    lcd.print(" ");
    lcd.clear();
}

void yellowPin_ISR() {
    userPassword = userPassword + "y";
    counter++;
    lcd.print(userPassword);
    lcd.print(" ");
    lcd.clear();
}

