
void setup(){
  Serial.begin(57600);

  initIMU();
  initCard();
  
  delay(1000);
}
char oneLiner[500];
char multiLiner[1000];
int idx = 0;
int loopCount = 0;
void loop(){
  loopCount += 1;
  getIMUString(oneLiner);
  Serial.write(oneLiner);
  //cardLog();
  //multiLiner += oneLiner;
  if(loopCount >= 10)
  {
    Serial.write(multiLiner);
    //cardLog();
    
    multiLiner[0] = '\0';
    idx = 0;
  }
}

