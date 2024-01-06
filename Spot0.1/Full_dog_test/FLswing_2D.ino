void FLswing_2D(double q1, double q2, double q3)
{
  shoulder_ang = map(135, 0, 270, 480, 84);
  pwm.setPWM(8, 0, shoulder_ang);
  hip_ang = map(q2, 0, 270, 98, 501);
  pwm.setPWM(9, 0, hip_ang);
  knee_ang = map(q3, 0, 270, 80, 480);
  pwm.setPWM(10, 0, knee_ang); 
}
