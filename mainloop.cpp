#include "mainloop.h"
#include <constants.h>

MainLoop::MainLoop(SDL_Renderer* renderer, Textures* textures)
{
    this->renderer = renderer;
    this->textures = textures;
}

void MainLoop::loop()
{

    int startNewGameType = MENU;

    while( !quit )
    {
        initGameType();

        handleEvent();

        startNewGameType = MyGame->changeGame();
        if(startNewGameType == QUIT)
        {
            quit = true;
        }
        else if(startNewGameType  != NOTHING)
        {
            MyGame = NULL;
            MyGame = Game::makeGame(startNewGameType, renderer, textures);
            MyGame->initRects();
        }

        //Logic
        MyGame->placeTextures();

        //Rendering
        renderGrid();
    }
}

void MainLoop::initGameType()
{
    if(MyGame == NULL)
    {
        MyGame = Game::makeGame(MENU, renderer, textures);
        MyGame->initRects();
    }
}

void MainLoop::handleEvent()
{
    SDL_Event event;

    //Events
    while ( SDL_PollEvent( &event ) )
    {
        exitGameLoop(event);
        MyGame->handleEvent( event );
    }
}

void MainLoop::exitGameLoop(SDL_Event event)
{
    if( event.type == SDL_QUIT )
    {
        quit = true;
    }
}

void MainLoop::renderGrid()
{
    SDL_RenderClear(renderer);
    MyGame->renderTextures();
    SDL_RenderPresent( renderer );
}
