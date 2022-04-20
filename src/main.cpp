#include "node.h"
#include "sensor.h"
#include "serial.h"

const int BAUD_RATE = 9600;

HX711ForceSensor sensor;
Newton::ArduinoSerialHandle serial_handle = Newton::ArduinoSerialHandle();
Newton::Node node(serial_handle, sensor);

void setup(void)
{
    Serial.begin(BAUD_RATE);
    sensor.begin();
}

void loop(void)
{
    node.update();
}

// notify listeners via this interrupt...
void serialEvent(void)
{
    (*serial_handle.callback())();
}