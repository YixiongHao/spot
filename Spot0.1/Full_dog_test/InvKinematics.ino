void InvKinematics(double x, double y, double z)
{
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.println(z);
        
  D = (x*x + y*y + z*z - hip_len*hip_len - upperl_len*upperl_len - lowerl_len*lowerl_len)/(2*upperl_len*lowerl_len);
  q1 = atan2(y, z) - atan2(sqrt(y*y + z*z - hip_len*hip_len), hip_len);
  q3 = atan2(sqrt(1-D*D), D);
  q2 = atan2(x, sqrt(y*y + z*z - hip_len*hip_len)) - atan2(lowerl_len*sin(q3), upperl_len + lowerl_len*cos(q3));

  q1 = q1*57.3+286;
  q2 = -q2*57.3+93;//91
  q3 = -q3*57.3+150;//147
}
