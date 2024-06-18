/**
 * @file ennemi.c
 * @author @Akram akram.louati@esprit.tn
 * @brief 
 * @version 0.1
 * @date 2021-04-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "H.h"

void InitGhool(Ghool *E)
{
	E->image = IMG_Load("IMG/ES/BurningGhoulL.png");
	SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));

	E->positionAbsolue.x = 1100;
	E->positionAbsolue.y = 370;
	E->positionAbsolue.w = Ghool_WIDTH;
	E->positionAbsolue.h = Ghool_HEIGHT;
	E->positionAnimation.x = 0;
	E->positionAnimation.y = 0;
	E->positionAnimation.w = Ghool_WIDTH;
	E->positionAnimation.h = Ghool_HEIGHT;
	E->direction = 2;
}

void AfficherGhool(Ghool E, SDL_Surface *screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation, screen, &E.positionAbsolue);
}
void AnimerGhool(Ghool *E)
{
	if (E->direction == 1)
	{
		E->image = IMG_Load("IMG/ES/BurningGhoulR.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	}
	else if (E->direction == 2)
	{
		E->image = IMG_Load("IMG/ES/BurningGhoulL.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	}
	E->positionAnimation.x += Ghool_WIDTH;
	E->positionAnimation.x = E->positionAnimation.x % (Ghool_WIDTH * 16);
}

void DeplacerGhool(Ghool *E)
{

	if (E->direction == 1 && E->positionAbsolue.x < 1100)
	{
		E->positionAbsolue.x += 20;
	}
	else if (E->positionAbsolue.x == 1100)
	{
		E->direction = 2;
	}
	if (E->direction == 2 && E->positionAbsolue.x > 100)
	{
		E->positionAbsolue.x -= 20;
	}
	else if (E->positionAbsolue.x == 100)
	{
		E->direction = 1;
	}
}

int CollGhool(Ghool E, Hero H)
{
	if ((E.positionAbsolue.x + E.positionAbsolue.w < H.position.x) || (E.positionAbsolue.x > H.position.x + H.position.w - 80) ||
		(E.positionAbsolue.y + E.positionAbsolue.h < H.position.y) || (E.positionAbsolue.y > H.position.y + H.position.h - 80))
	{
		return 0; // pas de collision
	}
	else
		return 1;
}

void LibererGhool(Ghool *E)
{
	SDL_FreeSurface(E->image);
	//Mix_FreeChunk(E->DK);
}

