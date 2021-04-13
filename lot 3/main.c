#include <stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include "minimap.h"

int main(int argc, char* args[])
{
minimap m;
temps t;
//initialisatiin
SDL_Surface* screen=NULL;
SDL_Surface* grand=NULL;
SDL_Surface* gamer=NULL;
SDL_Surface* enemi=NULL;
///player position
SDL_Rect gamerposition;
gamerposition.x=10;
gamerposition.y=735;
//player box position
SDL_Rect boxplayer;
boxplayer.x=gamerposition.x;
boxplayer.y=gamerposition.y;
boxplayer.w=265;
boxplayer.h=168;
//object box position
SDL_Rect boxobject;
boxobject.x=400;
boxobject.y=800;
boxobject.w=65;
boxobject.h=85;


SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
grand = IMG_Load("col.bmp");
gamer=IMG_Load("joueur.bmp");
enemi=IMG_Load("enemi.png");
screen = SDL_SetVideoMode(1200,950,32,SDL_HWSURFACE );
initminimap(&m);
Initemps(&t);

int imup=0;
int quit =0;
int pos=0;
while (quit==0)
{
SDL_BlitSurface(grand, NULL, screen, NULL);

if (SDL_PollEvent (&m.ev)!=0)
{
	if (m.ev.type==SDL_QUIT)
		{
			quit=1;
		}

}
   if( m.ev.type == SDL_KEYDOWN )
        {
		    if(m.ev.key.keysym.sym== SDLK_RIGHT)
				{
					
						gamerposition.x+=5;
						boxplayer.x=gamerposition.x;
						m.greendotX+=1.5;
				    if( check_collision( boxplayer, boxobject ) ==1 && imup==0)
					    {
					        gamerposition.x-=5;
					       boxplayer.x=gamerposition.x;
					       m.greendotX-=1.5;

					    }

				}
			if(m.ev.key.keysym.sym== SDLK_LEFT)
				{
					gamerposition.x-=5;
					boxplayer.x=gamerposition.x;
					m.greendotX-=1.5;
					if( check_collision( boxplayer, boxobject ) ==1 && imup==0)
					    {
					        gamerposition.x+=5;
					       boxplayer.x=gamerposition.x;
					       m.greendotX+=1.5;
					    }
					
				}
			if(m.ev.key.keysym.sym== SDLK_UP)
				{
					gamerposition.y-=6;
					boxplayer.y=gamerposition.y;
					
				}

 		}

 	if( m.ev.type == SDL_KEYUP )
        {
			if(m.ev.key.keysym.sym== SDLK_LEFT)
				{
					gamerposition.x+=0.1;
					boxplayer.x=gamerposition.x;
				}
 		}
 		
 		if(m.greendotX < 310)
 		{
 			m.greendotX=310;

 		}
 		if(gamerposition.y < 735 )
 		{

 			gamerposition.y+=2;
 			boxplayer.y=gamerposition.y;
 		}
 		if(gamerposition.y < 735 && check_collision( boxplayer, boxobject ) ==1)
 		{
			gamerposition.y-=2;
 			boxplayer.y=gamerposition.y;
 		}

 		if(gamerposition.x <5)
 		{
 			gamerposition.x=5;
 		}

m=afficherminimap(m,screen);
apply_surface( gamerposition.x, gamerposition.y, gamer, screen );
apply_surface( 900, 800, enemi, screen );
t=affichertemps(t,screen);
SDL_Flip(screen);
}
SDL_FreeSurface(screen);
SDL_FreeSurface(enemi);
SDL_FreeSurface(gamer);
SDL_FreeSurface(t.seconds);


SDL_Quit();
return 0;
}
