#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;


//Screen dimension constants
const int SCREEN_WIDTH = 2000;
const int SCREEN_HEIGHT = 2000;


//tank body
float r = 60 ;
float s = 740 ;

//tank pipe 
float p ;
float q ;


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();


//The window renderer
SDL_Renderer* gRenderer = NULL;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gBackGround = NULL;


//initializing SDL
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "tanksGod", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}
	
	return success;
}



bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gBackGround = SDL_LoadBMP( "bg.bmp" );
	if( gBackGround == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
		success = false;
	}
	
	return success;
}


void close()
{
	//Deallocate surface
	SDL_FreeSurface( gBackGround );
	gBackGround = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{


	SDL_Event event;
	
	//key pushes
	bool ka = false;
	bool kd = false;
	bool ku = false;
	bool kr = false;
	bool kl = false;
	bool kD = false;
	
	//boxRGBA ( gBackGround , 0 , 0 , 1200 , 800 , 0 , 0 , 0 , 255 );

	SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );        
	SDL_RenderFillRect( gRenderer, &fillRect );
	
	//Render green outlined quad
    SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );        
    SDL_RenderDrawRect( gRenderer, &outlineRect );

		
	//key press
	if ( SDL_PollEvent(&event) );
	{
		if (event.type == SDL_QUIT)
			return 0;

		if (event.type == SDL_KEYDOWN)
		{
			
			//exit
			if (event.key.keysym.sym == SDLK_y)
				//return 0;
				cout<<"y as exit works"<<endl;
				
				
			//player 1 left side movement

			if (event.key.keysym.sym == SDLK_d)
			{
				cout<<"d works"<<endl;
				kd = true;
			}

			if (event.key.keysym.sym == SDLK_a)
				ka = true;




			//player 2 right side movement	
			if (event.key.keysym.sym == SDLK_UP)
				ku=true;


			if (event.key.keysym.sym == SDLK_RIGHT)
				kr=true;



			if (event.key.keysym.sym == SDLK_LEFT)
				kl=true;

			if ( r<670 )
				r = 670;
				
				
			if (event.key.keysym.sym == SDLK_DOWN)
				kD=true;



		}

		
		
		if (event.type == SDL_KEYUP)
		{
		
		

			if (event.key.keysym.sym == SDLK_d)
				kd = false;


			if (event.key.keysym.sym == SDLK_a)
				ka = false;
						
			if (event.key.keysym.sym == SDLK_UP)
				ku = false;
						
			if (event.key.keysym.sym == SDLK_RIGHT)				
				kr=false;	
									
			if (event.key.keysym.sym == SDLK_LEFT)			
				kl=false;
				
			if (event.key.keysym.sym == SDLK_DOWN)			
				kD=false;

		}


	if(kl==true)
	{
		r += -13;
	}
	
	if(kr==true)
	{
		r += 13;
	}
	
	if (kd == true)
	{	   
		p += 13;
	}
	
	if (ka == true)
	{
		p += -13;
	}
	
	
	//controls for not leaving window
	
	if ( r>1140 )
		r = 1140;

	if ( p<60 )
		p = 60;

	if ( p> 530 )
		p = 530;

	if ( q>740 )
		q = 740;
	
	if ( s<60 )
		s = 60;
		
	if ( q > 740 )
		q = 740;
	
	if ( s > 740 )
		s = 740;
	if ( s < 60 )
		s = 60;
		
	if ( p> 530 )
		p = 530;
	if ( p<60 )
		p = 60;
			
	if ( r>1140 )
		r = 1140;
	if ( r<670 )
		r = 670;
		
                
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			while(true){
					std::cout<<"f\n";
								//Apply the image
					SDL_BlitSurface( gBackGround , NULL , gScreenSurface , NULL );
					std::cout<<"f\n";
					//Update the surface
					SDL_UpdateWindowSurface( gWindow );
					std::cout<<"f\n";
					SDL_Delay( 20 );
				}
			}
		}
	}
	
	
	//Wait two seconds
	SDL_Delay( 2000 );	
	

	//Free resources and close SDL

	close();

	return 0;
}
