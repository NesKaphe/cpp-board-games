#include "FiveOrMore.hpp"
#include "JoueurFiveOrMore.hpp"
#include "fonctions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

FiveOrMore::FiveOrMore() : Jeu(1) {
    //ctor
    this->joueur = new JoueurFiveOrMore(0);
    this->grilleDeJeu = 0;
    this->score = 0;
}

FiveOrMore::~FiveOrMore() {
    //dtor
    if(this->joueur != 0) { //Si on avait deja crée le joueur
	delete this->joueur;
    }
    if(this->grilleDeJeu != 0) { //Si on avait deja crée une grille de jeu
	delete this->grilleDeJeu;
    }
}

void FiveOrMore::lancerJeu() {
    int choix;
    std::string nomJoueur;
    saisieString(&nomJoueur, "Entrez votre nom : ");
    while(true) {
	clear_screen();
	std::cout << "Menu principal Five or More" << std::endl;
	std::cout << "1 - Quitter Five or More" << std::endl;
	std::cout << "2 - Jeu original" << std::endl;
	std::cout << "3 - Variante" << std::endl;
	choix = saisieChiffre("Quel est votre choix "+nomJoueur+" ? ");

	switch(choix) {
	case 1:
	    return ;
	    break;
	case 2:
	    this->initialiserJeu(GrilleFiveMore::VARIANTE_ORIGINALE);
	    break;
	case 3:
	    this->initialiserJeu(GrilleFiveMore::VARIANTE_1);
	    break;
	default:
	    continue;
	}
	this->joueur->setGrilleDeJeu(this->grilleDeJeu);
	this->partie(); //On lance la partie
    }
}

void FiveOrMore::initialiserJeu(int variante) {
    int nbLignes, nbColonnes;

    //Definition des dimensions de la grille de Jeu
    clear_screen();
    std::cout << "Definition des dimension de la grille de jeu" << std::endl << std::endl;
    do {
	nbLignes = saisieChiffre("Combien de lignes ? ");
	nbColonnes = saisieChiffre("Combien de colonnes ? ");
	if(nbLignes < 5 && nbColonnes < 5) {
	    std::cout << "Dimensions incorrectes" << std::endl;
	}
    }
    while(nbLignes < 5 && nbColonnes < 5);

    this->grilleDeJeu = new GrilleFiveMore(nbLignes,nbColonnes,variante);
}

void FiveOrMore::partie() {
    int ligne;
    int colonne;
    int couleur;
    bool genererJetons = true;
    int nbJetonsEfface = 0;
    std::string rejouer;

    while(!this->grilleDeJeu->finPartie()) {
        if(genererJetons) {
            for(int i = 0; i < 3; i++) { //On va générer 3 jetons aleatoire sur la grille
                do {
                    ligne = rand() % this->grilleDeJeu->getNbLignes(); //On choisis une ligne entre 0 et nbLignes
                    colonne = rand() % this->grilleDeJeu->getNbColonnes(); //On choisis une colonne entre 0 et nbLignes
                    couleur = (rand() % GrilleFiveMore::NB_COULEURS) + GrilleFiveMore::COULEUR_ROUGE; //On choisis une couleur entre la premiere couleur et nb_couleurs
                }
                while(!this->grilleDeJeu->caseVide(ligne,colonne) && !this->grilleDeJeu->finPartie()); // On recommence tant que la case trouvée n'est pas vide
                this->grilleDeJeu->setJeton(ligne,colonne,couleur); //Finalement, on place le jeton dans la grille
            }
        }

        genererJetons = true; //Si genererJetons etait a false, on le remet a true pour le tour suivant
        nbJetonsEfface = this->grilleDeJeu->viderAlignements(); //On va compter le nombre de jetons effacés de la grille de jeu
        if(nbJetonsEfface > 0) {
            this->calculScore(nbJetonsEfface); //On met a jour le score en fonction des jetons supprimés de la grille
            genererJetons = false; //Si on a effacé des jetons de la grille, on a le droit de rejouer sans ajout supplementaire de jetons par l'ordi
        }

        clear_screen();
        this->afficherScore();
        this->afficherJeu();
        if(this->grilleDeJeu->finPartie()) { //Si la partie est finie
            this->afficherMessageFin(); //On affiche un message de fin
	    //ici on propose de rejouer avec les meme regles et si oui on vide la grille + remet le score a 0 et on est reparti dans la boucle, sinon on termine

	    do {
		saisieString(&rejouer, "Voulez vous rejouer avec les mêmes regles ? <o/n> ");
	    }
	    while(rejouer.compare("o") != 0 && rejouer.compare("n"));
	    this->grilleDeJeu->initialiserGrille();
	    this->score = 0;

	    if(rejouer.compare("o") == 0) {
		continue;
	    }
	    else {
		break;
	    }
        }
        else {
            this->joueur->jouer(); //Sinon, on laisse le joueur jouer

        }
    }
}

void FiveOrMore::afficherScore() {
    std::cout << "Votre score : " << this->score << std::endl << std::endl;
}

void FiveOrMore::afficherJeu() {
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
                case GrilleFiveMore::CASE_VIDE:
                    std::cout << " _ ";
                    break;
                case GrilleFiveMore::COULEUR_BLEU:
                    std::cout << " B ";
                    break;
                case GrilleFiveMore::COULEUR_JAUNE:
                    std::cout << " J ";
                    break;
                case GrilleFiveMore::COULEUR_ORANGE:
                    std::cout << " O ";
                    break;
                case GrilleFiveMore::COULEUR_ROUGE:
                    std::cout << " R ";
                    break;
                case GrilleFiveMore::COULEUR_VERT:
                    std::cout << " V ";
                    break;
                default:
                    std::cout << " _ ";
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

void FiveOrMore::calculScore(int nbJetonSupprime) {
    this->score += (nbJetonSupprime * nbJetonSupprime);
}

void FiveOrMore::afficherMessageFin() {
    std::cout << "Partie termine ! Vous avez obtenu le score de " << this->score << " " << this->joueur->getNom() << std::endl;
    pause();
}
