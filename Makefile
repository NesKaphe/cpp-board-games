DEBUG = no
PATHSRC = src/
PATHHEADERS = include/
PATHBIN = bin/
CC = g++

ifeq ($(DEBUG), yes)
	CFLAGS = -g -W -Wall -I$(PATHHEADERS)
else
	CFLAGS = -W -Wall -I$(PATHHEADERS)
endif

EXEC = jeux
OBJ = $(OBJBASE) $(OBJFIVEMORE) $(OBJPUISSANCE4) $(OBJMORPION) $(OBJOTHELLO) $(OBJDAMES) bin/main.o
OBJBASE = bin/fonctions.o bin/Grille.o bin/Jeu.o bin/Joueur.o
OBJFIVEMORE = bin/FiveOrMore.o bin/GrilleFiveMore.o bin/JoueurFiveOrMore.o
OBJOTHELLO = bin/GrilleOthello.o bin/JoueurOthello.o bin/HumainOthello.o bin/IAOthello.o bin/Othello.o
OBJPUISSANCE4 = bin/GrillePuissance4.o bin/JoueurPuissance4.o bin/HumainPuissance4.o bin/IAPuissance4.o bin/Puissance4.o
OBJMORPION = bin/GrilleMorpion.o bin/JoueurMorpion.o bin/HumainMorpion.o bin/IAMorpion.o bin/Morpion.o
OBJDAMES = bin/GrilleDames.o bin/JoueurDames.o bin/HumainDames.o bin/IADames.o bin/Dames.o

all: $(EXEC)

jeux: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

bin/main.o: main.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

bin/%.o: src/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf bin/*.o

mrproper:
	@rm -rf $(EXEC)
