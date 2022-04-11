#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(13,  12);
//UltraSonicDistanceSensor sensorFront(13, 12);  // Initialize sensor that uses digital pins 13 and 12.
//UltraSonicDistanceSensor sensorLeft(11, 10);  // Initialize sensor that uses digital pins 13 and 12.
//UltraSonicDistanceSensor sensorRight(9, 8);  // Initialize sensor that uses digital pins 13 and 12.

void setup_echo()
{
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
    //int distanceBack = sensorFront.measureDistanceCm();
    //int distaneLeft = sensorLeft.measureDistanceCm();
    //int distanceRight = sensorRight.measureDistanceCm();
}

void testPrint() 
{
    // Every 1 sec, do a measurement using the sensor and print the distance in centimeters.
    Serial.println(distanceFront);
    Serial.println(distanceLeft);
    Serial.println(distanceRight);
    delay(2000);
}
