/**
 * @file background.c
 * @author @Akram akram.louati@esprit.tn
 * @brief 
 * @version 0.1
 * @date 2021-04-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "H.h"

void InitBackground(Background *Backg)
{
	//Load background
	Backg->backgroundImg = SDL_LoadBMP("IMG/Background/background.bmp");

	Backg->backgroundPos.x = 0;
	Backg->backgroundPos.y = 0;
	Backg->backgroundPos.w = SCREEN_W;
	Backg->backgroundPos.h = SCREEN_H;
}

void AfficherBackground(Background *Backg, SDL_Surface *screen)
{
	//Blit bachground
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen, NULL);
}

void FreeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}
