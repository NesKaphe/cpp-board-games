#ifndef FIVEORMORE_HPP
#define FIVEORMORE_HPP

#include "Jeu.hpp"
#include "GrilleFiveMore.hpp"
#include "JoueurFiveOrMore.hpp"


class FiveOrMore : public Jeu
{
    public:
        FiveOrMore();
        virtual ~FiveOrMore();
        virtual void lancerJeu();
        virtual void initialiserJeu(int variante);
        virtual void partie();
        virtual void afficherJeu();
        virtual void afficherScore();
        virtual void afficherMessageFin();
        virtual void calculScore(int nbJetonsEfface);


    protected:
        GrilleFiveMore *grilleDeJeu;
        JoueurFiveOrMore *joueur;
        int score;
    private:
};

#endif // FIVEORMORE_HPP
