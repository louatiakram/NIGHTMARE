#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "es.h"
#include "background.h"

void initEs(Es *A)
{
	A->image = IMG_Load("IMG/fireball.png");
	SDL_SetColorKey(A->image, SDL_SRCCOLORKEY, SDL_MapRGB(A->image->format, 255, 255, 255));

	A->positionAbsolue.x = 970;
	A->positionAbsolue.y = 160;
	A->positionAbsolue.w = ES_WIDTH;
	A->positionAbsolue.h = ES_HEIGHT;
	A->positionAnimation.x = 0;
	A->positionAnimation.y = 0;
	A->positionAnimation.w = ES_WIDTH;
	A->positionAnimation.h = ES_HEIGHT;
}

void AfficherEs(Es A, SDL_Surface *screen)
{
	SDL_BlitSurface(A.image, &A.positionAnimation, screen, &A.positionAbsolue);
}
void AnimerEs(Es *A)
{
	A->positionAnimation.x += ES_WIDTH;
	A->positionAnimation.x = A->positionAnimation.x % (ES_WIDTH * 3);
	SDL_Delay(1);
}
void LibererEs(Es *A)
{
	SDL_FreeSurface(A->image);
}