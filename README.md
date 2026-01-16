# 🤖 CommandBot - An AI-Powered Voice-Controlled Robot

A smart **voice-controlled robot** powered by **Google Gemini AI**, capable of understanding natural language voice commands, responding with speech, and safely navigating using obstacle detection — all communicated wirelessly over **WiFi**.

This project follows a **hybrid AI + embedded systems architecture**, where high-level intelligence runs on a computer and real-time motor control runs on the robot.

---

## ✨ Features

- 🎤 Voice control using speech recognition
- 🧠 Gemini AI for natural language understanding
- 📶 WiFi communication (no serial cable needed)
- 🔊 Text-to-speech robot feedback
- 🚧 Obstacle detection and avoidance
- 🤖 Hybrid AI + sensor-based control

---

## 🧠 System Architecture

```bash
Voice Input (Microphone)
↓
Speech Recognition (Python)
↓
Gemini AI (Command Understanding)
↓
WiFi Command (TCP/IP)
↓
Robot Controller (ESP32 / Arduino)
↓
Obstacle Check (Ultrasonic Sensor)
↓
Motor Control + Voice Feedback
```

> AI decides **WHAT** to do, sensors decide **IF** it’s safe  
> (Hybrid Reactive–Deliberative Control)

---

## 🛠️ Hardware Requirements

- ESP32 / Arduino with WiFi
- L298N motor driver
- DC motors and robot chassis
- Ultrasonic sensor (HC-SR04)
- Battery / power supply
- Laptop or PC with microphone

---

## 🧰 Software & Technologies

### Embedded Side

- Arduino / ESP32
- WiFi TCP server
- Ultrasonic sensor interface
- Motor control logic

### AI & Control Side

- Python 3.12
- Google Gemini API
- SpeechRecognition
- pyttsx3 (text-to-speech)
- Socket programming (WiFi)

---

## 📁 Project Structure

```bash
CommandBot/
│
├── Arduino/
│ └── robot_wifi_ai.ino
│
├── Python/
│ ├── voice_assistant.py
│ ├── gemini_api.py
│ ├── tts.py
│ ├── requirements.txt
│
├── .gitignore
└── README.md
```

---

## Getting Sarted

### **For Arduino Code: All Libraries are available inside Arduino Library Manager**

- Arduino IDE ([https://www.arduino.cc/en/software](https://www.arduino.cc/en/software))
- ArduinoJson library ([https://arduinojson.org/](https://arduinojson.org/))
- ArduinoBearSSL library ([invalid URL removed]) (optional, for secure communication)
- ChatGPT library (`ChatGPT.hpp`) (download or implement your own)

### **For Python Code: Enter a virtual environment and install the libraries**

- Python 3.x ([https://www.python.org/downloads/](https://www.python.org/downloads/))
- SpeechRecognition library (`pip install SpeechRecognition`)
- PyTextToSpeech library (`pip install pyttsx3`)
- webbrowser library (included in standard library)

---

## ⚙️ Setup Instructions

### 1️⃣ Arduino / ESP32 Setup

1. Open `Arduino/robot_wifi_ai.ino`
2. Update WiFi credentials:
   ```cpp
   const char* ssid = "YOUR_WIFI";
   const char* password = "YOUR_PASSWORD";
   ```
3. Upload the code
4. Note the robot IP address from the Serial Monitor

### 2️⃣ Python Setup

1. Install requirements:

   ```bash
   pip install -r requirements.txt
   ```

2. Update IP address in `voice_assistant.py`:

   ```python
   ARDUINO_IP = "YOUR_ROBOT_IP"
   ```

3. Update Gemini API key in `voice_assistant.py`:

   ```python
   GEMINI_API_KEY = "YOUR_GEMINI_API_KEY"
   ```

4. Run the script:
   ```bash
   python voice_assistant.py
   ```

---

## 🔐 Safety & Intelligence

1. Robot will not move forward if an obstacle is detected
2. Obstacle logic runs locally on the robot
3. AI failures do not compromise safety

---

## 🎓 Academic Relevance

1. Demonstrates AI + Embedded Systems integration
2. Uses state-of-the-art Gemini LLM
3. Follows real-world robotics architecture
4. Suitable for mini/major projects and demos

---

## 🚀 Future Enhancements

1. Camera + Gemini Vision
2. Autonomous navigation mode
3. Mobile app controller
4. Cloud logging and analytics

---

## 👨‍💻 Author

Kshitij S

---
