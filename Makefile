game:*.c *.h
	gcc *.h *.c -lm -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf -lSDL_mixer -o NIGHTMARE -g
	./NIGHTMARE
