#include <HttpClientController.h>

HttpClientController* mpController;

void setup() 
{
  Serial.begin(9600);
  Serial.println("hage");
  //mpController = new HttpClientController(11, 12, "aterm-a6ce7e-g", "49c2c1903e584");
  //mpController = new HttpClientController(11, 12, "aterm-adb403-a", "6045a3bd50d50");
  //mpController->setup();
}
 
void loop() 
{
  return;
  while (mpController->update() == HttpClientController::Process)
  {
    Serial.println(mpController->getState());
    return;
  }
  //Serial.println(mpController->getState());
  
  //mpController->get("ja.wikipedia.org", "/wiki/Uniform_Resource_Locator");
  //Serial.println(mpController->responseStatusCode());
  //Serial.println(mpController->responseStatusCode() >= 0 ? "get succeeded" : "get failed");
}
