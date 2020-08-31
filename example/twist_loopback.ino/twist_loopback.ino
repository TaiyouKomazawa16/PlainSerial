#include "PlainSerial.h"
#include "PlaneTwist.h"

PlaneTwist twist;
Float32 f;
PlainSerial uart(&Serial);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (uart.read(1, &twist) == 0)
  {
    uart.write(1, &twist);
  }
  delay(18);
}
