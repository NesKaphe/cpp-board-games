#ifndef JOUEURMORPION_H
#define JOUEURMORPION_H

#include "Joueur.hpp"
#include "GrilleMorpion.hpp"

class JoueurMorpion : public Joueur {

    public:
	JoueurMorpion(GrilleMorpion *grilleDeJeu, int couleur);
	virtual ~JoueurMorpion();
	virtual void setGrilleDeJeu(GrilleMorpion *grilleDeJeu);
	virtual int getCouleur();
    protected:
	GrilleMorpion *grilleDeJeu;
	const int couleur;
};

#endif //JOUEURMORPION_H
