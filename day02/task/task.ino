#include <Servo.h>

#define LEFT    0
#define MIDDLE  1
#define RIGHT   2

typedef struct s_sensors {
    unsigned int  value;                              // value of analog read
    unsigned int  brightness;                         // bright (0) -> midium (1) -> dim (2)
    unsigned char sensor_id;                          // left 'L', middle 'M' and right 'R' sensor
}   t_sensors;

enum Brightness {
  bright,
  midium,
  dim
};

typedef struct s_sectors {
    bool s0;
    bool s1;
    bool s2;
    bool s3;
    bool s4;
    bool s5;
    bool s6;
    bool s7;
    bool s8;
}   t_sectors;


/*  variables  */

const int servo_pin = 9;
const int middle_sensor_pin = A1;                       // photoresistor0
const int left_sensor_pin = A0;                         // photoresistor1
const int right_sensor_pin = A2;                        // photoresist or2
int pos = 0;                                            // variable to store the servo position

Servo myservo;
enum Brightness Levels;
t_sensors sensors[3] = {0};


/*  functions  */

void sort_brightest();

void setup() {

    myservo.attach(servo_pin);                            // attaches the servo on pin 9 to the servo object
    Serial.begin(9600);
    
    sensors[LEFT].sensor_id = 'L'; 
    sensors[MIDDLE].sensor_id = 'M'; 
    sensors[RIGHT].sensor_id = 'R'; 
}

void loop() {
    sensors[MIDDLE].value = analogRead(middle_sensor_pin);
    sensors[LEFT].value = analogRead(left_sensor_pin);
    sensors[RIGHT].value = analogRead(right_sensor_pin);

    // find the highest value
    sort_brightest();
    // check the diff between 2nd and the rest


    // Serial.print(sensors.L);
    // Serial.print(" - ");
    // Serial.print(sensors.M);
    // Serial.print(" - ");
    // Serial.print(sensors.R);
    // Serial.println();

    // pos = map(sensors.M, 0, 1023, 0, 180);        //value
    // myservo.write(pos);
    Serial.println(pos);
    Serial.println();

    // myservo.write(180);
    // delay(1000);
    // myservo.write(0);
    // delay(1000);
    // delay(1000);

    delay(2000);
}

void sort_brightest() {

  if (sensors[MIDDLE].value >= sensors[LEFT].value && sensors[MIDDLE].value >= sensors[RIGHT].value) {
      sensors[MIDDLE].brightness = bright;
    
      if (sensors[LEFT].value >= sensors[RIGHT].value) {
        sensors[LEFT].brightness = midium;
        sensors[RIGHT].brightness = dim;
      } else {
        sensors[LEFT].brightness = dim;
        sensors[RIGHT].brightness = midium;
      }
  }
  else if (sensors[LEFT].value > sensors[MIDDLE].value && sensors[LEFT].value > sensors[RIGHT].value) {
      sensors[LEFT].brightness = bright;
      
      if (sensors[MIDDLE].value >= sensors[RIGHT].value) {
        sensors[MIDDLE].brightness = midium;
        sensors[RIGHT].brightness = dim;
      } else {
        sensors[MIDDLE].brightness = dim;
        sensors[RIGHT].brightness = midium;
      }
  }
  else {
      sensors[RIGHT].brightness = bright;
   
      if (sensors[LEFT].value >= sensors[MIDDLE].value) {
        sensors[LEFT].brightness = midium;
        sensors[MIDDLE].brightness = dim;
      } else {
        sensors[LEFT].brightness = dim;
        sensors[MIDDLE].brightness = midium;
      }
  }
}
