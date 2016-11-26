#include <HttpClientController.h>

HttpClientController* mpController;

void setup() 
{
  Serial.begin(9600);
  mpController = new HttpClientController(11, 12, "aterm-a6ce7e-g", "49c2c1903e584");
  mpController->setup();
}

void loop() 
{
  while (mpController->update() == HttpClientController::Process)
  {
    Serial.println(mpController->getState());
    return;
  }
  Serial.println(mpController->getState());

  /*
  switch(mpController->update())
  {
    case HttpClientController::Process:
    {
      Serial.println(mpController->getState());
      return;
    }
    case HttpClientController::Succeeded:
    {
      Serial.println("http connected");  
    }
    case HttpClientController::Failed:
    {
      Serial.println("http failed");
      return;
    }
  }
  */

  mpController->get("www.google.com", "/");
  Serial.println(mpController->responseStatusCode() >= 0 ? "get succeeded" : "get failed");
}
