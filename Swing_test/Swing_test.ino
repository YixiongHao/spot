#include <Wire.h>
#include<Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50
#define hip_len 54
#define upperl_len 160
#define lowerl_len 150

uint8_t servonum = 0; //used foe recording purposes
int hip = 0;
int thigh = 1;
int leg = 2;
int j, k;
String s, s1, s2, s3, s4;
double X=100, Y=-220, Z=54; //coords Y=-219.32
double q1, q2, q3;  //double for more accuracy, angles
double D;
double hip_ang, thigh_ang, leg_ang; //temporary fix

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("X movement test");
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {
    swing(X, Y, Z);
    delay(2000);
    for(X=100; X>-100; X--)
    {     
      swing(X, Y, Z);
    }

    delay(1000);
    
    for(Y=-220; Y<=-140; Y++)
    {
      //Y=4*X+400-220;
      swing(X, Y, Z);
    }

    delay(1000);

    for(X=-100; X<50; X++)
    {    
      swing(X, Y, Z);
    }

    delay(1000);

    for(X=50; X<100; X++)
    {
      Y=-1.6*X+160-220;
      swing(X, Y, Z);
    }

  }
}
