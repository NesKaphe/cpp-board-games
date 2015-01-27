#include "Othello.hpp"
#include "fonctions.hpp"

Othello::Othello() : Jeu(2) {
    this->joueur1 = NULL;
    this->joueur2 = NULL;
    this->grilleDeJeu = NULL;
    this->tourJoueur = Othello::JOUEUR1;
    this->scoreJoueur1 = 2;
    this->scoreJoueur2 = 2;
}

Othello::~Othello() {
    if(this->grilleDeJeu != NULL) {
	delete this->grilleDeJeu;
    }

    if(this->joueur2 != NULL) {
	delete this->joueur2;
    }

    if(this->joueur1 != NULL) {
	delete this->joueur1;
    }
}

void Othello::initialiserJeu(int variante) {
    this->grilleDeJeu = new GrilleOthello(variante);
}

void Othello::lancerJeu() {
    int choix;
    int profondeur;
    std::string nomJoueur;

    this->initialiserJeu();

    while(true) {
	std::cout << "Menu principal Othello" << std::endl;
	std::cout << "1 - Quitter Othello" << std::endl;
	std::cout << "2 - Jouer contre un Humain" << std::endl;
	std::cout << "3 - Jouer contre une IA et commencer" << std::endl;
	std::cout << "4 - Jouer contre une IA et jouer le deuxieme" << std::endl;
	std::cout << "5 - Duel d'IA" << std::endl;
	choix = saisieChiffre("Quel est votre choix ? ");

	switch(choix) {
	case 1:
	    return;
	case 2:
	    this->joueur1 = new HumainOthello(this->grilleDeJeu, GrilleOthello::CASE_NOIRE);
	    this->joueur2 = new HumainOthello(this->grilleDeJeu, GrilleOthello::CASE_BLANCHE);
	    saisieString(&nomJoueur, "Entrez le nom du joueur 1 : ");
	    this->joueur1->setNom(nomJoueur);
	    saisieString(&nomJoueur, "Entrez le nom du joueur 2 : ");
	    this->joueur2->setNom(nomJoueur);
	    break;
	case 3:
	    profondeur = saisieChiffre("Quelle profondeur pour l'IA ? ");
	    this->joueur1 = new HumainOthello(this->grilleDeJeu, GrilleOthello::CASE_NOIRE);
	    this->joueur2 = new IAOthello(this->grilleDeJeu, GrilleOthello::CASE_BLANCHE, profondeur);
	    saisieString(&nomJoueur, "Entrez votre nom : ");
	    this->joueur1->setNom(nomJoueur);
	    this->joueur2->setNom("Ordi");
	    break;
	case 4:
	    profondeur = saisieChiffre("Quelle profondeur pour l'IA ? ");
	    this->joueur1 = new IAOthello(this->grilleDeJeu, GrilleOthello::CASE_NOIRE, profondeur);
	    this->joueur2 = new HumainOthello(this->grilleDeJeu, GrilleOthello::CASE_BLANCHE);
	    saisieString(&nomJoueur, "Entrez votre nom : ");
	    this->joueur1->setNom("Ordi");
	    this->joueur2->setNom(nomJoueur);
	    break;
	case 5:
	    profondeur = saisieChiffre("Quelle profondeur pour l'IA 1 ? ");
	    this->joueur1 = new IAOthello(this->grilleDeJeu, GrilleOthello::CASE_NOIRE, profondeur);
	    profondeur = saisieChiffre("Quelle profondeur pour l'IA 2 ? ");
	    this->joueur2 = new IAOthello(this->grilleDeJeu, GrilleOthello::CASE_BLANCHE, profondeur);
	    this->joueur1->setNom("Ordi 1");
	    this->joueur2->setNom("Ordi 2");
	    break;
	default:
	    continue;
	}

	this->partie();
	delete this->joueur1;
	delete this->joueur2;
	this->joueur1 = NULL;
	this->joueur2 = NULL;
    }
}

void Othello::partie() {
    bool bouclePartie = true;
    std::string rejouer;

    while(bouclePartie) {
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
	    this->tourJoueur = Othello::JOUEUR1;
	    if(rejouer.compare("o") == 0) {
		bouclePartie = true;
		continue;
	    }
	    else {
		break;
	    }
	}
	
	if(this->tourJoueur == Othello::JOUEUR1) {
	    std::cout << "C'est à " << this->joueur1->getNom() << " de jouer (N)" << std::endl;
	    this->joueur1->jouer();
	    if(this->joueur1->getquit()) {
		return;
	    }
	}
	else {
	    std::cout << "C'est à " << this->joueur2->getNom() << " de jouer (B)" << std::endl;
	    this->joueur2->jouer();
	    if(this->joueur2->getquit()) {
		return;
	    }
	}

	this->calculScore();
	if(this->tourJoueur == Othello::JOUEUR1) {
	    this->tourJoueur = Othello::JOUEUR2;
	}
	else {
	    this->tourJoueur = Othello::JOUEUR1;
	}
	
    }
}

void Othello::afficherJeu() {
    int i,j;
    
    cout << "\n" << this->joueur1->getNom() << "(N) : " << this->scoreJoueur1;
    cout << " - " << this->scoreJoueur2 << " : (B)" << this->joueur2->getNom() << std::endl;
    cout << "\n" ;
    cout <<"============================\n";
    for (i=0; i<8; i++) {
	cout <<7-i+1;
        for (j=0; j<8; j++) {
	    
	    if(this->grilleDeJeu->lireCase(j,7-i)==1){cout << "||N";}
	    if(this->grilleDeJeu->lireCase(j,7-i)==2){cout << "||B";}
	    if(this->grilleDeJeu->lireCase(j,7-i)==0){cout << "|| ";}
	    
	    
        }
	cout << "\n" ;
	cout <<"============================\n";
    }
    
    cout <<"   A||B||C||D||E||F||G||H" ;
    
    cout << "\n" << endl;
}

void Othello::afficherMessageFin() {

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

void Othello::calculScore() {
    int i,j;
    int score1 = 0;
    int score2 = 0;

    for(i = 0; i < this->grilleDeJeu->getNbLignes(); i++) {
	for(j = 0; j < this->grilleDeJeu->getNbColonnes(); j++) {
	    if(this->grilleDeJeu->lireCase(i,j) == GrilleOthello::CASE_NOIRE)
		score1++;
	    if(this->grilleDeJeu->lireCase(i,j) == GrilleOthello::CASE_BLANCHE)
		score2++;
	}
    }

    this->scoreJoueur1 = score1;
    this->scoreJoueur2 = score2;
}
