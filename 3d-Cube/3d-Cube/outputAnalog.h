#ifndef __OUTPUT_ANALOG__H
#define __OUTPUT_ANALOG__H
#include "Mat3d.h"

void initAnalogScope();
void setAnalogValue(int value, int channel);
void setLine(vec3 point1 , vec3 point , int steps);

#endif