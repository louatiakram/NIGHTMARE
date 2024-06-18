/**
 * @file hero.c
 * @author @Akram akram.louati@esprit.tn
 * @brief 
 * @version 0.1
 * @date 2021-04-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "H.h"

void InitHero(Hero *A)
{
	A->Walk = Mix_LoadWAV("SON/walk.wav");
	A->Jump = Mix_LoadWAV("SON/jump.wav");
	A->Attack = Mix_LoadWAV("SON/sword.wav");
	
	A->HP = IMG_Load("IMG/Background/v0.png");
	A->PosHP.x = 50;
	A->PosHP.y = 20;

	int i;
	char WalkRight[50];
	char walkR0[] = "IMG/Hero/HeroR/HeroR";
	char bmp[] = ".bmp";
	for (i = 0; i < 10; i++)
	{
		sprintf(WalkRight, "%s%d%s", walkR0, i, bmp);
		A->image[i] = SDL_LoadBMP(WalkRight);
		//transparent
		SDL_SetColorKey(A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 0, 0, 0));
	}
	A->vie = 3;
	A->moving = 0;
	A->direction = 0;
	A->position.x = 20;
	A->position.y = SCREEN_H - 70 - A->image[0]->h;
	A->position.w = A->image[0]->w;
	A->position.h = A->image[0]->h;
}

void MoveHero(Hero *A)
{
	if (A->direction == 0) //Right
	{
		int i;
		char WalkRight[50];
		char walkR0[] = "IMG/Hero/HeroR/HeroR";
		char bmp[] = ".bmp";
		for (i = 0; i < 10; i++)
		{
			sprintf(WalkRight, "%s%d%s", walkR0, i, bmp);
			A->image[i] = SDL_LoadBMP(WalkRight);
			//transparent
			SDL_SetColorKey(A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 0, 0, 0));
		}
		A->position.w = A->image[0]->w;
		A->position.h = A->image[0]->h;
	}
	if (A->direction == 1) //Left
	{
		int i;
		char WalkLeft[50];
		char HeroL0[] = "IMG/Hero/HeroL/HeroL";
		char bmp[] = ".bmp";
		for (i = 0; i < 10; i++)
		{
			sprintf(WalkLeft, "%s%d%s", HeroL0, i, bmp);
			A->image[i] = SDL_LoadBMP(WalkLeft);
			//transparent
			SDL_SetColorKey(A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 0, 0, 0));
		}
		A->position.w = A->image[0]->w;
		A->position.h = A->image[0]->h;
	}
	if (A->direction == 2) //Attack Right
	{
		int i;
		char Attack[50];
		char A0[] = "IMG/Hero/Attack/A";
		char bmp[] = ".bmp";
		for (i = 0; i < 8; i++)
		{
			sprintf(Attack, "%s%d%s", A0, i, bmp);
			A->image[i] = SDL_LoadBMP(Attack);
			//transparent
			SDL_SetColorKey(A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 0, 0, 0));
		}
		A->position.w = A->image[0]->w;
		A->position.h = A->image[0]->h;
	}
	if (A->direction == 3) //Death
	{
		int i;
		char Death[50];
		char D0[] = "IMG/Hero/Death/D";
		char bmp[] = ".bmp";
		for (i = 0; i < 9; i++)
		{
			sprintf(Death, "%s%d%s", D0, i, bmp);
			A->image[i] = SDL_LoadBMP(Death);
			//transparent
			SDL_SetColorKey(A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 0, 0, 0));
		}
		A->position.w = A->image[0]->w;
		A->position.h = A->image[0]->h;
	}
}

void FreeHero(Hero *A)
{
	Mix_FreeChunk(A->Walk);
	Mix_FreeChunk(A->Jump);
	Mix_FreeChunk(A->Attack);
	int i;
	for (i = 0; i < 10; i++)
		SDL_FreeSurface(A->image[i]);
}
