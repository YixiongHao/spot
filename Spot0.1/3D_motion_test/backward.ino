void backward()
{
  swing(x2, y2, Z_rest);
    
  delay(d_time);
    
  for(X=x2; X<=x1; X++)
  {
    swing_2D(X, y2, Z_rest);
    delay(d_t1);;
  }

  delay(d_time);
    
  for(Y=y2; Y<=y3; Y++)
  {
    swing_2D(x1, Y, Z_rest);
    delay(d_t1);;
  }

  delay(d_time);

  for(X=x1; X>=-x_mid; X--)
  {    
    swing_2D(X, y3, Z_rest);
    delay(d_t1);;
  }

  delay(d_time);

  for(X=-x_mid; X>=x2; X--)
  {
    Y=dydx*X+Y_rest+y_offset;
    swing_2D(X, Y, Z_rest);
    delay(d_t1);;
  }
}
