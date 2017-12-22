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
//static int SCREEN_WIDTH = 1200;
//static int SCREEN_HEIGHT = 800;
//Points for draw line func
#define POINTS_COUNT 2

//Isometric incline
#define INCLIN 0.7

//test
//#define X_MARGIN 630
//#define Y_MARGIN 360

//Grid point size, always square
#define GRID_SIZE 8

//margin percentage
#define MARGIN_PERC 40;


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

//window size control
typedef struct window_dim_s
{
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int X_MARGIN;
    int Y_MARGIN;
} window_dim_t;

//global var instance struct
typedef struct instance_s
{
    int angle;
    int **alt_grid;
    window_dim_t *dim;
    SDL_Window *window;
    SDL_Renderer *rend;
    
} instance_t;

extern instance_t *instance;

//alog funcs
float isomet_x(int, int);
float isomet_y(int, int, int);
float rotate_x(float, float);
float rotate_y(float, float);

//grid manip
void _grid_rotate_left(void);
void _grid_rotate_right(void);
void _grid_alt_down(void);
void _grid_alt_up(void);

//event listener
int event_listener(void);

void render_isomet_grid(void);
void altitude_grid(char *alt_file_path);
void free_alt_grid(void);

//void lol(SDL_Renderer *);
//void update_first_point(void);
//void rnder_grid(SDL_Renderer *);
//void iso_metrisize(SDL_Renderer *);


#endif /* iso_met_h */
