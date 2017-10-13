#ifndef MAINLOOP_H
#define MAINLOOP_H

#include <SDL2/SDL.h>
#include <textures.h>
#include <game.h>

class MainLoop
{
public:
    MainLoop(SDL_Renderer* renderer, Textures* textures);
    void loop();
    void initGameType();
    void handleEvent();
    void exitGameLoop(SDL_Event event);

private:
    SDL_Renderer* renderer = NULL;
    Textures* textures = NULL;
    Game* MyGame = NULL;
    bool quit = false;

    void renderGrid();

};

#endif // MAINLOOP_H
