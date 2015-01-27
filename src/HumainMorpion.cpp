#include "HumainMorpion.hpp"
#include <iostream>
#include "fonctions.hpp"

HumainMorpion::HumainMorpion(GrilleMorpion *grilleDeJeu, int couleur) : JoueurMorpion(grilleDeJeu, couleur) {

}

HumainMorpion::~HumainMorpion() {

}

void HumainMorpion::jouer() {
    int ligne, colonne;
    bool boucle = false;

    do {
	ligne = saisieChiffre("Sur quelle ligne voulez vous jouer ? ");
	colonne = saisieChiffre("Sur quelle colonne voulez vous jouer ? ");
	boucle = false;
	if(!this->grilleDeJeu->placerJeton(ligne-1,colonne-1,this->getCouleur())) {
	    std::cout << "Impossible de jouer ce coup" << std::endl;
	    boucle = true;
	}
    }
    while(boucle);
}
