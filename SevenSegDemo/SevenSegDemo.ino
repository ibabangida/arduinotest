#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_7segment* p_7seg = nullptr;

void setup()
{
  p_7seg = new Adafruit_7segment();
  p_7seg->begin(0x70);
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i <= 9999; ++i)
  {
    Serial.println(i);
    p_7seg->print(i, 10);
    p_7seg->writeDisplay();
    delay(1000); 
  }
}
