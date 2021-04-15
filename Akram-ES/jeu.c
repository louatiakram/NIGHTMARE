#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "defs.h"
#include "background.h"
#include "ennemi.h"
#include "es.h"
#include "jeu.h"

int jouer(SDL_Surface *screen)
{
	int Done = 0;
	const int FPS = 30;
	SDL_Surface *Text, *Boom;
	TTF_Font *Font = NULL;
	SDL_Color color = {255, 255, 0};
	Ennemi ennemi;
	Es es;
	Background Backg;
	Mix_Music *MP;
	SDL_Event event;
	Uint32 start;

	TTF_Init();
	Font = TTF_OpenFont("Font/VCR_OSD_MONO.ttf", 20);
	Text = TTF_RenderText_Solid(Font, "GAME OVER", color);

	Boom = IMG_Load("IMG/Boom.png");
	SDL_SetColorKey(Boom, SDL_SRCCOLORKEY, SDL_MapRGB(Boom->format, 255, 255, 255));

	MP = Mix_LoadMUS("SON/MP.mp3");
	Mix_PlayMusic(MP, -1);

	initBackground(&Backg);
	initEnnemi(&ennemi);
	initEs(&es);

	SDL_EnableKeyRepeat(10, 10);
	while (Done == 0)
	{
		start = SDL_GetTicks();
		if (collisionBB(ennemi, es))
		{
			Mix_HaltMusic();
			Mix_HaltChannel(-1);
			Mix_PlayChannel(-1, ennemi.BOOM, 0);
			SDL_BlitSurface(Boom, NULL, screen, &ennemi.positionAbsolue);
			SDL_BlitSurface(Text, NULL, screen, &ennemi.positionAbsolue);
			SDL_Flip(screen);
			SDL_Delay(800);
			Mix_PlayChannel(-1, ennemi.OVER, 0);
			SDL_Delay(4500);
			exit(1);
		}
		else
			Done = 0;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				Done = 1;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE: //Appui sur la touche Echap, on arrête le programme
					Done = 1;
					break;
				case SDLK_RIGHT:
					es.positionAbsolue.x += 40; //Es Down
					break;
				case SDLK_LEFT:
					es.positionAbsolue.x -= 40; //Es Down
					break;
				case SDLK_UP:
					es.positionAbsolue.y -= 40; //Es Up
					break;
				case SDLK_DOWN:
					es.positionAbsolue.y += 40; //Es Down
					break;
				}
				break;
			}
		}
		AfficherBackground(&Backg, screen);

		AfficherEnnemi(ennemi, screen);
		AfficherEs(es, screen);

		AnimerEnnemi(&ennemi);
		AnimerEs(&es);

		Deplacer(&ennemi);

		collisionBB(ennemi, es);

		SDL_Flip(screen);

		if (1000 / FPS > SDL_GetTicks() - start)
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
	}
	LibererBackground(&Backg);
	Mix_FreeMusic(MP);

	TTF_CloseFont(Font);
	TTF_Quit();
	SDL_FreeSurface(Text);

	LibererEnnemi(&ennemi);
	LibererEs(&es);

	return (0);
}