/******************

Chris Ray
Nathan Vahrenberg

box.h

*******************/
#ifndef BOX_H
#define BOX_H

#include <iostream>
#include<iomanip>
#include<string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"

using namespace std;

class Box
{
	public:
		Box();
		void display(SDL_Surface *);
		void setX(int);
		void setY(int);
		void setHeight(int);
		void setWidth(int);
		void setMessage(string);
		void setFontSize(int);
		int getX();
		int getY();
		int getHeight();
		int getWidth();
		string getMessage();
		int getFontSize();
		void renderBox();
		virtual void update() = 0;
	
	private:
		int height;
		int width;
		int x;
		int y;
		string message;

		int fontSize;
		SDL_Rect box;
		TTF_font * font;
		SDL_Color textColor;
		SDL_Surface * messageSurface;
		
};

#endif