#include <arduino.h>
#pragma once

class ESP8266;
class SoftwareSerial;

class WiFiController
{
public:
  /// Constructor
  explicit WiFiController(int rx_pin, int tx_pin, const char* p_SSID, const char* p_password, uint32_t buffer_size = 1024);

  /// Setup
  bool setup();

  /// Get Content
  bool reqURL(const char* p_host, const char* p_get_request, uint8_t port = 80);

  /// Get Buffer
  const uint8_t* getBuffer() const { return mpBuffer; }

  /// Get Buffer Size
  uint32_t getBufferSize() const { return mBufferSize; }

private:
  char* mpSSID;
  char* mpPassword;
  ESP8266* mpWiFi;
  SoftwareSerial* mpSerial;
  uint8_t* mpBuffer;
  uint32_t mMaxBufferSize;
  uint32_t mBufferSize;
};
