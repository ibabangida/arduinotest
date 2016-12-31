#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 12);

void setup()
{
  Serial.begin(115200);
  while (!Serial) {}
  mySerial.begin(115200);
  while (!mySerial) {}
}

void loop()
{
  if(mySerial.available()) Serial.write(mySerial.read());
  if (Serial.available()) mySerial.write(Serial.read());
}

