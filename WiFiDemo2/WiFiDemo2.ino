#include <WiFiController.h>

WiFiController* mpController;

void setup() 
{
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("process start");
  //mpController = new WiFiController(11, 12, "aterm-a6ce7e-g", "49c2c1903e584");
  mpController = new WiFiController(11, 12, "aterm-adb403-g", "6045a3bd50d50");
  mpController->setup();
}

void loop() 
{
  mpController->reqURL("ntp-a1.nict.go.jp", "GET /cgi-bin/json HTTP/1.1\r\nHost: ntp-a1.nict.go.jp\r\n\r\n");
  for (int i = 0, i_max = mpController->getBufferSize(); i < i_max; ++i)
  {
    Serial.print(static_cast<char>(mpController->getBuffer()[i]));
  }
  Serial.println();
  delay(2000);
}
