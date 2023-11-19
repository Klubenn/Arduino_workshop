#include <Servo.h>
#include <stdlib.h>

Servo myservo;
const int servo_pin = 9;
int pos = 0;                              // variable to store the servo position
int middle_sensor_pin = A1;               // photoresistor0
int left_sensor_pin = A0;                 // photoresistor1
int right_sensor_pin = A2;                // photoresistor2


#define DELIMITER 0.2
#define LEFT	1
#define MIDDLE	2
#define RIGHT	3

typedef struct	s_sens
{
	int		brightness;
	char	position;
}				t_sens;

enum
{
	MR 	= 0,
	MRR = 30,
	R 	= 60,
	RRL = 90,
	RL 	= 120,
	RLL = 150,
	L 	= 180,
	LLM = 210,
	LM 	= 240,
	LMM = 270,
	M 	= 300,
	MMR = 330,
};

t_sens Left, Right, Middle = {0};
int dist_0_1, dist_1_2, dist_0_2 = 0;
int sector = -1;

void setup() {
	myservo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
	Serial.begin(9600);
}

int cmpfunc (const void * a, const void * b)
{
	t_sens *sens1 = (t_sens *)a;
	t_sens *sens2 = (t_sens *)b;
	if (sens2->brightness == sens1->brightness)
		sens1->brightness += 1;
	return (sens2->brightness - sens1->brightness);
}

void turn_motor()
{
	if (sector >= 180)
		sector -= 180;
	myservo.write(sector);
}

void calculate_distance()
{
	t_sens sens[] = {Left, Middle, Right};
	qsort(sens, 3, sizeof(t_sens), cmpfunc);
	qsort(sens, 3, sizeof(t_sens), cmpfunc);
	dist_0_1 = sens[0].brightness - sens[1].brightness;
	dist_1_2 = sens[1].brightness - sens[2].brightness;
	dist_0_2 = sens[0].brightness - sens[2].brightness;
	if (dist_0_1 > dist_1_2)
	{
		if ((float)dist_0_1 / (float)dist_0_2 > DELIMITER)
		{
			// sectors R, L, M
			if (sens[0].position == RIGHT)
				sector = R;
			else if (sens[0].position == LEFT)
				sector = L;
			else
				sector = M;
		}
		else
		{
			//sectors MRR, RRL, RLL, LLM, LMM, MMR
			if (sens[0].position == RIGHT)
			{
				if (sens[1].position == MIDDLE)
					sector = MRR;
				else // if (sens[1].position == LEFT)
					sector = RRL;
			}
			else if (sens[0].position == LEFT)
			{
				if (sens[1].position == RIGHT)
					sector = RLL;
				else // if (sens[1].position == MIDDLE)
					sector = LLM;
			}
			else // if (sens[0].position == MIDDLE)
			{
				if (sens[1].position == LEFT)
					sector = LMM;
				else // if (sens[1].position == RIGHT)
					sector = MMR;
			}
		}
	}
	else
	{
		// sectors RL, LM, MR
		if ((sens[0].position == LEFT && sens[1].position == RIGHT) ||
			(sens[1].position == LEFT && sens[0].position == RIGHT))
			sector = RL;
		else if ((sens[0].position == LEFT && sens[1].position == MIDDLE) ||
				 (sens[1].position == LEFT && sens[0].position == MIDDLE))
			sector = LM;
		else
			sector = MR;
	}

	turn_motor();
}

void loop() {
	Middle.brightness = analogRead(middle_sensor_pin);
	Left.brightness = analogRead(left_sensor_pin);
	Right.brightness = analogRead(right_sensor_pin);
	Left.position = LEFT;
	Right.position = RIGHT;
	Middle.position = MIDDLE;

	Serial.print(Left.brightness);
	Serial.print(" - ");
	Serial.print(Middle.brightness);
	Serial.print(" - ");
	Serial.print(Right.brightness);
	Serial.println();

	calculate_distance();

	delay(2000);

}