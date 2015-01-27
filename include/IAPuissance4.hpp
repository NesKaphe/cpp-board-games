#ifndef IAPUISSANCE4_H
#define IAPUISSANCE4_H

#include "JoueurPuissance4.hpp"

class IAPuissance4 : public JoueurPuissance4 {

    public:
	/* CONSTANTES DE CLASSE */
	static const int ORDI       = 1; //Tour
	static const int ADVERSAIRE = 2; //Tour
	static const int NUL        = 0; //Aucun gagnant
	static const int PROFONDEUR_FACILE = 2; //Profondeur pour le parcours de l'algo min et max
        static const int PROFONDEUR_MOYEN = 3;
        static const int PROFONDEUR_DIFFICILE = 6;
	/* FIN CONSTANTES DE CLASSE */
	
        IAPuissance4(GrillePuissance4 *grilleDeJeu, int couleur, int profondeur, int _couleurAdversaire);
	virtual ~IAPuissance4();
	virtual void jouer();
    protected:
	int min(int profondeur);
	int max(int profondeur);
	int eval();
        void annulerCoup(int colonne);
	int tourJoueur;
        const int profondeur;
        const int couleurAdversaire;
    

};

#endif //IAPUISSANCE4_H
