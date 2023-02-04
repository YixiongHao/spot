#include <Wire.h>
#include<VL53L0X.h>

VL53L0X sensor;
unsigned long t1, t2, t3, t4;

//#define LONG_RANGE
#define HIGH_SPEED
//#define HIGH_ACCURACY

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  sensor.setTimeout(500);
  if(!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor");
    while(1);{}
  }
  #if defined LONG_RANGE
  //lower the return signal rate limit (default is 0.25 MCPS)
  sensor.setSignalRateLimit(0.1);
  //increase laser pulse periods (defaults are 14 and 10 PCLKs)
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
  #endif

  #if defined HIGH_SPEED
    //reduce timing budget to 20 ms (default is 33ms)
    sensor.setMeasurementTimingBudget(20000);
  #elif deifned HIGH_ACCURACY
    //increase timing budget to 200 ms
    sensor.setMeasurementTimingBudget(200000);
  #endif
}


void loop() {
  // put your main code here, to run repeatedly:
  t1=micros();
  Serial.print(sensor.readRangeSingleMillimeters());
  t2=micros();
  t1=t2-t1;
  Serial.print("ms");
  Serial.println(t1);
  delay(2000);
}
