////
////  oldMain.c
////  Raise_the_terrain
////
////  Created by Nicholas Boutboul on 12/15/17.
////  Copyright © 2017 Raid Co. All rights reserved.
////
//
////#include "oldMain.h"
//
////
////  main.c
////  Raise_the_terrain
////
////  Created by Nicholas Boutboul on 12/11/17.
////  Copyright © 2017 Raid Co. All rights reserved.
////
//
////int *TEMP[8] = {
////    {120, 60, 40, 60, 20, -20, -80, -120},
////    {40, 20, 30, 30, -10, -40, -90, -110},
////    {20, 30, 10, 06, -6, -20, -26, -90},
////    {00, -6, 10, 10, -6, -20, -20, -40},
////    {-20, -20, -18, -14, -40, -20, -20, -30},
////    {-10, -10, -10, -10, -8, -20, -20, -30},
////    {20, 10, 10, 10, 10, 04, 10, -10},
////    {30, 24, 24, 22, 20, 18, 14, 16}
////};
//
////Using SDL and standard IO
//#include <SDL2/SDL.h>
//#include <stdio.h>
//
////Screen dimension constants
//const int SCREEN_WIDTH = 1600;
//const int SCREEN_HEIGHT = 900;
//
//
//#define POINTS_COUNT 5
//
//static SDL_Point points[POINTS_COUNT] = {
//    {200, 200},
//    {400, 200},
//    {400, 400},
//    {200, 400},
//    {200, 200}
//};
//
//int main(int argc, char* argv[])
//{
//    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
//        SDL_Window* window = NULL;
//        SDL_Renderer* renderer = NULL;
//
//        if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) == 0) {
//            SDL_bool done = SDL_FALSE;
//
//            while (!done) {
//                SDL_Event event;
//
//                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
//                SDL_RenderClear(renderer);
//
//                points[0].x = 200;
//                points[0].y = 200;
//                points[1].x = 400;
//                points[1].y = 200;
//                points[2].x = 400;
//                points[2].y = 400;
//                points[3].x = 200;
//                points[3].y = 400;
//                points[4].x = 200;
//                points[4].y = 200;
//                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
//                SDL_RenderDrawLines(renderer, points, POINTS_COUNT);
//                points[0].x = 400;
//                points[0].y = 200;
//                points[1].x = 600;
//                points[1].y = 200;
//                points[2].x = 600;
//                points[2].y = 400;
//                points[3].x = 400;
//                points[3].y = 400;
//                points[4].x = 400;
//                points[4].y = 200;
//                SDL_RenderDrawLines(renderer, points, POINTS_COUNT);
//                SDL_RenderPresent(renderer);
//
//                while(SDL_PollEvent(&event))
//                    if(event.type == SDL_QUIT)
//                        done = SDL_TRUE;
//
//                SDL_Delay(10);
//            }
//        }
//
//        if (renderer) {
//            SDL_DestroyRenderer(renderer);
//        }
//        if (window) {
//            SDL_DestroyWindow(window);
//        }
//    }
//    SDL_Quit();
//    return 0;
//}
//
