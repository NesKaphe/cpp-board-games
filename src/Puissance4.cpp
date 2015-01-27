#include "Puissance4.hpp"
#include <string>

Puissance4::Puissance4() : Jeu(2) {
    this->joueur1 = NULL;
    this->joueur2 = NULL; //On ne connait pas encore le type de joueur
    this->grilleDeJeu = NULL;
    this->scoreJoueur1 = 0;
    this->scoreJoueur2 = 0;
    this->tourJoueur = Puissance4::JOUEUR1;
}

Puissance4::~Puissance4() {
    if(this->joueur1 != 0) {
	delete this->joueur1;
    }
    if(this->joueur2 != 0) {
	delete this->joueur2;
    }
    if(this->grilleDeJeu != 0) {
	delete this->grilleDeJeu;
    }
}

void Puissance4::lancerJeu() {
    int choix;
    std::string nomJoueur;
    bool boucle = true;

    while(true) {
	clear_screen();
	std::cout << "Menu principal Puissance4" << std::endl;
	std::cout << "1 - Quitter Puissance4" << std::endl;
	std::cout << "2 - Jeu original" << std::endl;
	std::cout << "3 - Variante" << std::endl;
	choix = saisieChiffre("Quel est votre choix ? ");

	switch(choix) {

	case 1:
	    return;
	    break;
	case 2:
	    this->initialiserJeu(GrillePuissance4::VARIANTE_ORIGINALE);
	    break;
	case 3:
	    this->initialiserJeu(GrillePuissance4::VARIANTE_1);
	    break;

	}

	boucle = true;
	while(boucle) {
	    clear_screen();
	    std::cout << "Mode de jeu" << std::endl;
	    std::cout << "1 - Jouer contre un Humain" << std::endl;
	    std::cout << "2 - Jouer contre une IA facile" << std::endl;
	    std::cout << "3 - Jouer contre une IA moyen" << std::endl;
	    std::cout << "4 - Jouer contre une IA difficile" << std::endl;
	    std::cout << "5 - Duel d'IA" << std::endl;
	    choix = saisieChiffre("Quel est votre choix ? ");
	    
	    switch(choix) {

	    case 1:
		saisieString(&nomJoueur, "Entrez le nom du joueur 1 : ");
		this->joueur1 = new HumainPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_ROUGE);
		this->joueur1->setNom(nomJoueur);
		saisieString(&nomJoueur, "Entrez le nom du joueur 2 : ");
		this->joueur2 = new HumainPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_JAUNE);
		this->joueur2->setNom(nomJoueur);
		boucle = false;
		break;
	    case 2:
		saisieString(&nomJoueur, "Entrez le nom du joueur 1 : ");
		this->joueur1 = new HumainPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_ROUGE);
		this->joueur1->setNom(nomJoueur);
		this->joueur2 = new IAPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_JAUNE, IAPuissance4::PROFONDEUR_FACILE, GrillePuissance4::COULEUR_ROUGE);
		this->joueur2->setNom("Ordi");
		boucle = false;
		break;
	    case 3:
		saisieString(&nomJoueur, "Entrez le nom du joueur 1 : ");
		this->joueur1 = new HumainPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_ROUGE);
		this->joueur1->setNom(nomJoueur);
		this->joueur2 = new IAPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_JAUNE, IAPuissance4::PROFONDEUR_MOYEN, GrillePuissance4::COULEUR_ROUGE);
		this->joueur2->setNom("Ordi");
		boucle = false;
		break;
	    case 4:
		saisieString(&nomJoueur, "Entrez le nom du joueur 1 : ");
		this->joueur1 = new HumainPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_ROUGE);
		this->joueur1->setNom(nomJoueur);
		this->joueur2 = new IAPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_JAUNE, IAPuissance4::PROFONDEUR_DIFFICILE, GrillePuissance4::COULEUR_ROUGE);
		this->joueur2->setNom("Ordi");
		boucle = false;
		break;
	    case 5:
		this->joueur1 = new IAPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_ROUGE, IAPuissance4::PROFONDEUR_DIFFICILE, GrillePuissance4::COULEUR_JAUNE);
		this->joueur1->setNom("Ordi 1");
		this->joueur2 = new IAPuissance4(this->grilleDeJeu, GrillePuissance4::COULEUR_JAUNE, IAPuissance4::PROFONDEUR_DIFFICILE, GrillePuissance4::COULEUR_ROUGE);
		this->joueur2->setNom("Ordi 2");
		boucle = false;
		break;
	    default:
		boucle = true;
		break;
	    }
	}

	this->partie();
	delete this->joueur1;
	delete this->joueur2;
	this->joueur1 = 0;
	this->joueur2 = 0;
    }
}

