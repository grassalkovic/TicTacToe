#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <log.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool initSDL( SDL_Window*& window, SDL_Renderer*& renderer, Log* mainLog );
void closeSDL( SDL_Window*& window, SDL_Renderer*& renderer );
void paintGrid( SDL_Renderer* renderer );


#endif // MAIN_H
