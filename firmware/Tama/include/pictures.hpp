#pragma once
#include <RGBmatrixPanel.h>
struct Frames
{
    const uint16_t** frames;
    size_t count;
};
class Pictures
{
private:
  
public:
  static const uint16_t standartFrame[];
  static const uint16_t standart_wow[];
  static const uint16_t cute_eyes[];
  static const uint16_t evil_eyes[];
  static const uint16_t funny_eyes[];
  static const uint16_t mouth[];
  static const uint16_t togue[];
  static const Frames standart;
  static const Frames closed_eyes;
  static const Frames look_away;
  static const Frames hmm_eyes;
  static const Frames standart_speak;
  static const Frames hmm_speak;

  Pictures();
  ~Pictures();
};
