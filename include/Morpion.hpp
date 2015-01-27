#ifndef MORPION_H
#define MORPION_H

#include "Jeu.hpp"
#include "GrilleMorpion.hpp"
#include "JoueurMorpion.hpp"
#include "HumainMorpion.hpp"
#include "IAMorpion.hpp"

class Morpion : public Jeu {
    public:

	/* CONSTANTES DE CLASSE */
	static const int JOUEUR1 = 1;
	static const int JOUEUR2 = 2;
	/* FIN CONSTANTES DE CLASSE */

	Morpion();
	virtual ~Morpion();
    	virtual void lancerJeu();
	virtual void initialiserJeu(int variante = Grille::VARIANTE_ORIGINALE);
	virtual void partie();
	virtual void afficherJeu();
	virtual void afficherMessageFin();
	virtual void calculScore(int numJoueur, int point);

    protected:

	GrilleMorpion *grilleDeJeu;
	JoueurMorpion *joueur1;
	JoueurMorpion *joueur2;
	int tourJoueur;
	int scoreJoueur1;
	int scoreJoueur2;
};

#endif //MORPION_H
