/******************

Chris Ray
Nathan Vahrenberg

box.cpp

*******************/

#include "box.h"

using namespace std;

// Constructor
Box::Box()
{
	height = 100;
	width = 100;
	x = 0;
	y = 0;
	message = "Foo";
	fontSize = 40;

	box.x = x;
	box.y = y;
	box.w = width;
	box.h = height;	
	boxR = 255;
	boxG = 255;
	boxB = 255;

	messageSurface = NULL;
	font = NULL;
}

// Set functions
void Box::setX(int newX)
{
	x = newX;
	box.x = x;
}

void Box::setY(int newY)
{
	y = newY;
	box.y = y;
}

void Box::setHeight(int newHeight)
{
	height = newHeight;
	box.h = height;
}

void Box::setWidth(int newWidth)
{
	width = newWidth;
	box.w = width;
}

void Box::setMessage(string newMessage)
{
	message = newMessage;
}

void Box::setFontSize(int newFontSize)
{
	fontSize = newFontSize;
}

void Box::setTextColor(Uint8 red, Uint8 green, Uint8 blue)
{
	textColor = {red, green, blue};
}

void Box::setBoxColor(Uint8 red, Uint8 green, Uint8 blue)
{
	boxR = red;
	boxG = green;
	boxB = blue;
}

// Get functions
int Box::getX()
{
	return x;
}

int Box::getY()
{
	return y;
}

int Box::getHeight()
{
	return height;
}

int Box::getWidth()
{
	return width;
}

string Box::getMessage()
{
	return message;
}

// Sends box to render function
void Box::display(SDL_Surface* destination )
{
	SDL_Rect offset;

	offset.x = getX();
	offset.y = getY();

	SDL_FillRect(destination, &box, SDL_MapRGB(destination->format, boxR, boxG, boxB));

	SDL_BlitSurface( messageSurface, NULL, destination, &offset );
}

// Applies box to screen
void Box::renderBox()
{
	if((font != NULL) && (messageSurface != NULL))
	{
		cleanBox();
	}	

	font = TTF_OpenFont("LIVINGBY.TTF", fontSize);
	setTextColor(0, 0, 0);
	messageSurface = TTF_RenderText_Solid(font, message.c_str(), textColor);
}

// Free allocated memory
void Box::cleanBox()
{
	SDL_FreeSurface(messageSurface);
	TTF_CloseFont(font);
}
