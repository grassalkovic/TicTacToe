#include "game.h"
#include <iostream>
#include <string>

Game::Game(SDL_Renderer* renderer, Textures* textures)
{
    this->renderer = renderer;
    this->textures = textures;
}

Game* Game::makeGame(int gameType, SDL_Renderer* renderer, Textures* textures)
{
    switch (gameType) {
    case MENU:
        return new Menu(renderer, textures);
        break;
    case TICTACTOE:
        return new TicTacToe(renderer, textures);
        break;
    default:
        return NULL;
    }
}

void Menu::initRects()
{
    for(int i = 0; i <= MENU_SIZE; i++)
    {
        menuGrid[i].x = 0;
        menuGrid[i].y = i * MENU_HEIGHT;
        menuGrid[i].w = MENU_WIDTH;
        menuGrid[i].h = MENU_HEIGHT;
    }
}

void Menu::placeTextures(/*SDL_Event event*/)
{
    menu = textures->getMenuCell();
}

void Menu::renderTextures()
{
    SDL_RenderCopy( renderer, menu.first, NULL, &menuGrid[0] );
    SDL_RenderCopy( renderer, menu.second, NULL, &menuGrid[1] );
}


void Menu::handleEvent(SDL_Event event)
{

    if(event.key.keysym.sym == SDLK_ESCAPE )
    {
        startNewGame = QUIT;
    }

    if(event.key.keysym.sym == SDLK_RETURN)
    {
        startNewGame = TICTACTOE;
    }
}

int Menu::changeGame()
{
    return startNewGame;
}

TicTacToe::TicTacToe(SDL_Renderer* renderer, Textures* textures):Game(renderer, textures)
{
    //    just to remember how to create constructor
}

void TicTacToe::initRects()
{
    int position = 0;
    for(int i = 0; i <= 2; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            grid[position].x = i * TEXTURE_WIDTH;
            grid[position].y = j * TEXTURE_HEIGHT;
            grid[position].w = TEXTURE_WIDTH;
            grid[position].h = TEXTURE_HEIGHT;
            position += 1;
        }
    }
}

void TicTacToe::placeTextures(/*SDL_Event event*/)
{

    cell.clear();
    drawDefaultGrid();
    drawPickMe();
    drawTurns();
    drawWinner();
}

void TicTacToe::drawDefaultGrid()
{
    for( int i = 0; i < GRID_SIZE; i++)
        cell.push_back(textures->getEmptyCell());
}

void TicTacToe::drawPickMe()
{
    int x, y;
    SDL_GetMouseState( &x, &y );
    for( int i = 0; i < GRID_SIZE; i++)
        if( isMouseInsideCell(x, y, grid[i]) )
            cell.at(i) = textures->getPickMeCell();
}

void TicTacToe::drawTurns()
{
    for( int i = 0; i < GRID_SIZE; i++)
    {
        if(turns[i] == 'X')
        {
            cell.at(i) = textures->getXCell();
        }

        if(turns[i] == 'O')
        {
            cell.at(i) = textures->getOCell();
        }
    }
}

void TicTacToe::drawWinner()
{
    checkRows();
    checkColumns();
    checkDiagonals();
}

void TicTacToe::checkRows()
{
    if(turns[0] == 'X' && turns[1] == 'X' && turns[2] == 'X' )
        winner = textures->getWinnerXCell().first;

    if(turns[3] == 'X' && turns[4] == 'X' && turns[8] == 'X' )
        winner = textures->getWinnerXCell().first;

    if(turns[6] == 'X' && turns[7] == 'X' && turns[8] == 'X' )
        winner = textures->getWinnerXCell().first;

    if(turns[0] == 'O' && turns[1] == 'O' && turns[2] == 'O' )
        winner = textures->getWinnerOCell().second;

    if(turns[3] == 'O' && turns[4] == 'O' && turns[8] == 'O' )
        winner = textures->getWinnerOCell().second;

    if(turns[6] == 'O' && turns[7] == 'O' && turns[8] == 'O' )
        winner = textures->getWinnerOCell().second;

    //////    0 ,1, 2,
    //////    3, 4, 5,
    //////    6 ,7, 8,

}

