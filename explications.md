# explication du jeu

## l'ordre d'execution
-	1) main.c
-	2) menu.c
-	3) main.c
-	4) jeu_pong.c
	-	4bis) compteur
	-	4bis2) formes (toutes les formes _disponibles_)
-	5) gagnant.c

## fonctionnement du code main.c

### les includes
#### les includes -> bibliothèques
SDL2/SDL.h -> notre interface en tant que telle
SDL2_mixer.h -> pour notre musique

*se renseigner sur stdlib et stdio*

#### les includes -> nos codes
jeu_pong.h -> juste pour inclure notre fonction de jeu dedans
formes.h -> concerne toutes les formes du main.c (ici pour afficher le gagnant)
menu.h -> pour faire un prototype de notre fonction menu

### la fonction main 
on initialise nos fenêtres, rendu, la musique, le background du menu 
ensuite on récupère les tailles de notre fenêtre
ensuite on appelle notre menu (cf menu.c) qui nous renvoie un entier. cet entier = choix user.
là dessus on met des conditions :
-	si choix = 0 => mode facile
-	si choix = 1 => mode normale
-	si choix = 2 => mode difficile
-	si choix = 3 => quitter

si choix appartient [0,2] => on appelle la fonction pong, et on lui met notre window, le renderer, vitesse en y et x pour la balle, la vitesse des raquettes et enfin les dimensions du screen

une fois que le jeu pong terminé, on renvoie un entier, soit 1, soit 2.
c'est alors qu'on vérifie qui a gagné.
premiere condition : "si gagnant est 1 alors affiche_gagnant sinon rien
deuxieme conditon : same

enfin on arrête tout ce qu'on a pu initialiser => renderer, fenetre, music, et sdl

