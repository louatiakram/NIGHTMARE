#ifndef ENNEMI_H
#define ENNEMI_H

#include <SDL/SDL.h>
#include "background.h"
#include "es.h"

typedef struct Ennemi
{
	SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
	SDL_Surface *image;
	Mix_Chunk *DK;
	Mix_Chunk *BOOM;
	Mix_Chunk *OVER;
	int direction;
} Ennemi;

void initEnnemi(Ennemi *E);

void AfficherEnnemi(Ennemi E, SDL_Surface *screen);

void AnimerEnnemi(Ennemi *E);

void Deplacer(Ennemi *E);

int collisionBB(Ennemi E, Es A);

void LibererEnnemi(Ennemi *E);

#endif