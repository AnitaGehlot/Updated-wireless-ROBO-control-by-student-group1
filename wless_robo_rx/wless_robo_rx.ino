#include <LiquidCrystal.h>

LiquidCrystal lcd(13,11,5,4,3,2);
int R2=10,R1=9,L2=8,L1=7;

void setup()
{ 
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
}

void loop()
{
  
  Serial.print("work log : ");
  int action=Serial.read();
  
  if(action==20){
    Serial.println("moving forward");
    digitalWrite(R1,0);
    digitalWrite(R2,1);
    digitalWrite(L1,0);
    digitalWrite(L2,1);
    lcd.clear();
    lcd.print("MOVE-FORWARD");
  }
  else if(action==30){
    Serial.println("moving right");
    digitalWrite(R1,1);
    digitalWrite(R2,0);
    digitalWrite(L1,0);
    digitalWrite(L2,1);
    lcd.clear();
    lcd.print("TURN-RIGHT"); 
  }
  else if(action==40)
  {
    Serial.println("moving reverse");
    digitalWrite(R1,1);
    digitalWrite(R2,0);
    digitalWrite(L1,1);
    digitalWrite(L2,0);
    lcd.clear();
    lcd.print("REVERSE");
  }
  else if(action==50){
    Serial.println("moving left");
    digitalWrite(R1,0);
    digitalWrite(R2,1);
    digitalWrite(L1,1);
    digitalWrite(L2,0);
    lcd.clear();
    lcd.print("TURN-LEFT");
  }
  else// if(action==-1)
  {
    Serial.println("no command : no movement");
    digitalWrite(R1,0);
    digitalWrite(R2,0);
    digitalWrite(L1,0);
    digitalWrite(L2,0);
    lcd.clear();
    lcd.print("HALTED");
  }
  Serial.println();
  delay(250);  
}
