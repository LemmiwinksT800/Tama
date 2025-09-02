#include<DisplayManager.hpp>
DisplayManager::DisplayManager(RGBmatrixPanel& mat): matrix(mat){}
DisplayManager::~DisplayManager()
{
}
void DisplayManager::drawFace(const Frames frames){
    for (size_t index_frame = 0; index_frame < frames.count; ++index_frame)
    {
        matrix.drawRGBBitmap(0, yPosFace, frames.frames[index_frame], 64, 32);
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
    }
}
void DisplayManager::drawFace(){
    matrix.setCursor(0, 0);
    matrix.drawRGBBitmap(0,  yPosFace, Pictures::standart, 64, 32);
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
        matrix.drawRGBBitmap(0, yPosFace, Pictures::standart, 64, 32);
        matrix.swapBuffers(false);
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