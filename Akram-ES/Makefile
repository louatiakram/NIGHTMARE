all:main.o ennemi.o es.o jeu.o background.o
	gcc main.o ennemi.o es.o jeu.o background.o -o Akram-ES -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
jeu.o:jeu.c
	gcc -c jeu.c -g
es.o:es.c
	gcc -c es.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -g
background.o:background.c
	gcc -c background.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f Akram-ES
