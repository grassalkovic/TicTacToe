#include "base.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <constants.h>
#include <iostream>

SDLInitialization::SDLInitialization()
{
    //Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    //Set texture filtering to linear
    !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
}

void SDLInitialization::initSDL()
{
    window = SDL_CreateWindow( "TicTacToe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN  );
    initRenderer();
    initImage();
    initFonts();
}

void SDLInitialization::initRenderer()
{
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL )
    {
        std::cout << "SDL_Renderer could not initialize! SDL_Renderer Error: %s\n" << SDL_GetError() << std::endl;
    }
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, SDL_ALPHA_OPAQUE );
    SDL_RenderClear( renderer );
}


void SDLInitialization::initImage()
{
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) && imgFlags ) )
    {
        std::cout << "SDL_image could not initialize! SDL_image Error: %s\n" << IMG_GetError() << std::endl;
    }
}

void SDLInitialization::initFonts()
{
    if( TTF_Init() == -1 )
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << TTF_GetError() << std::endl;
    }
}

void SDLInitialization::closeSDL()
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );

    window = NULL;
    renderer = NULL;
}

SDL_Window* SDLInitialization::getWindow()
{
    return window;
}

SDL_Renderer* SDLInitialization::getRenderer()
{
    return renderer;
}
