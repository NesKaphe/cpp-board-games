#ifndef IAMORPION_H
#define IAMORPION_H

#include "JoueurMorpion.hpp"

class IAMorpion : public JoueurMorpion {

    public:
	/* CONSTANTES DE CLASSE */
	static const int ORDI       = 1; //Tour
	static const int ADVERSAIRE = 2; //Tour
	static const int NUL        = 0; //Aucun gagnant
	static const int PROFONDEUR_FACILE = 2; //Profondeur pour le parcours de l'algo min et max
        static const int PROFONDEUR_MOYEN  = 3;
        static const int PROFONDEUR_DIFFICILE = 5;
	/* FIN CONSTANTES DE CLASSE */
	
        IAMorpion(GrilleMorpion *grilleDeJeu, int couleur, int profondeur);
	virtual ~IAMorpion();
	virtual void jouer();
    protected:
	int min(int profondeur);
	int max(int profondeur);
	int eval();
	int tourJoueur;
        const int profondeur;
    

};

#endif //IAMORPION_H
