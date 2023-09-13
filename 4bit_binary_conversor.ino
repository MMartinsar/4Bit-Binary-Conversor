int miNum = 0;
int value = 0;
int pindex = 10;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()>0){
    miNum = Serial.parseInt();
  	Serial.println(miNum);
    
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    while(miNum > 0){
      value = miNum % 2;
      miNum = miNum / 2;
      if (value == 1){
      	digitalWrite(pindex, HIGH);
        pindex++;
      }else{
        digitalWrite(pindex, LOW);
        pindex++;
      }
      Serial.println(value);
    }
  }
  pindex = 10;
}