#include "HumainPuissance4.hpp"
#include <iostream>
#include "fonctions.hpp"

HumainPuissance4::HumainPuissance4(GrillePuissance4 *grilleDeJeu, int _couleur) : JoueurPuissance4(grilleDeJeu, _couleur) {
}

HumainPuissance4::~HumainPuissance4() {

}

void HumainPuissance4::jouer() {
    int colonne;
    bool boucle = false;
    switch(this->grilleDeJeu->getNumVariante()) {
	case GrillePuissance4::VARIANTE_ORIGINALE:
	case GrillePuissance4::VARIANTE_1:
	    do {
		colonne = saisieChiffre("Sur quelle colonne voulez vous jouer ?");
		boucle = false;
		if(!this->grilleDeJeu->placerJeton(colonne-1,this->getCouleur())) {
		    std::cout << "Impossible de jouer ce coup" << std::endl;
		    boucle = true;
		}
	    }
	    while(boucle);
	    break;
	//On pourra ajouter d'autres variantes ici
    }
}
