
void setup(){
  Serial.begin(57600);
  Serial.println("hello?");
  delay(1000);
  initIMU();
  initCard();
  
  delay(1000);
}
//char oneLiner[10];
char multiLiner[500];
int idx = 0;
int loopCount = 0;

void loop(){
  loopCount += 1;
  getIMUString(multiLiner,idx);
  //Serial.write(multiLiner);
  //cardLog();
  //multiLiner += oneLiner;
  if(loopCount >= 5)
  {
    Serial.print(">");
    Serial.write(multiLiner);
    cardLog(multiLiner);
    
    multiLiner[0] = '\0';
    idx = 0;
    loopCount = 0;
  }
}

