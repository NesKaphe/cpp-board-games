#ifndef DAMES_HP
#define DAMES_HP

#include "Jeu.hpp"
#include "GrilleDames.hpp"
#include "JoueurDames.hpp"
#include "IADames.hpp"
#include "HumainDames.hpp"


class Dames : public Jeu{
    public:


typedef char coup[3];



        Dames();
        virtual ~Dames();
        virtual void initialiserJeu(int variante = GrilleDames::VARIANTE_ORIGINALE);
        virtual void lancerJeu();
        virtual void partie();
        virtual void afficherJeu();
        virtual void afficherScore();
	virtual void calculScore() ;
	//virtual bool finpartie();

    protected:
       GrilleDames *grilleDeJeu;
        JoueurDames *joueur1;
JoueurDames *joueur2;
	int scoreJoueur1;
	int scoreJoueur2;
	int scoreJoueur11;
	int scoreJoueur22;

    private:
};

#endif // DAMES_HPP
