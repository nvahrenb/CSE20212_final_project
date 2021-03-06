/******************

Chris Ray
Nathan Vahrenberg

*******************/

#ifndef AXEBABY_H
#define AXEBABY_H

#include <iostream>
#include<iomanip>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

using namespace std;

class Axebaby
{

	public:
		Axebaby();
		void update( int, int );
		void display( SDL_Surface* );
		int attack( int, int );
		int isDead();
		void applyDamage(int);
		void Free_Memory();
		int getX();
		int getY();
		int getDirection();
		int getPoints();
		void setEnable(int);
		void setHandicap(int);
	
	
	private:
		// Attributes
		int x;
		int y;
		int health;
		int speed;
		int power;
		int xVel;
		int yVel;
		int direction;
		int isStanding;
		int isAttacking;
		int isDying;
		int Dead;
		int points;
		int enable;
		int handicap;
		// Sprites
		SDL_Surface* SpriteAxebaby;
		SDL_Rect moving[4];
		SDL_Rect attacking[1];
		SDL_Rect movingL[4];
		SDL_Rect attackingL[1];
		SDL_Rect dying[9];
		//Sounds
		Mix_Chunk * spawn;
		Mix_Chunk * die;
		
		int clipSelect;
		
		// Private optimize function
		SDL_Surface * optimizeImage(string);
};

#endif