void TicTacToe::checkColumns()
{
    if(turns[0] == 'X' && turns[3] == 'X' && turns[6] == 'X' )
        winner = textures->getWinnerXCell().first;

    if(turns[1] == 'X' && turns[4] == 'X' && turns[7] == 'X' )
        winner = textures->getWinnerXCell().first;

    if(turns[2] == 'X' && turns[5] == 'X' && turns[8] == 'X' )
        winner = textures->getWinnerXCell().first;

    if(turns[0] == 'O' && turns[3] == 'O' && turns[6] == 'O' )
        winner = textures->getWinnerOCell().second;

    if(turns[1] == 'O' && turns[4] == 'O' && turns[7] == 'O' )
        winner = textures->getWinnerOCell().second;

    if(turns[2] == 'O' && turns[5] == 'O' && turns[8] == 'O' )
        winner = textures->getWinnerOCell().second;

    //////    0, 3, 6,
    //////    1, 4, 7,
    //////    2, 5, 8,
}

void TicTacToe::checkDiagonals()
{
    if(turns[0] == 'X' && turns[4] == 'X' && turns[8] == 'X' )
        winner = textures->getWinnerXCell().first;

    if(turns[6] == 'X' && turns[4] == 'X' && turns[2] == 'X' )
        winner = textures->getWinnerXCell().first;

    if(turns[0] == 'O' && turns[4] == 'O' && turns[8] == 'O' )
        winner = textures->getWinnerOCell().second;

    if(turns[6] == 'O' && turns[4] == 'O' && turns[2] == 'O' )
        winner = textures->getWinnerOCell().second;

    //////    0, 4, 8
    //////    6, 4, 2
}

void TicTacToe::renderTextures()
{
    if(SDL_RenderCopy( renderer, textures->getBG(), NULL, NULL ) == -1)
    {
        std::cout << "First RenderCopy error: " << SDL_GetError() << std::endl;
    }

    for( int i = 0; i < cell.size();i++)
    {
        if(SDL_RenderCopy( renderer, cell[i], NULL, &grid[i] ) == -1)
        {
            std::cout << "Second RenderCopy error: " << SDL_GetError() << std::endl;
        }
    }

    if(winner != NULL)
    {
        SDL_RenderCopy( renderer, winner, NULL, NULL );
    }
}

void TicTacToe::handleEvent(SDL_Event event)
{
    int x, y;

    if(event.type == SDL_MOUSEBUTTONUP)
    {
        SDL_GetMouseState( &x, &y );
        for( int i = 0; i < GRID_SIZE; i++)
        {
            if(turns[i] == NULL)
            {
                if( isMouseInsideCell(x, y, grid[i]) )
                    if(xturn == 'X')
                    {
                        xturn = ' ';
                        turns[i] = 'X';
                    }
                    else
                    {
                        xturn = 'X';
                        turns[i] = 'O';
                    }
            }
         }
    }
    else if (event.key.keysym.sym == SDLK_RETURN)
    {
        winner = NULL;
        for( int i = 0; i < GRID_SIZE; i++)
        {
            turns[i] = NULL;

        }
    }

    if(event.key.keysym.sym == SDLK_ESCAPE )
    {
        startNewGame = MENU;
    }

}

int TicTacToe::changeGame()
{
    return startNewGame;
}

bool TicTacToe::isMouseInsideCell(int x, int y, SDL_Rect rect)
{
    bool inside = true;
    if( x < rect.x )
        inside = false;
    else if( x > rect.x + TEXTURE_WIDTH )
        inside = false;
    else if( y < rect.y )
        inside = false;
    else if( y > rect.y + TEXTURE_HEIGHT )
        inside = false;

    return inside;
}
