#include "Dames.hpp"
#include "JoueurDames.hpp"
#include "fonctions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Dames::Dames() : Jeu(2) {
    //ctor
    this->joueur1 = NULL;
    this->joueur2 = NULL;
    this->scoreJoueur1 = 0;
    this->scoreJoueur2 = 0;
    this->scoreJoueur11 = 0;
    this->scoreJoueur22 = 0;
    this->initialiserJeu();
}

Dames::~Dames() {
    //dtor
    if (this->joueur1 != NULL) {
        delete this->joueur1;
    }
    if (this->joueur2 != NULL) {
        delete this->joueur2;
    }
    if (this->grilleDeJeu != NULL) {
        delete this->grilleDeJeu;
    }
}

void Dames::lancerJeu() {
    int choix = 0;


    while (true) {
        choix = 0;

        std::cout << "Menu principal Dames" << std::endl;
        std::cout << "1 - Quitter Dames" << std::endl;
        std::cout << "2 - Jouer contre l'ordinateur et jouer le premier" << std::endl;
        std::cout << "3 - Jouer contre l'ordinateur et jouer le deuxieme" << std::endl;
        std::cout << "4 - Jouer a 2" << std::endl;
        choix = saisieChiffre("Quel est votre choix ? ");

        if (choix == 1) {
            return;
        } else if (choix == 2) {
            this->joueur1 = new HumainDames(this->grilleDeJeu, 1, false);
            this->joueur2 = new IADames(this->grilleDeJeu, 2, false);
        } else if (choix == 3) {
            this->joueur1 = new IADames(this->grilleDeJeu, 1, false);
            this->joueur2 = new HumainDames(this->grilleDeJeu, 2, false);
        } else if (choix == 4) {
            this->joueur1 = new HumainDames(this->grilleDeJeu, 1, false);
            this->joueur2 = new HumainDames(this->grilleDeJeu, 2, false);
        } else {
            continue;
        }

        this->partie();
        delete this->joueur1;
        delete this->joueur2;
        this->joueur1 = NULL;
        this->joueur2 = NULL;
        this->grilleDeJeu->initialiserGrille(); //On re vide la grille pour une eventuelle prochaine partie
    }
}

void Dames::initialiserJeu(int variante) {


    this->grilleDeJeu = new GrilleDames(10, 10, variante);





}

void Dames::calculScore() {
    int compteur = 0, compteur1 = 0, compteur2 = 0, compteur3 = 0;
    int i;
    int j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (this->grilleDeJeu->lireCase(i, j) == (GrilleDames::N)) {
                compteur++;
            }
            if (this->grilleDeJeu->lireCase(i, j) == this->grilleDeJeu->reines((GrilleDames::N))) {
                compteur2++;
            }
            if (this->grilleDeJeu->lireCase(i, j) == (GrilleDames::B)) {
                compteur1++;
            }
            if (this->grilleDeJeu->lireCase(i, j) == this->grilleDeJeu->reines((GrilleDames::B))) {
                compteur3++;
            }
            this->scoreJoueur1 = compteur;
            this->scoreJoueur2 = compteur1;
            this->scoreJoueur11 = compteur2;
            ;
            this->scoreJoueur22 = compteur3;
            ;
            ;

        }
    }

}

void Dames::afficherScore() {

    cout << "Score N: " << this->scoreJoueur1 << " B: " << this->scoreJoueur2 << endl;
    cout << "Reines N: " << this->scoreJoueur11 << " Reines B: " << this->scoreJoueur22 << endl;


}

void Dames::partie() {
    this->afficherJeu();
    while ((!this->grilleDeJeu->finPartie())&&(!this->joueur2->getquit())&&(!this->joueur1->getquit())) {
        this->joueur1->jouer();
        this->grilleDeJeu->afficherJeu();
        this->calculScore();
        this->afficherScore();


        if ((!this->grilleDeJeu->finPartie())&&(!this->joueur2->getquit())&&(!this->joueur1->getquit())) {
            this->joueur2->jouer();
            this->grilleDeJeu->afficherJeu();
            this->calculScore();
            this->afficherScore();
        }


    }
    this->grilleDeJeu->afficherJeu();
    this->calculScore();
    this->afficherScore();
    if (this->grilleDeJeu->finPartie()) {
        if (this->grilleDeJeu->score(2)<this->grilleDeJeu->score(1))cout << "noir vainqueur " << endl;
        else cout << "blanc vainqueur " << endl;
    } else cout << "pas de vainqueur " << endl;
}

void Dames::afficherJeu() {
    int i, j;

    cout << "\n";
    cout << "  ===============================\n";
    for (i = 0; i < 10; i++) {
        cout << i;
        // cout <<7-i+1;
        for (j = 0; j < 10; j++) {

            if (this->grilleDeJeu->lireCase(i, j) == 1) {
                cout << "||N";
            }
            if (this->grilleDeJeu->lireCase(i, j) == 2) {
                cout << "||B";
            }
            if (this->grilleDeJeu->lireCase(i, j) == 3) {
                cout << "||O";
            }
            if (this->grilleDeJeu->lireCase(i, j) == 4) {
                cout << "||C";
            }
            if (this->grilleDeJeu->lireCase(i, j) == 0) {
                cout << "|| ";
            }




        }
        cout << "||";
        cout << "\n";
        cout << "  ===============================\n";
    }

    cout << "   0||1||2||3||4||5||6||7||8||9";

    cout << "\n" << endl;

}
