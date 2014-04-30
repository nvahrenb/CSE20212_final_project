//Christopher Ray, Nathan Vahrenberg
//Professor Scott
//CSE 20212
//29 April 2014

//text.cpp
//Implementation for Text class, for use with text.h in slayerz

#include"box.h"
#include"text.h"

Text::Text(int newWidth, int newHeight, int newX, int newY, int newFontSize, string newMessage)
{
	setWidth(newWidth); 		//setting text box height, width, x coord, and y coord
	setHeight(newHeight);
	setX(newX);
	setY(newY);
	
	setFontSize(newFontSize); 	//setting font size
	setMessage(newMessage); 	//setting the string to be displayed

	renderBox(); 			//drawing the text box on the screen
}

int Text::update(SDL_Event event)
{
	
}





