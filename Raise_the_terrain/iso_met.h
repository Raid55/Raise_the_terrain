//
//  iso_met.h
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/15/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#ifndef iso_met_h
#define iso_met_h

//Using SDL and standard IO
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <SDL2/SDL.h>
#include <sys/types.h>

//Screen dimension constants
static int SCREEN_WIDTH = 1200;
static int SCREEN_HEIGHT = 800;
//Points for draw line func
#define POINTS_COUNT 2

//Isometric incline
#define INCLIN 0.7

//test
#define X_MARGIN 630
#define Y_MARGIN 360

//Grid point size, always square
#define GRID_SIZE 8

//margin percentage
#define MARGIN_PERC 20;


//first point global var
//int f_point[2] = {0, 0};
//
//int TEMP[8][8] = {
//    {120, 60, 40, 60, 20, -20, -80, -120},
//    {40, 20, 30, 30, -10, -40, -90, -110},
//    {20, 30, 10, 06, -6, -20, -26, -90},
//    {00, -6, 10, 10, -6, -20, -20, -40},
//    {-20, -20, -18, -14, -40, -20, -20, -30},
//    {-10, -10, -10, -10, -8, -20, -20, -30},
//    {20, 10, 10, 10, 10, 04, 10, -10},
//    {30, 24, 24, 22, 20, 18, 14, 16}
//};
//buff
#define BUFF_SIZE 1024

//alog funcs
float isomet_x(int, int);
float isomet_y(int, int, int);
float rotate_x(float, float, int);
float rotate_y(float, float, int);

void render_isomet_grid(SDL_Renderer *rend, int **alt_grid, int angle);
int **altitude_grid(char *);
void free_alt_grid(int **grid);

//void lol(SDL_Renderer *);
//void update_first_point(void);
//void rnder_grid(SDL_Renderer *);
//void iso_metrisize(SDL_Renderer *);


#endif /* iso_met_h */