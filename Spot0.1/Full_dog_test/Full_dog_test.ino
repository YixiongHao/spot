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
int i, j, k, tx, ty, tz;
String s, s1, s2, s3, s4;
double X, Y, Z;
double X_, Y_, Z_;
double X_rest=0, Y_rest=-220, Z_rest=64;
double q1, q2, q3;  //double for more precision, angles
double D;
double shoulder_ang, hip_ang, knee_ang; //temporary fix
double x1=50, x2=-50, y2=-230, y3=-170, z1=104, z2=24, x_mid=25;
double dx=abs(x_mid-x1), dy=abs(y2-y3), dz=abs(z1-z2), dx_3D=abs(x1-x2);
double dydx=dy/dx, dzdx=dz/dx_3D; //gradients
double y_offset=x1*dydx;
int d_time = 150;
int d_t1 = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start");
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  /*InvKinematics(X_rest, Y_rest, Z_rest);
  BRswing_2D(q1, q2, q3);
  FRswing_2D(q1, q2, q3);
  BLswing_2D(q1, q2, q3);
  FLswing_2D(q1, q2, q3);*/

  InvKinematics(x1, y2, Z_rest);
  FLswing_2D(q1, q2, q3);
  BRswing_2D(q1, q2, q3);
  InvKinematics(x2, y2, Z_rest);
  FRswing_2D(q1, q2, q3);
  BLswing_2D(q1, q2, q3);
  delay(d_time);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {
    demo();
    /*String s = Serial.readString();
    String s1 = s.substring(0, 3);
    String s2 = s.substring(4, 7);
    Serial.println(s);
    int j = s1.toInt();
    int k = s2.toInt();

    InvKinematics(X_rest, -160, Z_rest);
    FLswing_2D(q1, q2, q3);
    BRswing_2D(q1, q2, q3);
    InvKinematics(X_rest, Y_rest, j);
    FRswing(q1, q2, q3);
    InvKinematics(X_rest, Y_rest, k);
    BLswing(q1, q2, q3);*/


    /*Y=Y_rest;
    for(X=x1; X>=x2; X-=2)
    {
      InvKinematics(X, y2, 100);
      FLswing(q1, q2, q3);
      InvKinematics(X, y2, 30);
      BRswing(q1, q2, q3);
      if(Y<=y3)
      {
        Y+=5;
      }
      if(-X>=x_mid)
      {
        Y=dydx*X+Y_rest+y_offset;
      }
      InvKinematics(-X, Y, Z_rest);
      FRswing_2D(q1, q2, q3);
      BLswing_2D(q1, q2, q3);
    }

    delay(10);

    Y=Y_rest;
    for(X=x1; X>=x2; X-=2)
    {
      InvKinematics(X, y2, 100);
      FRswing(q1, q2, q3);
      InvKinematics(X, y2, 30);
      BLswing(q1, q2, q3);
      if(Y<=y3)
      {
        Y+=5;
      }
      if(-X>=x_mid)
      {
        Y=dydx*X+Y_rest+y_offset;
      }
      InvKinematics(-X, Y, Z_rest);
      FLswing_2D(q1, q2, q3);
      BRswing_2D(q1, q2, q3);
    }

    delay(10); */   
    
  }

}
