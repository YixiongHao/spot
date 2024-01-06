#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor1;
VL53L0X sensor2;
VL53L0X sensor3;

int sF=5, sL=4, sR=15;

long sFDist, sLDist, sRDist;

void setup() {
  // put your setup code here, to run once:
  pinMode(sF, OUTPUT);
  digitalWrite(sF, LOW);
  pinMode(sL, OUTPUT);
  digitalWrite(sL, LOW);
  pinMode(sR, OUTPUT);
  digitalWrite(sR, LOW);

  delay(500);

  Wire.begin();

  Serial.begin(115200);

  //SENSOR 1
  pinMode(sF, INPUT);
  delay(150);
  Serial.println("00");
  sensor1.init(true);
  Serial.println("01");
  delay(100);
  sensor1.setAddress((uint8_t)22);
  Serial.println("02");
  sensor1.setTimeout(500);

  //SENSOR 2
  pinMode(sL, INPUT);
  delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)25);
  Serial.println("04");
  sensor2.setTimeout(500);

  //SENSOR 3
  pinMode(sR, INPUT);
  delay(150);
  sensor3.init(true);
  Serial.println("05");
  delay(100);
  sensor3.setAddress((uint8_t)28);
  Serial.println("06");
  sensor3.setTimeout(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  sFDist = (sensor1.readRangeSingleMillimeters());
  Serial.print("sFDist(cm): ");
  Serial.println(sFDist);
  
  sLDist = (sensor2.readRangeSingleMillimeters());
  Serial.print("sLDist(cm): ");
  Serial.println(sLDist);
  
  sRDist = (sensor3.readRangeSingleMillimeters());
  Serial.print("sRDist(cm): ");
  Serial.println(sRDist);

  Serial.println("____________________________");

  delay(2000);//try lower time
  
}
