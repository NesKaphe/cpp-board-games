#ifndef HUMAINMORPION_H
#define HUMAINMORPION_H

#include "JoueurMorpion.hpp"

class HumainMorpion : public JoueurMorpion {

    public:
	HumainMorpion(GrilleMorpion *grilleDeJeu, int couleur);
	virtual ~HumainMorpion();
	virtual void jouer();
    protected:


};

#endif //HUMAINMORPION_H
