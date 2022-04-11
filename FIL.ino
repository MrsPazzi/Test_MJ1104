#include <HCSR04.h>
#include <Math.h>

UltraSonicDistanceSensor distanceSensor(13,  12);  // Initiate pin 13 as Trig, pin 12 as echo.
int enA = 7;
int in1 = 6;
int in2 = 5;

int enB = 2;
int in3 = 4;
int in4 = 3;

int n = 1;


float distance = distanceSensor.measureDistanceCm();

int rdistance = (int)round(distance);



byte rutt[12][2] = 
  {
  {2,1}, 
  {1,1}, 
  {1,2}, 
  {2,2}, 
  {2,3},
  {3,3},
  {3,2},
  {3,1},
  {3,0},
  {2,0},
  {1,0},
  {0,0}
  };

 
r[12] = {2,1,1,2,2,3,3,3,3,2,1,0}
c[12] = {1,1,2,2,3,3,2,1,0,0,0,0}

struct route {
  byte row;
  byte col;
  };
route arrayOfPositions[12];

for (int n = 0; i < 12; n++){
  arrayOfPositions[n].row = r[n]
  arrayOfPositions[n].col = c[n]
  }


void setup(){
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  }
  
void loop() 
{
  int LIST[] = {1,2,3,4};//Lista som används för navigering
  int R = LIST[0];
  while(n >= 0)
  {
    if (rdistance%38 == 0)
    {
      n = n+1;
      for (int i = 0 ; i < 4; i++)
      {
        for (int j = 0 ; j < 4; j++)
        {
          rutt[][] = [i][j]
          Serial.print(rutt[i][j]);
          
          if [i+1][j] == rutt[n+1][0] // S
          {
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
          if else ([i-1,j] == rutt[n+1][n+1]) // N
          {
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
          if else([i,j+1] == rutt[n+1][]) // E
          {
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
            R = LIST[3]
          }
          if else([i,j-1] == rutt[n+1][])
          {
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
        }
      }
    }
  }
}


      
    
      
    
      

}
