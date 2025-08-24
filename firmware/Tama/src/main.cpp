#include <Arduino.h>
#include <pictures.hpp>
#define CLK 11
#define OE   9
#define LAT 10

#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);

void setup() {
  matrix.begin();
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
}