void Puissance4::initialiserJeu(int variante) {
    int choix;
    if(variante == GrillePuissance4::VARIANTE_1) {
	choix = saisieChiffre("Combien de tours voulez vous? (0: aucune limite)");
    }
    this->grilleDeJeu = new GrillePuissance4(variante, choix);
}

void Puissance4::partie() {

    bool bouclePartie = true;
    std::string rejouer;
    std::vector<intPair> vect;
    while(bouclePartie) {
	clear_screen();
	if(this->grilleDeJeu->getNumVariante() == GrillePuissance4::VARIANTE_1) {
	    this->afficherScores();
	}

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
	    this->tourJoueur = Puissance4::JOUEUR1;

	    if(rejouer.compare("o") == 0) {
		bouclePartie = true;
		continue;
	    }
	    else {
		break;
	    }
	}
	
	if(this->tourJoueur == Puissance4::JOUEUR1) {
	    std::cout << "C'est à " << this->joueur1->getNom() << " de jouer (Rouge)" << std::endl;
	    this->joueur1->jouer();
	}
	else {
	    std::cout << "C'est à " << this->joueur2->getNom() << " de jouer (Jaune)" << std::endl;
	    this->joueur2->jouer();
	}

	switch(this->grilleDeJeu->getNumVariante()) {
	case GrillePuissance4::VARIANTE_ORIGINALE:
	    if(alignementN(this->grilleDeJeu, 4, &vect))
		this->calculScore(vect, 1);
	    break;
	case GrillePuissance4::VARIANTE_1:
	    while(alignementN(this->grilleDeJeu, 4, &vect)) {
		this->calculScore(vect, 1);
		this->grilleDeJeu->viderAlignement();
	    }
	    break;
	}


	if(this->tourJoueur == Puissance4::JOUEUR1) {
	    this->tourJoueur = Puissance4::JOUEUR2;
	}
	else {
	    this->tourJoueur = Puissance4::JOUEUR1;
	}
	vect.clear();
    }
}

void Puissance4::afficherJeu() {
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
        std::cout << "  ";
        for(j = 0; j < this->grilleDeJeu->getNbColonnes(); j++) {
            std::cout << "|";

            switch(this->grilleDeJeu->lireCase(i,j)) {
                case GrillePuissance4::CASE_VIDE:
                    std::cout << " _ ";
                    break;
                case GrillePuissance4::COULEUR_JAUNE:
                    std::cout << " J ";
                    break;
                case GrillePuissance4::COULEUR_ROUGE:
                    std::cout << " R ";
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

void Puissance4::calculScore(std::vector<intPair> vect, int point) { //Bug de calcul des scores a voir plus tard
    
    int nbJoueursAlign = 1;
    std::vector<intPair>::iterator it = vect.begin();
    int uneCase = this->grilleDeJeu->lireCase(it->first,it->second);
    int compteur1 = 0;
    int compteur2 = 0;
    int total1,total2;

    while(it != vect.end()) {
	if(this->grilleDeJeu->lireCase(it->first,it->second) != uneCase) {
	    compteur2++;
	    nbJoueursAlign = 2;
	}
	else {
            compteur1++;
        }
	it++;
    }
std::cout << "c1 : " << compteur1 << "; c2 : " << compteur2 << std::endl;
    if(compteur1 % 4 != 0) {
	    total1 = compteur1 / 4 + 1;
    }
    else {
        total1 = compteur1 / 4;
    }

    if(compteur2 % 4 != 0) {
	total2 = compteur2 / 4 + 1;
    }
    else {
	total2 = compteur2 / 4;
    }	

    if(nbJoueursAlign == 1) {
	if(this->joueur1->getCouleur() == uneCase) {
	    this->scoreJoueur1 += total1 * point;
	}
	else {
	    this->scoreJoueur2 += total1 * point;
	}
    }
    else {
	if(this->tourJoueur == Puissance4::JOUEUR1) {
	    this->scoreJoueur1 += total1 * point;
	    this->scoreJoueur2 += total2 * point;
        }
	else {
	    this->scoreJoueur1 += total2 * point;
	    this->scoreJoueur2 += total1 * point;
	}
    }

}

void Puissance4::afficherMessageFin() {
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

    if(this->grilleDeJeu->getNumVariante() == GrillePuissance4::VARIANTE_1) {
	std::cout << this->joueur1->getNom() << " a obtenu " << this->scoreJoueur1 << " points et ";
	std::cout << this->joueur2->getNom() << " a obtenu " << this->scoreJoueur2 << " points." << std::endl;
    }

    pause();
}

void Puissance4::afficherScores() {
    std::cout << this->joueur1->getNom() << " : " << this->scoreJoueur1 << "                  " << this->joueur2->getNom() << " : " << this->scoreJoueur2 << std::endl;
}
