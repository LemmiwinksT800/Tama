#include<DisplayManager.hpp>
DisplayManager::DisplayManager(RGBmatrixPanel& mat): matrix(mat){}
DisplayManager::~DisplayManager()
{
}
void DisplayManager::drawFace(const uint16_t* face_frame){
    for (size_t index_frame = 0; index_frame < 11; ++index_frame)
    {
        matrix.drawRGBBitmap(0, yPosFace, face_frame, 64, 32);
        matrix.drawRGBBitmap(23, 20 + yPosFace, Pictures::mouth, 18, 12);
        if (textFramesLeft)
        {
            --textFramesLeft;
            writeText();
        }
        matrix.swapBuffers(false);
        --breath;
        if (!breath){
            breath = breathFramesCount;
            yPosFace = yPosFace % 2 == 0;
        }
        matrix.fillScreen(0);
    }
}
void DisplayManager::drawFace(const uint16_t* face_frame, const Frames mouth_frames){
    for (size_t index_frame = 0; index_frame < 11; ++index_frame)
    {
        matrix.drawRGBBitmap(0, yPosFace, face_frame, 64, 32);
        matrix.drawRGBBitmap(23, 20 + yPosFace, mouth_frames.frames[index_frame], 18, 12);
        if (textFramesLeft)
        {
            --textFramesLeft;
            writeText();
        }
        matrix.swapBuffers(false);
        --breath;
        if (!breath){
            breath = breathFramesCount;
            yPosFace = yPosFace % 2 == 0;
        }
        matrix.fillScreen(0);
    }
}
void DisplayManager::drawFace(const uint16_t* face_frame, const uint16_t* mouth_frame){
    for (size_t index_frame = 0; index_frame < 11; ++index_frame)
    {
        matrix.drawRGBBitmap(0, yPosFace, face_frame, 64, 32);
        matrix.drawRGBBitmap(23, 20 + yPosFace, mouth_frame, 18, 12);
        if (textFramesLeft)
        {
            --textFramesLeft;
            writeText();
        }
        matrix.swapBuffers(false);
        --breath;
        if (!breath){
            breath = breathFramesCount;
            yPosFace = yPosFace % 2 == 0;
        }
        matrix.fillScreen(0);
    }
}
void DisplayManager::drawFace(const Frames face_frames){
    for (size_t index_frame = 0; index_frame < face_frames.count; ++index_frame)
    {
        matrix.drawRGBBitmap(0, yPosFace, face_frames.frames[index_frame], 64, 32);
        matrix.drawRGBBitmap(23, 20 + yPosFace, Pictures::mouth, 18, 12);
        if (textFramesLeft)
        {
            --textFramesLeft;
            writeText();
        }
        matrix.swapBuffers(false);
        --breath;
        if (!breath){
            breath = breathFramesCount;
            yPosFace = yPosFace % 2 == 0;
        }
        matrix.fillScreen(0);
    }
}
void DisplayManager::drawFace(const Frames face_frames, const Frames mouth_frames){
    for (size_t index_frame = 0; index_frame < face_frames.count; ++index_frame)
    {
        matrix.drawRGBBitmap(0, yPosFace, face_frames.frames[index_frame], 64, 32);
        matrix.drawRGBBitmap(23, 20 + yPosFace, mouth_frames.frames[index_frame], 18, 12);
        if (textFramesLeft)
        {
            --textFramesLeft;
            writeText();
        }
        matrix.swapBuffers(false);
        --breath;
        if (!breath){
            breath = breathFramesCount;
            yPosFace = yPosFace % 2 == 0;
        }
        matrix.fillScreen(0);
    }
}
void DisplayManager::drawFace(const Frames face_frames, const uint16_t* mouth_frame){
    for (size_t index_frame = 0; index_frame < face_frames.count; ++index_frame)
    {
        matrix.drawRGBBitmap(0, yPosFace, face_frames.frames[index_frame], 64, 32);
        matrix.drawRGBBitmap(23, 20 + yPosFace, mouth_frame, 18, 12);
        if (textFramesLeft)
        {
            --textFramesLeft;
            writeText();
        }
        matrix.swapBuffers(false);
        --breath;
        if (!breath){
            breath = breathFramesCount;
            yPosFace = yPosFace % 2 == 0;
        }
        matrix.fillScreen(0);
    }
}
void DisplayManager::drawFace(){
    matrix.setCursor(0, 0);
    matrix.drawRGBBitmap(0,  yPosFace, Pictures::standartFrame, 64, 32);
    matrix.drawRGBBitmap(23,  20 + yPosFace, Pictures::mouth, 18, 12);
    matrix.swapBuffers(false);

    int scenary = rand() % 4;
    switch (scenary)
    {
    case 0:
        drawFace(Pictures::closed_eyes);
        break;
    case 1:
        drawFace(Pictures::look_away);
        break;
    case 2:
        drawFace(Pictures::funny_eyes, Pictures::standart_speak);
        break;
    default:
        drawFace(Pictures::standart);
        break;
    }
}
void DisplayManager::writeText(){
    int16_t x, y;
    uint16_t w, h;
    matrix.getTextBounds(lastText, 0, 0, &x, &y, &w, &h);
    int16_t startX = (64 - w) / 2;
    matrix.setCursor(startX, yPosFace);
    matrix.setTextWrap(true);
    matrix.setTextSize(1);
    matrix.setTextColor(lastTextColor);
    matrix.print(lastText);
}
void DisplayManager::writeText(const char* text, uint16_t color){
    matrix.setTextWrap(true);
    matrix.setTextSize(1);
    matrix.setTextColor(color);
    matrix.swapBuffers(false);
    lastText = text;
    lastTextColor = color;
    textFramesLeft = 11;
}