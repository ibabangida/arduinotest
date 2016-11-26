#include "HttpClientController.h"
#include <HttpClient_ESP8266_AT.h>

HttpClientController::HttpClientController(int rx_pin, int tx_pin, const char* p_ssid, const char* p_password, int wait_sec)
  : mpSSID(p_ssid)
  , mpPassword(p_password)
  , mWaitSec(wait_sec)
  , mProcStartSec(0)
  , mState(StateNone)
{
  mpClient = new HttpClient_ESP8266_AT(rx_pin, tx_pin);
}

void HttpClientController::setup()
{
  mProcStartSec = millis(); 
  mState = StateProcAT;
}

int HttpClientController::update()
{
  if (mProcStartSec != 0 && millis() - mProcStartSec > mWaitSec)
  {
    mState = StateNone;    
    mProcStartSec = 0;
    return Failed;
  }

  switch(mState)
  {
    case StateNone:
    case StateConnected:
    {
      return Succeeded;
    }
    case StateProcAT:
    {
      if (mpClient->statusAT()) mState = StateProcAP;
    }
    break;
    case StateProcAP:
    {
      if (mpClient->connectAP(mpSSID, mpPassword)) mState = StateProcWiFi;
    }
    break;
    case StateProcWiFi:
    {
      if (mpClient->statusWiFi()) 
      {
        mState = StateConnected;
        mProcStartSec = 0;
        return Succeeded;
      }
    }
    break;
    default: break;
  }

  return Process;
}

void HttpClientController::get(const char* p_url, const char* p_path)
{
  mpClient->get(p_url, p_path);
}

int HttpClientController::responseStatusCode()
{
  return mpClient->responseStatusCode();
}
