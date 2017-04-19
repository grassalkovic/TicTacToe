#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <main.h>
#include <log.h>
#include <test.h>

using namespace std;

int main(int argc, char *argv[])
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    Log* mainLog = new Log();

    SDL_Init(SDL_INIT_VIDEO);


    if ( initSDL( window, renderer, mainLog ) != 0 )
    {
        mainLog->write( "Init failed ..." );
        return 1;
    }    

    //Clear main renderer
    SDL_RenderClear( renderer );

    paintGrid( renderer );

    //Render screen
    SDL_RenderPresent( renderer );

    SDL_Delay(2000);

    cout << "Hello World!" << endl;

    closeSDL( window, renderer );
    return 0;
}

bool initSDL( SDL_Window*& window, SDL_Renderer*& renderer, Log* mainLog )
{
    window = SDL_CreateWindow( "TicTacToe",
                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN  );
    if ( window == NULL )
    {
        mainLog->write( "Window could not be created! SDL_Error: " );
        mainLog->write( SDL_GetError() );
        return 1;
    }

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    if( renderer == NULL )
    {
        mainLog->write( "Renderer could not be created! SDL_Error: %s\n" );
        mainLog->write( SDL_GetError() );
        return 1;
    }

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) && imgFlags ) )
    {
        mainLog->write( "Image could not be created! SDL_Error: %s\n" );
        mainLog->write( IMG_GetError() );
        return 1;
    }
}

void closeSDL( SDL_Window*& window, SDL_Renderer*& renderer )
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );

    window = NULL;
    renderer = NULL;

}

void paintGrid( SDL_Renderer* renderer )
{
    // render grid from 2 vertical and 2 horizontal lines
    // I put 3 lines next to each other to make the grid thicker
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, SDL_ALPHA_OPAQUE );
    for( int i = 1; i <= 2; i++ )
    {
        SDL_RenderDrawLine( renderer, SCREEN_WIDTH * i / 3, 0, SCREEN_WIDTH * i / 3, SCREEN_HEIGHT );
        SDL_RenderDrawLine( renderer, SCREEN_WIDTH * i / 3 - 1, 0, SCREEN_WIDTH * i / 3 - 1, SCREEN_HEIGHT );
        SDL_RenderDrawLine( renderer, SCREEN_WIDTH * i / 3 + 1, 0, SCREEN_WIDTH * i / 3 + 1 , SCREEN_HEIGHT );
    }

    for( int i = 1; i <= 2; i++ )
    {
        SDL_RenderDrawLine( renderer, 0, SCREEN_HEIGHT * i / 3, SCREEN_WIDTH, SCREEN_HEIGHT * i / 3);
        SDL_RenderDrawLine( renderer, 0, SCREEN_HEIGHT * i / 3 - 1, SCREEN_WIDTH, SCREEN_HEIGHT * i / 3 - 1 );
        SDL_RenderDrawLine( renderer, 0, SCREEN_HEIGHT * i / 3 + 1, SCREEN_WIDTH, SCREEN_HEIGHT * i / 3 + 1 );
    }

}
