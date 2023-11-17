/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int sensorPinM = A1; // photoresistor0
int sensorPinL = A0; // photoresistor1
int sensorPinR = A2; // photoresistor2
int sensorValueM = 0;
int sensorValueL = 0;
int sensorValueR = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  sensorValueM = analogRead(sensorPinM);
  sensorValueL = analogRead(sensorPinL);
  sensorValueR = analogRead(sensorPinR);
  Serial.print(sensorValueL);
  Serial.print(" - ");
  Serial.print(sensorValueM);
  Serial.print(" - ");
  Serial.print(sensorValueR);
  Serial.println();

  pos = map(sensorValueM, 0, 1023, 0, 180);
  myservo.write(pos);
  Serial.println(pos);
  Serial.println();
  
  delay(1000);

  // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //   // in steps of 1 degree
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }
  // delay(20);
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }
  // delay(20);

}
