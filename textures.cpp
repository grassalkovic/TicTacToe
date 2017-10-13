#include <constants.h>
#include <iostream>
#include "textures.h"
#include <string>


Textures::Textures( SDL_Renderer* renderer )
{
    this->renderer = renderer;
    font = TTF_OpenFont("XPED Expanded.ttf", FONT_SIZE);
    pair<SDL_Texture*, SDL_Texture*> menu;
    menu.first = NULL;
    menu.second = NULL;
}

void Textures::loadTextures()
{
    bg = loadTexture( "skybox.png" );
    xCell = loadTexture( "red-alphabet-letter-x.png" );
    oCell = loadTexture( "red-alphabet-letter-o.png" );
    pickMe = loadTexture( "red-pick-me.png");
    empty = loadTexture( "red-empty.png");
    menu = loadFontTexture( "    Press 'enter' to start    ", "    press 'escape' to exit    " );
    winnerX = loadFontTexture("     Player 'X' WON     ", "     Player 'O' WON     ");
    winnerO = loadFontTexture("     Player 'X' WON     ", "     Player 'O' WON     ");
}

SDL_Texture* Textures::loadTexture( char* file )
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* newSurface = NULL;

    newSurface = IMG_Load( file );
    if (newSurface == NULL)
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << IMG_GetError() << std::endl;

    SDL_SetColorKey( newSurface, SDL_TRUE, SDL_MapRGB( newSurface->format, 0, 0, 0 ) );

    newTexture = SDL_CreateTextureFromSurface( renderer, newSurface );
    SDL_FreeSurface( newSurface );

    return newTexture;
}

std::pair<SDL_Texture*, SDL_Texture*> Textures::loadFontTexture(char *text1, char *text2)
{
    std::pair<SDL_Texture*, SDL_Texture*> twoValues;
    SDL_Surface* newSurface = NULL;
    SDL_Color color={0,0,0};

    newSurface = TTF_RenderText_Solid(font, text1, color);
    if (newSurface == NULL)
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << IMG_GetError() << std::endl;

    SDL_SetColorKey( newSurface, SDL_TRUE, SDL_MapRGB( newSurface->format, 255, 255, 255 ) );

    twoValues.first = SDL_CreateTextureFromSurface( renderer, newSurface );
    SDL_FreeSurface( newSurface );

    newSurface = TTF_RenderText_Solid(font, text2, color);
    if (newSurface == NULL)
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << IMG_GetError() << std::endl;

    SDL_SetColorKey( newSurface, SDL_TRUE, SDL_MapRGB( newSurface->format, 255, 255, 255 ) );

    twoValues.second = SDL_CreateTextureFromSurface( renderer, newSurface );
    SDL_FreeSurface( newSurface );

    return twoValues;
}

SDL_Texture* Textures::getBG()
{
    return bg;
}

SDL_Texture* Textures::getXCell()
{
    return xCell;
}

SDL_Texture* Textures::getOCell()
{
    return oCell;
}

SDL_Texture* Textures::getPickMeCell()
{
    return pickMe;
}

SDL_Texture* Textures::getEmptyCell()
{
    return empty;
}

pair<SDL_Texture*, SDL_Texture*> Textures::getMenuCell()
{
    return menu;
}

pair<SDL_Texture*, SDL_Texture*> Textures::getWinnerXCell()
{
    return winnerX;
}

pair<SDL_Texture*, SDL_Texture*> Textures::getWinnerOCell()
{
    return winnerO;
}
