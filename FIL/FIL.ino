#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(13,  12);  // Initiate pin 13 as Trig, pin 12 as echo.
int enA = 0;
int in1 = 2;
int in2 = 3;

int enB = 1;
int in3 = 4;
int in4 = 5;

int n = 0;

//Dessa två listor är raden-och column-indexen som behöver åka till för att komma i mål. Alltså en rutt som fordonet tar i labyrinten.
int r[12] = {2,1,1,2,2,3,3,3,3,2,1,0};
int c[12] = {1,1,2,2,3,3,2,1,0,0,0,0};

//kompass, för att anpassa svängning till riktning (1=nord, 2=väst, 3=öst, 4=syd). Börjar med riktning norr.
int R = 1; // R = 1


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

void setup(){
  Serial.begin(9600);
  //pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
}

//Funktion som avgör om fordonet ska svänga höger eller vänster, beroende på hur den är riktat och vad den ska rikta mot.

int orientering(int current,int wished){
  for (int i = 0; i < 5; i++){
    if(LEFT[0][i] == current && LEFT[1][i] == wished){
      Serial.println("LEFT");
      turnB();
      current = wished;
      return current;
    }
    else if(RIGHT[0][i] == current && RIGHT[1][i] == wished){
      Serial.println("RIGHT");
      turnA();
      current = wished;
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


void loop(){
  calibrateB();
  forward();
  float distance = distanceSensor.measureDistanceCm();
  int rdist = distance * 100; //Avståndet är höjs med 100 för att bli ett heltal, för att modulus operatorn kan endast göras med integer värden.
      //Om distansen är 38cm så kommer den göre ett beslut utifrån dess värden den har. 
      if(rdist%3800 == 0){

        int i = r[n];
        int j = c[n];
        
        Serial.println("n = ");
        Serial.println(n);
        Serial.println(rdist);
        Serial.println("i,j = ");
        Serial.println(i);
        Serial.println(j);

        
        //Här söks alla vertikala och horisontala grannar, efter vilken som näst på tur i rutten. 
        if(i-1 == r[n+1] && j == c[n+1]) //matris-indexet under
        {
          Serial.println("NORTH");
          orientering(R,1);
          R = 1;
        }
        
        else if(i+1 == r[n+1] && j == c[n+1]) //matris-indexet över
        {
          Serial.println("SOUTH");
          orientering(R,4);
          R = 4;
        }
        
        else if(i  == r[n+1] && (j-1) == c[n+1]) //matris-indexet till höger
        {
          Serial.println("WEST");
          orientering(R,2);
          R = 2;
        }
        
        else if(i == r[n+1] && (j+1) == c[n+1]) //matris-indexet till vänster
        {
          Serial.println("EAST");
          orientering(R,3);
          R = 3;
        }
        
        Serial.println("-----------------------------");
        
        if(n < sizeof(r)){
        n++;
        }
        return;
        }
}
