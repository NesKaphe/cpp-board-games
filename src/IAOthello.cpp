#include "IAOthello.hpp"
#include <cstdlib> //Pour rand
#include <iostream>

IAOthello::IAOthello(GrilleOthello *grilleDeJeu, int couleur, int _profondeur) : JoueurOthello(grilleDeJeu, couleur), profondeur(_profondeur) {
}

IAOthello::~IAOthello() {

}

void IAOthello::jouer() {
    int valeur_max = -1000;
    int valeur_case_courante;

    // Variables pour le parcours du plateau de Jeu
    int colonne;
    int ligne;

    // Variables pour se souvenir de la position du meilleur coup
    int maxi_colonne = -1;
    int maxi_ligne = -1;

    for(ligne = 0; ligne < this->grilleDeJeu->getNbLignes(); ligne++) {
	for(colonne = 0; colonne < this->grilleDeJeu->getNbColonnes(); colonne++) {
	    if(this->grilleDeJeu->coupPossible(ligne,colonne,this->getCouleur())) {
		//On va simuler un coup a partir de cette case
		this->grilleDeJeu->jouerCoup(ligne,colonne,this->getCouleur());

		valeur_case_courante = this->min(this->profondeur-1);

		if(valeur_case_courante > valeur_max || ((valeur_case_courante == valeur_max) && (rand()%2 == 0))) {
		    valeur_max = valeur_case_courante;
		    maxi_colonne = colonne;
		    maxi_ligne = ligne;
		}

		//On annule notre coup
		this->grilleDeJeu->annulerCoup();
	    }
	}
    }

    //On joue finalement le meilleur coup trouvé
    std::cout << "j'ai trouvé : l="<<maxi_ligne<<";c="<<maxi_colonne<<std::endl;
    if(maxi_colonne > -1 && maxi_ligne > -1)
	this->grilleDeJeu->jouerCoup(maxi_ligne, maxi_colonne, this->getCouleur());
    //Sinon on ne joue pas car on ne peut pas
}

int IAOthello::min(int profondeur) {
    int valeur_min = 1000;
    int valeur_case_courante;
    int colonne;
    int ligne;
    int couleur_case;

    if(this->getCouleur() == GrilleOthello::CASE_NOIRE)
	couleur_case = GrilleOthello::CASE_BLANCHE;
    else
	couleur_case = GrilleOthello::CASE_NOIRE;


    if(profondeur == 0 || this->grilleDeJeu->finPartie()) { //Dernier coup ou gagnant
	return this->eval();
    }

    for(ligne = 0; ligne < this->grilleDeJeu->getNbLignes(); ligne++) {
	for(colonne = 0; colonne < this->grilleDeJeu->getNbColonnes(); colonne++) {
	    if(this->grilleDeJeu->coupPossible(ligne,colonne,couleur_case)) {
		//On simule un coup
		this->grilleDeJeu->jouerCoup(ligne,colonne,couleur_case);

		valeur_case_courante = this->max(profondeur - 1);

		if(valeur_case_courante < valeur_min || ((valeur_case_courante == valeur_min) && (rand()%2 == 0))) {
		    valeur_min = valeur_case_courante;
		}

		this->grilleDeJeu->annulerCoup();
	    }
	}
    }

    return valeur_min;
}

int IAOthello::max(int profondeur) {
    int valeur_max = -1000;
    int valeur_case_courante;
    int ligne;
    int colonne;

    if(profondeur == 0 || this->grilleDeJeu->finPartie()) { // Dernier coup ou gagnant
	return this->eval();
    }

    for(ligne = 0; ligne < this->grilleDeJeu->getNbLignes(); ligne++) {
	for(colonne = 0; colonne < this->grilleDeJeu->getNbColonnes(); colonne++) {
	    if(this->grilleDeJeu->coupPossible(ligne,colonne,this->getCouleur())) {
		//On simule un coup
		this->grilleDeJeu->jouerCoup(ligne,colonne,this->getCouleur());

		valeur_case_courante = this->min(profondeur-1);
		
		if(valeur_case_courante > valeur_max || ((valeur_case_courante == valeur_max) && (rand()%2 == 0))) {
		    valeur_max = valeur_case_courante;
		}

		this->grilleDeJeu->annulerCoup();
	    }
	}
    }
    return valeur_max;
}

int IAOthello::eval() {
    int nombre_de_pions = 0;
    int ligne, colonne;
    int nb_jetons_adversaire = 0;
    int nb_jetons_ia = 0;

    for(ligne = 0; ligne < this->grilleDeJeu->getNbLignes(); ligne++) {
	for(colonne = 0; colonne < this->grilleDeJeu->getNbColonnes(); colonne++) {
	    if(!this->grilleDeJeu->caseVide(ligne,colonne)) {
		nombre_de_pions++;
		if(this->grilleDeJeu->lireCase(ligne,colonne) == this->getCouleur()) {
		    nb_jetons_ia++;
		}
		else {
		    nb_jetons_adversaire++;
		}
	    }
	}
    }

    if(this->grilleDeJeu->finPartie()) {
	if(nb_jetons_ia > nb_jetons_adversaire) { //IA Gagnante
	    return 100 - nombre_de_pions;
	}
	else if(nb_jetons_ia < nb_jetons_adversaire) { //IA Perdante
	    return -100-nombre_de_pions;
	}
	else { //Match nul
	    return 0;
	}
    }

    //Si on est ici, on doit evaluer la partie alors qu'elle n'est pas encore finie
    return nb_jetons_ia - nb_jetons_adversaire;
}
