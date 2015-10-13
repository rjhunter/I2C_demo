#include <Wire.h>

const int analog_pin = 3;
const int red_led = 6;
const int green_led = 5;
const int max_val = 192;
const int step = 16;
int counter = 0;
int current_step = step;
void setup()
{
    Wire.begin();        // join i2c bus (address optional for master)
    pinMode(red_led, OUTPUT);
    pinMode(green_led, OUTPUT);

    //Serial.begin(9600);  // start serial for output
}

void loop()
{
    counter = counter + current_step;

    if (counter < 0) {
        current_step = step;
        counter = 0;
    } else if (counter > max_val) {
        current_step = -step;
        counter = max_val;
    }

    analogWrite(red_led, counter);
    analogWrite(green_led, max_val-counter);

    Wire.beginTransmission(8); // transmit to device #8
    Wire.write((unsigned char)counter);
    Wire.endTransmission();    // stop transmitting

    int delay_value = analogRead(analog_pin);
    delay(delay_value);

    // Serial.print("Current state: ");
    // Serial.println(counter);
    // Serial.print("Current delay: ");
    // Serial.println(delay_value);
}
