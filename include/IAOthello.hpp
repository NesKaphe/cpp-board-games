#ifndef IAOTHELLO_H
#define IAOTHELLO_H

#include "JoueurOthello.hpp"

class IAOthello : public JoueurOthello {

public:

    IAOthello(GrilleOthello *grilleDeJeu, int couleur, int profondeur);
    virtual ~IAOthello();
    virtual void jouer();

protected:
    int min(int profondeur);
    int max(int profondeur);
    int eval();
    int tourJoueur;
    const int profondeur;

};

#endif
