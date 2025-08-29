#include <Arduino.h>
#include <DFPlayerMini_Fast.h>
#include <SoftwareSerial.h>



class SoundManager
{
private:
    DFPlayerMini_Fast MP3;
    SoftwareSerial& serial;
public:
    SoundManager(SoftwareSerial& ser);
    ~SoundManager();
    void begin();
    void play(int song);
};


