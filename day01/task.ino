#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String voltage_input = "";
#define TEXT_PIN 7

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    Serial.begin(9600);
    analogWrite(TEXT_PIN, 0);
}

void loop() {

    int sensorValue = analogRead(A0);
    delay(200);

    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);
    lcd.setCursor(0,0);
    lcd.print(voltage);

    // BONUS
    // Serial.println("Enter the voltage");
    // while (Serial.available() == 0)
    //   ;
    // voltage_input = Serial.readString();
    // lcd.clear();
    // float voltage_converted = float(voltage_input.toInt()%256) / 255 * 5;
    // lcd.print(voltage_converted);
    // analogWrite(9, voltage_input.toInt()%256);
}