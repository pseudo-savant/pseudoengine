#include <stdio.h>
#include <cstdlib>
#include <SDL.h>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

char windowTitle[64];

int main( int argc, char* args[] ){
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    } else
    {
        strcpy(windowTitle, "pseudoengine v0.0.1");
        printf("SDL initialized successfully. Creating window...");
        //Create window
        window = SDL_CreateWindow( windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
    
    }
    return 0;
}