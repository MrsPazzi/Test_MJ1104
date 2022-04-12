#include <HCSR04.h>
#include <Math.h>

UltraSonicDistanceSensor distanceSensor(13,  12);  // Initiate pin 13 as Trig, pin 12 as echo.
int enA = 7;
int in1 = 6;
int in2 = 5;

int enB = 2;
int in3 = 4;
int in4 = 3;

int n = 0;


float distance = distanceSensor.measureDistanceCm();

int rdistance = (int)round(distance);

 
int r[12] = {2,1,1,2,2,3,3,3,3,2,1,0};
int c[12] = {1,1,2,2,3,3,2,1,0,0,0,0};

void setup(){
  Serial.begin(9600);
  //pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
  }
  
void loop() 
{
  int LIST[] = {1,2,3,4};//Lista som används för navigering
  int R = LIST[0];
  while(n >= 0)
  rdistance = distanceSensor.measureDistanceCm();
  Serial.println(rdistance);
  {
    if (rdistance%38 == 0 && distance != -1)
    {
      speedOff();
      
      for (int i = 0 ; i < 4; i++)
      {
        for (int j = 0 ; j < 4; j++)
        {
          if(i+1== r[n+1] && j == c[n+1])
          {
            if(R == 2) // LEFT
            {
              //left turn
              turnA();
            }
            
            else if(R == 3) // RIGHT
            {
              //right turn
              turnB();
            }
            R = LIST[3]; //riktar söder
             
          } 
          
          else if(i-1 == r[n+1] && j ==c[n+1])
          {
            if(R == 3) // LEFT
            {
              //left turn
              turnA();
            }
            else if(R == 2) // RIGHT
            {
              //right turn
              turnB();
            }
            R = LIST[0]; //riktar norr
          }
          
          else if(i == r[n+1] && j+1 == c[n+1])
          {
            if (R ==  1) // RIGHT
            {
              //right turn
              turnB();
            }
            else if(R == 4) // LEFT
            {
              //left turn
              turnA();
            }
            R = LIST[2]; //riktar mot öst
          }
          
          else if(i == r[n+1] && j-1 == c[n+1])
          {
            //väst
            if (R ==  1) //riktat nord
            {
              //turn left
              turnA();
            }
            else if(R == 4) //riktat syd
            {
              //turn right
              turnB();
            }
            R = LIST[1]; //riktar mot väst
          }
          forward(); //åker frammåt oavsett om den behövt svänga eller ej.
        }
      }
      n = n+1;
    }
  }
}
