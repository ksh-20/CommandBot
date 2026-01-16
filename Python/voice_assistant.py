import speech_recognition as sr
import socket
from api import ask_gemini
from tts import speak

ARDUINO_IP = "192.168.1.100"
PORT = 80

recognizer = sr.Recognizer()
mic = sr.Microphone()

def send_command(cmd):
    s = socket.socket()
    s.connect((ARDUINO_IP, PORT))
    s.send((cmd + "\n").encode())
    response = s.recv(1024).decode()
    s.close()
    return response

speak("Robot is ready")

while True:
    with mic as source:
        recognizer.adjust_for_ambient_noise(source)
        speak("Listening")
        audio = recognizer.listen(source)

    try:
        text = recognizer.recognize_google(audio)
        command = ask_gemini(text)

        response = send_command(command)
        speak(response)

    except:
        speak("I did not understand")