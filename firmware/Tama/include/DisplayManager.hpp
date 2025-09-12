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
    void drawFace(const uint16_t* face_frame);
    void drawFace(const uint16_t* face_frame, const Frames mouth_frames);
    void drawFace(const uint16_t* face_frame, const uint16_t* mouth_frame);
    void drawFace(const Frames face_frames);
    void drawFace(const Frames face_frames, const Frames mouth_frames);
    void drawFace(const Frames face_frames, const uint16_t* mouth_frame);
    void writeText(const char* text, uint16_t color);
    void writeText();
};

