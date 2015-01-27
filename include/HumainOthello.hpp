#ifndef HUMAINOTHELLO_H
#define HUMAINOTHELLO_H

#include "JoueurOthello.hpp"

class HumainOthello : public JoueurOthello {

public:
    HumainOthello(GrilleOthello *grilleDeJeu, int couleur);
    virtual ~HumainOthello();
    virtual void jouer();
    void afficherAide();
    void afficherCoupsPossible();
};

#endif //HUMAINOTHELLO_H
