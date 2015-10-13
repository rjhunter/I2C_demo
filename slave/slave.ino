#include <Wire.h>

const int red_led = 6;
const int green_led = 5;
const int max_val = 192;
int counter = 0;

void setup()
{
    pinMode(red_led, OUTPUT);
    pinMode(green_led, OUTPUT);
    Wire.begin(8);                // join i2c bus with address #8
    Wire.onReceive(receiveEvent); // register event
    //Serial.begin(9600);
}

void loop()
{
    analogWrite(red_led, counter);
    analogWrite(green_led, max_val - counter);
    //Serial.println(counter, DEC);
}

void receiveEvent(int nbytes)
{
    while (Wire.available())
        counter = Wire.read();
}
