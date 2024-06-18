/**
 * @file Ghost.c
 * @author @Akram akram.louati@esprit.tn
 * @brief 
 * @version 0.1
 * @date 2021-05-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "H.h"

void InitGhost(Ghost *E)
{
	E->image = IMG_Load("IMG/ES/GhostShriek.png");
	SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));

	E->positionAbsolue.x = 1100;
	E->positionAbsolue.y = 370;
	E->positionAbsolue.w = Ghost_WIDTH;
	E->positionAbsolue.h = Ghost_HEIGHT;
	E->positionAnimation.x = 0;
	E->positionAnimation.y = 0;
	E->positionAnimation.w = Ghost_WIDTH;
	E->positionAnimation.h = Ghost_HEIGHT;
	E->direction = 2;
}

void AfficherGhost(Ghost E, SDL_Surface *screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation, screen, &E.positionAbsolue);
}
void AnimerGhost(Ghost *E)
{
	if (E->direction == 1)
	{
		E->image = IMG_Load("IMG/ES/GhostShriek.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	}
	else if (E->direction == 2)
	{
		E->image = IMG_Load("IMG/ES/GhostShriek.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	}
	E->positionAnimation.x += Ghost_WIDTH;
	E->positionAnimation.x = E->positionAnimation.x % (Ghost_WIDTH * 4);
}

void DeplacerGhost(Ghost *E)
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

int CollGhost(Ghost E, Hero H)
{
	if ((E.positionAbsolue.x + E.positionAbsolue.w < H.position.x) || (E.positionAbsolue.x > H.position.x + H.position.w - 80) ||
		(E.positionAbsolue.y + E.positionAbsolue.h < H.position.y) || (E.positionAbsolue.y > H.position.y + H.position.h - 80))
	{
		return 0; // pas de collision
	}
	else
		return 1;
}

void LibererGhost(Ghost *E)
{
	SDL_FreeSurface(E->image);
}

