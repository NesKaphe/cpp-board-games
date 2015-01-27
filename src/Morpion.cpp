#include "Morpion.hpp"
#include "fonctions.hpp"
#include <string>
#include <iostream>

Morpion::Morpion() : Jeu(2) {
    this->joueur1 = new HumainMorpion(0, GrilleMorpion::CROIX);
    this->joueur2 = 0;
    this->grilleDeJeu = 0;
    this->tourJoueur = Morpion::JOUEUR1;
    this->scoreJoueur1 = 0;
    this->scoreJoueur2 = 0;
}

Morpion::~Morpion() {
    if(this->grilleDeJeu != 0) {
	delete this->grilleDeJeu;
    }

    delete this->joueur1;

    if(this->joueur2 != 0) {
	delete this->joueur2;
    }
}

void Morpion::initialiserJeu(int variante) {
    this->grilleDeJeu = new GrilleMorpion(variante);
}

void Morpion::lancerJeu() {
    int choix;
    std::string nomJoueur;

    this->initialiserJeu(GrilleMorpion::VARIANTE_ORIGINALE);

    saisieString(&nomJoueur, "Entrez votre nom : ");
    this->joueur1->setNom(nomJoueur);
    this->joueur1->setGrilleDeJeu(this->grilleDeJeu);

    while(true) {
	clear_screen();
	std::cout << "Mode de jeu" << std::endl;
	std::cout << "1 - Quitter Morpion" << std::endl;
	std::cout << "2 - Jouer contre un Humain" << std::endl;
	std::cout << "3 - Jouer contre une IA facile" << std::endl;
	std::cout << "4 - Jouer contre une IA moyenne" << std::endl;
	std::cout << "5 - Jouer contre une IA difficile" << std::endl;
	choix = saisieChiffre("Quel est votre choix ? ");
	
	switch(choix) {
	case 1:
	    return;
	case 2:
	    saisieString(&nomJoueur, "Entrez le nom du joueur 2 : ");
	    this->joueur2 = new HumainMorpion(this->grilleDeJeu, GrilleMorpion::ROND);
	    this->joueur2->setNom(nomJoueur);
	    break;
	case 3:
	    this->joueur2 = new IAMorpion(this->grilleDeJeu, GrilleMorpion::ROND, IAMorpion::PROFONDEUR_FACILE);
	    this->joueur2->setNom("Ordi");
	    break;
	case 4:
	    this->joueur2 = new IAMorpion(this->grilleDeJeu, GrilleMorpion::ROND, IAMorpion::PROFONDEUR_MOYEN);
	    this->joueur2->setNom("Ordi");
	    break;
	case 5:
	    this->joueur2 = new IAMorpion(this->grilleDeJeu, GrilleMorpion::ROND, IAMorpion::PROFONDEUR_DIFFICILE);
	    this->joueur2->setNom("Ordi");
	    break;
	default:
	    continue;
	    break;
	}

	this->partie();
	delete this->joueur2;
	this->joueur2 = 0;
    }
}

void Morpion::partie() {

    bool bouclePartie = true;
    std::string rejouer;
    while(bouclePartie) {
	clear_screen();
	this->afficherJeu();

	if(this->grilleDeJeu->finPartie()) {
	    bouclePartie = false;
	    this->afficherMessageFin();
	    do {
		saisieString(&rejouer, "Voulez vous rejouer avec les mêmes regles ? <o/n> ");
	    }
	    while(rejouer.compare("o") != 0 && rejouer.compare("n"));

	    this->grilleDeJeu->initialiserGrille();
	    this->scoreJoueur1 = 0;
	    this->scoreJoueur2 = 0;
	    this->tourJoueur = Morpion::JOUEUR1;
	    if(rejouer.compare("o") == 0) {
		bouclePartie = true;
		continue;
	    }
	    else {
		break;
	    }
	}

	if(this->tourJoueur == Morpion::JOUEUR1) {
	    std::cout << "C'est à " << this->joueur1->getNom() << " de jouer" << std::endl;
	    this->joueur1->jouer();
	}
	else {
	    std::cout << "C'est à " << this->joueur2->getNom() << " de jouer" << std::endl;
	    this->joueur2->jouer();
	}

	if(alignementN(this->grilleDeJeu, 3)) {
	    this->calculScore(this->tourJoueur, 1);
	}
	else {
	    if(this->tourJoueur == Morpion::JOUEUR1) {
		this->tourJoueur = Morpion::JOUEUR2;
	    }
	    else {
		this->tourJoueur = Morpion::JOUEUR1;
	    }
	}

    }

}

void Morpion::calculScore(int numJoueur, int point) {
    
    switch(numJoueur) {
    case Morpion::JOUEUR1:
	this->scoreJoueur1 += point;
	break;
    case Morpion::JOUEUR2:
	this->scoreJoueur2 += point;
	break;
    }

}

void Morpion::afficherJeu() {
    int i, j, k;

    std::cout << "   ";
    for(k = 1; k <= this->grilleDeJeu->getNbColonnes(); k++) {
        std::cout << " "<< k << "  ";
    }

    std::cout << std::endl << "   ";
    for(k = 0; k < this->grilleDeJeu->getNbColonnes(); k++) {
        std::cout << "___ ";
    }

    std::cout << std::endl;
    for(i = 0; i < this->grilleDeJeu->getNbLignes(); i++) {
        std::cout << i+1 << " ";
        for(j = 0; j < this->grilleDeJeu->getNbColonnes(); j++) {
            std::cout << "|";

            switch(this->grilleDeJeu->lireCase(i,j)) {
                case GrilleMorpion::CASE_VIDE:
                    std::cout << " _ ";
                    break;
                case GrilleMorpion::CROIX:
                    std::cout << " X ";
                    break;
                case GrilleMorpion::ROND:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "   ";
                    break;
            }
        }
        std::cout << "|" << std::endl << "  |";
        for(k = 0; k < this->grilleDeJeu->getNbColonnes(); k++) {
            std::cout << "___|";
        }
        std::cout << std::endl;
    }
}

void Morpion::afficherMessageFin() {

    std::cout << "Partie terminée! ";
    if(this->scoreJoueur1 > this->scoreJoueur2) {
	std::cout << this->joueur1->getNom() << " a gagné !" << std::endl;
    }
    else if(this->scoreJoueur1 < this->scoreJoueur2) {
	std::cout << this->joueur2->getNom() << " a gagné !" << std::endl;
    }
    else {
	std::cout << "C'est un match nul" << std::endl;
    }

    pause();
}

