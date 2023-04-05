int sens;
int ledPin = 6;
int sensorPin = A0;

int ReadSens_and_Condition(){
  int i;
  int sval = 0;

  for (i = 0; i < 5; i++){
    sval = sval + analogRead(0);    // sensor on analog pin 0
  }

  sval = sval / 5;    // average
  sval = sval / 4;    // scale to 8 bits (0 - 255)
  sval = 255 - sval;  // invert output
  return sval;
}

void blink()
{
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}

void setup(){
  Serial.begin(9600);
}

void loop(){
  sens = ReadSens_and_Condition();
  Serial.println(sens);
  analogWrite(ledPin, sens); //아날로그 값으로 밝기 변화
  
}


