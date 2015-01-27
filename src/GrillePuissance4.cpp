#include "GrillePuissance4.hpp"
#include <vector>

GrillePuissance4::GrillePuissance4(int variante = GrillePuissance4::VARIANTE_ORIGINALE, int _nbTours) : Grille(6,7), numVariante(variante), nbTours(_nbTours) {
    //ctor
    this->initialiserGrille();
    this->toursRestant = _nbTours;
}

GrillePuissance4::~GrillePuissance4() {
    //dtor
}

void GrillePuissance4::initialiserGrille() {
    int i,j;
    for(i = 0; i < this->nbLignes; i++) {
	for(j = 0; j < this->nbColonnes; j++) {
	    this->viderCase(i,j);
	}
    }
}

bool GrillePuissance4::finPartie() {
    switch(this->numVariante) {

    case GrillePuissance4::VARIANTE_ORIGINALE:
	std::cout << "ici" << std::endl;
	if(!alignementN(this,4)) {
	    return this->grillePleine();
	}
	return true;
    case GrillePuissance4::VARIANTE_1:
	if(this->nbTours != 0) {
	    return this->grillePleine() || this->toursRestant == 0;
	}
	return this->grillePleine();
    }
    return false;
}

bool GrillePuissance4::placerJeton(int colonne, int valeur) {

    int i = 0;

    if(this->nbTours != 0) {
	if(this->toursRestant == 0) {
	    return false;
	}
    }

    if(valeur != GrillePuissance4::COULEUR_JAUNE && valeur != GrillePuissance4::COULEUR_ROUGE) {
	return false; //Couleur inconnue
    }

    if(!this->caseVide(0,colonne)) {
	return false; //Colonne deja pleine
    }

    while(i < this->nbLignes - 1 && this->caseVide(i+1,colonne)) {
	i++;
    }

    //Arrivé ici, on est sur la bonne ligne pour placer notre jeton
    this->setJeton(i,colonne,valeur);
    if(this->nbTours != 0) {
	this->toursRestant--;
    }
    return true;
}

void GrillePuissance4::annuleTour() {
    if(this->nbTours != 0) {
	this->toursRestant++;
    }
}

int GrillePuissance4::viderAlignement() {
    std::vector<intPair> vect;
    int i;
    int JoueurAlignement = 0;
    int uneCase;
    int caseCourante;
    if(alignementN(this,4,&vect)) { //Si on a un alignement d'au moins 4, on va recuperer les coordonnées dans le vector
        std::vector<intPair>::iterator it = vect.begin();
	JoueurAlignement++;
	uneCase = this->lireCase(it->first, it->second);
        while(it != vect.end()) {
	    caseCourante = this->lireCase(it->first, it->second);
	    if(caseCourante != uneCase) { //Si ce n'est pas le meme joueur qui a une case formant un alignement de 4 ou plus
		JoueurAlignement = 2;
	    }
	    
            for(i = it->first; i > 0; i--) { //On va remonter la colonne pour appliquer la gravité
		this->setJeton(i, it->second, this->lireCase(i-1, it->second));
	    }

	    this->viderCase(0, it->second); //On vide la case du haut car elle sera forcement vide a la fin de l'operation 
            it++;
        }
    }
    return JoueurAlignement; //0 joueurs, 1 joueur ou 2 joueurs avaient un alignement
}

int GrillePuissance4::getNumVariante() {
    return this->numVariante;
}
