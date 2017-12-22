//
//  mini_algos.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/17/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

#define ISOMET_X(x,y)  (inclination * x) - (inclination * y)
#define ISOMET_Y(x,y,z)  (1 - inclination) * x + (1 - inclination) * y - z

float isomet_x(int x, int y)
{
    return (INCLIN * x) - (INCLIN * y);
}

float isomet_y(int x, int y, int z)
{
    return (1 - INCLIN) * x + (1 - INCLIN) * y - z;
}
float rotate_x(float wx, float wy, int angle)
{
    float conv_ang;
    
    conv_ang = angle * M_PI / 180;
    return (wx * cos(conv_ang)) - (wy * sin(conv_ang));
}
float rotate_y(float wx, float wy, int angle)
{
    float conv_ang;
    
    conv_ang = angle * M_PI / 180;
    return (wx * sin(conv_ang)) + wy * cos(conv_ang);
}

