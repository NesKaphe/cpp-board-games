#ifndef GRILLE_PUISSANCE4_H
#define GRILLE_PUISSANCE4_H

#include "Grille.hpp"
#include "fonctions.hpp"

class GrillePuissance4 : public Grille {

    public:
	
	/* CONSTANTES DE CLASSE */
	static const int COULEUR_JAUNE = 1;
	static const int COULEUR_ROUGE = 2;
	static const int VARIANTE_1 = 1001;
	/* FIN CONSTANTES DE CLASSE */

        GrillePuissance4(int variante,int nbTours = 0);
	virtual ~GrillePuissance4();
        virtual void annuleTour();
        virtual int viderAlignement(); //Variante 1
        virtual bool placerJeton(int colonne, int couleur); //Tous
	
        virtual int getNumVariante();

	virtual void initialiserGrille();
	virtual bool finPartie();

    protected:
	const int numVariante;
        const int nbTours;
        int toursRestant;

};

#endif // GRILLE_PUISSANCE4_H
