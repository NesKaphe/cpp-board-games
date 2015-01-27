#include "IAPuissance4.hpp"
#include "fonctions.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>

IAPuissance4::IAPuissance4(GrillePuissance4 *grilleDeJeu, int couleur, int _profondeur, int _couleurAdversaire) : JoueurPuissance4(grilleDeJeu, couleur), profondeur(_profondeur), couleurAdversaire(_couleurAdversaire) {
    this->tourJoueur = IAPuissance4::ORDI;
}

IAPuissance4::~IAPuissance4() {

}

void IAPuissance4::jouer() {

    int valeur_max = -10000;
    int valeur_case_courante = -10000;

    int colonne;

    int maxi_colonne = -1;

    for(colonne = 0; colonne < this->grilleDeJeu->getNbColonnes(); colonne++) {
	if(this->grilleDeJeu->caseVide(0,colonne)) {   
	    //On va simuler un coup a partir de cette case
	    this->grilleDeJeu->placerJeton(colonne,this->getCouleur());

	    valeur_case_courante = this->min(this->profondeur-1);
	    std::cout << "valeur_cas_courante = " << valeur_case_courante << std::endl;
	    if(valeur_case_courante > valeur_max || ((valeur_case_courante == valeur_max) && (rand()%2 == 0)) ) {
		valeur_max = valeur_case_courante;
		maxi_colonne = colonne;
	    }

	    //On annule le coup
	    this->annulerCoup(colonne);
	}
    }

    //On joue finalement le meilleur coup trouvé
    this->grilleDeJeu->placerJeton(maxi_colonne, couleur);

}

void IAPuissance4::annulerCoup(int colonne) {

    int i = 0;
    bool fin = false;

    while(!fin) {
	if(this->grilleDeJeu->caseVide(i,colonne)) {
	    i++;
	}
	else {
	    fin = true;
	}
    }

    this->grilleDeJeu->viderCase(i,colonne);
    this->grilleDeJeu->annuleTour();
}

int IAPuissance4::min(int profondeur){

    int valeur_min = 100;
    int valeur_case_courante;
    int colonne;

    if(profondeur == 0 || this->grilleDeJeu->finPartie()) { // Dernier coup ou fin de partie
	return this->eval();
    }

    this->tourJoueur = IAPuissance4::ADVERSAIRE;
    for(colonne = 0; colonne < this->grilleDeJeu->getNbColonnes(); colonne++) {
	if(this->grilleDeJeu->caseVide(0,colonne)) {
	    //On va simuler un coup a partir de cette case
	    this->grilleDeJeu->placerJeton(colonne,this->couleurAdversaire);
	    valeur_case_courante = this->max(profondeur - 1);

	    if(valeur_case_courante < valeur_min || ((valeur_case_courante == valeur_min) && (rand()%2 == 0))) {
		valeur_min = valeur_case_courante;
	    }

	    //On annule le coup
	    this->annulerCoup(colonne);
	}
    }
    this->tourJoueur = IAPuissance4::ORDI;
    return valeur_min;
}

int IAPuissance4::max(int profondeur) {

    int valeur_max = -100;
    int valeur_case_courante;
    int colonne;

    if(profondeur == 0 || this->grilleDeJeu->finPartie()) { // Dernier coup ou fin de partie
	return this->eval();
    }

    this->tourJoueur = IAPuissance4::ORDI;
    for(colonne = 0; colonne < this->grilleDeJeu->getNbColonnes(); colonne++) {
	if(this->grilleDeJeu->caseVide(0,colonne)) {
	    //On va simuler un coup a partir de cette case
	    this->grilleDeJeu->placerJeton(colonne,this->getCouleur());
	    
	   valeur_case_courante = this->min(profondeur-1);
		
	   if(valeur_case_courante > valeur_max || ((valeur_case_courante == valeur_max) && (rand()%2 == 0))) {
	       valeur_max = valeur_case_courante;
	   } 
	   
	   //On annule le coup
	   this->annulerCoup(colonne);
	}
    }
    this->tourJoueur = IAPuissance4::ADVERSAIRE;
    return valeur_max;
}

int IAPuissance4::eval() {
    int vainqueur;
    int nombre_de_pions = 0;
    int ligne, colonne;
    int valeur = 0;
    int nb_jetons_adversaire = 0;
    int nb_jetons_ia = 0;
    std::vector<intPair> vect;

    //On compte le nombre de pions dans la grille de jeu afin d'attribuer un meilleur score pour les parties rapides)
    for(ligne = 0; ligne < this->grilleDeJeu->getNbLignes(); ligne++) {
	for(colonne = 0; colonne < this->grilleDeJeu->getNbColonnes(); colonne++) {
	    if(!this->grilleDeJeu->caseVide(ligne,colonne))
		nombre_de_pions++;
	}
    }

    if(this->grilleDeJeu->finPartie()) {
	if(alignementN(this->grilleDeJeu, 4)) {
	    vainqueur = this->tourJoueur; //Le vainqueur est le dernier a avoir joué
	}
	else {
	    vainqueur = IAPuissance4::NUL;
	}

	switch(vainqueur) {

	case IAPuissance4::NUL:
	    return 0;

	case IAPuissance4::ORDI:
	    return 1000 - nombre_de_pions;

	case IAPuissance4::ADVERSAIRE:
	    return -1000-nombre_de_pions;

	}
    }

    //Si on est là c'est que la partie n'est pas finie mais que l'on doit quand même evaluer la grille de jeu
    alignementN(this->grilleDeJeu, 3, &vect);
    std::vector<intPair>::iterator it = vect.begin();
    while(it != vect.end()) {
	if(this->grilleDeJeu->lireCase(it->first, it->second) == this->getCouleur()) {
	    nb_jetons_ia++;
	}
	else {
	    nb_jetons_adversaire++;
	}
	it++;
    }

    valeur = nb_jetons_ia - nb_jetons_adversaire;

    return valeur;
}
