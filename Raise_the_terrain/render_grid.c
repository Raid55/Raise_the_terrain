//
//  render_grid.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/17/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

void render_isomet_grid()
{
    int i = 0, j = 0;
    float s_wx, s_wy, e_wx, e_wy;
    float s_rx, s_ry, e_rx, e_ry;
    int square_size = 60 * instance->dim->SCREEN_HEIGHT / 100 / (GRID_SIZE - 1);
    
    SDL_SetRenderDrawColor(instance->rend,0xFF,0xFF,0xFF,0xFF);
    while(i < GRID_SIZE)
    {
        j = 0;
        while(j < GRID_SIZE - 1)
        {
            
            s_wx = isomet_x(j * square_size, i * square_size);
            s_wy = isomet_y(j * square_size, i * square_size,
                            instance->alt_grid[i][j]);
            e_wx = isomet_x((j + 1) * square_size, i * square_size);
            e_wy = isomet_y((j + 1) * square_size, i * square_size,
                            instance->alt_grid[i][j + 1]);

            s_rx = rotate_x(s_wx, s_wy);
            s_ry = rotate_y(s_wx, s_wy);
            e_rx = rotate_x(e_wx, e_wy);
            e_ry = rotate_y(e_wx, e_wy);
            
            SDL_RenderDrawLine(instance->rend,
                               s_rx + instance->dim->X_MARGIN,
                               s_ry + instance->dim->Y_MARGIN,
                               e_rx + instance->dim->X_MARGIN,
                               e_ry + instance->dim->Y_MARGIN);
            
            s_wx = isomet_x(i * square_size, j * square_size);
            s_wy = isomet_y(i * square_size, j * square_size,
                            instance->alt_grid[j][i]);
            e_wx = isomet_x(i * square_size, (j + 1) * square_size);
            e_wy = isomet_y(i * square_size, (j + 1) * square_size,
                            instance->alt_grid[j + 1][i]);

            s_rx = rotate_x(s_wx, s_wy);
            s_ry = rotate_y(s_wx, s_wy);
            e_rx = rotate_x(e_wx, e_wy);
            e_ry = rotate_y(e_wx, e_wy);
            
            SDL_RenderDrawLine(instance->rend,
                               s_rx + instance->dim->X_MARGIN,
                               s_ry + instance->dim->Y_MARGIN,
                               e_rx + instance->dim->X_MARGIN,
                               e_ry + instance->dim->Y_MARGIN);
            j++;
        }
        i++;
    }
}
