# jeu_pong

For the innovation track in esme sudria, they ask us to conceive a game in c language. 
We has chosen to code our **pong game**.
*This project is realised by Clément Reiffers and Owen Locqueneux*

## How to play

the left player (player 1) use "Z" to go to the top of the screen and "S" to go down.
the right player (player 2) use "up arrow" to go to the top of the screen and "down arrow" to go down.

## How to launch this game

### Windows Users
There is a **main.exe** file in jeu_pong folder.
You must launch this app to play the game.
For Windows users, just click on this compilation or write on the terminal :
```bash
./main.exe
```

### Linux Users
There is a **main** file in jeu_pong folder
you must launch this app to play the game
For linux users, write on the terminal :
```bash 
./main
```
## How to compile this game

There is a **Makefile** in jeu_pong folder.
### Windows Users

You just have to write "make windows" in the terminal to compile it.
if you haven't installed make software, go install it !
Makefile executes these commands :
```bash
gcc -std=c17 ellipse.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 

gcc -std=c17 raquette.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 

gcc -std=c17 compteur.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 

gcc -std=c17 jeu_pong.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer 

gcc -std=c17 menu.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

gcc -std=c17 gagnant.c -c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

gcc -std=c17 main.c ellipse.o raquette.o compteur.o jeu_pong.o menu.o gagnant.o -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -o main

```
### Linux Users

You just have to write "make linux" in the terminal to compile it.
if you haven't installed make software, go install it !
Makefile executes these commands :
```bash
	gcc -std=c17 ellipse.c -c -Wall -lSDL2main -lSDL2  -lm
	gcc -std=c17 raquette.c -c -Wall -lSDL2main -lSDL2  -lm
	gcc -std=c17 compteur.c -c -Wall -lSDL2main -lSDL2  -lm
	gcc -std=c17 jeu_pong.c -c -Wall -lSDL2main -lSDL2 -lSDL2_mixer  -lm
	gcc -std=c17 menu.c -c -Wall -lSDL2main -lSDL2 -lSDL2_ttf -lm
	gcc -std=c17 gagnant.c -c -Wall -lSDL2main -lSDL2 -lSDL2_ttf -lm

	gcc -std=c17 main.c ellipse.o raquette.o compteur.o jeu_pong.o menu.o gagnant.o -Wall -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -lm -o main
```
## Different Files
There are many files in this jeu_pong folder, like :
-   menu.c : to know the exactly choice of what player wants
-   jeu_pong.c : it's just the game, but we give him some settings to regulate difficulty 
-   main.c :  it's just a bridge between the player's choice and the game, so it's the main file
-   compteur.c : to draw the counter
-   ellipse.c : to draw circles in the game