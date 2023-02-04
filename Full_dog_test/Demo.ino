void demo()
{
  for(Y=Y_rest; Y>=-290; Y--)
  {
    InvKinematics(X_rest, Y, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);    
  }
  delay(d_time);
  for(Y=-290; Y<=-140; Y++)
  {
    InvKinematics(X_rest, Y, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);    
  }
  delay(d_time);
  for(Y=-140; Y>=-290; Y--)
  {
    InvKinematics(X_rest, Y, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);    
  }
  delay(d_time);
  for(Y=-290; Y<=Y_rest; Y++)
  {
    InvKinematics(X_rest, Y, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);     
  }

  
  delay(500);

  
  for(X=X_rest; X<=70; X++)
  {
    InvKinematics(X, Y_rest, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);     
  }
  delay(d_time);
  for(X=70; X>=-80; X--)
  {
    InvKinematics(X, Y_rest, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);     
  }
  delay(d_time);
  for(X=-80; X<=70; X++)
  {
    InvKinematics(X, Y_rest, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);     
  }
  delay(d_time);
  for(X=70; X>=X_rest; X--)
  {
    InvKinematics(X, Y_rest, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);      
  }
  
  
  delay(500);


  for(i=0; i<=70; i++)
  {
    InvKinematics(X_rest, Y_rest, Z_rest-i);
    BRswing(q1, q2, q3);
    FRswing(q1, q2, q3);
    InvKinematics(X_rest, Y_rest, Z_rest+i);
    BLswing(q1, q2, q3);
    FLswing(q1, q2, q3);      
  }
  delay(d_time);
  for(i=70; i>=-70; i--)
  {
    InvKinematics(X_rest, Y_rest, Z_rest-i);
    BRswing(q1, q2, q3);
    FRswing(q1, q2, q3);
    InvKinematics(X_rest, Y_rest, Z_rest+i);
    BLswing(q1, q2, q3);
    FLswing(q1, q2, q3);     
  }
  delay(d_time);
  for(i=-70; i<=70; i++)
  {
    InvKinematics(X_rest, Y_rest, Z_rest-i);
    BRswing(q1, q2, q3);
    FRswing(q1, q2, q3);
    InvKinematics(X_rest, Y_rest, Z_rest+i);
    BLswing(q1, q2, q3);
    FLswing(q1, q2, q3);      
  }
  delay(d_time);
  for(i=70; i>=0; i--)
  {
    InvKinematics(X_rest, Y_rest, Z_rest-i);
    BRswing(q1, q2, q3);
    FRswing(q1, q2, q3);
    InvKinematics(X_rest, Y_rest, Z_rest+i);
    BLswing(q1, q2, q3);
    FLswing(q1, q2, q3);     
  }

  
  delay(500);

  for(i=0; i<=40; i++)
  {
    InvKinematics(X_rest, Y_rest-i, Z_rest);
    FRswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
    InvKinematics(X_rest, Y_rest+i, Z_rest);
    BRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
  }
  delay(d_time);
  for(i=40; i>=-40; i--)
  {
    InvKinematics(X_rest, Y_rest-i, Z_rest);
    FRswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
    InvKinematics(X_rest, Y_rest+i, Z_rest);
    BRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
  }
  delay(d_time);
  for(i=-40; i<=40; i++)
  {
    InvKinematics(X_rest, Y_rest-i, Z_rest);
    FRswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
    InvKinematics(X_rest, Y_rest+i, Z_rest);
    BRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
  }
  delay(d_time);
  for(i=40; i>=0; i--)
  {
    InvKinematics(X_rest, Y_rest-i, Z_rest);
    FRswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
    InvKinematics(X_rest, Y_rest+i, Z_rest);
    BRswing_2D(q1, q2, q3);
    BLswing_2D(q1, q2, q3);
  }

  
  delay(500);


  for(i=0; i<=30; i++)
  {
    InvKinematics(X_rest, Y_rest-i, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    InvKinematics(X_rest, Y_rest+i, Z_rest);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3); 
    delay(d_t1);   
  }
  delay(d_time);
  for(i=30; i>=-30; i--)
  {
    InvKinematics(X_rest, Y_rest-i, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    InvKinematics(X_rest, Y_rest+i, Z_rest);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
    delay(d_t1);    
  }
  delay(d_time);
  for(i=-30; i<=30; i++)
  {
    InvKinematics(X_rest, Y_rest-i, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    InvKinematics(X_rest, Y_rest+i, Z_rest);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
    delay(d_t1);    
  }
  delay(d_time);
  for(i=30; i>=0; i--)
  {
    InvKinematics(X_rest, Y_rest-i, Z_rest);
    BRswing_2D(q1, q2, q3);
    FRswing_2D(q1, q2, q3);
    InvKinematics(X_rest, Y_rest+i, Z_rest);
    BLswing_2D(q1, q2, q3);
    FLswing_2D(q1, q2, q3);
    delay(d_t1);    
  }

  delay(500);

}
