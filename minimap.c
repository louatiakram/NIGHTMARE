/**
 * @file minimap.c
 * @author @Akram akram.louati@esprit.tn
 * @brief 
 * @version 0.1
 * @date 2021-04-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "H.h"

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface(source, NULL, destination, &offset);
}
void initminimap(minimap *m)
{
    m->mini = IMG_Load("IMG/Minimap/mini.jpg");
    m->HeroDot = IMG_Load("IMG/Minimap/HeroDot.png");
    m->symenemi = IMG_Load("IMG/Minimap/symenemi.png");
    m->greendotX = 410;
    m->greendotY = 75;
    m->reddotX = 700;
    m->reddotY = 60;
}
minimap afficherminimap(minimap m, SDL_Surface *screen)
{
    apply_surface(400, 0, m.mini, screen);
    apply_surface(m.greendotX, m.greendotY, m.HeroDot, screen);
    //apply_surface(m.reddotX, m.reddotY, m.symenemi, screen);
    return m;
}
int check_collision(SDL_Rect A, SDL_Rect B)
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
    if (bottomA <= topB)
    {
        return 0;
    }

    if (topA >= bottomB)
    {
        return 0;
    }

    if (rightA <= leftB)
    {
        return 0;
    }

    if (leftA >= rightB)
    {
        return 0;
    }

    //If none of the sides from A are inside B
    return 1;
}
