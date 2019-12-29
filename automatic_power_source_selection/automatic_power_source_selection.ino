float GridInput = 0.0;
float SolarInput = 0.0;
void setup() {
  // put your setup code here, to run once:

pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
Serial.begin(9600);
}

void loop() {
 int GridVoltage = analogRead(A0);
 int SolarVoltage = analogRead(A1);
 GridInput = (GridVoltage * 5.0) / 1024.0;
 SolarInput = (SolarVoltage * 5.0) / 1024.0;
 
if(GridInput <= 4.5 && SolarInput <= 1.5)
{  
digitalWrite(9, LOW);

digitalWrite(8, LOW);
}
else{
  if(GridInput >=4.5 && SolarInput >= 1.5){
digitalWrite(9, HIGH);

digitalWrite(8, LOW);
}
if(GridInput >=4.5 && SolarInput <= 1.5){
digitalWrite(9, HIGH);

digitalWrite(8, HIGH);

}
if(GridInput <=4.5 && SolarInput >= 1.5){
digitalWrite(9, LOW);

digitalWrite(8, HIGH);

}

if(SolarInput >= 1.5){
if(GridInput >= 4.5)
{  
delay(600000);
digitalWrite(9, HIGH);

digitalWrite(8, LOW);
}
}
if(GridInput <= 4.5){
  if(SolarInput >= 1.5){
    
    digitalWrite(8, HIGH);
    
  }
}
}


delay(1000);
}


