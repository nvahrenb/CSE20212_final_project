#include"terrain.h"
#include"item.h"

Terrain::Terrain(int newX, int newY, int newType)
{
	setx(newX);
	sety(newY);
	setType(newType);

	if(getType() == 1)
	{
		TerrainImage = loadTerrainImage("rock2f.png");
	}
	else if(getType() == 2)
	{
		TerrainImage = loadTerrainImage("tree.png");
	}
}

SDL_Surface * Terrain::loadTerrainImage(string filename)
{
	SDL_Surface* loadedImage = NULL;

	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load( filename.c_str() );

	if( loadedImage != NULL )
	{
		optimizedImage = SDL_DisplayFormat( loadedImage );

		SDL_FreeSurface( loadedImage );

		if( optimizedImage != NULL )
		{
			Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );

			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
		}
	}

	return optimizedImage;
}