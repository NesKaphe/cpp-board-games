

#include "fonctions.hpp"



#include "JoueurDames.hpp"


#include <iostream>

using namespace std;



JoueurDames::JoueurDames(GrilleDames * grilleDeJeu,int c,bool q) {

    this->nom = c;

    this->grilleDeJeu = grilleDeJeu;


    this->quit=q;

}

bool JoueurDames::getquit() {
    return this->quit;
}

int JoueurDames::getname() {
    return this->nom;
}

JoueurDames::~JoueurDames()

{

    //dtor

}














