typedef struct 
{
	SDL_Surface* mini ;
	SDL_Surface* symjoueur ;
    SDL_Surface* symenemi ;
    SDL_Event ev;
    float greendotX;
    float greendotY;
    float reddotX;
    float reddotY;

}minimap;
typedef struct 
{
	Uint32 start;
	TTF_Font *font;
	SDL_Surface *seconds;
	SDL_Color textColor;
	char timeshown[100];

}temps;

void initminimap(minimap *m);
minimap afficherminimap(minimap m,SDL_Surface * screen);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
void Initemps(temps *t);
temps affichertemps(temps t,SDL_Surface* screen);
int check_collision( SDL_Rect A, SDL_Rect B );