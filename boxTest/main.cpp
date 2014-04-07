#include"text.h"

int main( int argc, char* args[] )
{
	int screenWidth = 960;
	int screenHeight = 600;
	int screenBPP = 32;
	int quit = 0;

	SDL_Surface * screen = NULL;
	
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Event event;

	screen = SDL_SetVideoMode(screenWidth, screenHeight, screenBPP, SDL_SWSURFACE);
	SDL_WM_SetCaption("Box Test", NULL);
	
	Text textBox(300, 50, 10, 10, 40, "WEESNAW");
	
	while (quit == 0){
	
		while( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_QUIT )
			{
				quit = 1;
			}

			textBox.display(screen);
	
			SDL_Flip( screen );
	
			SDL_Delay( 100 );
		}
	
	}

	textBox.cleanBox();
	TTF_Quit();
	SDL_Quit();
	
	return 0;
}
