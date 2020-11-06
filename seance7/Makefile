CC=gcc
CFLAGS=-Wall
LDFLAGS= # Link Dynamic FLAGS (Librairie) on peut rjter sdl ici
EXEC=fact
OBJ= factorielle.o index.o 

all: $(EXEC)

$(EXEC): $(OBJ)
		$(CC) -o $(EXEC) $^ $(LDFLAGS)
%.o: %.c 
		$(CC) -c $< $(CFLAGS)
## equivalent à ça :
# factorielle.o: factorielle.c
# 		$(CC) -c factorielle.c 

# index.o: index.c 
# 		$(CC) -c index.c

clean:
	rm -f *.o 

mrproper:
	rm $(EXEC)