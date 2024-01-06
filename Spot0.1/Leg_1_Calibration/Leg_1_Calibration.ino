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
    int n6 = s6.toInt();

    //leg 1
    anglePulse = map(n4, 0, 270, 81, 481);
    pwm.setPWM(4, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    anglePulse = map(n5, 0, 270, 502, 99);
    pwm.setPWM(5, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    anglePulse = map(n6, 0, 270, 479, 82);
    pwm.setPWM(6, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");

    //leg 2
    anglePulse = map(n4, 0, 270, 480, 84);
    pwm.setPWM(8, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    anglePulse = map(n5, 0, 270, 98, 501);
    pwm.setPWM(9, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    anglePulse = map(n6, 0, 270, 80, 480);
    pwm.setPWM(10, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");

    //leg 3
    anglePulse = map(n4, 0, 270, 477, 76);
    pwm.setPWM(0, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    anglePulse = map(n5, 0, 270, 504, 98);
    pwm.setPWM(1, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    anglePulse = map(n6, 0, 270, 479, 79);
    pwm.setPWM(2, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");

    //leg 4
    anglePulse = map(n4, 0, 270, 69, 469);
    pwm.setPWM(12, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    anglePulse = map(n5, 0, 270, 92, 493);
    pwm.setPWM(13, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
    anglePulse = map(n6, 0, 270, 92, 482);
    pwm.setPWM(14, 0, anglePulse);
    Serial.print(anglePulse);
    Serial.print(" ");
  }
}
