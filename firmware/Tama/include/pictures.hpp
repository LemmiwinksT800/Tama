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
  static const uint16_t standart[];
  static const Frames closed_eyes;
  static const Frames look_away;
  Pictures();
  ~Pictures();
};
