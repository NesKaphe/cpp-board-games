#ifndef PUISSANCE4_H
#define PUISSANCE4_H

#include "Jeu.hpp"
#include "GrillePuissance4.hpp"
#include "JoueurPuissance4.hpp"
#include "HumainPuissance4.hpp"
#include "IAPuissance4.hpp"

class Puissance4 : public Jeu {

    public:
	/* CONSTANTES DE CLASSE */
	static const int JOUEUR1 = 1;
	static const int JOUEUR2 = 2;
	/* FIN CONSTANTES DE CLASSE */

	Puissance4();
	virtual ~Puissance4();
	virtual void lancerJeu();
	virtual void initialiserJeu(int variante);
	virtual void partie();
	virtual void afficherJeu();
	virtual void afficherMessageFin();
        virtual void calculScore(std::vector<intPair>, int alignementEfface);
	virtual void afficherScores();

    protected:
	GrillePuissance4 *grilleDeJeu;
	JoueurPuissance4 *joueur1;
	JoueurPuissance4 *joueur2;
	int scoreJoueur1;
	int scoreJoueur2;
	int tourJoueur;
};

#endif //PUISSANCE4
