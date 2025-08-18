#include <Arduino.h>
#include <DFPlayerMini_Fast.h>
#include <SoftwareSerial.h>
SoftwareSerial Ser(3, 2);
DFPlayerMini_Fast Mp3;
void setup() {
  Serial.begin(9600);  
  Ser.begin(9600);
  Mp3.begin(Ser);
  Mp3.volume(20);
}
void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd == "1") {
      Mp3.play(1);
    }
    else if (cmd == "2") {
      Mp3.play(2);
    }
  }
}
