#include "Wire.h"

void setup(){
  Serial.begin(57600);
  delay(1);
  Wire.begin();
  delay(1);

  initIMU();
  
  delay(1000);
}

void loop(){
  String oneLiner = "";
  getIMUString(&oneLiner);
  
  Serial.println(oneLiner);  
}

