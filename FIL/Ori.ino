
//under är alla möjliga kombinationer gällande anpassning för svängning. 
//[0] är mängden som nuvarande riktning och [1] är mängden önskade riktningar. 
int LEFT[2][4] = 
{
  {4,3,2,1},
  {3,1,4,2}
};

int RIGHT[2][4] = 
{
  {3,4,2,1},
  {4,2,1,3}
};


//Funktion som avgör om fordonet ska svänga höger eller vänster, beroende på hur den är riktat och vad den ska rikta mot.
int orientering(int current,int wished,int tid)
{
  for (int i = 0; i < 5; i++)
  {
    Serial.println("for orient"); //REGGAR INTE
    
    if(LEFT[0][i] == current && LEFT[1][i] == wished)
    {
      Serial.println("LEFT");

      forward();
      delay(300);
      calibrateTurn();
      turnB();
      current = wished;
      delay(tid);
      return current;
    }
    else if(RIGHT[0][i] == current && RIGHT[1][i] == wished){
      Serial.println("RIGHT");

      forward();
      delay(300);
      calibrateTurn();
      turnA();
      current = wished;
      delay(tid);
      return current;
    }
    
    else if(current ==  wished){
      //FORWARD
      Serial.println("FORWARD");
      current = wished;
      
      return current;
    }
    
    Serial.println("Current & wished: ");
    Serial.println(current);
    Serial.println(wished);
  }
}
