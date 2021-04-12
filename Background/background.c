#include "background.h"

void InitBack(Background *Backg)
{
	Backg->backgroundImg = SDL_LoadBMP("IMG/background.bmp");
	Backg->backgroundCollide = SDL_LoadBMP("IMG/background.bmp");

	Backg->backgroundPos.x = 0;
	Backg->backgroundPos.y = 0;
	Backg->backgroundPos.w = SCREEN_W;
	Backg->backgroundPos.h = SCREEN_H;
}

void AfficherBack(Background *Backg)
{
	//Blit the bachground to the backbuffer
	if (Backg->backgroundPos.x > Backg->backgroundImg->w - SCREEN_W)
		Backg->backgroundPos.x = 0;
	if (Backg->backgroundPos.x < 0)
		Backg->backgroundPos.x = Backg->backgroundImg->w - SCREEN_W;
}

void Scrolling(Background *Backg, SDL_Surface *screen)
{
SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen, NULL); //scrolling horizontal
}

void LibererBack(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}
