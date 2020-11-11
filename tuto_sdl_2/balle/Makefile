w :
	gcc -std=c17 main.c -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -o main
l :
	gcc main.c -o main -L./lib -I./include -lSDL2-2.0
	./main
wall :
	gcc -Wall -Wextra main.c -o main -L./lib -I./include -lSDL2-2.0

# FLAGS= -std=c17 -I SDL2\include -L SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 
# all :
# 	gcc  -c ellipse.c $(FLAGS)
# 	gcc  $(FLAGS) ellipse.o main.c


# CC=gcc
# CFLAGS=  -std=c17 main.c -I SDL2\include -L SDL2\lib -lmingw32 -lSDL2main -lSDL2
# LDFLAGS= -std=c17 main.c -I SDL2\include -L SDL2\lib -lmingw32 -lSDL2main -lSDL2 -o main# Link Dynamic FLAGS (Librairie) on peut rjter sdl ici
# EXEC=ell
# OBJ= ellipse.o main.o 

# all: $(EXEC)

# $(EXEC): $(OBJ)
# 		$(CC) -o $(EXEC) $^ $(LDFLAGS)
# %.o: %.c 
# 		$(CC) -c $< $(CFLAGS)
# ## equivalent à ça :
# # factorielle.o: factorielle.c
# # 		$(CC) -c factorielle.c 

# # index.o: index.c 
# # 		$(CC) -c index.c

# clean:
# 	rm -f *.o 

# mrproper:
# 	rm $(EXEC)