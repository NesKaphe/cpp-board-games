#include "Grille.hpp"


Grille::Grille(int Lignes, int Colonnes) : nbLignes(Lignes), nbColonnes(Colonnes) {
    //ctor
    this->tableau = new int*[Lignes];
    for(int i = 0; i < Lignes; i++) {
        this->tableau[i] = new int[Colonnes];
    }
}

Grille::~Grille() {
    //dtor
    for(int i = 0; i < this->nbLignes; i++) {
        delete [] tableau[i];
    }
    delete [] tableau;
}


bool Grille::caseVide(int ligne, int colonne) {
    return this->tableau[ligne][colonne] == Grille::CASE_VIDE;
}

void Grille::viderCase(int ligne, int colonne) {
    this->tableau[ligne][colonne] = Grille::CASE_VIDE;
}

void Grille::setJeton(int ligne, int colonne, int valeur) {
    this->tableau[ligne][colonne] = valeur;
}

int Grille::lireCase(int ligne, int colonne) {
    return this->tableau[ligne][colonne];
}

bool Grille::coordonneesValide(int ligne, int colonne) {
    if(ligne < 0 || ligne > this->nbLignes-1) {
        return false;
    }
    if(colonne < 0 || colonne > this->nbColonnes-1) {
        return false;
    }

    return true;
}

int Grille::getNbLignes() {
    return this->nbLignes;
}

int Grille::getNbColonnes() {
    return this->nbColonnes;
}
