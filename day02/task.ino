// #include <Servo.h>
// #include <stdlib.h>

// typedef struct  s_sens
// {
//         int             brightness;
//         char    position;
// }

// Servo myservo_upper;
// Servo myservo_lower;
// const int servo_pin1 = 9;
// const int servo_pin2 = 10;
// int pos = 0;                              // variable to store the servo position
// int middle_sensor_pin = A1;               // photoresistor0
// int left_sensor_pin = A0;                 // photoresistor1
// int right_sensor_pin = A2;                // photoresistor2
// t_sens One, Three, Two = {0};

// void setup() {
//         myservo_upper.attach(servo_pin1);  // attaches the servo on pin 9 to the servo object
//         myservo_lower.attach(servo_pin2);  // attaches the servo on pin 9 to the servo object
//         Serial.begin(9600);
// }


// #define DELIMITER 0.3
// #define LEFT    1
// #define MIDDLE  2
// #define RIGHT   3

// typedef struct  s_sens
// {
//         int     brightness;
//         int     position;
// }                               t_sens;

// int position_upper = 0;
// int position_lower = 0;

// void scan()
// {
//   for (int i = 0; i <= 180; i++)
//   {
//     myservo_upper.write(i);
//     if (Three.brightness - One.brightness < 0)
//       break;
//   }
// }


// void loop() {
//   // while(1)
//   // {
//   //   myservo_upper.write(0);
//   //   myservo_lower.write(0);
//   // }
//   scan();
//   // for (int i = 0; i <= 180; i++)
//   // {
//   //   myservo_upper.write(i);
//   //   myservo_lower.write(i);
//   //   delay(20);
//   // }
//   // for (int i = 180; i >= 0; i--)
//   // {
//   //   myservo_upper.write(i);
//   //   myservo_lower.write(i);
//   //   delay(20);
//   // }



//         One.brightness = analogRead(left_sensor_pin);
//         Two.brightness = analogRead(middle_sensor_pin);
//         Three.brightness = analogRead(right_sensor_pin);
//         One.position = LEFT;
//         Two.position = MIDDLE;
//         Three.position = RIGHT;

//         Serial.print(One.brightness);
//         Serial.print(" - ");
//         Serial.print(Two.brightness);
//         Serial.print(" - ");
//         Serial.print(Three.brightness);
//         Serial.println();

//         // calculate_distance();

//         delay(500);

// }



#include <Servo.h>
#include <stdlib.h>

Servo myservo_upper;
Servo myservo_lower;
const int servo_pin1 = 9;
const int servo_pin2 = 10;
int pos = 0;                              // variable to store the servo position
int middle_sensor_pin = A1;               // photoresistor0
int left_sensor_pin = A0;                 // photoresistor1
int right_sensor_pin = A2;                // photoresistor2


typedef struct  s_sens
{
    int             brightness;
    char    position;
}                               t_sens;

t_sens One, Three, Two = {0};

void setup() {
    myservo_upper.attach(servo_pin1);  // attaches the servo on pin 9 to the servo object
    myservo_lower.attach(servo_pin2);  // attaches the servo on pin 9 to the servo object
    Serial.begin(9600);
}

int position_upper = 0;
int position_lower = 0;


void loop()
{
    // while(1)
    // {
    //   myservo_upper.write(position_upper);
    //   myservo_lower.write(position_lower);
    // }

    // while(1)
    // {
    //   for (int i = 0; i <= 180; i++)
    //   {
    //     // myservo_upper.write(i);
    //     myservo_lower.write(i);
    //     delay(20);
    //   }
    //   for (int i = 180; i >= 0; i--)
    //   {
    //     // myservo_upper.write(i);
    //     myservo_lower.write(i);
    //     delay(20);
    //   }
    // }


    Two.brightness = analogRead(middle_sensor_pin);
    One.brightness = analogRead(left_sensor_pin);
    Three.brightness = analogRead(right_sensor_pin);

    Serial.print(One.brightness);
    Serial.print(" - ");
    Serial.print(Two.brightness);
    Serial.print(" - ");
    Serial.print(Three.brightness);
    Serial.println();

    if (Three.brightness - One.brightness > 20 && position_upper < 180)
        position_upper += 1;
    if (Three.brightness - Two.brightness > 20 && position_lower < 180)
        position_lower += 1;
    if (Two.brightness - One.brightness > 20 && position_lower < 180)
        position_lower += 1;

    if (Three.brightness - One.brightness < 0 && position_upper > 0)
        position_upper -= 1;
    if (Three.brightness - Two.brightness < 0 && position_lower > 0)
        position_lower -= 1;
    if (Two.brightness - One.brightness < 0 && position_lower > 0)
        position_lower -= 1;

    myservo_upper.write(position_upper);
    myservo_lower.write(position_lower);

    delay(40);

}
