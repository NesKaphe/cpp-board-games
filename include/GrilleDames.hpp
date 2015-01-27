#ifndef GRILLEDAMES_H
#define GRILLEDAMES_H

#include <stdio.h>
#include <stdlib.h>
#include "Grille.hpp"

class GrilleDames : public Grille

{public:
    GrilleDames(int dimLigne, int dimColonne, int variante = GrilleDames::VARIANTE_ORIGINALE);
 static const int N      = 1;
        static const int B        = 2;
 static const int RN      = 3;
        static const int RB        = 4;

virtual void initialiserGrille();
virtual ~GrilleDames();
bool mange(int j,int x,int y,int x2, int y2);
bool possible(int j,int x,int y,int x2, int y2);
 bool candeplace();

bool cherchereine(int j, int x, int y);
bool deplace(int j,int x,int y,int x2, int y2);
bool mangereine(int j,int x,int y,int x2, int y2);
bool deplacereine(int j,int x,int y,int x2, int y2);
bool canmangereine(int j,int x,int y,int x2, int y2);
bool cherche(int j, int x, int y);
int score(int j);
int reines(int j);
bool canmange(int j,int x,int y,int x2, int y2);
void afficherJeu();
bool joueia(int j);

bool finPartie();

protected:
const int numVariante;
};

#endif
