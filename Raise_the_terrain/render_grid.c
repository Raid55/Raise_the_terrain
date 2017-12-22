//
//  render_grid.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/17/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

void render_isomet_grid(SDL_Renderer *rend, int **alt_grid, int angle)
{
    int i = 0, j = 0;
    float a = angle * M_PI / 180;
    float s_wx, s_wy, e_wx, e_wy;
    float s_rx, s_ry, e_rx, e_ry;
    int square_size = 60 * SCREEN_HEIGHT / 100 / (GRID_SIZE - 1);
    
    SDL_SetRenderDrawColor(rend,0xFF,0xFF,0xFF,0xFF);
    while(i < GRID_SIZE)
    {
        j = 0;
        while(j < GRID_SIZE - 1)
        {
            
            s_wx = isomet_x(j * square_size, i * square_size);
            s_wy = isomet_y(j * square_size, i * square_size, alt_grid[i][j]);
            e_wx = isomet_x((j + 1) * square_size, i * square_size);
            e_wy = isomet_y((j + 1) * square_size, i * square_size, alt_grid[i][j + 1]);

            s_rx = s_wx * cos(a) - s_wy * sin(a);
            s_ry = s_wx * sin(a) + s_wy * cos(a);/*rotate_y(s_wx, s_wy, angle)*/
            e_rx = e_wx * cos(a) - e_wy * sin(a);
            e_ry = e_wx * sin(a) + e_wy * cos(a);
            
            SDL_RenderDrawLine(rend, s_rx + X_MARGIN, s_ry + Y_MARGIN, e_rx + X_MARGIN, e_ry + Y_MARGIN);
            
            s_wx = isomet_x(i * square_size, j * square_size);
            s_wy = isomet_y(i * square_size, j * square_size, alt_grid[j][i]);
            e_wx = isomet_x(i * square_size, (j + 1) * square_size);
            e_wy = isomet_y(i * square_size, (j + 1) * square_size, alt_grid[j + 1][i]);

            s_rx = s_wx * cos(a) - s_wy * sin(a);
            s_ry = s_wx * sin(a) + s_wy * cos(a);
            e_rx = e_wx * cos(a) - e_wy * sin(a);
            e_ry = e_wx * sin(a) + e_wy * cos(a);
            
            SDL_RenderDrawLine(rend, s_rx + X_MARGIN, s_ry + Y_MARGIN, e_rx + X_MARGIN, e_ry + Y_MARGIN);
            j++;
        }
        i++;
    }
}
