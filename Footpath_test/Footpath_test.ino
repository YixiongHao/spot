#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <stdlib.h>

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
double X=0, Y=-219.32, Z=54; //coords
double q1, q2, q3;  //double for more accuracy, angles
float D;
int hip_ang, thigh_ang, leg_ang;
int step_width, step_height;
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("X movement test");
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

void inverse_kinematics(int X, int Y, int Z)
{
    D = (X*X + Y*Y + Z*Z - hip_len*hip_len - upperl_len*upperl_len - lowerl_len*lowerl_len)/(2*upperl_len*lowerl_len);
    q1 = atan2(Y, Z) - atan2(sqrt(Y*Y + Z*Z - hip_len*hip_len), hip_len);
    q3 = atan2(sqrt(1-D*D), D);
    q2 = atan2(X, sqrt(Y*Y + Z*Z - hip_len*hip_len)) - atan2(lowerl_len*sin(q3), upperl_len + lowerl_len*cos(q3));

    q1 = q1*57.3+286;
    q2 = -q2*57.3+91;
    q3 = -q3*57.3+147;

    hip_ang = map(135, 0, 270, 90, 490);
    pwm.setPWM(hip, 0, hip_ang);
    thigh_ang = map(q2, 270, 0, 94, 502);
    pwm.setPWM(thigh, 0, thigh_ang);
    leg_ang = map(q3, 0, 270, 95, 498);
    pwm.setPWM(leg, 0, leg_ang);   
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {
    for(X=-60; X<=60; X++)
    {
      Y=X-200;
      D = (X*X + Y*Y + Z*Z - hip_len*hip_len - upperl_len*upperl_len - lowerl_len*lowerl_len)/(2*upperl_len*lowerl_len);
    q1 = atan2(Y, Z) - atan2(sqrt(Y*Y + Z*Z - hip_len*hip_len), hip_len);
    q3 = atan2(sqrt(1-D*D), D);
    q2 = atan2(X, sqrt(Y*Y + Z*Z - hip_len*hip_len)) - atan2(lowerl_len*sin(q3), upperl_len + lowerl_len*cos(q3));

    q1 = q1*57.3+286;
    q2 = -q2*57.3+91;
    q3 = -q3*57.3+147;

    hip_ang = map(135, 0, 270, 90, 490);
    pwm.setPWM(hip, 0, hip_ang);
    thigh_ang = map(q2, 270, 0, 94, 502);
    pwm.setPWM(thigh, 0, thigh_ang);
    leg_ang = map(q3, 0, 270, 95, 498);
    pwm.setPWM(leg, 0, leg_ang);  

    if(X<=-60)
    {
      delay(3000);
    }
    }
     
  }
}
