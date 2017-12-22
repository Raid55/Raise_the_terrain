//
//  main.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/11/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

int main(int ac,char **av)
{
    int angle;
    int alt_file;
    int **alt_grid;
    SDL_bool done = SDL_FALSE;
    SDL_Window* window = NULL;
    SDL_Event event;
    SDL_Renderer* renderer = NULL;
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        perror(SDL_GetError()), SDL_Quit();
        return 0;
    }
    angle = 0;
    if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_RESIZABLE,
                                    &window, &renderer) == 0)
    {
        if (ac == 2)
        {
            printf("%s", av[1]);
            alt_grid = altitude_grid(av[1]);
            if (alt_grid)
            {
                while(!done)
                {
                    SDL_SetRenderDrawColor(renderer,0,0,0,0);
                    SDL_RenderClear(renderer);
//                     if(poll_events() == 1)
//                       break;
                    while(SDL_PollEvent(&event))
                        if(event.type == SDL_QUIT)
                            done = SDL_TRUE;
                    render_isomet_grid(renderer, alt_grid, angle);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(10);
                }
            }
        }
        else
            perror("No altitude file, derp...");
    }
    
    if (renderer)
        SDL_DestroyRenderer(renderer);
        
    if (window)
        SDL_DestroyWindow(window);
    
    free_alt_grid(alt_grid);
    SDL_Quit();
    return 0;
}
