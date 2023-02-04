void BRswing(double q1, double q2, double q3)
{
  shoulder_ang = map(q1, 0, 270, 477, 76);
  pwm.setPWM(0, 0, shoulder_ang);
  hip_ang = map(q2, 0, 270, 504, 98);
  pwm.setPWM(1, 0, hip_ang);
  knee_ang = map(q3, 0, 270, 479, 79);
  pwm.setPWM(2, 0, knee_ang); 
}
