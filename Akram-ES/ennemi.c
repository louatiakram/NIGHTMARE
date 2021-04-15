#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "defs.h"
#include "ennemi.h"
#include "es.h"
#include "background.h"

void initEnnemi(Ennemi *E)
{
	E->BOOM = Mix_LoadWAV("SON/Boom.wav");
	E->DK = Mix_LoadWAV("SON/DK.wav");
	E->OVER = Mix_LoadWAV("SON/Over.wav");
	Mix_PlayChannel(-1, E->DK, -1);

	E->image = IMG_Load("IMG/DemonKR.png");
	SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 255, 255, 255));

	E->positionAbsolue.x = 60;
	E->positionAbsolue.y = 140;
	E->positionAbsolue.w = Ennemi_WIDTH;
	E->positionAbsolue.h = Ennemi_HEIGHT;
	E->positionAnimation.x = 0;
	E->positionAnimation.y = 0;
	E->positionAnimation.w = Ennemi_WIDTH;
	E->positionAnimation.h = Ennemi_HEIGHT;
	E->direction = 1;
}

void AfficherEnnemi(Ennemi E, SDL_Surface *screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation, screen, &E.positionAbsolue);
}
void AnimerEnnemi(Ennemi *E)
{
	if (E->direction == 1)
	{
		E->image = IMG_Load("IMG/DemonKR.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 255, 255, 255));
	}
	else if (E->direction == 2)
	{
		E->image = IMG_Load("IMG/DemonKL.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 255, 255, 255));
	}
	E->positionAnimation.x += Ennemi_WIDTH;
	E->positionAnimation.x = E->positionAnimation.x % (Ennemi_WIDTH * 2);
	SDL_Delay(80);
}

void Deplacer(Ennemi *E)
{
	if (E->direction == 1 && E->positionAbsolue.x < 800)
	{
		E->positionAbsolue.x += 20;
	}
	else if (E->positionAbsolue.x == 800)
	{
		E->direction = 2;
	}
	if (E->direction == 2 && E->positionAbsolue.x > 60)
	{
		E->positionAbsolue.x -= 20;
	}
	else if (E->positionAbsolue.x == 60)
	{
		E->direction = 1;
	}
}

int collisionBB(Ennemi E, Es A)
{
	if ((E.positionAbsolue.x + E.positionAbsolue.w < A.positionAbsolue.x) || (E.positionAbsolue.x > A.positionAbsolue.x + A.positionAbsolue.w) ||
		(E.positionAbsolue.y + E.positionAbsolue.h < A.positionAbsolue.y) || (E.positionAbsolue.y > A.positionAbsolue.y + A.positionAbsolue.h))
	{
		return 0; // pas de collision
	}
	else
		return 1;
}

void LibererEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
	Mix_FreeChunk(E->DK);
	Mix_FreeChunk(E->BOOM);
	Mix_FreeChunk(E->OVER);
}
