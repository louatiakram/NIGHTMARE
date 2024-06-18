/**
 * @file main.c
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
 * @brief MENU
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
	SDL_Surface *screen = NULL, *background = NULL, *texte = NULL, *Play = NULL, *Settings = NULL, *Credits = NULL, *Exit = NULL, *Scoreboard = NULL, *coatofarm = NULL, *animation = NULL;
	SDL_Rect positionBackground, positionClic, positionPlay, positionSettings, positionCredits, positionScoreboard, positionExit, positionText, positioncoatofarm;

	SDL_Surface *SettingsM = NULL, *Home = NULL, *Mute = NULL;
	SDL_Rect positionSettingsM, positionHome, positionMute;

	SDL_Surface *CreditsM;
	SDL_Rect positionCreditsM;

	SDL_Surface *logo = NULL;
	SDL_Rect positionLogo;

	Mix_Music *music;
	Mix_Chunk *click, *select;

	SDL_Color couleurNoire = {0, 0, 0};
	TTF_Font *police = NULL;

	SDL_Event event;

	int continuer = 1;
	int rang = 0;

	if (TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	music = Mix_LoadMUS("SON/MENU/Ori-AYearningfortheSky.mp3");
	select = Mix_LoadWAV("SON/MENU/Select.wav");
	click = Mix_LoadWAV("SON/MENU/click.wav");
	Mix_PlayMusic(music, -1);

	SDL_WM_SetCaption("NIGHTMARE", NULL);
	SDL_WM_SetIcon(SDL_LoadBMP("IMG/MENU/BinaryBeastsEx.bmp"), NULL);
	screen = SDL_SetVideoMode(1486, 809, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_SRCALPHA);

	background = SDL_LoadBMP("IMG/MENU/Background.bmp");

	coatofarm = IMG_Load("IMG/MENU/CoatOfArm.png");
	logo = IMG_Load("IMG/MENU/Logo.png");

	Play = IMG_Load("IMG/MENU/Buttons/Play.png");
	Settings = IMG_Load("IMG/MENU/Buttons/Settings.png");
	Scoreboard = IMG_Load("IMG/MENU/Buttons/Scoreboard.png");
	Credits = IMG_Load("IMG/MENU/Buttons/Credits.png");
	Exit = IMG_Load("IMG/MENU/Buttons/Exit.png");

	police = TTF_OpenFont("FONT/VCR_OSD_MONO.ttf", 40);
	texte = TTF_RenderText_Blended(police, "@Binary Beasts", couleurNoire);

	positionBackground.x = 0;
	positionBackground.y = 0;
	positionLogo.x = 700;
	positionLogo.y = 50;
	positioncoatofarm.x = 1250;
	positioncoatofarm.y = 620;
	positionPlay.x = 141;
	positionPlay.y = 167;
	positionSettings.x = 98;
	positionSettings.y = 255;
	positionCredits.x = 159;
	positionCredits.y = 320;
	positionScoreboard.x = 240;
	positionScoreboard.y = 254;
	positionExit.x = 185;
	positionExit.y = 393;
	positionText.x = 380;
	positionText.y = 760;

	SDL_EnableKeyRepeat(50, 50);

	while (continuer == 1)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_DOWN:
					if (rang == 0)
					{
						Mix_PlayChannel(-1, select, 0);
						Play = IMG_Load("IMG/MENU/Buttons/Play.png");
						Play = IMG_Load("IMG/MENU/Buttons/PlayA.png");
						rang++;
					}
					else if (rang == 1)
					{
						Mix_PlayChannel(-1, select, 0);
						Play = IMG_Load("IMG/MENU/Buttons/Play.png");
						Settings = IMG_Load("IMG/MENU/Buttons/SettingsA.png");
						rang++;
					}
					else if (rang == 2)
					{
						Mix_PlayChannel(-1, select, 0);
						Settings = IMG_Load("IMG/MENU/Buttons/Settings.png");
						Scoreboard = IMG_Load("IMG/MENU/Buttons/ScoreboardA.png");
						rang++;
					}
					else if (rang == 3)
					{
						Mix_PlayChannel(-1, select, 0);
						Credits = IMG_Load("IMG/MENU/Buttons/CreditsA.png");
						Scoreboard = IMG_Load("IMG/MENU/Buttons/Scoreboard.png");
						rang++;
					}
					else if (rang == 4)
					{
						Credits = IMG_Load("IMG/MENU/Buttons/Credits.png");
						Exit = IMG_Load("IMG/MENU/Buttons/ExitA.png");
						Mix_PlayChannel(-1, select, 0);
						rang++;
					}
					break;
				case SDLK_UP:
					if (rang == 5)
					{
						Mix_PlayChannel(-1, select, 0);
						Exit = IMG_Load("IMG/MENU/Buttons/Exit.png");
						Credits = IMG_Load("IMG/MENU/Buttons/CreditsA.png");
						rang--;
					}
					else if (rang == 4)
					{
						Mix_PlayChannel(-1, select, 0);
						Credits = IMG_Load("IMG/MENU/Buttons/Credits.png");
						Scoreboard = IMG_Load("IMG/MENU/Buttons/ScoreboardA.png");
						rang--;
					}
					else if (rang == 3)
					{
						Mix_PlayChannel(-1, select, 0);
						Scoreboard = IMG_Load("IMG/MENU/Buttons/Scoreboard.png");
						Settings = IMG_Load("IMG/MENU/Buttons/SettingsA.png");
						rang--;
					}
					else if (rang == 2)
					{
						Settings = IMG_Load("IMG/MENU/Buttons/Settings.png");
						Play = IMG_Load("IMG/MENU/Buttons/PlayA.png");
						Mix_PlayChannel(-1, select, 0);
						rang--;
					}
					else if (rang == 1)
					{

						Settings = IMG_Load("IMG/MENU/Buttons/Settings.png");
						Play = IMG_Load("IMG/MENU/Buttons/Play.png");
						rang--;
					}
					else if (rang == 0)
					{
						Mix_PlayChannel(-1, select, 0);
						Play = IMG_Load("IMG/MENU/Buttons/Play.png");
						Play = IMG_Load("IMG/MENU/Buttons/PlayA.png");
						rang++;
					}
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_KP_ENTER)
				{
					if (rang == 1)
					{
						int i;
						SDL_Surface *screenTEMP = SDL_ConvertSurface(screen, screen->format, SDL_SWSURFACE); //Copie du contenu du screen
						for (i = 0; i < 180; i++)															 //Rotozoom avant chaque debut d'un niveau
						{
							SDL_Surface *effect = rotozoomSurface(screenTEMP, i += 0.5, 0.4, SMOOTHING_ON);
							SDL_BlitSurface(effect, NULL, screen, NULL);
							SDL_FreeSurface(effect);
							SDL_Flip(screen);
						}
						Play = IMG_Load("IMG/MENU/Buttons/PlayA.png");
						screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_SRCALPHA);
						if (jouer(screen) == 0)
						{
							screen = SDL_SetVideoMode(1486, 809, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_SRCALPHA);
						}
						else
						{
							jouer(screen);
						}
					}
					else if (rang == 5)
					{
						Mix_PlayChannel(-1, click, 0);
						SDL_Delay(120);
						Exit = IMG_Load("IMG/MENU/Buttons/ExitA.png");
						continuer = 0;
					}
				}
				break;
			case SDL_MOUSEMOTION:
				if (event.motion.x > 141 && event.motion.x < 317 && event.motion.y > 167 && event.motion.y < 234)
				{
					Play = IMG_Load("IMG/MENU/Buttons/PlayA.png");
					Settings = IMG_Load("IMG/MENU/Buttons/Settings.png");
					Credits = IMG_Load("IMG/MENU/Buttons/Credits.png");
					Scoreboard = IMG_Load("IMG/MENU/Buttons/Scoreboard.png");
					Exit = IMG_Load("IMG/MENU/Buttons/Exit.png");
				}
				else if (event.motion.x > 98 && event.motion.x < 220 && event.motion.y > 254 && event.motion.y < 300)
				{
					Play = IMG_Load("IMG/MENU/Buttons/Play.png");
					Settings = IMG_Load("IMG/MENU/Buttons/SettingsA.png");
					Credits = IMG_Load("IMG/MENU/Buttons/Credits.png");
					Scoreboard = IMG_Load("IMG/MENU/Buttons/Scoreboard.png");
					Exit = IMG_Load("IMG/MENU/Buttons/Exit.png");
				}
				else if (event.button.x > 160 && event.button.x < 300 && event.button.y > 320 && event.button.y < 373)
				{
					Play = IMG_Load("IMG/MENU/Buttons/Play.png");
					Settings = IMG_Load("IMG/MENU/Buttons/Settings.png");
					Credits = IMG_Load("IMG/MENU/Buttons/CreditsA.png");
					Scoreboard = IMG_Load("IMG/MENU/Buttons/Scoreboard.png");
					Exit = IMG_Load("IMG/MENU/Buttons/Exit.png");
				}
				else if (event.motion.x > 239 && event.motion.x < 361 && event.motion.y > 254 && event.motion.y < 300)
				{
					Play = IMG_Load("IMG/MENU/Buttons/Play.png");
					Settings = IMG_Load("IMG/MENU/Buttons/Settings.png");
					Credits = IMG_Load("IMG/MENU/Buttons/Credits.png");
					Scoreboard = IMG_Load("IMG/MENU/Buttons/ScoreboardA.png");
					Exit = IMG_Load("IMG/MENU/Buttons/Exit.png");
				}
				else if (event.motion.x > 185 && event.motion.x < 274 && event.motion.y > 395 && event.motion.y < 427)
				{
					Play = IMG_Load("IMG/MENU/Buttons/Play.png");
					Settings = IMG_Load("IMG/MENU/Buttons/Settings.png");
					Credits = IMG_Load("IMG/MENU/Buttons/Credits.png");
					Scoreboard = IMG_Load("IMG/MENU/Buttons/Scoreboard.png");
					Exit = IMG_Load("IMG/MENU/Buttons/ExitA.png");
				}
				else
				{
					Play = IMG_Load("IMG/MENU/Buttons/Play.png");
					Settings = IMG_Load("IMG/MENU/Buttons/Settings.png");
					Credits = IMG_Load("IMG/MENU/Buttons/Credits.png");
					Scoreboard = IMG_Load("IMG/MENU/Buttons/Scoreboard.png");
					Exit = IMG_Load("IMG/MENU/Buttons/Exit.png");
				}
				break;
			/*case SDL_MOUSEBUTTONDOWN:
				printf("Position: %dx | %dy\n", event.button.x, event.button.y);*/
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					positionClic.x = event.button.x;
					positionClic.y = event.button.y;

					if (event.motion.x > 141 && event.motion.x < 317 && event.motion.y > 167 && event.motion.y < 234)
					{
						int i;
						SDL_Surface *screenTEMP = SDL_ConvertSurface(screen, screen->format, SDL_SWSURFACE); //Copie du contenu du screen
						for (i = 0; i < 180; i++)															 //Rotozoom avant chaque debut d'un niveau
						{
							SDL_Surface *effect = rotozoomSurface(screenTEMP, i += 0.5, 0.4, SMOOTHING_ON);
							SDL_BlitSurface(effect, NULL, screen, NULL);
							SDL_FreeSurface(effect);
							SDL_Flip(screen);
						}
						Play = IMG_Load("IMG/MENU/Buttons/PlayA.png");
						screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_SRCALPHA);
						if (jouer(screen) == 0)
						{
							screen = SDL_SetVideoMode(1486, 809, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_SRCALPHA);
						}
						else
						{
							jouer(screen);
						}
					}
					else if (event.button.x > 160 && event.button.x < 300 && event.button.y > 320 && event.button.y < 373)
					{
						Mix_PlayChannel(-1, click, 0);
						SDL_Delay(120);
						int done = -1;
						positionCreditsM.x = 20;
						positionCreditsM.y = 40;
						CreditsM = IMG_Load("IMG/MENU/CreditsM.png");
						while (done)
						{
							while (SDL_PollEvent(&event))
							{
								switch (event.type)
								{
								case SDL_MOUSEBUTTONUP:
									if (event.button.button == SDL_BUTTON_LEFT)
									{
										positionClic.x = event.button.x;
										positionClic.y = event.button.y;
										if (event.button.x > 160 && event.button.x < 300 && event.button.y > 320 && event.button.y < 373)
										{
											CreditsM = IMG_Load("IMG/MENU/CreditsM.png");
										}
									}
									break;
								case SDL_KEYDOWN:
									if (event.key.keysym.sym == SDLK_ESCAPE)
									{
										Mix_PlayChannel(-1, click, 0);
										SDL_Delay(120);
										done = 0;
									}
									break;
								}
								SDL_BlitSurface(CreditsM, NULL, screen, &positionCreditsM);
								SDL_Flip(screen);
							}
						}
					}
					else if (event.motion.x > 98 && event.motion.x < 220 && event.motion.y > 254 && event.motion.y < 300)
					{
						Mix_PlayChannel(-1, click, 0);
						SDL_Delay(120);
						int done = -1;
						int i = 50;
						positionSettingsM.x = 20;
						positionSettingsM.y = 20;
						SettingsM = IMG_Load("IMG/MENU/Settings/SettingsM.png");
						positionHome.x = 53;
						positionHome.y = 400;
						Home = IMG_Load("IMG/MENU/Settings/Home.png");
						positionMute.x = 206;
						positionMute.y = 320;
						Mute = IMG_Load("IMG/MENU/Settings/Mute.png");

						while (done)
						{
							while (SDL_PollEvent(&event))
							{
								switch (event.type)
								{
								case SDL_MOUSEMOTION:
									if (event.button.x > 207 && event.button.x < 249 && event.button.y > 321 && event.button.y < 363)
									{
										Mute = IMG_Load("IMG/MENU/Settings/MuteA.png");
									}
									else if (event.button.x > 56 && event.button.x < 105 && event.button.y > 399 && event.button.y < 448)
									{
										Home = IMG_Load("IMG/MENU/Settings/HomeA.png");
									}
									else
									{
										Home = IMG_Load("IMG/MENU/Settings/Home.png");
										Mute = IMG_Load("IMG/MENU/Settings/Mute.png");
									}
									break;
								case SDL_MOUSEBUTTONUP:
									if (event.button.button == SDL_BUTTON_LEFT)
									{
										positionClic.x = event.button.x;
										positionClic.y = event.button.y;
										if (event.button.x > 207 && event.button.x < 249 && event.button.y > 321 && event.button.y < 363)
										{
											Mute = IMG_Load("IMG/MENU/Settings/MuteA.png");
											Mix_HaltMusic();
											Mix_PlayChannel(-1, click, 0);
										}
										else if (event.button.x > 56 && event.button.x < 105 && event.button.y > 399 && event.button.y < 448)
										{
											Home = IMG_Load("IMG/MENU/Settings/HomeA.png");
											Mix_PlayChannel(-1, click, 0);
											SDL_Delay(120);
											done = 0;
										}
									}
									break;
								case SDL_KEYDOWN:
									if (event.key.keysym.sym == SDLK_ESCAPE)
									{
										Mix_PlayChannel(-1, click, 0);
										SDL_Delay(120);
										done = 0;
									}
									if (event.key.keysym.sym == SDLK_w)
									{
										Mix_PlayChannel(-1, click, 0);
										screen = SDL_SetVideoMode(700, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
										SDL_BlitSurface(background, NULL, screen, &positionBackground);
										SDL_BlitSurface(logo, NULL, screen, &positionLogo);
										SDL_BlitSurface(coatofarm, NULL, screen, &positioncoatofarm);
										SDL_BlitSurface(Play, NULL, screen, &positionPlay);
										SDL_BlitSurface(Settings, NULL, screen, &positionSettings);
										SDL_BlitSurface(Scoreboard, NULL, screen, &positionScoreboard);
										SDL_BlitSurface(Credits, NULL, screen, &positionCredits);
										SDL_BlitSurface(Exit, NULL, screen, &positionExit);
										SDL_BlitSurface(texte, NULL, screen, &positionText);
									}
									if (event.key.keysym.sym == SDLK_f)
									{
										Mix_PlayChannel(-1, click, 0);
										screen = SDL_SetVideoMode(1486, 809, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
										SDL_BlitSurface(background, NULL, screen, &positionBackground);
										SDL_BlitSurface(logo, NULL, screen, &positionLogo);
										SDL_BlitSurface(coatofarm, NULL, screen, &positioncoatofarm);
										SDL_BlitSurface(Play, NULL, screen, &positionPlay);
										SDL_BlitSurface(Settings, NULL, screen, &positionSettings);
										SDL_BlitSurface(Scoreboard, NULL, screen, &positionScoreboard);
										SDL_BlitSurface(Credits, NULL, screen, &positionCredits);
										SDL_BlitSurface(Exit, NULL, screen, &positionExit);
										SDL_BlitSurface(texte, NULL, screen, &positionText);
									}
									if (event.key.keysym.sym == SDLK_u)
									{
										i = i + 15;
										Mix_VolumeMusic(i);
									}
									if (event.key.keysym.sym == SDLK_d)
									{
										i = i - 15;
										Mix_VolumeMusic(i);
									}
									if (event.key.keysym.sym == SDLK_m)
									{
										Mix_HaltMusic();
									}
									if (event.key.keysym.sym == SDLK_p)
									{
										if (Mix_PlayingMusic() == 0)
										{
											Mix_PlayMusic(music, -1);
										}
										else
										{
											if (Mix_PausedMusic() == 1)
											{
												Mix_ResumeMusic();
											}
											else
											{
												Mix_PauseMusic();
											}
										}
									}
									break;
								}
								SDL_BlitSurface(SettingsM, NULL, screen, &positionSettingsM);
								SDL_BlitSurface(Home, NULL, screen, &positionHome);
								SDL_BlitSurface(Mute, NULL, screen, &positionMute);
								SDL_Flip(screen);
							}
						}
					}
					else if (event.button.x > 160 && event.button.x < 300 && event.button.y > 320 && event.button.y < 373)
					{
						Credits = IMG_Load("IMG/MENU/Buttons/CreditsA.png");
					}
					else if (event.motion.x > 239 && event.motion.x < 361 && event.motion.y > 254 && event.motion.y < 300)
					{
						Scoreboard = IMG_Load("IMG/MENU/Buttons/ScoreboardA.png");
					}
					else if (event.motion.x > 185 && event.motion.x < 274 && event.motion.y > 395 && event.motion.y < 427)
					{
						Mix_PlayChannel(-1, click, 0);
						SDL_Delay(50);
						Exit = IMG_Load("IMG/MENU/Buttons/ExitA.png");
						continuer = 0;
					}
				}
				break;
			}
		}
		SDL_BlitSurface(background, NULL, screen, &positionBackground);
		SDL_BlitSurface(logo, NULL, screen, &positionLogo);
		SDL_BlitSurface(coatofarm, NULL, screen, &positioncoatofarm);
		SDL_BlitSurface(Play, NULL, screen, &positionPlay);
		SDL_BlitSurface(Settings, NULL, screen, &positionSettings);
		SDL_BlitSurface(Scoreboard, NULL, screen, &positionScoreboard);
		SDL_BlitSurface(Credits, NULL, screen, &positionCredits);
		SDL_BlitSurface(Exit, NULL, screen, &positionExit);
		SDL_BlitSurface(texte, NULL, screen, &positionText);

		SDL_Flip(screen);
	}
	SDL_FreeSurface(background);
	SDL_FreeSurface(logo);
	SDL_FreeSurface(coatofarm);
	SDL_FreeSurface(Play);
	SDL_FreeSurface(Settings);
	SDL_FreeSurface(Scoreboard);
	SDL_FreeSurface(Credits);
	SDL_FreeSurface(Exit);

	Mix_FreeMusic(music);

	Mix_FreeChunk(click);
	Mix_FreeChunk(select);

	TTF_CloseFont(police);
	TTF_Quit();
	SDL_FreeSurface(texte);

	SDL_Quit();
	printf("\033[1;31m");
	printf("Thx For ur Attention! @BinaryBeasts\n");
	printf("\033[0m");
	return 0;
}