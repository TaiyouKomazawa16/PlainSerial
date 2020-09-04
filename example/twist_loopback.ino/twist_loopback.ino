#include "PlainSerial.h"
#include "PlaneTwist.h"

PlaneTwist twist;
PlainSerial uart(&Serial);

void setup()
{
  Serial.begin(9600);
  uart.add_frame(&twist);
}

void loop()
{
  if (uart.read() == 0)
  {
    uart.write(0, &twist);
  }
  delay(18);
}
