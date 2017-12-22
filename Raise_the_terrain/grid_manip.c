//
//  grid_manip.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/22/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

void _grid_rotate_left()
{
    instance->angle--;
}
void _grid_rotate_right()
{
    instance->angle++;
}
void _grid_alt_down()
{
    int i, j;

    for(i = 0; i < GRID_SIZE; i++)
        for(j = 0;j < GRID_SIZE ; j++)
            instance->alt_grid[i][j]--;
}
void _grid_alt_up()
{
    int i, j;
    
    for(i = 0; i < GRID_SIZE; i++)
        for(j = 0;j < GRID_SIZE ; j++)
            instance->alt_grid[i][j]++;
}
