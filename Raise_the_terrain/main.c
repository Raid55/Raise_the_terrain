//
//  main.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/11/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

instance_t *instance;

int main(int ac,char **av)
{
    SDL_bool done = SDL_FALSE;
    SDL_Event event;
    window_dim_t _dim_init = {1200, 800, 520, 320};
    instance_t _inst_init = {0, NULL, &_dim_init, NULL, NULL};
    instance = &_inst_init;
    
    //test
    SDL_Rect testLol = {.x = 20, .y = 20, .w = 300, .h = 30};
//    testLol.x = 0;
//    testLol.y =
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        perror(SDL_GetError()), SDL_Quit();
        return 0;
    }
    if (SDL_CreateWindowAndRenderer(instance->dim->SCREEN_WIDTH,
                                    instance->dim->SCREEN_HEIGHT,
                                    SDL_WINDOW_RESIZABLE,
                                    &(instance->window), &(instance->rend)) == 0)
    {
        if (ac == 2)
        {
            printf("%s", av[1]);
            altitude_grid(av[1]);
            if (instance->alt_grid)
            {
                while(!done)
                {
                    SDL_SetRenderDrawColor(instance->rend,0,0,0,0);
                    SDL_RenderClear(instance->rend);

                    while(SDL_PollEvent(&event))
                        if(event.type == SDL_QUIT)
                            done = SDL_TRUE;
                    SDL_SetRenderDrawColor (instance->rend, 66, 185, 244, 255);
                    SDL_RenderDrawRect(instance->rend, &testLol);
                    SDL_RenderFillRect (instance->rend, & testLol);
                    SDL_SetTextInputRect(&testLol);
                    SDL_StartTextInput();
                    render_isomet_grid();
                    SDL_RenderPresent(instance->rend);
                    if (!event_listener())
                        break;
//                    SDL_Delay(10);
                }
            }
        }
        else
            perror("No altitude file, derp...");
    }
    
    if (instance->rend)
        SDL_DestroyRenderer(instance->rend);
        
    if (instance->window)
        SDL_DestroyWindow(instance->window);
    
    if (instance->alt_grid)
        free_alt_grid();
    
    SDL_Quit();
    return 0;
}
