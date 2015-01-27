#ifndef GRILLEMORPION_H
#define GRILLEMORPION_H

#include "Grille.hpp"

class GrilleMorpion : public Grille {

    public:

	/* CONSTANTES DE CLASSE*/
	static const int CROIX  = 10;
	static const int ROND   = 11;
	/* FIN CONSTANTES DE CLASSE */

	GrilleMorpion(int variante = GrilleMorpion::VARIANTE_ORIGINALE);
	virtual ~GrilleMorpion();
	
	virtual bool placerJeton(int ligne, int colonne, int valeur);
	virtual void initialiserGrille();
	virtual bool finPartie();

	virtual int getNumVariante();

    protected:
	const int numVariante;
};

#endif //GRILLEMORPION_H
