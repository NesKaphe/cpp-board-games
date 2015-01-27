#ifndef HUMAIN_PUISSANCE4_H
#define HUMAIN_PUISSANCE4_H

#include "JoueurPuissance4.hpp"
#include "GrillePuissance4.hpp"

class HumainPuissance4 : public JoueurPuissance4 {

    public:

	HumainPuissance4(GrillePuissance4 *grilleDeJeu, int couleur);
	virtual ~HumainPuissance4();
	virtual void jouer();

    protected:

};

#endif //HUMAIN_PUISANCE4_H
