/*
 * getDistance
 *
 * Example of using SharpIR library to calculate the distance beetween the sensor and an obstacle
 *
 * Created by Giuseppe Masino, 15 June 2016
 *
 * -----------------------------------------------------------------------------------
 *
 * Things that you need:
 * - Arduino
 * - A Sharp IR Sensor
 *
 *
 * The circuit:
 * - Arduino 5V -> Sensor's pin 1 (Vcc)
 * - Arduino GND -> Sensor's pin 2 (GND)
 * - Arduino pin A0 -> Sensor's pin 3 (Output)
 *
 *
 * See the Sharp sensor datasheet for the pin reference, the pin configuration is the same for all models.
 * There is the datasheet for the model GP2Y0A41SK0F:
 *
 * http://www.robotstore.it/open2b/var/product-files/78.pdf
 *
 */

//import the library in the sketch
#include <SharpIR.h>

// Define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

const int numReadings2 = 10;

int readings2[numReadings2];      // the readings from the analog input
int readIndex2 = 0;              // the index of the current reading
int total2 = 0;                  // the running total
int average2 = 0;                // the average

int inputPin2 = A1;

const int numReadings3 = 10;

int readings3[numReadings3];      // the readings from the analog input
int readIndex3 = 0;              // the index of the current reading
int total3 = 0;                  // the running total
int average3 = 0;                // the average

int inputPin3 = A2;

const int numReadings4 = 10;

int readings4[numReadings4];      // the readings from the analog input
int readIndex4 = 0;              // the index of the current reading
int total4 = 0;                  // the running total
int average4 = 0;                // the average

int inputPin4 = A3;

//Create a new instance of the library
//Call the sensor "sensor"
//The model of the sensor is "GP2YA41SK0F"
//The sensor output pin is attached to the pin A0
SharpIR sensor( SharpIR::GP2Y0A21YK0F, A0 );
SharpIR sensor2( SharpIR::GP2Y0A21YK0F, A1 );
SharpIR sensor3( SharpIR::GP2Y0A21YK0F, A2 );
SharpIR sensor4( SharpIR::GP2Y0A21YK0F, A3 );


void setup()
{
  Serial.begin( 9600 ); //Enable the serial comunication
    // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
    for (int thisReading2 = 0; thisReading2 < numReadings2; thisReading2++) {
    readings2[thisReading2] = 0;
  }

    for (int thisReading3 = 0; thisReading3 < numReadings3; thisReading3++) {
    readings3[thisReading3] = 0;
  }
      for (int thisReading4 = 0; thisReading4 < numReadings4; thisReading4++) {
    readings4[thisReading4] = 0;
  }
  
}

void loop()
{
    // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;



    // subtract the last reading:
  total2 = total2 - readings2[readIndex2];
  // read from the sensor:
  readings2[readIndex2] = analogRead(inputPin2);
  // add the reading to the total:
  total2 = total2 + readings2[readIndex2];
  // advance to the next position in the array:
  readIndex2 = readIndex2 + 1;

  // if we're at the end of the array...
  if (readIndex2 >= numReadings2) {
    // ...wrap around to the beginning:
    readIndex2 = 0;
  }

  // calculate the average:
  average2 = total2 / numReadings2;


    // subtract the last reading:
  total3 = total3 - readings3[readIndex3];
  // read from the sensor:
  readings3[readIndex3] = analogRead(inputPin3);
  // add the reading to the total:
  total3 = total3 + readings3[readIndex3];
  // advance to the next position in the array:
  readIndex3 = readIndex3 + 1;

  // if we're at the end of the array...
  if (readIndex3 >= numReadings3) {
    // ...wrap around to the beginning:
    readIndex3 = 0;
  }

  // calculate the average:
  average3 = total3 / numReadings3;

      // subtract the last reading:
  total4= total4 - readings4[readIndex4];
  // read from the sensor:
  readings4[readIndex4] = analogRead(inputPin4);
  // add the reading to the total:
  total4 = total4 + readings4[readIndex4];
  // advance to the next position in the array:
  readIndex4 = readIndex4 + 1;

  // if we're at the end of the array...
  if (readIndex4 >= numReadings4) {
    // ...wrap around to the beginning:
    readIndex4 = 0;
  }

  // calculate the average:
  average4 = total4 / numReadings4;

  
  // send it to the computer as ASCII digits
  Serial.println(average3);
  delay(1);        // delay in between reads for stability
 // int distance = sensor.getDistance(); //Calculate the distance in centimeters and store the value in a variable
  //  int distance2 = sensor2.getDistance(); //Calculate the distance in centimeters and store the value in a variable
   //   int distance3 = sensor3.getDistance(); //Calculate the distance in centimeters and store the value in a variable
    //    int distance4 = sensor4.getDistance(); //Calculate the distance in centimeters and store the value in a variable

 // Serial.print("Mean distance: ");
 // Serial.print(distance3);
 // Serial.println(" cm");
   // Serial.println( distance2 ); //Print the value to the serial monitor
  //    Serial.println( distance3 ); //Print the value to the serial monitor
   //     Serial.println( distance4 ); //Print the value to the serial monitor
if(average > 100) {
    Joystick.button(1,1); 
}
else {
    Joystick.button(1,0);
}
if(average2 > 100) {
    Joystick.button(2,1);
}
else {
    Joystick.button(2,0);
}
if(average3 > 100) {
    Joystick.button(3,1);
}
else {
    Joystick.button(3,0);
}
if(average4 > 100) {
    Joystick.button(4,1);
}
else {
    Joystick.button(4,0);
}
  delay(1); 
}
