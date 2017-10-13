#ifndef CONSTANTS_H
#define CONSTANTS_H

//const char* SCREEN_NAME = "TicTacToe";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int TEXTURE_WIDTH = SCREEN_WIDTH / 3;
const int TEXTURE_HEIGHT = SCREEN_HEIGHT / 3;
const int MENU_WIDTH = SCREEN_WIDTH;
const int MENU_HEIGHT = SCREEN_HEIGHT / 2;
const int SCALED_TEXTURE_WIDTH = TEXTURE_WIDTH * .8;
const int SCALED_TEXTURE_HEIGHT = TEXTURE_HEIGHT * .8;
const int SCALED_GAP_WIDTH = TEXTURE_WIDTH * .2;
const int SCALED_GAP_HEIGHT = TEXTURE_HEIGHT * .2;
const int GRID_SIZE = 9;
const int MENU_SIZE = 2;
const int FONT_SIZE = 150;

enum game {
    NOTHING,
    QUIT,
    MENU,
    TICTACTOE,
};

#endif // CONSTANTS_H
