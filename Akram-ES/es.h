#ifndef ES_H
#define ES_H

#include <SDL/SDL.h>
#include "background.h"

typedef struct Es
{
	SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
	SDL_Surface *image;
} Es;

void initEs(Es *A);

void AfficherEs(Es A, SDL_Surface *screen);

void AnimerEs(Es *A);

void LibererEs(Es *A);

#endif