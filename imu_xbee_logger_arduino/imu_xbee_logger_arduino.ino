
void setup(){
  Serial.begin(57600);

  initIMU();
  
  delay(1000);
}
int loopCount = 0;
void loop(){
  loopCount += 1;
  String oneLiner = "";
  getIMUString(&oneLiner);
  
  if (loopCount % 100)
  {
    Serial.println(oneLiner);  
    loopCount = 0;
  }
}

