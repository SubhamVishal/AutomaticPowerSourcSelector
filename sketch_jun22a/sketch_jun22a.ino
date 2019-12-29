#include <LiquidCrystal.h>
#define beta 4090
#define resistance 33

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int ledPin = 15;
int relayPin=16;
int aPin = 8;
int bPin = 7;
int buttonPin = 6;
int analogPin = 0;

float setTemp = 20.0;
float measuredTemp;
char  mode = 'c';
boolean override = false;
float hysteresis = 0.25;


void setup() {
  // put your setup code here, to run once:
lcd.begin(2, 20);
pinMode(ledPin, OUTPUT);
pinMode(relayPin, OUTPUT);
pinMode(aPin, INPUT);
pinMode(bPin, INPUT);
pinMode(buttonPin, INPUT);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

}

int getEncoderTurn()
{
  static int oldA = LOW;
  static int oldB = LOW;
  int result = 0;
  int newA = digitalRead(aPin);
  int newB = digitalRead(bPin);
  if (newA != oldA || newB != oldB)
  {
    if (oldA == LOW && newA == HIGH)
    {
      result = -(oldB * 2 - 1);
    }
  }
   oldA = newA;
   oldB = newB;
   return result;
  }

   float readTemp()
   {
    long a = analogRead(analogPin);
    float temp = beta / (log(((1025.0 * resistance / a) - 33.0) / 33.0) +
    (beta / 298.0)) - 273.0;
    return temp;
   }
   void updateOutputs()
   { if (override || measuredTemp < setTemp - hysteresis)
   {
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayPin, LOW);
   }
   }
   void updateDisplay()
   {
    lcd.setCursor(0, 0);
    lcd.print("Actual: ");
    lcd.print(adjustUnits(measuredTemp));
    lcd.print(" o");
    lcd.print(mode);
    lcd.print(" ");

    lcd.setCursor(0,1);
    if (override)
    {
      lcd.print(" OVERRIDE ON ");
    }
    else
    {
      lcd.print("Set:  ");
      lcd.print(adjustUnits(setTemp));
      lcd.print(" o");
      lcd.print(mode);
      lcd.print(" ");
    }
   }
   float adjustUnits(float temp)
   {
    if (mode == 'c')
    {
      return temp;
    }
    else
    {
      return (temp * 9) / 5 + 32;
    }
   }
    
  
