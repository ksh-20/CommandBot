#include <WiFi.h>
#include "conf.h"

// For Motors
#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 10

// For Ultrasonic Sensor
#define TRIG 2
#define ECHO 3

// For WiFi
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
    delay(1000);

  server.begin();
  stopRobot();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) 
    return;

  String cmd = client.readStringUntil('\n');
  cmd.trim();
  cmd.toUpperCase();

  long distance = getDistance();

  if (distance < 20 && cmd == "FORWARD") {
    stopRobot();
    client.println("Obstacle detected");
  } else {
    execute(cmd);
    client.println("Executed: " + cmd);
  }

  client.stop();
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  return duration * 0.034 / 2;
}

void execute(String cmd) {
  if (cmd == "FORWARD") 
    forward();
  else if (cmd == "BACKWARD")
    backward();
  else if (cmd == "LEFT")
    left();
  else if (cmd == "RIGHT")
    right();
  else
    stopRobot();
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}