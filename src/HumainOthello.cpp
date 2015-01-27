#include "HumainOthello.hpp"
#include "fonctions.hpp"

HumainOthello::HumainOthello(GrilleOthello * grilleDeJeu, int couleur) : JoueurOthello(grilleDeJeu, couleur) {
}

HumainOthello::~HumainOthello() {

}

void HumainOthello::jouer() {

    std::string saisie;
    bool boucle = true;

    while(boucle) {
	saisieString(&saisie, "Quelle action voulez vous faire ? ");
	if(saisie.compare("help") == 0) {
	    this->afficherAide();
	    boucle = true;
	}
	else if(saisie.compare("coups") == 0) {
	    this->afficherCoupsPossible();
	    boucle = true;
	}
	else if(saisie.compare("quit") == 0) {
	    boucle = false;
	    this->quit = true;
	}
	else if(saisie.compare("PA") == 0) {
	    if(this->grilleDeJeu->listeCoupsPossible(this->getCouleur()).empty()) {
		boucle = false;
	    }
	    else {
		boucle = true;
		std::cout << "Impossible de passer votre tour, faites \"help\" pour obtenir de l'aide" << std::endl;
	    }
	}
	else if(saisie.compare("annuler") == 0) {
	    this->grilleDeJeu->annulerCoup();
	    boucle = false;
	}
	else {
	    if(this->grilleDeJeu->jouerCoup(saisie[0] - 'A', saisie[1] - '1', this->getCouleur())){
		boucle = false;
	    }
	    else {
		boucle = true;
		std::cout << "Impossible de jouer ce coup" << std::endl;
	    }
	}
    }
}

void HumainOthello::afficherCoupsPossible() {
    std::vector<intPair> coups = this->grilleDeJeu->listeCoupsPossible(this->getCouleur());
    std::vector<intPair>::iterator it = coups.begin();
    int taille = coups.size();
    int compteur = 0;
    char lettre = 'A';
    std::cout << "Liste des coups disponibles :" << std::endl;
    while(it != coups.end()) {
	lettre += it->first;
	std::cout << lettre << it->second + 1;
	if(compteur < taille-1) {
	    std::cout << ",";
	}
	it++;
	lettre = 'A';
    }
    std::cout << std::endl;
}

void HumainOthello::afficherAide() {
    std::cout << "Commandes disponibles :" << std::endl;
    std::cout << "help : Affiche l'aide" << std::endl;
    std::cout << "coups : Affiche la liste des coups disponibles" << std::endl;
    std::cout << "quit : Quitte la partie" << std::endl;
    std::cout << "<Colonne><Ligne> : Joue un coup sur la colonne et la ligne (Exemple : C4)" << std::endl;
}
