//Christopher Ray, Nathan Vahrenberg
//Professor Scott
//CSE 20212
//April 29, 2014

//Power.cpp
//Implmentation for Power class, for use with Power.h in slayerz

#include <cmath>
#include"item.h"
#include"Power.h"

Power::Power(int newX, int newY, int newType)
{
	setX(newX); 						//setting x and y coordinates type of powerup
	setY(newY);
	setType(newType);

	yOffset = 0.0; 						//initializing variables for floating animation
	t = 0.0;
	PowerImage = optimizeImage("sprites/powerups.bmp"); 	//loading powerup image
}

SDL_Surface * Power::optimizeImage(string filename)
{
	SDL_Surface * tempImage = NULL; 			//temporary surface to hold uploaded image
	SDL_Surface * optimized = NULL; 			//surface that will be output

	tempImage = IMG_Load(filename.c_str()); 		//loading the desired image

	if(tempImage != NULL) 					//this is here just in case there is an issue loading the image
	{
		optimized = SDL_DisplayFormat(tempImage); 	//optimized is now the uploaded image
		SDL_FreeSurface(tempImage); 			//freeing tempImage memory

		if( optimized != NULL ) 			//here just in case there was an issue with optimized
		{
		    Uint32 colorkey = SDL_MapRGB( optimized->format, 255, 255, 255 ); //this prevents white (color of image background) from being displayed
		    SDL_SetColorKey( optimized, SDL_SRCCOLORKEY, colorkey ); 	//this in effect creates a transparent background for the powerup
		}
	}

	return optimized;
}

void Power::display(SDL_Surface* destination )
{
	yOffset = 8*sin( t ); 						//calculating y offset for floating animation
	t += 0.1;
	if (t >= 2*M_PI){
		t = 0;
	}

	SDL_Rect offset;

	offset.x = getX(); 						//setting the coordinates for the source surface on the destination surface (the screen)
	offset.y = getY() + yOffset;

	chooseImage();

	SDL_BlitSurface( PowerImage, &clip, destination, &offset ); 	//applying the clip of the source surface to the destination surface (the screen)
}

void Power::cleanImage()
{
	SDL_FreeSurface(PowerImage);
}

void Power::chooseImage()
{
	if(getType() == 1) 		//type 1 corresponds to the mic powerup (kill all enemies on screen)
	{
		clip.x = 0;
		clip.w = 50;
		clip.y = 0;
		clip.h = 50;
	}
	else if(getType() == 4) 	//type 4 corresponds to the drum powerup (freeze all enemies on screen)
	{
		clip.x = 50;
		clip.w = 50;
		clip.y = 0;
		clip.h = 50;
	}
	else if(getType() == 2) 	//type 2 corresponds to the guitar powerup (slow all enemies on screen)
	{
		clip.x = 0;
		clip.w = 50;
		clip.y = 50;
		clip.h = 50;
	}
	else 				//type 3 corresponds to the bass powerup (reduce attack power of all enemies on screen)
	{
		clip.x = 50;
		clip.w = 50;
		clip.y = 50;
		clip.h = 50;
	}
}
