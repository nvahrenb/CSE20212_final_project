#include"board.h"

int main( int argc, char* args[] )
{
	Board testBoard;
	SDL_Event event;
	int quit = 0;

	while(quit == 0)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				quit = 1;
			}
			else
			{	
				testBoard.update(event);
			}
		}
	}
	
	testBoard.clean();
		
	return 0;
}
