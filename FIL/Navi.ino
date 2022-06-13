int r[12] = {2,1,1,2,2,3,3,3,3,2,1,0};
int c[12] = {1,1,2,2,3,3,2,1,0,0,0,0};

int navi(int n,int tid)
{
      int i = r[n];
      int j = c[n];

      Serial.println("n = ");
      Serial.println(n);
      Serial.println("i,j = ");
      Serial.println(i);
      Serial.println(j);
        
      //Här söks alla vertikala och horisontala grannar, efter vilken som näst på tur i rutten. 
      if(i-1 == r[n+1] && j == c[n+1]) //matris-indexet under
      {
        Serial.println("NORTH");
        orientering(R,1,tid);
        R = 1;
      }
      
      else if(i+1 == r[n+1] && j == c[n+1]) //matris-indexet över
      {
        Serial.println("SOUTH");
        orientering(R,4,tid);
        R = 4;
      }
       
      else if(i  == r[n+1] && (j-1) == c[n+1]) //matris-indexet till höger
      {
        Serial.println("WEST");
        orientering(R,2,tid);
        R = 2;
      }
        
      else if(i == r[n+1] && (j+1) == c[n+1]) //matris-indexet till vänster
      {
         Serial.println("EAST");
         orientering(R,3,tid);
         R = 3;
      }
      Serial.println("-----------------------------");
      delay(100);
      return n;
}
       
      
