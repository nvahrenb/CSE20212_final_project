//Christopher Ray, Nathan Vahrenberg
//Professor Scott
//CSE 20212
//29 April 2014

//terrain.h
//Header file for Terrain class, for use with terrain.cpp in slayerz

#ifndef TERRAIN_H
#define TERRAIN_H

#include "item.h"

class Terrain : public Item 				//Power class inherits from Item class
{
	public:
		Terrain(int, int, int); 		//constructor
		void display(SDL_Surface *); 		//function for displaying terrain on screen
		void Free_Memory(); 			//function for freeing memory or terrain image
		
	private:
		SDL_Surface * TerrainImage; 		//the image for the terrain 
		SDL_Surface * optimizeImage(string); 	//function for optimizing an uploaded image (creating transparent background)
};


#endif
