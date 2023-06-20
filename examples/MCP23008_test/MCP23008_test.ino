//
//    FILE: MCP23008_test.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2023-06-20
// PUPROSE: test MCP23008 library


#include "MCP23008.h"
#include "Wire.h"

MCP23008 MCP(0x22);

void setup()
{
  Serial.begin(115200);
  Serial.print("MCP23008_test version: ");
  Serial.println(MCP23008_LIB_VERSION);

  Wire.begin();
  MCP.begin();

  MCP.pinMode8(0x00);    // 0 = output , 1 = input
  uint8_t value = mcp.getPinMode8();
  Serial.println(value, HEX);

  MCP.pinMode8(0xFF);
  value = mcp.getPinMode8();
  Serial.println(value, HEX);

  Serial.println();
  for (int i = 0; i < 8; i++)
  {
    mcp.pinmode(i, OUTPUT);
    value = mcp.getPinMode8();
    Serial.println(value, HEX);
  }

  Serial.println();
  for (int i = 0; i < 8; i++)
  {
    mcp.pinmode(i, INPUT);
    value = mcp.getPinMode8();
    Serial.println(value, HEX);
  }

  Serial.println();
  for (int i = 0; i < 8; i++)
  {
    mcp.pinmode(i, OUTPUT);
    value = mcp.getPinMode8();
    Serial.println(value, HEX);
  }

  Serial.println();
  for (int i = 0; i < 8; i++)
  {
    mcp.pinmode(i, INPUT_PULLUP);
    value = mcp.getPinMode8();
    Serial.println(value, HEX);
  }

  Serial.println();
}


void loop()
{
}


// -- END OF FILE --
