#include "Wire.h"

#include "ADXL345.h"
#include <HMC5883L.h>
#include <ITG3200.h>

ADXL345 Accel;
HMC5883L compass;
ITG3200 gyro = ITG3200();

int error = 0;

void initIMU()
{
  Wire.begin();
  //////accel
  Accel.set_bw(ADXL345_BW_100);
  Serial.print("BW_OK? ");
  Serial.println(Accel.status, DEC);
  Accel.powerOn();
  //////end accel/////////////////////
  
  //////////compass
  compass = HMC5883L(); // Construct a new HMC5883 compass.
  error = compass.SetMeasurementMode(Measurement_Continuous);
  
  if(error != 0){ // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
  }
  
  ///////end compass//////////////////////
  
  ////////gyro
  gyro.init(ITG3200_ADDR_AD0_LOW); 
  
  //Serial.print("zeroCalibrating...");
  //gyro.zeroCalibrate(2500, 2);
  Serial.println("done.");
  
  /////end gyro/////////////////////////


}
unsigned long prevMillis = 0;
void getIMUString(char* liner, int& index)
{
  //Read Accelerometer
  int acc_data[3];
  int gx, gy, gz;
  
  unsigned long startMillis = millis();
  Accel.readAccel(acc_data);
  MagnetometerRaw raw = compass.ReadRawAxis(); 
  gyro.readGyroRaw(&gx, &gy, &gz);
  unsigned long endMillis = millis();
  
  if(!Accel.status){
    acc_data[0] = 0;
    acc_data[1] = 0;
    acc_data[2] = 0;
    //Error!
  }

  sprintf(liner + index, ">%lu %lu %i %i %i %i %i %i %i %i %i\n", startMillis, endMillis,
                                                        acc_data[0], acc_data[1], acc_data[2],
                                                        raw.XAxis, raw.YAxis, raw.ZAxis,
                                                        gx, gy, gz);
  index += strlen(liner+index);
  //Serial.println(startMillis - prevMillis);
  prevMillis = startMillis;
}


