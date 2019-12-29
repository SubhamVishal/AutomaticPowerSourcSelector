int state = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(12, INPUT);  
pinMode(13, INPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(12)== 0 && digitalRead(13)== 0)
{  
digitalWrite(9, HIGH);
digitalWrite(8, HIGH);

}
if(digitalRead(12)== 0 && digitalRead(13)== 1)
{  
digitalWrite(9, LOW);
digitalWrite(8, HIGH);

}
if(digitalRead(12) == 1 && digitalRead(13) == 0)
{state = 1;
 digitalWrite(9, HIGH);
digitalWrite(8, LOW);

}
if(digitalRead(12) == 1 && digitalRead(13) == 1)
{if(state == 1){digitalWrite(9, HIGH);
digitalWrite(8, LOW);
delay(6000);
 digitalWrite(9, LOW);
digitalWrite(8, HIGH);
state = 0;
}
else{
  digitalWrite(9, LOW);
digitalWrite(8, HIGH);
}
}
}


