#include <HCSR04.h>
#include <Math.h>

UltraSonicDistanceSensor distanceSensor(13,  12);  // Initiate pin 13 as Trig, pin 12 as echo.
int enA = 0;
int in1 = 2;
int in2 = 3;

int enB = 1;
int in3 = 4;
int in4 = 5;

int n = 0;

int kompass[4] = {1,2,3,4};//Lista som används för navigering
int R = kompass[0]; // R = 1


 
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
  forward();
  float distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);
    
for (int i = 0 ; i < 4; i++){
  
  for (int j = 0 ; j < 4; j++){
    
    if (distance > 38 && distance < 39){
      if(i+1== r[n+1] && j == c[n+1]) //matris-indexet under
        {
          if(R == 2) // LEFT
          {
            //left turn
            turnA();
            Serial.println("LEFT");
          }
          
          else if(R == 3) // RIGHT
          {
            //right turn
            turnB();
            Serial.println("RIGHT");
          }
          R = kompass[3]; //riktar söder
          
           
        } 
        
        else if(i-1 == r[n+1] && j ==c[n+1]) //matris-indexet över
        {
          if(R == 3) // LEFT
          {
            //left turn
            turnA();
            Serial.println("LEFT");
          }
          else if(R == 2) // RIGHT
          {
            //right turn
            turnB();
            Serial.println("RIGHT");
          }
          R = kompass[0]; //riktar norr
        }
        
        else if(i == r[n+1] && j+1 == c[n+1]) //matris-indexet vänster
        {
          if (R ==  1) // RIGHT
          {
            //right turn
            turnB();
            Serial.println("RIGHT");
          }
          else if(R == 4) // LEFT
          {
            //left turn
            turnA();
            Serial.println("LEFT");
          }
          R = kompass[2]; //riktar mot öst
        }
        
        else if(i == r[n+1] && j-1 == c[n+1]) //matris-indexet höger
        {
          //väst
          if (R ==  1) //riktat nord
          {
            //turn left
            turnA();
            Serial.println("LEFT");
          }
          else if(R == 4) //riktat syd
          {
            //turn right
            turnB();
            Serial.println("LEFT");
          }
          R = kompass[1]; //riktar mot väst
        }
        forward(); //åker frammåt oavsett om den behövt svänga eller ej.
        Serial.println("R = " + R);
        n = n+1;
        Serial.println("n = " + n);
        Serial.println("Next step...");
      
    }
  }
}
  delay(10000);     
    
}
