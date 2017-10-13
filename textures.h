#ifndef TEXTURES_H
#define TEXTURES_H

#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

class Textures
{
public:
    Textures( SDL_Renderer* renderer );
    void loadTextures();
    SDL_Texture* loadTexture( char* file );
    pair<SDL_Texture*, SDL_Texture*>  loadFontTexture( char* text1, char *text2);
    SDL_Texture* getBG();
    SDL_Texture* getXCell();
    SDL_Texture* getOCell();
    SDL_Texture* getPickMeCell();
    SDL_Texture* getEmptyCell();
    pair<SDL_Texture*, SDL_Texture*> getMenuCell();

    pair<SDL_Texture*, SDL_Texture*> getWinnerXCell();
    pair<SDL_Texture*, SDL_Texture*> getWinnerOCell();

private:
    SDL_Renderer* renderer;
    TTF_Font *font;
    SDL_Texture* bg = NULL;
    SDL_Texture* xCell = NULL;
    SDL_Texture* oCell = NULL;
    SDL_Texture* pickMe = NULL;
    SDL_Texture* empty = NULL;
    pair<SDL_Texture*, SDL_Texture*> menu;
    pair<SDL_Texture*, SDL_Texture*> winnerX;
    pair<SDL_Texture*, SDL_Texture*> winnerO;
};

#endif // TEXTURES_H
