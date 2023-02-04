void FRswing_2D(double q1, double q2, double q3)
{
  shoulder_ang = map(135, 0, 270, 81, 481);
  pwm.setPWM(4, 0, shoulder_ang);
  hip_ang = map(q2, 0, 270, 502, 99);
  pwm.setPWM(5, 0, hip_ang);
  knee_ang = map(q3, 0, 270, 479, 82);
  pwm.setPWM(6, 0, knee_ang); 
}
