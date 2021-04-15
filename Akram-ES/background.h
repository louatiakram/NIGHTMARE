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

void initBackground(Background *Backg);
void AfficherBackground(Background *Backg, SDL_Surface *screen);
void LibererBackground(Background *Backg);

#endif