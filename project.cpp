
/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SL, standard IO, and strings

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1000 ;
const int SCREEN_HEIGHT = 600 ;



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



bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "tanksGod", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
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

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

SDL_Surface* loadSurface( string path )
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( "bg.bmp" );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}

	return loadedSurface;
}


int main( int argc, char* args[] )
{
	
	//key pushes
	bool ka = false;
	bool kd = false;
	bool ku = false;
	bool kr = false;
	bool kl = false;
	bool kD = false;
	
	
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
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					
					//User presses a key
					else if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{
							
							//exit
							case SDLK_y:
							{
								return 0;
								break;
							}
								
							
							case SDLK_UP:
							{
								ku=true;
								break;
							}
							
							
							case SDLK_DOWN:
							{
								
								break;
							}
							
							
							case SDLK_LEFT:
							{
								kl=true;
								if ( r<670 )
									r = 670;
								break;
							}
							
							
							case SDLK_RIGHT:
							{
								kr=true;
								break;
							}	
							
							
							//tank pipe
							case SDLK_d:
							{
								kd = true;
							}

							
							case SDLK_a:
							{
								ka = true;
							}

							
						}
					}
					
						 if (e.type == SDL_KEYUP)
						{
						
						

							if (e.key.keysym.sym == SDLK_d)						
								kd = false;
							

							if (e.key.keysym.sym == SDLK_a)
								ka = false;
										
							if (e.key.keysym.sym == SDLK_UP)
								ku = false;
										
							if (e.key.keysym.sym == SDLK_RIGHT)				
								kr=false;	
													
							if (e.key.keysym.sym == SDLK_LEFT)			
								kl=false;
								
							if (e.key.keysym.sym == SDLK_DOWN)			
								kD=false;

						}
				}

				
				//tank body
				
				if ( kl == true )
				{
					r += -13;
				}
				
				if ( kr == true )
				{
					r += 13;
				}
				
				if ( kD == true )
				{
					s += 13;
				}
				
				if ( ku == true )
				{
					s -= 13;
				}
				
				if ( ku == true && kr == true )
				{
					//rotate the tank body to front right
				}
				
				if ( ku == true && kl == true )
				{
					//rotate the tank body to front left
				}
				
				if ( kD == true && kr == true )
				{
					//rotate the tank body to back right
				}
				
				
				if ( kD == true && kl == true )
				{
					//rotate the tank body to back left
				}
				
				
				
				//tank pipe
				
				if ( kd == true )
				{	   
					//rotate tank pipe to right
				}
				
				if ( ka == true )
				{
					//rotate tank pipe to left
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
					

				//Apply the current image
				SDL_BlitSurface( gBackGround, NULL, gScreenSurface, NULL );
			
				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
				
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
