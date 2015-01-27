#ifndef JOUEURDAMES_H
#define JOUEURDAMES_H

#include "Joueur.hpp"
#include "GrilleDames.hpp"


class JoueurDames : public Joueur
{


    public:


        JoueurDames(GrilleDames *grilleDeJeu,int j,bool q);
 // void setcoup(coup d);
       virtual ~JoueurDames();

    virtual int getname();
virtual bool getquit();




    protected:
        GrilleDames *grilleDeJeu;

int nom;

bool quit;


};

#endif // JOUEURDAMES__H
