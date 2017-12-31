//
//  mini_algos.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/17/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

float isomet_x(int x, int y)
{
    return (INCLIN * x) - (INCLIN * y);
}

float isomet_y(int x, int y, int z)
{
    return (1 - INCLIN) * x + (1 - INCLIN) * y - z;
}
float rotate_x(float wx, float wy)
{
    float conv_ang;
    
    conv_ang = instance->angle * M_PI / 180;
    return (wx * cos(conv_ang)) - (wy * sin(conv_ang));
}
float rotate_y(float wx, float wy)
{
    float conv_ang;
    
    conv_ang = instance->angle * M_PI / 180;
    return (wx * sin(conv_ang)) + (wy * cos(conv_ang));
}

//void X_MARG_CALC()
//{
//    int sc_he = instance->dim->SCREEN_HEIGHT;
//    instance->dim->X_MARGIN = ((instance->dim->SCREEN_WIDTH - instance->dim->SCREEN_HEIGHT) / 2) + MARGIN_PERC * sc_he / 100;
//}

