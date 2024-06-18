/**
 * @file Game.c
 * @author @Akram akram.louati@esprit.tn
 * @brief 
 * @version 0.1
 * @date 2021-05-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "H.h"

/**
 * @brief GAME
 * 
 * @param screen
 * @return int 
 */
int jouer(SDL_Surface *screen)
{
	int done = 0, i = 0, keysHeld[323] = {0}, framee = 0, imup = 0;

	Uint32 starttick;

	const int fps = 15;

	SDL_Event event;

	TTF_Font *Font = NULL;
	SDL_Color color = {0, 0, 0};
	SDL_Surface *OVER, *WON, *KILL, *DEAD;

	temps t;
	minimap m;
	Background B;
	Hero H;
	Ennemi E;
	EnnemiA EA;
	Ghool G;
	Ghost GG;

	initialiser_temps(&t);
	InitBackground(&B);
	InitEnnemi(&E);
	InitEnnemiA(&EA);
	InitGhool(&G);
	InitGhost(&GG);
	InitHero(&H);
	initminimap(&m);

	Mix_Music *MP;
	Mix_Chunk *O, *W;
	MP = Mix_LoadMUS("SON/MP.mp3");
	O = Mix_LoadWAV("SON/Death.wav");
	W = Mix_LoadWAV("SON/Won.wav");
	Mix_PlayMusic(MP, -1);

	TTF_Init();
	Font = TTF_OpenFont("FONT/VCR_OSD_MONO.ttf", 40);
	DEAD = TTF_RenderText_Solid(Font, "HERO DEAD", color);
	KILL = TTF_RenderText_Solid(Font, "DEMON DEAD", color);

	SDL_EnableKeyRepeat(50, 50);

	while (!done)
	{
		starttick = SDL_GetTicks();

		if (CollisionBB(E, H) && H.direction == 2 && B.backgroundPos.x == 8000)
		{
			Mix_HaltChannel(-1);
			Mix_PauseMusic();
			Mix_PlayChannel(-1, W, 0);
			E.image = NULL;
			E.positionAbsolue.x = 9999;
			E.positionAbsolue.y = 9999;
			E.etat = 9999;
			SDL_BlitSurface(KILL, NULL, screen, &H.position);
			SDL_Flip(screen);
			SDL_Delay(5000);
			Mix_ResumeMusic();
		}
		else if (CollisionBB(E, H) && H.direction != 2 && B.backgroundPos.x == 8000)
		{
			H.vie -= 1;
			H.position.x = rand() % 1200;
			H.position.y = rand() % 100;
			H.direction = 3;
			MoveHero(&H);
		}
		else if (CollGhool(G, H) && H.direction == 2 && B.backgroundPos.x == 2000)
		{
			Mix_HaltChannel(-1);
			Mix_PauseMusic();
			Mix_PlayChannel(-1, W, 0);
			G.image = NULL;
			G.positionAbsolue.x = 9999;
			G.positionAbsolue.y = 9999;
			SDL_BlitSurface(KILL, NULL, screen, &H.position);
			SDL_Flip(screen);
			SDL_Delay(5000);
			Mix_ResumeMusic();
		}
		else if (CollGhool(G, H) && H.direction != 2 && B.backgroundPos.x == 2000)
		{
			H.vie -= 1;
			H.position.x = rand() % 1120;
			H.position.y = rand() % 100;
			H.direction = 3;
			MoveHero(&H);
		}
		else if (CollGhost(GG, H) && H.direction == 2 && B.backgroundPos.x == 5000)
		{
			Mix_HaltChannel(-1);
			Mix_PauseMusic();
			Mix_PlayChannel(-1, W, 0);
			GG.image = NULL;
			GG.positionAbsolue.x = 9999;
			GG.positionAbsolue.y = 9999;
			SDL_BlitSurface(KILL, NULL, screen, &H.position);
			SDL_Flip(screen);
			SDL_Delay(5000);
			Mix_ResumeMusic();
		}
		else if (CollGhost(GG, H) && H.direction != 2 && B.backgroundPos.x == 5000)
		{
			H.vie -= 1;
			H.position.x = rand() % 1120;
			H.position.y = rand() % 100;
			H.direction = 3;
			MoveHero(&H);
		}
		else
			done = 0;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				H.moving = 1;
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				H.moving = 0;
				break;
			}
			if (keysHeld[SDLK_ESCAPE])
				done = 1;

			if (keysHeld[SDLK_RIGHT])
			{
				m.greendotX += 0.6;
				H.direction = 0;
				H.position.x += 10;
				MoveHero(&H);
				i++;
			}
			if (keysHeld[SDLK_RIGHT] && keysHeld[SDLK_LSHIFT])
			{
				m.greendotX += 0.1;
				H.direction = 0;
				H.position.x += 10;
				MoveHero(&H);
				i++;
			}
			if (keysHeld[SDLK_LEFT])
			{
				m.greendotX -= 0.6;
				H.direction = 1;
				H.position.x -= 10;
				MoveHero(&H);
				i++;
			}
			if (keysHeld[SDLK_LEFT] && keysHeld[SDLK_LSHIFT])
			{
				m.greendotX -= 0.1;
				H.direction = 1;
				H.position.x -= 10;
				MoveHero(&H);
				i++;
			}
			if (keysHeld[SDLK_SPACE])
			{
				H.direction = 2;
				MoveHero(&H);
				i++;
			}
			if (keysHeld[SDLK_UP])
			{
				if (H.position.y > 100)
				{
					H.position.y -= 100;
				}
			}
		}

		if ((H.direction == 0) || (H.direction == 1))
		{
			i = i % 10;
		}
		if (H.direction == 2)
		{
			i = i % 8;
		}
		if (H.direction == 3)
		{
			i = i % 9;
		}

		if (H.position.y < 380)
		{
			H.position.y += 18;
		}

		if (m.greendotX < 400)
		{
			m.greendotX = 400;
		}
		if (m.greendotX > 800)
		{
			m.greendotX = 800;
		}

		AfficherBackground(&B, screen);
		m = afficherminimap(m, screen);
		afficher_temps(&t, screen);

		if (H.position.x < 10)
		{
			H.position.x = 10;
		}

		if (H.position.x > 1000 && B.backgroundPos.x == 0)
		{
			B.backgroundPos.x = 1300;
			H.position.x = 10;
		}

		if (H.position.x > 1000 && B.backgroundPos.x == 1300)
		{
			//ghool
			B.backgroundPos.x = 2000;
			H.position.x = 10;
		}
		if (B.backgroundPos.x == 2000)
		{
			AfficherGhool(G, screen);
			AnimerGhool(&G);
			DeplacerGhool(&G);
		}
		if (H.position.x > 1000 && B.backgroundPos.x == 2000)
		{
			B.backgroundPos.x = 3400;
			H.position.x = 10;
		}
		if (H.position.x > 1000 && B.backgroundPos.x == 3400)
		{
			//ghost
			B.backgroundPos.x = 5000;
			H.position.x = 10;
		}
		if (B.backgroundPos.x == 5000)
		{
			AfficherGhost(GG, screen);
			AnimerGhost(&GG);
			DeplacerGhost(&GG);
			
		}
		if (H.position.x > 1000 && B.backgroundPos.x == 5000)
		{
			B.backgroundPos.x = 7200;
			H.position.x = 10;
		}
		if (H.position.x > 1000 && B.backgroundPos.x == 7200)
		{
			B.backgroundPos.x = 8000;
			H.position.x = 10;
		}
		if (B.backgroundPos.x == 8000)
		{
			DeplacerIA(&E, &H);
			DeplacerIAA(&EA, &H);

			if (E.etat == 0)
			{
				AfficherEnnemi(E, screen);
				AnimerEnnemi(&E);
			}
			if (E.etat == 1)
			{
				AfficherEnnemi(E, screen);
				AnimerEnnemi(&E);
				Deplacer(&E);
			}
			else if (E.etat == 2)
			{
				Mix_PlayChannel(-1, EA.DemonLA, 0);
				EA.positionAbsolue.x = E.positionAbsolue.x;
				EA.positionAbsolue.y = E.positionAbsolue.y;
				AfficherEnnemiA(EA, screen);
				AnimerEnnemiA(&EA);
				DeplacerEA(&EA);
				Deplacer(&E);
			}
			if (E.etat == 3)
			{
				AfficherEnnemi(E, screen);
				AnimerEnnemi(&E);
				Deplacer(&E);
			}
			else if (E.etat == 4)
			{
				Mix_PlayChannel(-1, EA.DemonLA, 0);
				EA.positionAbsolue.x = E.positionAbsolue.x;
				EA.positionAbsolue.y = E.positionAbsolue.y;
				AfficherEnnemiA(EA, screen);
				AnimerEnnemiA(&EA);
				DeplacerEA(&EA);
				Deplacer(&E);
			}
		}
		if (H.position.x > 1000 && B.backgroundPos.x == 8000)
		{
			B.backgroundPos.x = 8000;
			H.position.x = 1000;
		}

		if (H.vie == 3)
		{
			SDL_BlitSurface(H.HP, NULL, screen, &H.PosHP);
		}
		else if (H.vie == 2)
		{
			H.HP = IMG_Load("IMG/Background/v1.png");
			SDL_BlitSurface(H.HP, NULL, screen, &H.PosHP);
		}
		else if (H.vie == 1)
		{
			H.HP = IMG_Load("IMG/Background/v2.png");
			SDL_BlitSurface(H.HP, NULL, screen, &H.PosHP);
		}
		else
		{
			H.HP = IMG_Load("IMG/Background/v3.png");
			SDL_BlitSurface(H.HP, NULL, screen, &H.PosHP);
			Mix_PauseMusic();
			Mix_HaltChannel(-1);
			SDL_BlitSurface(DEAD, NULL, screen, &H.position);
			Mix_PlayChannel(-1, O, 0);
			SDL_Flip(screen);
			SDL_Delay(5000);
			done = 1;
			jouer(screen);
		}

		if (H.moving == 0)
			i = 0;
		SDL_BlitSurface(H.image[i], NULL, screen, &H.position);

		if (1000 / fps > SDL_GetTicks() - starttick)
		{
			SDL_Delay(1000 / fps - (SDL_GetTicks() - starttick));
		}

		SDL_Flip(screen);
	}

	free_temps(&t, screen);

	FreeBackground(&B);

	SDL_FreeSurface(H.HP);

	LibererEnnemi(&E);

	LibererEnnemiA(&EA);

	LibererGhool(&G);

	Mix_FreeMusic(MP);

	Mix_FreeChunk(O);

	Mix_FreeChunk(W);

	FreeHero(&H);

	return (0);
}
