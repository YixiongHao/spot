void test()
{
  Y=Y_rest;
  for(X=x1; X>=x2; X-=2)
  {
    InvKinematics(X, Y_rest, Z_rest);
    FLswing_2D(q1, q2, q3);
    BRswing_2D(q1, q2, q3);
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
    delay(2);
  }

  delay(1000);

  Y=Y_rest;
  for(X=x1; X>=x2; X-=2)
  {
    InvKinematics(X, Y_rest, Z_rest);
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
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
    delay(2);
  }
  
  delay(1000);
  
}
