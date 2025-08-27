#include <Arduino.h>
#include <pictures.hpp>
#include <DFPlayerMini_Fast.h>
#include <SoftwareSerial.h>
#define CLK 11
#define OE   9
#define LAT 10

#define A   A0
#define B   A1
#define C   A2
#define D   A3

SoftwareSerial Ser(3, 2);
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);
DFPlayerMini_Fast MP3;

void setup() {
  matrix.begin();
  Serial.begin(9600);
  Ser.begin(9600);
  MP3.begin(Ser);
  MP3.volume(20);
}

void loop() {
  
  matrix.setCursor(0, 0);
  matrix.drawRGBBitmap(0,  0, standart, 64, 32);
  matrix.swapBuffers(false);
  int scenary = rand() % 3;
  if (scenary == 0){
    for (size_t index_frame = 0; index_frame < sizeof(s) / sizeof(s[0]); ++index_frame)
    {
      matrix.drawRGBBitmap(0, 0, s[index_frame], 64, 32);
      matrix.swapBuffers(false);
    }
  }
  else if (scenary == 1){
    for (size_t index_frame = 0; index_frame < sizeof(s1) / sizeof(s1[0]); ++index_frame)
    {
      matrix.drawRGBBitmap(0, 0, s1[index_frame], 64, 32);
      matrix.swapBuffers(false);
    }
  }
  else if (scenary == 2){
      matrix.drawRGBBitmap(0, 0, standart, 64, 32);
      matrix.swapBuffers(false);
  }
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd == "1") {
      MP3.play(1);
    }
    else if (cmd == "2") {
      MP3.play(2);
    }
  }
}