#define CHANNEL_A_PIN 0

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int value=analogRead(CHANNEL_A_PIN);
value = (value >> 2) & 0xFF;
Serial.print(value);
delayMicroseconds(100);
}
