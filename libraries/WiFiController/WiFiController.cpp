#include "WiFiController.h"
#include <ESP8266.h>

WiFiController::WiFiController(int rx_pin, int tx_pin, const char* p_ssid, const char* p_password, uint32_t buffer_size)
  : mpSSID(p_ssid)
  , mpPassword(p_password)
  , mMaxBufferSize(buffer_size)
  , mBufferSize(0)
{
  // WiFi setup
  mpSerial = new SoftwareSerial(rx_pin, tx_pin);
  mpSerial->begin(9600);
  while (!(*mpSerial)) {}
  mpWiFi = new ESP8266(*mpSerial, 9600);

  // buffer setup
  mpBuffer = new uint8_t[mMaxBufferSize];
  memset(mpBuffer, 0, mMaxBufferSize);
}

bool WiFiController::setup()
{
  Serial.println("setup start.");

  if (mpWiFi->setOprToStationSoftAP()) 
  {
    Serial.println("setOprToStation succeeded.");
  } 
  else 
  {
    Serial.println("setOprToStation failed.");
    return false;
  }

  if (mpWiFi->joinAP(mpSSID, mpPassword)) 
  {
    Serial.println("joinAP succeeded.");
    Serial.println("---- ip information ----");
    Serial.println(mpWiFi->getLocalIP().c_str());
    Serial.println("------------------------");
  } 
  else 
  {
    Serial.println("joinAP failed.");
    return false;
  }
  
  if (mpWiFi->disableMUX())
  {
    Serial.println("disableMUX succeeded.");
  }
  else
  {
    Serial.println("disableMUX failed.");
    return false;
  }

  Serial.println("setup end.");
  return true;
}

bool WiFiController::reqURL(const char* p_host, const char* p_get_request, uint8_t port)
{
  // connect
  if (mpWiFi->createTCP(p_host, port))
  {
    Serial.println("createTCP succeeded.");
  }
  else
  {
    Serial.println("createTCP failed.");
    return false;
  }

  // get request
  mpWiFi->send(reinterpret_cast<const uint8_t*>(p_get_request), strlen(p_get_request));
  
  // receive
  mBufferSize = mpWiFi->recv(mpBuffer, mMaxBufferSize, 10000);
  Serial.print("recv size[");
  Serial.print(mBufferSize);
  Serial.println("]");

  // release
  if (mpWiFi->releaseTCP())
  {
    Serial.println("releaseTCP succeeded.");
  }
  else
  {
    Serial.println("releaseTCP failed.");
    return false;
  }

  return true;
}
