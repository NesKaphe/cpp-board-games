#ifndef IADAMES_H
#define IADAMES_H

#include "JoueurDames.hpp"

class IADames : public JoueurDames {


    public:


        IADames(GrilleDames *grilleDeJeu,int j,bool q);
 // void setcoup(coup d);


       virtual ~IADames();
        virtual void jouer();




};

#endif // IADAMES__H


