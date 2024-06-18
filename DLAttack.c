/**
 * @file DLAttack.c
 * @author @Akram akram.louati@esprit.tn
 * @brief 
 * @version 0.1
 * @date 2021-05-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "H.h"

void InitEnnemiA(EnnemiA *E)
{
	E->DemonLA = Mix_LoadWAV("SON/Fire.wav");
	
	E->image = IMG_Load("IMG/ES/DemonLordLA.png");
	SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	E->positionAbsolue.w = EnnemiA_WIDTH;
	E->positionAbsolue.h = EnnemiA_HEIGHT;
	E->positionAnimation.x = 0;
	E->positionAnimation.y = 0;
	E->positionAnimation.w = EnnemiA_WIDTH;
	E->positionAnimation.h = EnnemiA_HEIGHT;
	E->direction = 2;
}

void AfficherEnnemiA(EnnemiA E, SDL_Surface *screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation, screen, &E.positionAbsolue);
}
void AnimerEnnemiA(EnnemiA *E)
{
	if (E->direction == 1)
	{
		E->image = IMG_Load("IMG/ES/DemonLordRA.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	}
	else if (E->direction == 2)
	{
		E->image = IMG_Load("IMG/ES/DemonLordLA.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	}
	E->positionAnimation.x += EnnemiA_WIDTH;
	E->positionAnimation.x = E->positionAnimation.x % (EnnemiA_WIDTH * 11);
	SDL_Delay(40);
}

void DeplacerEA(EnnemiA *E)
{
	//Horizantale
	if (E->direction == 1 && E->positionAbsolue.x < 1100)
	{
		E->positionAbsolue.x += 20;
	}
	else if (E->positionAbsolue.x == 1100)
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
	//Verticale
	if (E->etat == 2 || E->etat == 4)
	{
		if (E->positionAbsolue.y < 300 && E->direction == 2)
		{
			E->positionAbsolue.y += 20;
		}
		else if (E->positionAbsolue.y == 300)
		{
			E->positionAbsolue.y -= 200;
		}
		if (E->positionAbsolue.y > 80 && E->direction == 1)
		{
			E->positionAbsolue.y -= 20;
		}
		else if (E->positionAbsolue.y == 80)
		{
			E->positionAbsolue.y += 200;
		}
	}
}

void DeplacerIAA(EnnemiA *E, Hero *H)
{
	E->s1 = E->positionAbsolue.x - 500;
	E->s2 = E->positionAbsolue.x - 200;
	E->s3 = E->positionAbsolue.x + 500;
	E->s4 = E->positionAbsolue.x + 200;

	if (H->position.x > E->s1 && H->position.x < E->s2 && E->direction == 2)
	{
		E->etat = 1;
	}
	else if (H->position.x >= E->s2 && E->direction == 2)
	{
		E->etat = 2;
	}
	else if (H->position.x < E->s3 && H->position.x > E->s4 && E->direction == 1)
	{
		E->etat = 3;
	}
	else if (H->position.x <= E->s4 && E->direction == 1)
	{
		E->etat = 4;
	}
	else
		E->etat = 0;
}

void LibererEnnemiA(EnnemiA *E)
{
	SDL_FreeSurface(E->image);
	Mix_FreeChunk(E->DemonLA);
}
