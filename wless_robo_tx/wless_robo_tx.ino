#include <LiquidCrystal.h>

LiquidCrystal lcd(13,11,9,8,7,6);

int FORWARD = 2;
int RIGHT = 3;
int REVERSE = 4;
int LEFT = 5;

void setup()
{
  lcd.begin(20,4);
  Serial.begin(9600);
  pinMode(FORWARD,INPUT_PULLUP);
  pinMode(RIGHT,INPUT_PULLUP);
  pinMode(REVERSE,INPUT_PULLUP);
  pinMode(LEFT,INPUT_PULLUP);
  lcd.setCursor(2,0);
  lcd.print("FORWARD ^");
  lcd.setCursor(4,1);
  lcd.print("LEFT <");
  lcd.setCursor(11,1);
  lcd.print("> RIGHT");
  lcd.setCursor(2,2);
  lcd.print("REVERSE v");
}

void loop()
{
  int val;
  if(digitalRead(FORWARD)==LOW)
  {
    val=20;
    Serial.write(val);
  }
  else if(digitalRead(RIGHT)==LOW)
  {
    val=30;
    Serial.write(val);
  }
  else if(digitalRead(REVERSE)==LOW)
  {
    val=40;
    Serial.write(val);
  }
  else if(digitalRead(LEFT)==LOW)
  {
    val=50;
    Serial.write(val);
  }
    //  Serial.write(val);
  delay(250);
}
