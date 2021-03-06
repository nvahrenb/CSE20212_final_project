//Christopher Ray, Nathan Vahrenberg
//Professor Scott
//CSE 20212
//29 April 2014

//zombie.h
//Header file for Zombie class, for use with zombie.cpp in slayerz

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <iomanip>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

using namespace std;

class Zombie
{
	public:
		Zombie(); 			//constructor
		void update( int, int ); 	//function for updating position, stats, and status depending on Player location
		void display( SDL_Surface* ); 	//function for displaying player on screen (handles animations specifically)
		int attack( int, int ); 	//function for attacking (specifically outputting damage amount)
		int isDead(); 			//returns 1 if the zombie is dead, 0 if it's still fighting
		void applyDamage(int); 		//function for taking damage
		void Free_Memory(); 		//function for freeing zombie image and audio
		int getX(); 			//returns zombie's x coordinate
		int getY(); 			//returns zombie's y coordinate
		int getDirection(); 		//returns the direction the zombieis facing (-1 for left, 1 for right)
		int getPoints(); 		//returns the point value for each zombie
		void setEnable(int); 		//used to set the value of enable (used for pausing the game)
		void setHandicap(int); 		//used to change zombie stats depending on the type of powerup used
	
	
	private:
		int x; 				//zombie's x coordinate
		int y; 				//zombie's y coordinate
		int health; 			//zombie's health
		int speed; 			//zombie's speed
		int power; 			//zombie's attack power
		int xVel; 			//zombie's x velocity
		int yVel; 			//zombie's y velocity
		int direction; 			//direction zombie is facing
		int isStanding; 		//returns 1 if the zombie is standing
		int isAttacking; 		//returns 1 if the zombie is attacking
		int isDying; 			//returns 1 if the zombie is dying
		int Dead; 			//1 if dead, 0 if alive
		int points; 			//how many points a zombie is worth
		int enable; 			//if 1, zombie can move, attack, be damaged, etc; if 0, zombie is effectively suspended or paused
		int handicap; 			//corresponds to the powerup used (1 = mic, 2 = guitar, 3 = bass, 4 = drums)
		SDL_Surface* SpriteZombie; 	//zombie image
		SDL_Rect moving[3]; 		//clips for moving (right)
		SDL_Rect attacking[3]; 		//clips for attacking (right)
		SDL_Rect movingL[3]; 		//clips for moving (left)
		SDL_Rect attackingL[3]; 	//clips for attacking (left)
		SDL_Rect dying[10]; 		//death animation clips
		Mix_Chunk * spawn; 		//sound effect for spawning
		Mix_Chunk * die; 		//death sound effect
		int clipSelect; 		//used to increment through the clip arrays

		SDL_Surface * optimizeImage(string); 						//function for optimizing an uploaded image

		void apply_zombie_sprite(int, int, SDL_Surface *, SDL_Surface *, SDL_Rect *); 	//function for displaying zombie image on screen 
	
};

#endif
