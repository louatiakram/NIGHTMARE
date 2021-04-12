#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>
#include "defs.h"

typedef struct
{
	SDL_Surface *backgroundImg;
	SDL_Surface *backgroundCollide;
	SDL_Rect backgroundPos;
} Background;

void InitBack(Background *Backg);
void AfficherBack(Background *Backg);
void Scrolling(Background *Backg, SDL_Surface *screen);
void LibererBack(Background *Backg);


#endif
