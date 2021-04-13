#include <stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include "minimap.h"


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}
void initminimap(minimap *m)
{
	m->mini = IMG_Load("mini.jpg");
	m->symjoueur = IMG_Load("symjoueur.png");
    m->symenemi = IMG_Load("symenemi.png");
    m->greendotX=310;
    m->greendotY=146;
    m->reddotX=500;
    m->reddotY=148;
}
minimap afficherminimap(minimap m,SDL_Surface * screen)
{
	apply_surface( 300, 0, m.mini, screen );
	apply_surface( m.greendotX, m.greendotY, m.symjoueur,screen );
	//apply_surface( m.reddotX, m.reddotY, m.symenemi, screen );
	return m;
}
void Initemps(temps *t)
{
	t->textColor;
	t->textColor.r = 255;
    t->textColor.g = 255;
    t->textColor.b = 255;
	t->start=SDL_GetTicks();
	t->font=TTF_OpenFont("lazy.ttf", 30);
}
temps affichertemps(temps t,SDL_Surface* screen)
{
sprintf(t.timeshown,"%d",SDL_GetTicks() - t.start);
t.seconds=TTF_RenderText_Solid( t.font, t.timeshown, t.textColor );
apply_surface( 0, 0, t.seconds, screen );

	return t;
}
int check_collision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return 0;
    }

    if( topA >= bottomB )
    {
        return 0;
    }

    if( rightA <= leftB )
    {
        return 0;
    }

    if( leftA >= rightB )
    {
        return 0;
    }

    //If none of the sides from A are inside B
    return 1;
}

