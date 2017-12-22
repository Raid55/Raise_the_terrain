//
//  event_handler.c
//  Raise_the_terrain
//
//  Created by Nicholas Boutboul on 12/22/17.
//  Copyright © 2017 Raid Co. All rights reserved.
//

#include "iso_met.h"

int event_listener()
{
    SDL_Event event;
    SDL_KeyboardEvent key_press;
    
    while (SDL_PollEvent(&event))
    {
     switch (event.type)
        {
            case SDL_QUIT:
                return (0);
            case SDL_KEYDOWN:
                key_press = event.key;
                if (key_press.keysym.sym == SDLK_ESCAPE)
                    return (0);
                if (key_press.keysym.sym == SDLK_UP)
                    _grid_alt_up();
                if (key_press.keysym.sym == SDLK_DOWN)
                    _grid_alt_down();
                if (key_press.keysym.sym == SDLK_RIGHT)
                    _grid_rotate_right();
                if (key_press.keysym.sym == SDLK_LEFT)
                    _grid_rotate_left();
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    instance->dim->SCREEN_WIDTH = event.window.data1;
                    instance->dim->SCREEN_HEIGHT = event.window.data2;
//                    instance->dim->X_MARGIN =
//                    instance->dim->Y_MARGIN = event.window.data1;
                }
                break;
        }
    }
    return (1);
}
