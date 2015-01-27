#ifndef JOUEUR_PUISSANCE4_H
#define JOUEUR_PUISSANCE4_H

#include "Joueur.hpp"
#include "GrillePuissance4.hpp"

class JoueurPuissance4 : public Joueur {

    public:
	JoueurPuissance4(GrillePuissance4 *grilleDeJeu, int couleur);
	virtual ~JoueurPuissance4();
	virtual void setGrilleDeJeu(GrillePuissance4 *grilleDeJeu);
	virtual int getCouleur();

    protected:
	GrillePuissance4 *grilleDeJeu;
	const int couleur;

};

#endif //JOUEUR_PUISSANCE4_H
