#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(13,  12);  // Initiate pin 13 as Trig, pin 12 as echo.
UltraSonicDistanceSensor distanceSensorA(11,  10); 
UltraSonicDistanceSensor distanceSensorB(9,  8); 

int enA = 6;
int in1 = 2;
int in2 = 3;

int enB = 7;
int in3 = 4;
int in4 = 5;

int n = 0; //ist. för 1
int t = 0;

//Dessa två listor är raden-och column-indexen som behöver åka till för att komma i mål. Alltså en rutt som fordonet tar i labyrinten.


//kompass, för att anpassa svängning till riktning (1=nord, 2=väst, 3=öst, 4=syd). Börjar med riktning norr.
int R = 1; // R = 1

int svngtid[6] = {400,410,405,400,415,405};

void setup()
{
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
}



void loop()
{
  calibrateStandard();
  forward();
  float distanceA = distanceSensorA.measureDistanceCm();
  float distanceB = distanceSensorB.measureDistanceCm();
  
  
  if(distanceA != -1 && distanceB != -1)
  {
    float summa = distanceA + distanceB;
    Serial.println(summa);
    if(summa < 17.5)
    {
      Serial.println("SUMMA:");
      Serial.println(summa);
      if(n < 11)
      {
        n++;
        Serial.println("n = ");
        Serial.println(n);
        navi(n,svngtid[t]);
        t++;
      }
    }
  }
  
  if(digitalRead(in2) == HIGH && digitalRead(in3) == HIGH)
  {
     //Avståndet är höjs med 100 för att bli ett heltal, för att modulus operatorn kan endast göras med integer värden.
    //Om distansen är 38cm så kommer den göre ett beslut utifrån dess värden den har. 
    
      
    if(distanceA != -1 && distanceB != -1)
    {
      if(distanceA > 8)
      {
        calibrateA();
        forward();
        delay(100);
        Serial.println("calibrateA");
      }
      else if(distanceA < 8)
      {
        calibrateB();
        forward();
        delay(100);
        Serial.println("calibrateB");
      }
    }
    
  }
  
}
