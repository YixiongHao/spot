void backright()
{
    swing(x2, y2, z1);
    
    delay(d_time);
    
    for(X=x2; X<=x1; X++)
    {
      Z=-dzdx*X+Z_rest;     
      swing(X, y2, Z);
      delay(d_t1);;
    }

    delay(d_time);

    for(Y=y2; Y<=y3; Y++)
    {
      swing(x1, Y, z2);
      delay(d_t1);;
    }

    delay(d_time);

    for(X=x1; X>=-x_mid; X--)
    {
      Z=-dzdx*X+Z_rest;     
      swing(X, y3, Z);
      delay(d_t1);;
    }

    delay(d_time);

    for(X=-x_mid; X>=x2; X--)
    {
      Y=dydx*X+Y_rest+y_offset;
      Z=-dzdx*X+Z_rest;
      swing(X, Y, Z);
      delay(d_t1);;
    }
}
