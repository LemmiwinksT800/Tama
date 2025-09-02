#pragma once
#include <Pictures.hpp>
#include <Fonts/FreeSans9pt7b.h>
class DisplayManager
{
private:
    RGBmatrixPanel& matrix;
    const char* lastText;
    uint16_t lastTextColor;
    int textFramesLeft = 0;
    const int breathFramesCount = 8;
    int breath = breathFramesCount;
    int yPosFace = 0;
public:
    DisplayManager(RGBmatrixPanel& mat);
    ~DisplayManager();
    void drawFace();
    void drawFace(const Frames frames);
    void writeText(const char* text, uint16_t color);
    void writeText();
};

