//Prateek
//www.prateek.in

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
#include <LiquidCrystal.h>
int level1 = A5;
int level2 = A4;
int level3 = A3;
int level4 = A2;
int level5 = A1;
int motor = 6;
int a;
int b;
int c;
int d;
int e;
int r; //Water Pump status flag
int m = 0; //water Pump flag
int z = 50; 


LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(level1, INPUT);
  pinMode(level2, INPUT);
  pinMode(level3, INPUT);
  pinMode(level4, INPUT);
  pinMode(level5, INPUT);
  pinMode(motor, OUTPUT);
  lcd.begin(16, 2); 
}

void loop()
{

  r = digitalRead(motor);
  a = analogRead(level1);
  b = analogRead(level2);
  c = analogRead(level3);
  d = analogRead(level4);
  e = analogRead(level5);
  



  if (e > z && d > z && c > z && b > z && a > z )
  {
    {
      digitalWrite(motor, LOW);
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tank 100% FULL");
    SendMessage();
    mySerial.println("ATD8830584864;"); //replace x by your number
    delay(100);
    mySerial.println("ATH");
  }
  else
  {
    if (e < z && d > z && c > z && b > z && a > z )
    {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tank is 80% FULL");
      SendMessage1();
    }
    else
    {
      if (e < z && d < z && c > z && b > z && a > z )
      {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Tank is 60% FULL");
        SendMessage2();
      }
      else
      {
        if (e < z && d < z && c < z && b > z && a > z )
        {


          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Tank is 40% FULL");
          SendMessage3();
        }
        else if (e < z && d < z && c < z && b < z && a > z )
        {

          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Tank is 20% FULL");
          SendMessage4();
        }
        else
        { if (e < z && d < z && c < z && b < z && a < z )
          {
            {
              digitalWrite(motor, HIGH);
            }
          }
        }
      }
    }
  }
  if (r == LOW)
  {
    //lcd.setCursor(0, 0);
    //lcd.print("Water Pump (OFF)");
  }
  else
  {
    //lcd.setCursor(0, 0);
    //lcd.print("Water Pump (ON)");
  }
  {
    delay(100);

  }
}
void SendMessage()
{
  Serial.println("Tank 100% FULL");
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"+918830584864\"\r");
  delay(1000);
  mySerial.println("Tank 100% FULL");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
void SendMessage1()
{
  Serial.println("Tank is 80% FULLt");
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"+918830584864\"\r");
  delay(1000);
  mySerial.println("Tank is 80% FULL ");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
void SendMessage2()
{
  Serial.println("Tank is 60% FULL");
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"+918830584864\"\r");
  delay(1000);
  mySerial.println("Tank is 60% FULL");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
void SendMessage3()
{
  Serial.println("Tank is 40% FULL");
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"+918830584864\"\r");
  delay(1000);
  mySerial.println("Tank is 40% FULL");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
void SendMessage4()
{
  Serial.println("Tank is 20% FULL");
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"+918830584864\"\r");
  delay(1000);
  mySerial.println("Tank is 20% FULL");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
