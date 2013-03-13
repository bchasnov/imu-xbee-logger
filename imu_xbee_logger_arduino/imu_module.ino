#include "ADXL345.h"
#include <HMC5883L.h>

ADXL345 Accel;
HMC5883L compass;

int error = 0;

void initIMU()
{
  Accel.set_bw(ADXL345_BW_100);
  Serial.print("BW_OK? ");
  Serial.println(Accel.status, DEC);

  compass = HMC5883L(); // Construct a new HMC5883 compass.
  error = compass.SetMeasurementMode(Measurement_Continuous);
  
  if(error != 0){ // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
  }

}

void getIMUString(String* oneLiner)
{
  *oneLiner = "";

  //Read Accelerometer
  int acc_data[3];
  
  int startMillis = millis();
  Accel.readAccel(acc_data);
  MagnetometerRaw raw = compass.ReadRawAxis();  
  int endMillis = millis();
  
  if(!Accel.status){
    acc_data[0] = 0;
    acc_data[1] = 0;
    acc_data[2] = 0;
    //Error!
  }
  
  *oneLiner += startMillis;
  *oneLiner += ",";
  *oneLiner += endMillis;
  *oneLiner += ";";
  *oneLiner += acc_data[0];
  *oneLiner += ",";
  *oneLiner += acc_data[1];
  *oneLiner += ",";
  *oneLiner += acc_data[2];  
  *oneLiner += ";";
  *oneLiner += raw.XAxis;
  *oneLiner += ",";
  *oneLiner += raw.YAxis;
  *oneLiner += ",";
  *oneLiner += raw.ZAxis;
  *oneLiner += ";";
 
 
  
}


