#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define hip 0
#define thigh 1
#define leg 2

#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50
int angle, anglePulse;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() > 0)
  {
    String s = Serial.readString();
    Serial.println(s);
    String s4 = s.substring(0, 3); //get first 4 characters
    String s5 = s.substring(4, 7); //get next 4 characters
    String s6 = s.substring(8, 11); //get third 4 characters
    
    int n4 = s4.toInt();
    int n5 = s5.toInt();
    int n6 = s6.  toInt();
    
    anglePulse = map(n4, 0, 270, 90, 490); // (90 500), 0 is into the stand, 90, 490
    pwm.setPWM(hip, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    
    anglePulse = map(n5, 270, 0, 94, 502); //(97, 497), 0 is right horizontal, 297 median
    pwm.setPWM(thigh, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    
    anglePulse = map(n6, 270, 0, 90, 495); //(96, 496), 0 is left, 296 median, 005 265 max
    pwm.setPWM(leg, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
  }
}
