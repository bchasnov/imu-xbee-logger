
void setup(){
  Serial.begin(57600);

  initIMU();
  initCard();
  
  delay(1000);
}
String oneLiner = "";
String multiLiner = "";
int loopCount = 0;
void loop(){
  loopCount += 1;
  oneLiner = "";
  getIMUString(&oneLiner);
  cardLog();
  //multiLiner += oneLiner;
  if(loopCount >= 10)
  {
    //Serial.print(multiLiner);
    //cardLog();
    loopCount = 0;
  }
}

