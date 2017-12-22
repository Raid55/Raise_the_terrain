
//
//  main.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/11/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

//int *TEMP[8] = {
//    {120, 60, 40, 60, 20, -20, -80, -120},
//    {40, 20, 30, 30, -10, -40, -90, -110},
//    {20, 30, 10, 06, -6, -20, -26, -90},
//    {00, -6, 10, 10, -6, -20, -20, -40},
//    {-20, -20, -18, -14, -40, -20, -20, -30},
//    {-10, -10, -10, -10, -8, -20, -20, -30},
//    {20, 10, 10, 10, 10, 04, 10, -10},
//    {30, 24, 24, 22, 20, 18, 14, 16}
//};

// Including the best header file
#include "iso_met.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer) == 0) {
    SDL_bool done = SDL_FALSE;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderPresent(renderer);
    update_first_point();
    //            rnder_grid(renderer);
    iso_metrisize(renderer);
    //          SDL_RenderPresent(renderer);
    while (!done) {
    SDL_Event event;

    while(SDL_PollEvent(&event))
    if(event.type == SDL_QUIT)
    done = SDL_TRUE;

    SDL_Delay(10);
    }
    }

    if (renderer) {
    SDL_DestroyRenderer(renderer);
    }
    if (window) {
    SDL_DestroyWindow(window);
    }
    }
    SDL_Quit();
    return 0;
    }

void update_first_point(void)
{
////    SDL_DisplayMode DM;
////    SDL_GetCurrentDisplayMode(SDL_GetNumVideoDisplays(), &DM);
////    printf("[%d][%d]",DM.h, DM.w);
f_point[0] = ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2) + (MARGIN_PERC * SCREEN_HEIGHT) / 100;
f_point[1] = (MARGIN_PERC * SCREEN_HEIGHT) / 100;

}
void lol(SDL_Renderer *rend)
{
int square_size = 80 * SCREEN_HEIGHT / 100 / GRID_SIZE;
SDL_RenderDrawLine(rend, f_point[0], f_point[1], f_point[0] + square_size * 8, f_point[1]);
SDL_RenderDrawLine(rend, f_point[0], f_point[1] + square_size, f_point[0] + square_size * 8, f_point[1] + square_size);
}


void rnder_grid(SDL_Renderer *rend)
{
int y, x;
int i, j;

int square_size = 80 * SCREEN_HEIGHT / 100 / (GRID_SIZE - 1);
y = f_point[1];
for(i = 0; i < GRID_SIZE; i++)
{
x = f_point[0];
for(j = 0; j < GRID_SIZE; j++)
{
if (j != (GRID_SIZE - 1))
x += square_size;
SDL_RenderDrawLine(rend, f_point[0], y, x, y);
SDL_RenderPresent(rend);
//finish loop and dont forget what you arent supossed to forget
//do that thing do that thing pompom pom pain pain pain
}
y += square_size;
}

x = f_point[0];
for(i = 0; i < GRID_SIZE; i++)
{
y = f_point[1];
for(j = 0; j < GRID_SIZE; j++)
{
if (j != (GRID_SIZE - 1))
y += square_size;
SDL_RenderDrawLine(rend, x, f_point[1], x, y);
SDL_RenderPresent(rend);

//finish loop and dont forget what you arent supossed to forget
//do that thing do that thing pompom pom pain pain pain
}
x += square_size;
}

//    SDL_RenderPresent(rend);

//    f_point = first_point();
}

void iso_metrisize(SDL_Renderer *rend)
{
int x, y;
int rx, ry;
int wx, wy;
int i, j;
int z = 0;
int r_sp, w_sp;
float a = 90 * M_PI / 180;
printf("AA[%f]pi?[%f]", a, M_PI);


int square_size = 80 * SCREEN_HEIGHT / 100 / (GRID_SIZE - 1);
y = f_point[1];
for(i = 0; i < GRID_SIZE; i++)
{
x = f_point[0];
for(j = 0; j < GRID_SIZE; j++)
{
if (j != (GRID_SIZE - 1))
x += square_size;
printf("x:[%d]y:[%d]", x, y);
rx = ((x * cos(a)) - (y * sin(a)));
ry = ((x * sin(a)) + (y * cos(a)));
printf("rx:[%d]ry:[%d]", rx, ry);
r_sp = f_point[0] * cos(a) - y * sin(a);
//            wx = INCLIN * rx - INCLIN * ry;
//            wy = (1 - INCLIN) * rx + (1 - INCLIN) * ry - z;
//            w_sp = INCLIN * r_sp - INCLIN * ry;

SDL_RenderDrawLine(rend, r_sp, ry, rx, ry);
SDL_RenderPresent(rend);
//finish loop and dont forget what you arent supossed to forget
//do that thing do that thing pompom pom pain pain pain
}
y += square_size;
}

x = f_point[0];
for(i = 0; i < GRID_SIZE; i++)
{
y = f_point[1];
for(j = 0; j < GRID_SIZE; j++)
{
if (j != (GRID_SIZE - 1))
y += square_size;
printf("2x:[%d]2y:[%d]", x, y);
rx = ((x * cos(a)) - (y * sin(a)));
ry = ((x * sin(a)) + (y * cos(a)));
printf("2rx:[%d]2ry:[%d]", rx, ry);
r_sp = x * sin(a) + f_point[1] * cos(a);
wx = INCLIN * x - INCLIN * y;
wy = (1 - INCLIN) * rx + (1 - INCLIN) * ry - z;
w_sp = (1 - INCLIN) * rx + (1 - INCLIN) * r_sp - z;

SDL_RenderDrawLine(rend, rx, r_sp, rx, ry);
SDL_RenderPresent(rend);

//finish loop and dont forget what you arent supossed to forget
//do that thing do that thing pompom pom pain pain pain
}
x += square_size;
}

//    SDL_RenderPresent(rend);

//    f_point = first_point();
}
//int SDL_RenderDrawLine(SDL_Renderer* renderer,
//                       int           x1,
//                       int           y1,
//                       int           x2,
//          
