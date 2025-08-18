import time
import os
import speech_recognition as sr
import serial
frimware = serial.Serial("COM3", 9600)
def answer(rec, audio):
    try:
        text = rec.recognize_google(audio, language="ru-RU").lower()
        print(text)
        if "привет" in text:
            frimware.write("hi")

    except sr.UnknownValueError:
        print("Ничего не понял, повтори")

r = sr.Recognizer()
m = sr.Microphone()

with m as source:
    r.adjust_for_ambient_noise(source)
listening = r.listen_in_background(m, answer)
#for _ in range(100): time.sleep(0.1)
# listening(wait_for_stop=False)
while True: time.sleep(0.1)