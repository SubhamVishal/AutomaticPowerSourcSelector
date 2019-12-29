#define RELAY1 9
#define RELAY2 8
int analogPin1 = A0;
int analogPin2 = A1;

void setup() {
  // put your setup code here, to run once:
pinMode(RELAY1, OUTPUT);
pinMode(RELAY2, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (analogRead(analogPin1)){
  digitalWrite(RELAY1, HIGH);
  
  digitalWrite(RELAY2, LOW);
}
if(analogRead(analogPin2)){
digitalWrite(RELAY1,LOW);
delay(2000);
digitalWrite(RELAY2, HIGH);


}
delay(1000);
}
