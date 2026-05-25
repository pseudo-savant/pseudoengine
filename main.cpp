#include <stdio.h>
#include <cstdlib>
#include <SDL.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

char windowTitle[64];

std::vector<SDL_Scancode> inputStack;

int main( int argc, char* args[] ){
    
    SDL_Window* window = NULL;
    
    SDL_Renderer* gRenderer = NULL;
    
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
        } else {
            gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
			}
			else
			{
                screenSurface = SDL_GetWindowSurface( window );

                //Fill the surface white
                SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xA0, 0xA0, 0xA0 ) );
                
                //Update the surface
                SDL_UpdateWindowSurface( window );

                //Hack to get window to stay up
                
                SDL_Event e; 
                bool quit = false; 
                while( quit == false ){
                    while( SDL_PollEvent( &e ) ){

                        if( e.type == SDL_QUIT ) quit = true; 
                        else if( e.type == SDL_KEYDOWN ){
                            inputStack.push_back(e.key.keysym.scancode);
                        }
                        if (std::find(inputStack.begin(), inputStack.end(), SDL_SCANCODE_W) != inputStack.end()){
                            SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
                            SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );		
				            SDL_RenderFillRect( gRenderer, &fillRect );
                            printf("lol");
                        }
                    }
                }
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );
                SDL_DestroyWindow( window );
                window = NULL;
	            gRenderer = NULL;
                SDL_Quit();
            }
    

        return 0;
        }
    }
}