import speech_recognition as sr
import serial

def start_recognition(com_port):
    firmware = serial.Serial(com_port, 9600, timeout=1)
    r = sr.Recognizer()
    mic = sr.Microphone()
    with mic as source:
        r.adjust_for_ambient_noise(source)

    def callback(recognizer, audio):
        try:
            text = recognizer.recognize_google(audio, language="ru-RU").lower()
            print(f"VOICE: {text}", flush=True)

            if "привет" in text:
                firmware.write(b"1\n")
            elif "пока" in text:
                firmware.write(b"2\n")

        except sr.UnknownValueError:
            pass
        except Exception as e:
            print(f"Speech error: {e}", flush=True)
    stop_listening = r.listen_in_background(mic, callback)
    return stop_listening
