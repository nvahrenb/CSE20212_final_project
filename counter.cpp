#include"box.h"
#include"counter.h"

// Constructor
Counter::Counter(int newWidth, int newHeight, int newX, int newY, int newFontSize, string newMessage, int newCountValue)
{
	setWidth(newWidth);
	setHeight(newHeight);
	setX(newX);
	setY(newY);
	
	setFontSize(newFontSize);
	setMessage(newMessage);

	renderBox();

	setCountValue(newCountValue);
}

// Get function
int Counter::getCountValue()
{
	return countValue;
}

// Set function
void Counter::setCountValue(int newCountValue)
{
	countValue = newCountValue;
}

// Update based on events
int Counter::update(SDL_Event event)
{	
	string newMessage;
	ostringstream convert;
	
	convert << getCountValue();
	newMessage = convert.str();
	setMessage(newMessage);	
	renderBox();
}
