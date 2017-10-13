#include <iostream>

#include <base.h>
#include <mainloop.h>
#include <textures.h>
//#include <log.h>

using namespace std;

int main(int argc, char *argv[])
{

    SDLInitialization* SDLInit= NULL;
    Textures* GameTextures = NULL;
    MainLoop* Loop = NULL;

    SDLInit = new SDLInitialization();
    SDLInit->initSDL();

    GameTextures = new Textures( SDLInit->getRenderer() );
    GameTextures->loadTextures();

    Loop = new MainLoop(SDLInit->getRenderer(), GameTextures);
    Loop->loop();

    SDLInit->closeSDL();

    cout << "Hello World!" << endl;
    return 0;
}

