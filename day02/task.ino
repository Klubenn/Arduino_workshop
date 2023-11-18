#include <Servo.h>

Servo myservo;
typedef struct s_sensors
{
    unsigned int L;
    unsigned int M;
    unsigned int R;
}               t_sensors;

typedef struct s_sensors
{
    unsigned int ;
    unsigned char sensor_position;
}               t_sensors;

typedef struct s_sectors
{
    bool s0;
    bool s1;
    bool s2;
    bool s3;
    bool s4;
    bool s5;
    bool s6;
    bool s7;
    bool s8;
}           t_sectors;

const int servo_pin = 9;

int pos = 0;                              // variable to store the servo position
int middle_sensor_pin = A1;               // photoresistor0
int left_sensor_pin = A0;                 // photoresistor1
int right_sensor_pin = A2;                // photoresistor2

int middle_sensor_value = 0;
int left_sensor_value = 0;
int right_sensor_value = 0;
t_sensors sensors = {0};
void setup() {

    myservo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
    Serial.begin(9600);
}

void loop() {
    sensors.M = analogRead(middle_sensor_pin);
    sensors.L = analogRead(left_sensor_pin);
    sensors.R = analogRead(right_sensor_pin);

    int brightest = std::max();
    Serial.print(sensors.L);
    Serial.print(" - ");
    Serial.print(sensors.M);
    Serial.print(" - ");
    Serial.print(sensors.R);
    Serial.println();

    pos = map(sensors.M, 0, 1023, 0, 180);        //angle
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

