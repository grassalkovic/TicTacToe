#ifndef BASE_H
#define BASE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

class SDLInitialization
{
public:
    SDLInitialization();
    void initSDL();
    void closeSDL();
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();

private:
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    void initRenderer();
    void initImage();
    void initFonts();
};

#endif // BASE_H
