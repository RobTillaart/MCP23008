//
//    FILE: MCP23008_performance.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2022-01-09
// PUPROSE: test MCP23008 library


#include "MCP23008.h"
#include "Wire.h"

MCP23008 MCP(0x27);

uint32_t start, stop;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.print("MCP23008_LIB_VERSION: ");
  Serial.println(MCP23008_LIB_VERSION);
  Serial.println();
  delay(100);

  Wire.begin();
  bool b = MCP.begin();

  MCP.pinMode8(0x00);  // 0 = output , 1 = input

  Serial.println("\ntime in microseconds\n");
  delay(100);


  Serial.print("TEST digitalWrite(0, value):\t");
  delay(100);
  start = micros();
  for (int i = 0; i < 8; i++)
  {
    MCP.digitalWrite(i, i & 0x01);  // alternating HIGH/LOW
  }
  stop = micros();
  Serial.println((stop - start) / 8.0);


  Serial.print("TEST digitalWrite(pin, value):\t");
  delay(100);
  start = micros();
  for (int pin = 0; pin < 8; pin++)
  {
    MCP.digitalWrite(pin, 1 - pin % 2); // alternating HIGH/LOW
  }
  stop = micros();
  Serial.println((stop - start) / 8.0);


  Serial.print("TEST digitalRead(pin):\t");
  delay(100);
  start = micros();
  for (int pin = 0; pin < 8; pin++)
  {
    volatile int val = MCP.digitalRead(pin);
  }
  stop = micros();
  Serial.println((stop - start) / 8.0);
  Serial.println();


  //////////////////////////////////////////////////
  //
  // write8 read8 interface
  //
  Serial.print("TEST write8(mask):\t");
  delay(100);
  start = micros();
  MCP.write8(0xAA); // alternating HIGH/LOW
  stop = micros();
  Serial.println(stop - start);


  Serial.print("TEST read8():\t");
  delay(100);
  start = micros();
  volatile int val8 = MCP.read8();
  stop = micros();
  Serial.println(stop - start);
  Serial.println();

  Serial.println("\ndone...");
}


void loop()
{
}


// -- END OF FILE --
