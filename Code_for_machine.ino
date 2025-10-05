#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int trigPin = 13;
const int echoPin = 12;
const int ButtonPin = 2 ;
int noise = 8 ;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int distance;
long duration;
int Times = 0; 
int runTimes1 = 0 ;
int R = 0 ;
int Round = 0;
int pass = 0 ;
int fail = 0 ;
int mistake = 0 ;
int flag = 0 ;
int ROUND[] = {1,2,3,4,5,6,7} ;
int TIMES[] = {7,8,8,9,9,10,10} ;
int a = 0 ;
int Result = 0 ;
unsigned long previousMillis = 0; 
unsigned long interval = 9000UL;    
void(* resetFunc) (void) = 0 ;
int buttonState = 0 ;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT) ;
  pinMode(echoPin, INPUT) ;
  pinMode(ButtonPin, INPUT_PULLUP) ;
  lcd.init();
  lcd.backlight();
  Round = 1 ;
  a = 0 ;
  Times = 7 ;
  runTimes1 = 0 ;
  for(int i = 5 ; i > 0 ; i--)
  {
    lcd.setCursor(2,0) ;
    lcd.print(i) ;
    lcd.setCursor(2,1) ;
    lcd.print(i) ;
    delay(250) ;
    lcd.setCursor(6,0) ;
    lcd.print(i) ;
    lcd.setCursor(6,1) ;
    lcd.print(i) ;
    delay(250) ;
    lcd.setCursor(10,0) ;
    lcd.print(i) ;
    lcd.setCursor(10,1) ;
    lcd.print(i) ;
    delay(250) ;
    lcd.setCursor(14,0) ;
    lcd.print(i) ;
    lcd.setCursor(14,1) ;
    lcd.print(i) ;
    delay(250) ;
    lcd.clear() ;
    previousMillis = millis() ;
  }
}

void loop() {
  if(digitalRead(ButtonPin) == HIGH && R == 0)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW) ;
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    lcd.setCursor(0,0) ;
    lcd.print("Round:") ;
    lcd.setCursor(7, 0) ;
    lcd.print(Round) ;
    lcd.setCursor(9,0) ;
    lcd.print("Fail:") ;
    lcd.setCursor(15,0) ;
    lcd.print(fail) ;
    lcd.setCursor(0,1) ;
    lcd.print("Count:") ;
    lcd.setCursor(7, 1) ;
    if(millis() - previousMillis <= interval && runTimes1 < TIMES[a])
    {
      if(Round == ROUND[a] && distance <= 150 && flag == 1)
      {
        pass += 1 ;
        Result += 1 ;
        runTimes1 += 1 ;
        lcd.setCursor(7,1) ;
        lcd.print(pass) ;
        previousMillis = millis() ;
        delay(interval - (millis() - previousMillis)) ;
        tone(noise, 1000) ;
        delay(500) ;
        noTone(noise) ;
        previousMillis = millis() ;
        if(digitalRead(ButtonPin) == LOW)
        {
          resetFunc() ;
        }
        if((runTimes1 == TIMES[a] || pass == TIMES[a] ) && a < 6)
        {
          a += 1 ;
          pass = 0 ;
          Round += 1 ;
          runTimes1 = 0 ;
          interval -= 500UL ;

          lcd.setCursor(7,0) ;
          lcd.print(ROUND[a]) ;
          lcd.setCursor(7,1) ;
          lcd.clear() ;
          lcd.print(pass) ;
        }
        previousMillis = millis() ;
        flag = 0 ;
      }
      else
      {
        flag = 1 ;
      }
    }
    else
    {
      if(a == 6)
      {
        lcd.clear() ;
        lcd.setCursor(0,0) ;
        lcd.print("MISSION SUCCESS!") ;
        lcd.setCursor(0,1) ;
        lcd.print("Result = ") ;
        lcd.setCursor(9,1) ;
        lcd.print(Result) ;
        delay(3000) ;
        lcd.clear() ;
        lcd.setCursor(0,0) ;
        lcd.print("PRESS BUTTON") ;
        lcd.setCursor(0,1) ;
        lcd.print("RESTART") ;
        R = 1;
      }
      if(millis() - previousMillis > interval)
      {
        runTimes1 += 1 ;
        fail += 1 ;
        lcd.setCursor(15,0) ;
        lcd.print(fail) ;
        if(fail == 2)
        {
          lcd.clear() ;
          lcd.setCursor(0,0) ;
          lcd.print("MISSION FAIL") ;
          lcd.setCursor(0,1) ;
          lcd.print("Result = ") ;
          lcd.setCursor(9,1) ;
          lcd.print(Result) ;
          delay(3000) ;
          lcd.clear() ;
          lcd.setCursor(0,0) ;
          lcd.print("PRESS BUTTON") ;
          lcd.setCursor(0,1) ;
          lcd.print("RESTART") ;
          R = 1 ;
        }
        delay(100) ;
        previousMillis = millis() ;
      }
    }
  }
  else
  {
    if(digitalRead(ButtonPin) == HIGH && R == 1)
    {
      buttonState = digitalRead(ButtonPin) ;
    }
    if(buttonState == LOW)
    {
      lcd.clear() ;
      delay(1000) ;
      resetFunc() ;
    }
  }
}