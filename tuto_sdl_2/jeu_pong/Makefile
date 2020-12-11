w :
	gcc -std=c17 ellipse.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 
	gcc -std=c17 raquette.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 
	gcc -std=c17 compteur.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 
	gcc -std=c17 jeu_pong.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer 
	gcc -std=c17 menu.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
	gcc -std=c17 gagnant.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf



	gcc -std=c17 main.c ellipse.o raquette.o compteur.o jeu_pong.o menu.o gagnant.o -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -o main

l :
	gcc main.c -o main -L./lib -I./include -lSDL2-2.0
	./main

wall :
	gcc -Wall -Wextra main.c -o main -L./lib -I./include -lSDL2-2.0
