#ifndef JOUEUROTHELLO_H
#define JOUEUROTHELLO_H

#include "Joueur.hpp"
#include "GrilleOthello.hpp"

class JoueurOthello : public Joueur {

public:
    JoueurOthello(GrilleOthello *grilleDeJeu, int couleur);
    virtual ~JoueurOthello();
    virtual void setGrilleDeJeu(GrilleOthello *grilleOthello);
    virtual int getCouleur();
protected:
    GrilleOthello *grilleDeJeu;
    const int couleur;

};

#endif
