#include <Arduino.h>
#include <pictures.hpp>
#include <SoftwareSerial.h>
#include <SoundManager.hpp>
#include <DisplayManager.hpp>
#define CLK 11
#define OE   9
#define LAT 10

#define A   A0
#define B   A1
#define C   A2
#define D   A3

SoftwareSerial Ser(3, 2);
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);
SoundManager MP3(Ser);
DisplayManager display(matrix);
void setup() {
  matrix.begin();
  Serial.begin(9600);
  MP3.begin();
}
 
void loop() {
  display.drawFace();
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd == "1") {
      MP3.play(1);
      display.writeText("Hello!", 0xb788);
    }
    else if (cmd == "2") {
      MP3.play(2);
      display.writeText("Bye!", 0xb788);
    }
  }
}