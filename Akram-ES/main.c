#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "defs.h"
#include "jeu.h"

int main(int argc, char **argv)
{

	SDL_Surface *screen;
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO );

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to init SDL: %s\n", SDL_GetError());
		return 1;
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)

	{
		printf("%s", Mix_GetError());
	}
	SDL_WM_SetCaption("Akram|ES", NULL);

	// Creates window
	screen = SDL_SetVideoMode(1000, 548, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_SRCALPHA);

	if (!screen)
	{
		printf("Unable to set 1000x548 VideoMode: %s\n", SDL_GetError());
		return 1;
	}
	
	//Game
	jouer(screen);

	//Exit Message
	printf("\033[1;31m");
	printf("Thx For ur Attention! @Akram\n");
	printf("\033[0m");
	return 0;
}