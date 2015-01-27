#include "IAMorpion.hpp"
#include "fonctions.hpp"
#include <cstdlib>

IAMorpion::IAMorpion(GrilleMorpion *grilleDeJeu, int couleur, int _profondeur) : JoueurMorpion(grilleDeJeu, couleur), profondeur(_profondeur) {
    this->tourJoueur = IAMorpion::ORDI;
}

IAMorpion::~IAMorpion() {

}

void IAMorpion::jouer() {

    int valeur_max = -100;
    int valeur_case_courante;

    // Variables pour le parcours du plateau de Jeu
    int colonne;
    int ligne;

    // Variables pour se souvenir de la position du meilleur coup
    int maxi_colonne;
    int maxi_ligne;


    for(ligne = 0; ligne < 3; ligne++) {
	for(colonne = 0; colonne < 3; colonne++) {
	    if(this->grilleDeJeu->caseVide(ligne,colonne)) {
		//On va simuler un coup a partir de cette case
		this->grilleDeJeu->placerJeton(ligne,colonne,GrilleMorpion::ROND);

		valeur_case_courante = this->min(this->profondeur-1);

		if(valeur_case_courante > valeur_max) {
		    valeur_max = valeur_case_courante;
		    maxi_colonne = colonne;
		    maxi_ligne = ligne;
		}
		this->grilleDeJeu->viderCase(ligne,colonne); //On annule le coup
	    }
	}
    }

    //On joue finalement le meilleur coup trouvé
    this->grilleDeJeu->setJeton(maxi_ligne, maxi_colonne, couleur);
}

int IAMorpion::min(int profondeur) {

    int valeur_min = 100;
    int valeur_case_courante;
    int colonne;
    int ligne;

    if(profondeur == 0 || this->grilleDeJeu->finPartie()) { // Dernier coup ou gagnant
	return this->eval();
    }

    this->tourJoueur = IAMorpion::ADVERSAIRE;
    for(ligne = 0; ligne < 3; ligne++) {
	for(colonne = 0; colonne < 3; colonne++) {
	    if(this->grilleDeJeu->caseVide(ligne,colonne)) { // Si la case est vide

		//On va simuler un coup a partir de cette case
		this->grilleDeJeu->placerJeton(ligne,colonne,GrilleMorpion::CROIX);
		valeur_case_courante = this->max(profondeur - 1);
		
		if(valeur_case_courante < valeur_min || ((valeur_case_courante == valeur_min) && (rand()%2 == 0)))	{
		    valeur_min = valeur_case_courante;
		}

		this->grilleDeJeu->viderCase(ligne,colonne); //On annule le coup
	    }
	}
    }
    this->tourJoueur = IAMorpion::ORDI;
    return valeur_min;
}

int IAMorpion::max(int profondeur) {
    int valeur_max = -100;
    int valeur_case_courante;
    int ligne;
    int colonne;

    if(profondeur == 0 || this->grilleDeJeu->finPartie()) { // Dernier coup ou gagnant
	return this->eval();
    }

    this->tourJoueur = IAMorpion::ORDI;
    for(ligne = 0; ligne < 3; ligne++) {
	for(colonne = 0; colonne < 3; colonne++) {
	    if(this->grilleDeJeu->caseVide(ligne,colonne)) { // Case vide
		//On simule un coup
		this->grilleDeJeu->placerJeton(ligne,colonne,GrilleMorpion::ROND);
		
		valeur_case_courante = this->min(profondeur-1);
		
		if(valeur_case_courante > valeur_max || ((valeur_case_courante == valeur_max) && (rand()%2 == 0))) {
		    valeur_max = valeur_case_courante;
		}
		
		this->grilleDeJeu->viderCase(ligne,colonne);
	    }
	}
    }
    this->tourJoueur = IAMorpion::ADVERSAIRE;
    return valeur_max;
}

int IAMorpion::eval() {

    int vainqueur;
    int nombre_de_pions = 0;
    int ligne, colonne;
    int gain_possible = 1;
    int valeur = 0;

    //On compte le nombre de pions dans la grille de jeu (afin d'attribuer un meilleur score pour les parties rapides)
    for(ligne = 0; ligne < 3; ligne++) {
	for(colonne = 0; colonne < 3; colonne++) {
	    if(!this->grilleDeJeu->caseVide(ligne,colonne))
		nombre_de_pions++;
	}
    }

    if(this->grilleDeJeu->finPartie()) {
	if(alignementN(this->grilleDeJeu, 3)) {
	    vainqueur = this->tourJoueur; //Le vainqueur est le dernier a avoir joué
	}
	else {
	    vainqueur = IAMorpion::NUL;
	}

	switch(vainqueur) {

	case IAMorpion::NUL:
	    return 0;

	case IAMorpion::ORDI:
	    return 100-nombre_de_pions;

	case IAMorpion::ADVERSAIRE:
	    return -100+nombre_de_pions;

	}
    }

    //Si on est là c'est que la partie n'est pas finie mais que l'on doit quand même evaluer la grille de jeu
    /* Recherche sur les lignes */
    ligne = 0;
    colonne = 0;
    while(ligne < 3) {
	while(colonne < 3 && gain_possible == 1) {
	    if(this->grilleDeJeu->lireCase(ligne,colonne) == GrilleMorpion::CROIX) { //Si on trouve un pion du joueur, l'ordi ne peut plus gagner
		gain_possible = 0;
	    }
	    colonne++;
	}

	valeur = valeur + gain_possible; //si gain possible = 1, on augmente le score, sinon il restera identique

	colonne = 0; //On remet l'iterateur a 0 pour la boucle suivante
	gain_possible = 1;
	ligne++;
    }

    /* Recherche sur les colonnes */
    ligne = 0;
    colonne = 0;
    while(colonne < 3) {
	while(ligne < 3 && gain_possible == 1) {
	    if(this->grilleDeJeu->lireCase(ligne,colonne) == GrilleMorpion::CROIX) { //Si on trouve un pion du joueur, l'ordi ne peut plus gagner
		gain_possible = 0;
	    }
	    ligne++;
	}

	valeur = valeur + gain_possible; //si gain possible = 1, on augmente le score, sinon il restera identique

	ligne = 0; //On remet l'iterateur a 0 pour la boucle suivante
	gain_possible = 1;
	colonne++;
    } 

    /* Recherche sur les diagonales */
    /*Comme on regarde les deux diagonales en même temps, gain_possible est mis a 2 pour representer les deux possibilités
     * Et si on trouve dans une diagonale une case C_JOUEUR, on enleve 1 a gain_possible. On ajoute finalement gain_possible a valeur
     */
    gain_possible = 2;
    colonne = 0;
    while(colonne < 3) {
	if(this->grilleDeJeu->lireCase(colonne,colonne) == GrilleMorpion::CROIX){
	    gain_possible--;
	}
	if(this->grilleDeJeu->lireCase(colonne,2-colonne) == GrilleMorpion::CROIX){
	    gain_possible--;
	}
	colonne++;
    }

    valeur = valeur + gain_possible;

    //On retourne finalement la valeur calculée
    return valeur;
}
