#include <Wire.h>
#include<Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50
#define hip_len 64
#define upperl_len 155
#define lowerl_len 155

uint8_t servonum = 0; //used for recording purposes
int hip = 0;
int thigh = 1;
int leg = 2;
int j, k;
String s, s1, s2, s3, s4;
double X, Y, Z;
double X_rest=0, Y_rest=-220, Z_rest=64;
double q1, q2, q3;  //double for more accuracy, angles
double D;
double hip_ang, thigh_ang, leg_ang; //temporary fix
double x1=100, x2=-100, y2=-220, y3=-155, z1=104, z2=24, x_mid=50;
double dx=abs(x_mid-x1), dy=abs(y2-y3), dz=abs(z1-z2), dx_3D=abs(x1-x2);
double dydx=dy/dx, dzdx=dz/dx_3D;
double y_offset=x1*dydx;
int d_time = 10;
int d_t1 = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start");
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  swing(X_rest, Y_rest, Z_rest);
  delay(d_time);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {
   forward();
  }

}
