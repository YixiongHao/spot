void forward()
{
  InvKinematics(x1, y2, Z_rest);
  BRswing_2D(q1, q2, q3);
  FRswing_2D(q1, q2, q3);
  BLswing_2D(q1, q2, q3);
  FLswing_2D(q1, q2, q3);
  delay(d_time);
    
  for(X=x1; X>=x2; X-=2)
  {
    InvKinematics(X, y2, Z_rest);
    BRswing_2D(q1, q2, q3);  
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
  }

  delay(d_time);
    
  for(Y=y2; Y<=y3; Y+=2)
  {
    InvKinematics(x2, Y, Z_rest);
    BRswing_2D(q1, q2, q3);  
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
  }

  delay(d_time);

  for(X=x2; X<=x_mid; X+=2)
  {    
    InvKinematics(X, y3, Z_rest);
    BRswing_2D(q1, q2, q3);  
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
  }

  delay(d_time);

  for(X=x_mid; X<=x1; X+=2)
  {
    Y=-dydx*X+Y_rest+y_offset;
    InvKinematics(X, Y, Z_rest);
    BRswing_2D(q1, q2, q3);  
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
  }
}
