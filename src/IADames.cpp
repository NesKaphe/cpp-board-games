

#include "fonctions.hpp"



#include "IADames.hpp"

#include "GrilleDames.hpp"



#include <iostream>

using namespace std;



IADames::IADames(GrilleDames * grilleDeJeu,int c,bool q):JoueurDames(grilleDeJeu,c,q) {

}


IADames::~IADames()

{

    //dtor

}

void IADames::jouer() {

       this->grilleDeJeu->joueia(this->nom);
    }












