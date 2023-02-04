#include <Wire.h>
#include<Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50
#define a1 155 //leg length  (163)
#define a2 155 //leg length  (163)

uint8_t servonum = 0; //used foe recording purposes
int hip = 0;
int thigh = 1;
int leg = 2;
int j, k;
String s, s1, s2, s3, s4;
double X=0, Y=-220; //coords
double q1, q2;  //double for more accuracy, angles
int hip_ang, thigh_ang, leg_ang; //temporary fix

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
    /*String s = Serial.readString();
    String Xc = s.substring(0, 4);
    String Yc = s.substring(5, 9);
    X = Xc.toInt(); //string to int
    Y = Yc.toInt(); //string to int
    Serial.print("X = ");
    Serial.println(X);
    Serial.print("Y= ");
    Serial.println(Y);*/
    String s = Serial.readString();
    X = s.toInt();
    for(X=100; X>-100; X--)
    {
    q2=acos((X*X+Y*Y-a1*a1-a2*a2)/(2*a1*a2));  //calculating first angle
    q1=atan2(Y,X)-atan2((a2*sin(q2)),(a1+a2*cos(q2)));  //q1=atan2(-Y,X)-asin(-L*sin(q2)/sqrt(X*X+Y*Y));
    q2=-q2*57.3+140; //+187
    q1=-q1*57.3+7; //-68
    Serial.print("q1= ");
    Serial.println(q1);
    Serial.print("q2= ");
    Serial.println(q2);

    hip_ang = map(135, 0, 270, 90, 490);
    pwm.setPWM(hip, 0, hip_ang);
    thigh_ang = map(q1, 270, 0, 94, 502);
    pwm.setPWM(thigh, 0, thigh_ang);
    leg_ang = map(q2, 270, 0, 90, 495);
    pwm.setPWM(leg, 0, leg_ang);
    if(X>=100)
    {
      delay(3000);
    }
    }   
  }
}
