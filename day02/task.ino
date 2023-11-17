#include <Servo.h>

Servo myservo;

const int servo_pin = 9;

int pos = 0;                              // variable to store the servo position
int middle_sensor_pin = A1;               // photoresistor0
int left_sensor_pin = A0;                 // photoresistor1
int right_sensor_pin = A2;                // photoresistor2

int middle_sensor_value = 0;
int left_sensor_value = 0;
int right_sensor_value = 0;

void setup() {
  myservo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {

  middle_sensor_value = analogRead(middle_sensor_pin);
  left_sensor_value = analogRead(left_sensor_pin);
  right_sensor_value = analogRead(right_sensor_pin);
  Serial.print(left_sensor_value);
  Serial.print(" - ");
  Serial.print(middle_sensor_value);
  Serial.print(" - ");
  Serial.print(right_sensor_value);
  Serial.println();

  pos = map(middle_sensor_value, 0, 1023, 0, 180);
  // myservo.write(pos);
  Serial.println(pos);
  Serial.println();
  
  // myservo.write(180);
  // delay(1000);
  // myservo.write(-180);
  // delay(1000);
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
  delay(20);

}

