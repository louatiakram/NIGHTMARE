#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "background.h"
#include "jeu.h"

int jouer(SDL_Surface *screen)
{
	int done = 0;

	Background Backg;

	SDL_Event event;

	InitBack(&Backg);

	// program Game loop
	SDL_EnableKeyRepeat(50, 50);

	while (!done)
	{

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			// exit if the window is closed
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE: //// exit if ESCAPE is pressed
					done = 1;
					break;
				case SDLK_SPACE:
					Backg.backgroundPos.x = Backg.backgroundPos.x + 8;
					break;
				}
				break;
			}
		}
		//Blit the bachground & Scrolling
		AfficherBack(&Backg);
		Scrolling(&Backg, screen);

		SDL_Flip(screen);
	}
	// free
	LibererBack(&Backg);
	return (0);
}
