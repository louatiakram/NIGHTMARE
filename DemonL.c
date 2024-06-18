/**
 * @file DemonL.c
 * @author @Akram akram.louati@esprit.tn
 * @brief 
 * @version 0.1
 * @date 2021-05-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "H.h"

void InitEnnemi(Ennemi *E)
{
	E->DemonL = Mix_LoadWAV("SON/DL.wav");
	//Mix_PlayChannel(-1, E->DemonL, -1);

	E->image = IMG_Load("IMG/ES/DemonLordL.png");
	SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	E->positionAbsolue.x = 1100;
	E->positionAbsolue.y = 200;
	E->positionAbsolue.w = Ennemi_WIDTH;
	E->positionAbsolue.h = Ennemi_HEIGHT;
	E->positionAnimation.x = 0;
	E->positionAnimation.y = 0;
	E->positionAnimation.w = Ennemi_WIDTH;
	E->positionAnimation.h = Ennemi_HEIGHT;
	E->direction = 2;
	E->etat = 0;
}

void AfficherEnnemi(Ennemi E, SDL_Surface *screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation, screen, &E.positionAbsolue);
}
void AnimerEnnemi(Ennemi *E)
{
	if (E->direction == 1)
	{
		E->image = IMG_Load("IMG/ES/DemonLordR.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	}
	if (E->direction == 2)
	{
		E->image = IMG_Load("IMG/ES/DemonLordL.png");
		SDL_SetColorKey(E->image, SDL_SRCCOLORKEY, SDL_MapRGB(E->image->format, 0, 0, 0));
	}

	E->positionAnimation.x += Ennemi_WIDTH;
	E->positionAnimation.x = E->positionAnimation.x % (Ennemi_WIDTH * 6);
	SDL_Delay(40);
}

void Deplacer(Ennemi *E)
{
	//Horizantale
	if (E->direction == 1 && E->positionAbsolue.x < 1100)
	{
		E->positionAbsolue.x += 5;
	}
	else if (E->positionAbsolue.x == 1100)
	{
		E->direction = 2;
	}
	if (E->direction == 2 && E->positionAbsolue.x > 60)
	{
		E->positionAbsolue.x -= 5;
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
			E->positionAbsolue.y += 10;
		}
		else if (E->positionAbsolue.y == 300)
		{
			E->positionAbsolue.y -= 200;
		}
		if (E->positionAbsolue.y > 80 && E->direction == 1)
		{
			E->positionAbsolue.y -= 10;
		}
		else if (E->positionAbsolue.y == 80)
		{
			E->positionAbsolue.y += 200;
		}
	}
}

int CollisionBB(Ennemi E, Hero H)
{
	if ((E.positionAbsolue.x + E.positionAbsolue.w < H.position.x) || (E.positionAbsolue.x > H.position.x + H.position.w - 80) ||
		(E.positionAbsolue.y + E.positionAbsolue.h < H.position.y) || (E.positionAbsolue.y > H.position.y + H.position.h - 80))
	{
		return 0; // pas de collision
	}
	else
		return 1;
}

void DeplacerIA(Ennemi *E, Hero *H)
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
	else if (H->position.x < E->s4 && E->direction == 1)
	{
		E->etat = 4;
	}
	else if (H->position.x <= E->s3 && H->position.x > E->s4 && E->direction == 1)
	{
		E->etat = 3;
	}
	else
		E->etat = 0;
}

void LibererEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
	//Mix_FreeChunk(E->DemonL);
}
