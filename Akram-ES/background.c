#include "background.h"

void initBackground(Background *Backg)
{
	Backg->backgroundImg = SDL_LoadBMP("IMG/background.bmp");
	Backg->backgroundPos.x = 0;
	Backg->backgroundPos.y = 0;
	Backg->backgroundPos.w = SCREEN_W;
	Backg->backgroundPos.h = SCREEN_H;
}

void AfficherBackground(Background *Backg, SDL_Surface *screen)
{
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen, NULL);
}

void LibererBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}