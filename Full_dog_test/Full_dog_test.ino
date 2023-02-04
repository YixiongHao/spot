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
double X_rest=0, Y_rest=-220, Z_rest=64;
double q1, q2, q3;  //double for more precision, angles
double D;
double shoulder_ang, hip_ang, knee_ang; //temporary fix
double x1=100, x2=-100, y2=-220, y3=-155, z1=104, z2=24, x_mid=50;
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
  InvKinematics(X_rest, Y_rest, Z_rest);
  BRswing_2D(q1, q2, q3);
  FRswing_2D(q1, q2, q3);
  BLswing_2D(q1, q2, q3);
  FLswing_2D(q1, q2, q3);
  delay(d_time);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {
    demo();
    
    /*s = Serial.readString();
    int j = s.toInt();
    Serial.println(j);
    InvKinematics(X_rest, Y_rest, Z_rest+j);
    BRswing(q1, q2, q3);
    FLswing(q1, q2, q3);
    InvKinematics(X_rest, Y_rest, Z_rest-j);
    BLswing(q1, q2, q3);
    FRswing(q1, q2, q3);*/

    
    /*for(X=0; X>-100; X--)
    {
      swing_2D(X, Y_rest, Z_rest);
      delay(d_t1);
    }
    for(X=-100; X<100; X++)
    {
      swing_2D(X, Y_rest, Z_rest);
      delay(d_t1);
    }
    for(X=100; X>-100; X--)
    {
      swing_2D(X, Y_rest, Z_rest);
      delay(d_t1);
    }
    for(X=-100; X<0; X++)
    {
      swing_2D(X, Y_rest, Z_rest);
      delay(d_t1);
    }

    delay(100);

    
    for(Y=-220; Y>-270; Y--)
    {
      swing_2D(X_rest, Y, Z_rest);
      delay(d_t1);
    }
    for(Y=-270; Y<-160; Y++)
    {
      swing_2D(X_rest, Y, Z_rest);
      delay(d_t1);
    }
    for(Y=-160; Y>-270; Y--)
    {
      swing_2D(X_rest, Y, Z_rest);
      delay(d_t1);
    }
    for(Y=-270; Y<-220; Y++)
    {
      swing_2D(X_rest, Y, Z_rest);
      delay(d_t1);
    }

    delay(100);

    for(Z=64; Z>-10; Z--)
    {
      swing(X_rest, Y_rest, Z);
      delay(d_t1);
    }
    for(Z=-10; Z<150; Z++)
    {
      swing(X_rest, Y_rest, Z);
      delay(d_t1);
    }
    for(Z=150; Z>-10; Z--)
    {
      swing(X_rest, Y_rest, Z);
      delay(d_t1);
    }
    for(Z=-10; Z<64; Z++)
    {
      swing(X_rest, Y_rest, Z);
      delay(d_t1);
    }

    delay(100);*/
  }

}
