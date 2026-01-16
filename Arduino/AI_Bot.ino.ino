// Kindly ignore this file, it is work in progress. Use the robot_control.ino file instead.

#include <ArduinoBearSSL.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <AIChatbot.h>

AiChatbot chatbot;

static const char *ssid = "<WIFI_SSID>";
static const char *password = "<WIFI_PW>";

WiFiClient client;
BearSSLClient sslClient(client);
ChatGPT<BearSSLClient> chat_gpt(&sslClient, "v1", "<OpenAI_API_KEY>");

int status = WL_IDLE_STATUS;

unsigned long getTime() {
  return WiFi.getTime();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  if (WiFi.status() == WL_NO_SHIELD)
    return;

  chatbot.begin(115200);

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    status = WiFi.begin(ssid, password);
    delay(1000);
  }
  Serial.println("Connected!");

  // Disable Server Name Indication:
  // for testing purposes only
  sslClient.setInsecure(BearSSLClient::SNI::Insecure);

  ArduinoBearSSL.onGetTime(getTime);
    
  // Set API keys
  chatbot.setKey("YOUR_CHATGPT_API_KEY", "chatgpt");

  // Connect to WiFi
  if (!chatbot.connectWiFi("SSID", "PASSWORD")) {
      Serial.println("Failed to connect to WiFi");
      while (true); // Halt if WiFi connection fails
  }
    
  // Select AI service and optionally specify version
  chatbot.selectAI("chatgpt", "gpt-3.5-turbo");

}

void loop() {
  // put your main code here, to run repeatedly:
  chatbot.update();
}