
void setup(){
  Serial.begin(57600);
  Serial.println("hello?");
  delay(1000);
  initIMU();
  initCard();
  
  delay(1000);
}
//char oneLiner[10];
char multiLiner[300];
int idx = 0;
int loopCount = 0;

unsigned long one = 0;
unsigned long two = 0;

void loop(){
  loopCount += 1;
  getIMUString(multiLiner,idx);
  Serial.write(multiLiner);
  idx = 0;
  //cardLog();
  //multiLiner += oneLiner;
  /*if(loopCount >= 3)
  {
    //Serial.print(">");
    //Serial.write(multiLiner);
    one = millis();
    cardLog(multiLiner);
    Serial.println(millis()-one);
    multiLiner[0] = '\0';
    idx = 0;
    loopCount = 0;
  }*/
}

