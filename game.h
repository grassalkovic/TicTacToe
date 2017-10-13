#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <textures.h>
#include <constants.h>
#include <vector>

class Game
{
public:
    Game(SDL_Renderer* renderer, Textures* textures);
//    ~Game();
    static Game* makeGame( int gameType, SDL_Renderer* renderer, Textures* textures );    
    virtual void initRects() = 0;
    virtual void placeTextures(/*SDL_Event event*/) = 0;
    virtual void renderTextures() = 0;
    virtual void handleEvent(SDL_Event event) = 0;
    virtual int changeGame() = 0;

protected:
    SDL_Renderer* renderer = NULL;
    Textures* textures = NULL;
    int startNewGame = NOTHING;

};

class Menu: public Game
{
public:
    Menu(SDL_Renderer* renderer, Textures* textures):Game(renderer, textures) {}
//    ~Menu();
    void initRects();
    void placeTextures(/*SDL_Event event*/);
    void renderTextures();
    void handleEvent(SDL_Event event);
    int changeGame();

private:
    SDL_Rect menuGrid[MENU_SIZE] = {};
    pair<SDL_Texture*, SDL_Texture*> menu;
};

class TicTacToe: public Game
{
public:
    TicTacToe(SDL_Renderer* renderer, Textures* textures);
//    ~TicTacToe();
    void initRects();
    void placeTextures(/*SDL_Event event*/);
    void renderTextures();
    void handleEvent(SDL_Event event);
    int changeGame();

private:
    SDL_Rect grid[GRID_SIZE] = {};
    std::vector<SDL_Texture*> cell;
    SDL_Texture* winner;
    char turns[GRID_SIZE] = {};
    char xturn = ' ';

    void drawDefaultGrid();
    bool isMouseInsideCell(int x, int y, SDL_Rect rect);
    void drawPickMe();
    void drawTurns();
    void drawWinner();
    void checkColumns();
    void checkDiagonals();
    void checkRows();
};

#endif // GAME_H
