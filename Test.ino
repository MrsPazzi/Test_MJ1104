  int row[12] = {2,1,1,2,2,3,3,3,3,2,1,0};
  int col[12] = {1,1,2,2,3,3,2,1,0,0,0,0};
  int n = 1  
  while (n >= 0 && n < row[max]){
      if (rdistance%38 == 0){
        
        if (i+1 == r[n] && j == c[n]){ //KLAR
          if(R == 2) // LEFT
          {
            //left turn
          }
          if else (R == 3) // RIGHT
          {
            //right turn
          }
          if else (R == 4) // FORWARD
          {
            //Forward
          }
          R = LIST[3];
         }
        
        if else(i-1 == row[n] && j == col[n]){ //
          if (R ==  1)// FORWARD
          {
            //forward
          }
          if else (R == 3) // LEFT
          {
            //left turn
          }
          if else (R == 2) // RIGHT
          {
            //right turn
          }
          R = LIST[0]
          
        }
      
        if else(i == row[n] && j+1 == col[n]){
          if (R ==  1) // RIGHT
          {
            //right turn
          }
          if else (R == 3) // FORWARD
          {
            //forward
          }
          if else (R == 4) // LEFT
          {
            //left turn
          }
          R = LIST[2]
        }
      
        if else(i == row[n] && j-1 == col[n]){
          //väst
          if (R ==  1)
          {
            //turn left
          }
          if else (R == 2)
          {
            //forward
          }
          if else (R == 4)
          {
            //turn right
          }
            R = LIST[1]
        }
      
      n = n + 1
    }
  }
  
    


  
