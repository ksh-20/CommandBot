import speech_recognition as sr
import serial
import time
from gemini_api import ask_gemini

# Change COM port (Windows)
arduino = serial.Serial(port="COM3", baudrate=9600, timeout=1)
time.sleep(2)

recognizer = sr.Recognizer()
mic = sr.Microphone()

print("Voice Control Started...")

while True:
    with mic as source:
        recognizer.adjust_for_ambient_noise(source)
        print("Listening...")
        audio = recognizer.listen(source)

    try:
        text = recognizer.recognize_google(audio)
        print("You said:", text)

        command = ask_gemini(text)
        print("Gemini Command:", command)

        arduino.write((command + "\n").encode())

    except sr.UnknownValueError:
        print("Could not understand")
    except Exception as e:
        print("Error:", e)
