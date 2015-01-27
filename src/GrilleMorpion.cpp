#include "GrilleMorpion.hpp"
#include "fonctions.hpp"

GrilleMorpion::GrilleMorpion(int variante) : Grille(3,3), numVariante(variante) {
    //ctor
    this->initialiserGrille();
}

GrilleMorpion::~GrilleMorpion() {

}

void GrilleMorpion::initialiserGrille() {
    int i,j;
    for(i = 0; i < this->nbLignes; i++) {
        for(j = 0; j < this->nbColonnes; j++) {
            this->setJeton(i,j,GrilleFiveMore::CASE_VIDE);
        }
    }
}

bool GrilleMorpion::finPartie() {
    if(!alignementN(this,3)) { //Si on a pas un alignement de 3
	return this->grillePleine();
    }
    return true;
}

bool GrilleMorpion::placerJeton(int ligne, int colonne, int valeur) {

    if(valeur != GrilleMorpion::CROIX && valeur != GrilleMorpion::ROND) {
	return false; //Valeur inconnue
    }

    if(!this->caseVide(ligne, colonne)) {
	return false; //Case déjà occupé
    }

    this->setJeton(ligne,colonne,valeur);
    return true;

}

int GrilleMorpion::getNumVariante() {
    return this->numVariante;
}
