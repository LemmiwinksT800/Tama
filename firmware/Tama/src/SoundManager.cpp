#include <SoundManager.hpp>
SoundManager::SoundManager(SoftwareSerial& ser): serial(ser)
{
}

SoundManager::~SoundManager()
{
}
void SoundManager::begin(){
    serial.begin(9600);
    MP3.begin(serial);
    MP3.volume(20);
}
void SoundManager::play(int song){
    MP3.play(song);
}