#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>

int main(int argc, char *argv[])
{ //Declaration Variable
	//Animation
	SDL_Surface *A[4];
	SDL_Rect positionA;
	SDL_Surface *screen = NULL, *background = NULL, *texte = NULL, *Play = NULL, *Settings = NULL, *Credits = NULL, *Exit = NULL, *Scoreboard = NULL, *coatofarm = NULL, *animation = NULL;
	SDL_Rect positionBackground, positionClic, positionPlay, positionSettings, positionCredits, positionScoreboard, positionExit, positionText, positioncoatofarm;
	//SettingsMenu:
	SDL_Surface *SettingsM = NULL, *Home = NULL, *Mute = NULL;
	SDL_Rect positionSettingsM, positionHome, positionMute;
	//CreditsM
	SDL_Surface *CreditsM;
	SDL_Rect positionCreditsM;
	//LOGO
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

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	TTF_Init();

	music = Mix_LoadMUS("sound/Ori-AYearningfortheSky.mp3");
	select = Mix_LoadWAV("sound/Select.wav");
	click = Mix_LoadWAV("sound/click.wav");
	Mix_PlayMusic(music, -1);

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("unable to initialize SDL : %s\n", SDL_GetError());
		return 1;
	}
	putenv("SDL_VIDEO_WINDOW_POS=center");
	SDL_WM_SetCaption("NIGHTMARE", NULL);
	SDL_WM_SetIcon(SDL_LoadBMP("image/BinaryBeastsEx.bmp"), NULL);
	screen = SDL_SetVideoMode(1486, 809, 32, SDL_HWSURFACE | SDL_DOUBLEBUF /* | SDL_RESIZABLE*/);

	if (screen == NULL)
	{
		printf("unable to set video mode : %s\n", SDL_GetError());
		return 1;
	}
	//A

	background = SDL_LoadBMP("image/Background.bmp");

	if (background == NULL)
	{
		printf("unable to set load bitmap : %s\n", SDL_GetError());
		return 1;
	}
	//LOGO
	coatofarm = IMG_Load("image/CoatOfArm.png");
	logo = IMG_Load("image/Logo.png");
	//Buttons
	Play = IMG_Load("image/Menu/Buttons/Play.png");
	Settings = IMG_Load("image/Menu/Buttons/Settings.png");
	Scoreboard = IMG_Load("image/Menu/Buttons/Scoreboard.png");
	Credits = IMG_Load("image/Menu/Buttons/Credits.png");
	Exit = IMG_Load("image/Menu/Buttons/Exit.png");

	if (Play == NULL || Settings == NULL || Scoreboard == NULL || Credits == NULL || Exit == NULL)
	{
		printf("unable to set load png : %s\n", SDL_GetError());
		return 1;
	}
	int a = 0;
	A[0] = IMG_Load("Layer1.png");
	A[1] = IMG_Load("Layer2.png");
	A[2] = IMG_Load("Layer3.png");
	A[3] = IMG_Load("Layer4.png");
	a++;
	if (a == 4)
		a = 0;

	police = TTF_OpenFont("font/VCR_OSD_MONO.ttf", 40);
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

	SDL_EnableKeyRepeat(68, 68); /* Activation de la répétition des touches */

	while (continuer == 1)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			/*case SDL_VIDEORESIZE:
				positionBackground.x = event.resize.w / 2 - background->w / 2;
				positionBackground.y = event.resize.h / 2 - background->h / 2;
				positionLogo.x = event.resize.w / 2 - logo->w / 2;
				positionLogo.y = event.resize.h / 2 - logo->h / 2;
				positioncoatofarm.x = event.resize.w / 2 - coatofarm->w / 2;
				positioncoatofarm.y = event.resize.h / 2 - coatofarm->h / 2;
				positionPlay.x = event.resize.w / 2 - Play->w / 2;
				positionPlay.y = event.resize.h / 2 - Play->h / 2;
				positionSettings.x = event.resize.w / 2 - Settings->w / 2;
				positionSettings.y = event.resize.h / 2 - Settings->h / 2;
				positionCredits.x = event.resize.w / 2 - Credits->w / 2;
				positionCredits.y = event.resize.h / 2 - Credits->h / 2;
				positionScoreboard.x = event.resize.w / 2 - Scoreboard->w / 2;
				positionScoreboard.y = event.resize.h / 2 - Scoreboard->h / 2;
				positionExit.x = event.resize.w / 2 - Exit->w / 2;
				positionExit.y = event.resize.h / 2 - Exit->h / 2;
				positionText.x = event.resize.w / 2 - texte->w / 2;
				positionText.y = event.resize.h / 2 - texte->h / 2;
				break;*/
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					/*case SDLK_ESCAPE: //Appui sur la touche Echap, on arrête le programme
					continuer = 0;
					break;*/
				case SDLK_s:
					if (event.key.keysym.sym == SDLK_s)
					{
						Mix_PlayChannel(-1, click, 0);
						SDL_Delay(120);
						int done = -1;
						int i = 50;

						while (done)
						{
							while (SDL_PollEvent(&event))
							{

								switch (event.type)
								{
								case SDL_KEYUP:

									if (event.key.keysym.sym == SDLK_ESCAPE)
									{
										Mix_PlayChannel(-1, click, 0);
										SDL_Delay(120);
										done = 0;
									}
									break;
								}
								//SettingsMenu
								positionSettingsM.x = 20;
								positionSettingsM.y = 20;
								SettingsM = IMG_Load("image/Menu/Settings/SettingsM.png");
								positionHome.x = 53;
								positionHome.y = 400;
								Home = IMG_Load("image/Menu/Settings/Home.png");
								positionMute.x = 206;
								positionMute.y = 320;
								Mute = IMG_Load("image/Menu/Settings/Mute.png");
								SDL_BlitSurface(SettingsM, NULL, screen, &positionSettingsM);
								SDL_BlitSurface(Mute, NULL, screen, &positionMute);
								SDL_BlitSurface(Home, NULL, screen, &positionHome);
								SDL_Flip(screen);
								//music up
								if (event.key.keysym.sym == SDLK_u)
								{
									i = i + 15;
									Mix_VolumeMusic(i);
								}
								//music down
								if (event.key.keysym.sym == SDLK_d)
								{
									i = i - 15;
									Mix_VolumeMusic(i);
								}
								//Stop the music
								if (event.key.keysym.sym == SDLK_m)
								{
									Mix_HaltMusic();
								}
								if (event.key.keysym.sym == SDLK_p)
								{
									//If there is no music playing
									if (Mix_PlayingMusic() == 0)
									{
										//Play the music
										Mix_PlayMusic(music, -1);
									}
									//If music is being played
									else
									{
										//If the music is paused
										if (Mix_PausedMusic() == 1)
										{
											//Resume the music
											Mix_ResumeMusic();
										}
										//If the music is playing
										else
										{
											//Pause the music
											Mix_PauseMusic();
										}
									}
								}
							}
						}
					}
					break;
					//SDL_Delay(2000);
				case SDLK_DOWN:
					if (rang == 0)
					{
						Mix_PlayChannel(-1, select, 0);
						Play = IMG_Load("image/Menu/Buttons/Play.png");
						Play = IMG_Load("image/Menu/Buttons/PlayA.png");
						rang++;
					}
					else if (rang == 1)
					{
						Mix_PlayChannel(-1, select, 0);
						Play = IMG_Load("image/Menu/Buttons/Play.png");
						Settings = IMG_Load("image/Menu/Buttons/SettingsA.png");
						rang++;
					}
					else if (rang == 2)
					{
						Mix_PlayChannel(-1, select, 0);
						Settings = IMG_Load("image/Menu/Buttons/Settings.png");
						Scoreboard = IMG_Load("image/Menu/Buttons/ScoreboardA.png");
						rang++;
					}
					else if (rang == 3)
					{
						Mix_PlayChannel(-1, select, 0);
						Credits = IMG_Load("image/Menu/Buttons/CreditsA.png");
						Scoreboard = IMG_Load("image/Menu/Buttons/Scoreboard.png");
						rang++;
					}
					else if (rang == 4)
					{
						Credits = IMG_Load("image/Menu/Buttons/Credits.png");
						Exit = IMG_Load("image/Menu/Buttons/ExitA.png");
						Mix_PlayChannel(-1, select, 0);
						rang++;
					}
					break;
				case SDLK_UP:
					if (rang == 5)
					{
						Mix_PlayChannel(-1, select, 0);
						Exit = IMG_Load("image/Menu/Buttons/Exit.png");
						Credits = IMG_Load("image/Menu/Buttons/CreditsA.png");
						rang--;
					}
					else if (rang == 4)
					{
						Mix_PlayChannel(-1, select, 0);
						Credits = IMG_Load("image/Menu/Buttons/Credits.png");
						Scoreboard = IMG_Load("image/Menu/Buttons/ScoreboardA.png");
						rang--;
					}
					else if (rang == 3)
					{
						Mix_PlayChannel(-1, select, 0);
						Scoreboard = IMG_Load("image/Menu/Buttons/Scoreboard.png");
						Settings = IMG_Load("image/Menu/Buttons/SettingsA.png");
						rang--;
					}
					else if (rang == 2)
					{
						Settings = IMG_Load("image/Menu/Buttons/Settings.png");
						Play = IMG_Load("image/Menu/Buttons/PlayA.png");
						Mix_PlayChannel(-1, select, 0);
						rang--;
					}
					else if (rang == 1)
					{

						Settings = IMG_Load("image/Menu/Buttons/Settings.png");
						Play = IMG_Load("image/Menu/Buttons/Play.png");
						rang--;
					}
					else if (rang == 0)
					{
						Mix_PlayChannel(-1, select, 0);
						Play = IMG_Load("image/Menu/Buttons/Play.png");
						Play = IMG_Load("image/Menu/Buttons/PlayA.png");
						rang++;
					}
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_KP_ENTER)
				{
					if (rang == 2)
					{
						Mix_PlayChannel(-1, click, 0);
						SDL_Delay(120);
						int done = -1;
						int i = 50;
						while (done)
						{
							while (SDL_PollEvent(&event))
							{

								switch (event.type)
								{
								case SDL_KEYDOWN:
									if (event.key.keysym.sym == SDLK_ESCAPE)
									{
										Mix_PlayChannel(-1, click, 0);
										SDL_Delay(120);
										done = 0;
									}
									break;
								}
								//SettingsMenu

								positionSettingsM.x = 20;
								positionSettingsM.y = 20;
								SettingsM = IMG_Load("image/Menu/Settings/SettingsM.png");
								positionHome.x = 53;
								positionHome.y = 400;
								Home = IMG_Load("image/Menu/Settings/Home.png");
								positionMute.x = 206;
								positionMute.y = 320;
								Mute = IMG_Load("image/Menu/Settings/Mute.png");
								SDL_BlitSurface(SettingsM, NULL, screen, &positionBackground);

								SDL_BlitSurface(Mute, NULL, screen, &positionMute);
								SDL_BlitSurface(Home, NULL, screen, &positionHome);
								SDL_Flip(screen);
								//music up
								if (event.key.keysym.sym == SDLK_u)
								{
									i = i + 15;
									Mix_VolumeMusic(i);
								}
								//music down
								if (event.key.keysym.sym == SDLK_d)
								{
									i = i - 15;
									Mix_VolumeMusic(i);
								}
								//Stop the music
								if (event.key.keysym.sym == SDLK_m)
								{
									Mix_HaltMusic();
								}
								if (event.key.keysym.sym == SDLK_p)
								{
									//If there is no music playing
									if (Mix_PlayingMusic() == 0)
									{
										//Play the music
										Mix_PlayMusic(music, -1);
									}
									//If music is being played
									else
									{
										//If the music is paused
										if (Mix_PausedMusic() == 1)
										{
											//Resume the music
											Mix_ResumeMusic();
										}
										//If the music is playing
										else
										{
											//Pause the music
											Mix_PauseMusic();
										}
									}
								}
							}
						}
					}
					if (rang == 5)
					{
						Mix_PlayChannel(-1, click, 0);
						SDL_Delay(120);
						Exit = IMG_Load("image/Menu/Buttons/ExitA.png");
						continuer = 0;
					}
					if (rang == 4)
					{
						Mix_PlayChannel(-1, click, 0);
						SDL_Delay(120);
						int done = -1;
						int i = 50;
						while (done)
						{
							while (SDL_PollEvent(&event))
							{

								switch (event.type)
								{
								case SDL_KEYDOWN:
									if (event.key.keysym.sym == SDLK_ESCAPE)
									{
										Mix_PlayChannel(-1, click, 0);
										SDL_Delay(120);
										done = 0;
									}
									break;
								}
								positionCreditsM.x = 20;
								positionCreditsM.y = 40;
								CreditsM = IMG_Load("image/Menu/CreditsM.png");
								SDL_BlitSurface(CreditsM, NULL, screen, &positionCreditsM);
								SDL_Flip(screen);
							}
						}
					}
				}

					break;
				case SDL_MOUSEMOTION:
					if (event.motion.x > 141 && event.motion.x < 317 && event.motion.y > 167 && event.motion.y < 234)
					{
						Play = IMG_Load("image/Menu/Buttons/PlayA.png");
						Mix_PlayChannel(-1, select, 0);
						Settings = IMG_Load("image/Menu/Buttons/Settings.png");
						Credits = IMG_Load("image/Menu/Buttons/Credits.png");
						Scoreboard = IMG_Load("image/Menu/Buttons/Scoreboard.png");
						Exit = IMG_Load("image/Menu/Buttons/Exit.png");
					}
					else if (event.motion.x > 98 && event.motion.x < 220 && event.motion.y > 254 && event.motion.y < 300)
					{
						Play = IMG_Load("image/Menu/Buttons/Play.png");
						Settings = IMG_Load("image/Menu/Buttons/SettingsA.png");
						Mix_PlayChannel(-1, select, 0);
						Credits = IMG_Load("image/Menu/Buttons/Credits.png");
						Scoreboard = IMG_Load("image/Menu/Buttons/Scoreboard.png");
						Exit = IMG_Load("image/Menu/Buttons/Exit.png");
					}
					else if (event.button.x > 160 && event.button.x < 300 && event.button.y > 320 && event.button.y < 373)
					{
						Play = IMG_Load("image/Menu/Buttons/Play.png");
						Settings = IMG_Load("image/Menu/Buttons/Settings.png");
						Credits = IMG_Load("image/Menu/Buttons/CreditsA.png");
						Mix_PlayChannel(-1, select, 0);
						Scoreboard = IMG_Load("image/Menu/Buttons/Scoreboard.png");
						Exit = IMG_Load("image/Menu/Buttons/Exit.png");
					}
					else if (event.motion.x > 239 && event.motion.x < 361 && event.motion.y > 254 && event.motion.y < 300)
					{
						Play = IMG_Load("image/Menu/Buttons/Play.png");
						Settings = IMG_Load("image/Menu/Buttons/Settings.png");
						Credits = IMG_Load("image/Menu/Buttons/Credits.png");
						Scoreboard = IMG_Load("image/Menu/Buttons/ScoreboardA.png");
						Mix_PlayChannel(-1, select, 0);
						Exit = IMG_Load("image/Menu/Buttons/Exit.png");
					}
					else if (event.motion.x > 185 && event.motion.x < 274 && event.motion.y > 395 && event.motion.y < 427)
					{
						Play = IMG_Load("image/Menu/Buttons/Play.png");
						Settings = IMG_Load("image/Menu/Buttons/Settings.png");
						Credits = IMG_Load("image/Menu/Buttons/Credits.png");
						Scoreboard = IMG_Load("image/Menu/Buttons/Scoreboard.png");
						Exit = IMG_Load("image/Menu/Buttons/ExitA.png");
						Mix_PlayChannel(-1, select, 0);
					}
					else
					{
						Play = IMG_Load("image/Menu/Buttons/Play.png");
						Settings = IMG_Load("image/Menu/Buttons/Settings.png");
						Credits = IMG_Load("image/Menu/Buttons/Credits.png");
						Scoreboard = IMG_Load("image/Menu/Buttons/Scoreboard.png");
						Exit = IMG_Load("image/Menu/Buttons/Exit.png");
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
							Play = IMG_Load("image/Menu/Buttons/PlayA.png");
						}
						else if (event.button.x > 160 && event.button.x < 300 && event.button.y > 320 && event.button.y < 373)
						{
							Mix_PlayChannel(-1, click, 0);
							SDL_Delay(120);
							int done = -1;
							positionCreditsM.x = 20;
							positionCreditsM.y = 40;
							CreditsM = IMG_Load("image/Menu/CreditsM.png");
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
												CreditsM = IMG_Load("image/Menu/CreditsM.png");
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
							SettingsM = IMG_Load("image/Menu/Settings/SettingsM.png");
							positionHome.x = 53;
							positionHome.y = 400;
							Home = IMG_Load("image/Menu/Settings/Home.png");
							positionMute.x = 206;
							positionMute.y = 320;
							Mute = IMG_Load("image/Menu/Settings/Mute.png");

							while (done)
							{
								while (SDL_PollEvent(&event))
								{
									switch (event.type)
									{
									case SDL_MOUSEMOTION:
										if (event.button.x > 207 && event.button.x < 249 && event.button.y > 321 && event.button.y < 363)
										{
											Mute = IMG_Load("image/Menu/Settings/MuteA.png");
										}
										else if (event.button.x > 56 && event.button.x < 105 && event.button.y > 399 && event.button.y < 448)
										{
											Home = IMG_Load("image/Menu/Settings/HomeA.png");
										}
										else
										{
											Home = IMG_Load("image/Menu/Settings/Home.png");
											Mute = IMG_Load("image/Menu/Settings/Mute.png");
										}
										break;
									case SDL_MOUSEBUTTONUP:
										if (event.button.button == SDL_BUTTON_LEFT)
										{
											positionClic.x = event.button.x;
											positionClic.y = event.button.y;
											if (event.button.x > 207 && event.button.x < 249 && event.button.y > 321 && event.button.y < 363)
											{
												Mute = IMG_Load("image/Menu/Settings/MuteA.png");
												Mix_HaltMusic();
												Mix_PlayChannel(-1, click, 0);
											}
											else if (event.button.x > 56 && event.button.x < 105 && event.button.y > 399 && event.button.y < 448)
											{
												Home = IMG_Load("image/Menu/Settings/HomeA.png");
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
											SDL_BlitSurface(A[a], NULL, screen, &positionA);
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
											SDL_BlitSurface(A[a], NULL, screen, &positionA);
											SDL_BlitSurface(logo, NULL, screen, &positionLogo);
											SDL_BlitSurface(coatofarm, NULL, screen, &positioncoatofarm);
											SDL_BlitSurface(Play, NULL, screen, &positionPlay);
											SDL_BlitSurface(Settings, NULL, screen, &positionSettings);
											SDL_BlitSurface(Scoreboard, NULL, screen, &positionScoreboard);
											SDL_BlitSurface(Credits, NULL, screen, &positionCredits);
											SDL_BlitSurface(Exit, NULL, screen, &positionExit);
											SDL_BlitSurface(texte, NULL, screen, &positionText);
										}
										//music up
										if (event.key.keysym.sym == SDLK_u)
										{
											i = i + 15;
											Mix_VolumeMusic(i);
										}
										//music down
										if (event.key.keysym.sym == SDLK_d)
										{
											i = i - 15;
											Mix_VolumeMusic(i);
										}
										//Stop the music
										if (event.key.keysym.sym == SDLK_m)
										{
											Mix_HaltMusic();
										}
										if (event.key.keysym.sym == SDLK_p)
										{
											//If there is no music playing
											if (Mix_PlayingMusic() == 0)
											{
												//Play the music
												Mix_PlayMusic(music, -1);
											}
											//If music is being played
											else
											{
												//If the music is paused
												if (Mix_PausedMusic() == 1)
												{
													//Resume the music
													Mix_ResumeMusic();
												}
												//If the music is playing
												else
												{
													//Pause the music
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
							Credits = IMG_Load("image/Menu/Buttons/CreditsA.png");
						}
						else if (event.motion.x > 239 && event.motion.x < 361 && event.motion.y > 254 && event.motion.y < 300)
						{
							Scoreboard = IMG_Load("image/Menu/Buttons/ScoreboardA.png");
						}
						else if (event.motion.x > 185 && event.motion.x < 274 && event.motion.y > 395 && event.motion.y < 427)
						{
							Mix_PlayChannel(-1, click, 0);
							SDL_Delay(120);
							Exit = IMG_Load("image/Menu/Buttons/ExitA.png");
							continuer = 0;
						}
					}
					break;
				}
			}

			SDL_BlitSurface(background, NULL, screen, &positionBackground);
			/*SDL_BlitSurface(A[a], NULL, screen, &positionA);*/
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
		return EXIT_SUCCESS;
	}
