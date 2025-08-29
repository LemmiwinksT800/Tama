#include<DisplayManager.hpp>
#include<Fonts/FreeSans9pt7b.h>
DisplayManager::DisplayManager(RGBmatrixPanel& mat): matrix(mat){}
DisplayManager::~DisplayManager()
{
}
void DisplayManager::drawFace(const Frames frames){
    for (size_t index_frame = 0; index_frame < frames.count; ++index_frame)
    {
        matrix.drawRGBBitmap(0, 0, frames.frames[index_frame], 64, 32);
        matrix.swapBuffers(false);
    }
}
void DisplayManager::drawFace(){
    matrix.setCursor(0, 0);
    matrix.drawRGBBitmap(0,  0, Pictures::standart, 64, 32);
    matrix.swapBuffers(false);

    int scenary = rand() % 3;
    switch (scenary)
    {
    case 0:
        drawFace(Pictures::closed_eyes);
        break;
    case 1:
        drawFace(Pictures::look_away);
        break;
    default:
        matrix.drawRGBBitmap(0, 0, Pictures::standart, 64, 32);
        matrix.swapBuffers(false);
        break;
    }
}
void DisplayManager::writeText(const char* text, uint16_t color){
    matrix.setCursor(0, 0);
    matrix.setTextWrap(true);
    matrix.setTextSize(1);
    matrix.setTextColor(color);
    matrix.print(text);
    matrix.swapBuffers(false);
}