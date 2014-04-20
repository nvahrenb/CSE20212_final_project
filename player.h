/******************

Chris Ray
Nathan Vahrenberg

*******************/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include"iomanip"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

using namespace std;

class Player{

	public:
		Player();
		void display( SDL_Surface* );
		void update( SDL_Event );
		//void move();
		int attack(int, int);
		void apply_damage( int );
		int isDead();
		void Free_Memory();
		int getX();
		int getY();
		
	private:
		int x;
		int y;
		int xVel;
		int yVel;
		int direction;
		int health;
		int speed;
		int power;
		SDL_Surface* spritePC;
		SDL_Surface* spritePCL;
		SDL_Rect standing[8];
		SDL_Rect moving[8];
		SDL_Rect attacking[6];
		SDL_Rect standingL[8];
		SDL_Rect movingL[8];
		SDL_Rect attackingL[6];
		SDL_Rect jumping[8];
		SDL_Rect jumpingL[8];
		SDL_Event event;
		int clipSelect;
		int isStanding;
		int isAttacking;
		int isJumping;
		int Dead;
		int recoil;

		SDL_Surface * optimizeImage(string);

};

#endif
