#ifndef TEXT_H
#define TEXT_H

#include"box.h"

class Text : public Box
{
	public:
		Text(int, int, int, int, int, string);
		virtual int update(SDL_Event );
};	

#endif
