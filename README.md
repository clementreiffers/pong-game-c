# jeu_pong

For the innovation course in the esme sudria, they ask us to conceive a game in c language. 
We has chosen to code our **pong game**.
*This project is realised by Clément Reiffers and Owen Locqueneux*

## How to launch this game

For now, this game works only on Windows, but for **linux users**, you can install Wine:
```bash
sudo apt install wine
```
There is a **main.exe** file in jeu_pong folder.
You must launch this app to play the game.
For Windows users, just click on this compilation, and for linux users, just executes the command :
```bash
wine main.exe
```

## How to compile this game

There is a **Makefile** in jeu_pong folder.
You just have to mark "make" in the terminal to compile him.
if you haven't installed make software, go install him !
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

## Different Files
There is some files which permit to compile this game, like :
-   menu.c $\rightarrow$ to know the exactly choice of what player wants
-   jeu_pong.c $\rightarrow$ it's just the game, but we give him some settings to regulate difficulty 
-   main.c $\rightarrow$ it's just a bridge between the player's choice and the game, so it's the main file
-   compteur.c $\rightarrow$ to draw the counter
-   ellipse.c $\rightarrow$ to draw circles in the game