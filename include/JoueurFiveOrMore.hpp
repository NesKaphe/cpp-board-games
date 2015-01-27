#ifndef JOUEURFIVEORMORE_H
#define JOUEURFIVEORMORE_H

#include "Joueur.hpp"
#include "GrilleFiveMore.hpp"


class JoueurFiveOrMore : public Joueur
{
    public:
        JoueurFiveOrMore(GrilleFiveMore *grilleDeJeu);
        virtual ~JoueurFiveOrMore();
        virtual void jouer();
	virtual void setGrilleDeJeu(GrilleFiveMore *grilleDeJeu);
    protected:
        GrilleFiveMore *grilleDeJeu;
    private:
};

#endif // JOUEURFIVEORMORE_H
