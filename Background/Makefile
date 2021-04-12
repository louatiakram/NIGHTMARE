all:main.o jeu.o background.o
	gcc main.o jeu.o background.o -o Background -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
jeu.o:jeu.c
	gcc -c jeu.c -g
background.o:background.c
	gcc -c background.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f Background
