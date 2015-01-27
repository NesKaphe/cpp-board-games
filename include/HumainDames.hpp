#ifndef HUMAINDAMES_H
#define HUMAINDAMES_H

#include "JoueurDames.hpp"

class HumainDames : public JoueurDames {


    public:


        HumainDames(GrilleDames * grilleDeJeu,int c,bool q);
 // void setcoup(coup d);


       virtual ~HumainDames();
        virtual void jouer();



};

#endif // IADAMES__H


