void BLswing(double q1, double q2, double q3)
{
  shoulder_ang = map(q1, 0, 270, 69, 469);
  pwm.setPWM(12, 0, shoulder_ang);
  hip_ang = map(q2, 0, 270, 92, 493);
  pwm.setPWM(13, 0, hip_ang);
  knee_ang = map(q3, 0, 270, 92, 482);
  pwm.setPWM(14, 0, knee_ang); 
}
