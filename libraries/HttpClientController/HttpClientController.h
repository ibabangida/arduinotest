#include <arduino.h>
#pragma once

class HttpClient_ESP8266_AT;

class HttpClientController
{
public:
  enum EState
  {
    StateNone,
    StateProcAT,
    StateProcAP,
    StateProcWiFi,
    StateConnected
  };

  enum EProcessState
  {
    Process,
    Succeeded,
    Failed,
  };

public:
  /// Constructor
  explicit HttpClientController(int rx_pin, int tx_pin, const char* p_SSID, const char* p_password, int wait_sec = 30 * 1000);

  /// Setup
  void setup();

  /// Update, After Call Setup Until Connection Fixed
  int update();

  /// Get
  void get(const char* p_url, const char* p_path);

  /// Response Status Code
  int responseStatusCode();

  /// Get State
  int getState() const { return mState; }

private:
  char* mpSSID;
  char* mpPassword;
  int mWaitSec;
  int mProcStartSec;
  EState mState;
  HttpClient_ESP8266_AT* mpClient;
};
