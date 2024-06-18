#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>

/**********defs**********/

/*Screen*/
#define SCREEN_W 1280
#define SCREEN_H 600

/*DemonLord*/
#define Ennemi_WIDTH 160
#define Ennemi_HEIGHT 120

/*DemonLordA*/
#define EnnemiA_WIDTH 240
#define EnnemiA_HEIGHT 190

/*Ghool*/
#define Ghool_WIDTH 142
#define Ghool_HEIGHT 150

/*Ghost*/
#define Ghost_WIDTH 105
#define Ghost_HEIGHT 125

/*Dragon*/
/*#define ES_WIDTH 190
#define ES_HEIGHT 175*/

/*Fireball*/
/*#define ES_WIDTH 26
#define ES_HEIGHT 26*/

/**********Structures**********/
typedef struct
{
    SDL_Surface *texte;
    SDL_Rect position;
    TTF_Font *police;
    char entree[100];
    int secondesEcoulees;
    SDL_Color couleurBlanche;
    time_t t1, t2;
    int min, sec;
} temps;

typedef struct
{
    SDL_Surface *backgroundImg;
    SDL_Rect backgroundPos;
} Background;

typedef struct
{
    SDL_Rect position, PosHP;
    SDL_Surface *image[10], *HP;
    Mix_Chunk *Walk;
    Mix_Chunk *Jump;
    Mix_Chunk *Attack;
    int vie;
    int moving;    //0:Not moving 1:moving
    int direction; //0:right 1:left 2:attack
} Hero;

/*typedef struct
{
    SDL_Surface *Death[9];
    SDL_Surface *Attack[8];
    SDL_Surface *rightImage[10];
    SDL_Surface *leftImage[10];
} Hero;*/
typedef struct
{
    SDL_Surface *mini;
    SDL_Surface *HeroDot;
    SDL_Surface *symenemi;
    SDL_Event ev;
    float greendotX;
    float greendotY;
    float reddotX;
    float reddotY;

} minimap;

typedef struct
{
    SDL_Rect positionAbsolue;
    SDL_Rect positionAnimation;
    SDL_Surface *image;
    Mix_Chunk *DemonLA;
    int direction, etat, s1, s2, s3, s4;
} EnnemiA;

typedef struct
{
    SDL_Rect positionAbsolue;
    SDL_Rect positionAnimation;
    SDL_Surface *image;
    Mix_Chunk *Ghool, *DemonL;
    int direction, etat, s1, s2, s3, s4;
} Ennemi;

typedef struct
{
    SDL_Rect positionAbsolue;
    SDL_Rect positionAnimation;
    SDL_Surface *image;
    Mix_Chunk *Ghool, *DemonL;
    int direction, etat, s1, s2, s3, s4;
} Ghool;

typedef struct
{
    SDL_Rect positionAbsolue;
    SDL_Rect positionAnimation;
    SDL_Surface *image;
    Mix_Chunk *Ghool, *DemonL;
    int direction, etat, s1, s2, s3, s4;
} Ghost;

/**********Functions**********/
int jouer(SDL_Surface *screen);

void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *screen);
void free_temps(temps *t, SDL_Surface *screen);

void InitBackground(Background *Backg);
void AfficherBackground(Background *Backg, SDL_Surface *screen);
void FreeBackground(Background *Backg);

void InitEnnemi(Ennemi *E);
void AfficherEnnemi(Ennemi E, SDL_Surface *screen);
void AnimerEnnemi(Ennemi *E);
void Deplacer(Ennemi *E);
int CollisionBB(Ennemi E, Hero H);
void DeplacerIA(Ennemi *E, Hero *H);
void LibererEnnemi(Ennemi *E);

void InitGhool(Ghool *E);
void AfficherGhool(Ghool E, SDL_Surface *screen);
void AnimerGhool(Ghool *E);
void DeplacerGhool(Ghool *E);
int CollGhool(Ghool E, Hero H);
void LibererGhool(Ghool *E);

void InitGhost(Ghost *E);
void AfficherGhost(Ghost E, SDL_Surface *screen);
void AnimerGhost(Ghost *E);
void DeplacerGhost(Ghost *E);
int CollGhost(Ghost E, Hero H);
void LibererGhost(Ghost *E);

void InitEnnemiA(EnnemiA *E);
void AfficherEnnemiA(EnnemiA E, SDL_Surface *screen);
void AnimerEnnemiA(EnnemiA *E);
void DeplacerEA(EnnemiA *E);
void DeplacerIAA(EnnemiA *E, Hero *H);
void LibererEnnemiA(EnnemiA *E);

void InitHero(Hero *A);
void MoveHero(Hero *A);
void FreeHero(Hero *A);

void initminimap(minimap *m);
minimap afficherminimap(minimap m, SDL_Surface *screen);
void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);
int check_collision(SDL_Rect A, SDL_Rect B);


