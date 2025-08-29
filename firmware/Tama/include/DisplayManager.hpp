#pragma once
#include <Pictures.hpp>

class DisplayManager
{
private:
    RGBmatrixPanel& matrix;
public:
    DisplayManager(RGBmatrixPanel& mat);
    ~DisplayManager();
    void drawFace();
    void drawFace(const Frames frames);
    void writeText(const char* text, uint16_t color);
};

