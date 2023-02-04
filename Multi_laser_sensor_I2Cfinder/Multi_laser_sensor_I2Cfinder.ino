#include <Wire.h>
#include<VL53L0X.h>

VL53L0X sensor;
VL53L0X sensor2;

void setup() {
  // put your setup code here, to run once
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  delay(500);
  Wire.begin();

  Serial.begin(115200);

  digitalWrite(4, HIGH);
  delay(150);
  Serial.println("00");
  sensor.init(true);

  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)22);
  Serial.println("02");

  digitalWrite(5, HIGH);
  delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)25);
  Serial.println("04");
  Serial.println("address set");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("I2C scanner.Scanning....");
  byte count = 0;
  for(byte i=1; i<120; i++)
  {
    Wire.beginTransmission(i);
    if(Wire.endTransmission()==0)
    {
      Serial.print("Focused address: ");
      Serial.print(i,DEC);
      Serial.print("(0x");
      Serial.print(i,HEX);
      Serial.println(")");
      count++;
      delay(1);//dunno if needed
    }//end of positive response
  }//end of loop
  Serial.println("Done. ");
  Serial.print("Found");
  Serial.print(count, DEC);
  Serial.println("device(s)");

  delay(100);
}
