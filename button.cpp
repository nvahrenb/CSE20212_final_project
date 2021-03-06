#include"box.h"
#include"button.h"

// Constructor
Button::Button(int newWidth, int newHeight, int newX, int newY, int newFontSize, string newMessage)
{
	setWidth(newWidth);
	setHeight(newHeight);
	setX(newX);
	setY(newY);
	
	setFontSize(newFontSize);
	setMessage(newMessage);

	renderBox();
}

// Update button based on events
int Button::update(SDL_Event event)
{
	int x = 0;
	int y = 0; 
	if( event.type == SDL_MOUSEBUTTONDOWN )
	{
		if( event.button.button == SDL_BUTTON_LEFT )
		{
			x = event.button.x; 
			y = event.button.y;
			if( ( x > getX()) && ( x < getX() + getWidth() ) && ( y > getY() ) && ( y < getY() + getHeight() ) ) 
			{
				setBoxColor(255, 255, 0);
				//return 1;
			}
		}
	}

	else if( event.type == SDL_MOUSEBUTTONUP )
	{
		if( event.button.button == SDL_BUTTON_LEFT )
		{
			x = event.button.x; 
			y = event.button.y;
			if( ( x > getX()) && ( x < getX() + getWidth() ) && ( y > getY() ) && ( y < getY() + getHeight() )) 
			{
				setBoxColor(255, 255, 255);
				return 1;
			}
		}
	}
	return 0;
}
