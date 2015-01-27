#include "HumainDames.hpp"

#include "GrilleDames.hpp"

#include "fonctions.hpp"

#include <iostream>

using namespace std;

HumainDames::HumainDames(GrilleDames * grilleDeJeu, int c, bool q) : JoueurDames(grilleDeJeu, c, q) {
}

HumainDames::~HumainDames() {

    //dtor

}

void HumainDames::jouer() {

    int inverse = (this->nom == GrilleDames::N) ? 2 : 1;
    int x1;
    int avant;
    int apres;
    int y1;
    int x2;
    int y2;
    bool res = true;
    bool resultat = false;
    bool cont = false;

    while (res && (this->quit == false)) {
        cout << "le joueur ";
        if (this->nom == GrilleDames::N) {
            cout << "noir";
        } else cout << "blanc";
        cout << " doit jouer ";
        if ((resultat == false) || (cont == true)) {

            if (cont) {//pour passer son tour x2=100 et pour arreter y2=1000
                      //on rentre si on a mange un pion et que l'on peu encore en manger avec le meme pion
                //car on doit manger le plus de pion possible
                cout << " obliger de manger le plus de pions possibles " << endl;
                x1 = x2;

                y1 = y2;

                x2 = 10;
                y2 = 10;
                do {
                    x2 = saisieChiffre("Ligne d'arrivÃ© du jeton : ");

                    y2 = saisieChiffre("Colonne d'arrivÃ© du jeton : ");
                } while ((x2 < 0) || (x2 > 9) || (y2 < 0) || (y2 > 9));
                if ((x2 == 100) || (y2 == 1000))break;
            }

            if (!resultat) {
                do {//pour passer son tour x2=100 et pour arreter y2=1000

                    cout << "au moins un coup " << endl;


                    x1 = saisieChiffre("Ligne du jeton Ã  deplacer : ");
                    y1 = saisieChiffre("Colonne du jeton Ã  deplacer : ");

                    x2 = saisieChiffre("Ligne d'arrivÃ© du jeton : ");

                    y2 = saisieChiffre("Colonne d'arrivÃ© du jeton : ");


                    if ((x2 == 100) || (y2 == 1000))break;
                } while (((x1 < 0) || (x1 > 9) || (y1 < 0) || (y1 > 9) || (x2 < 0) || (x2 > 9) || (y2 < 0) || (y2 > 9)));

            }



            if (!((x2 == 100) || (y2 == 1000))) {
                avant = this->grilleDeJeu->score(inverse);
                if (this->grilleDeJeu->lireCase(x1, y1) == this->nom) {
                    resultat = this->grilleDeJeu->mange(this->nom, x1, y1, x2, y2);
                    if (!resultat) {
                        resultat = this->grilleDeJeu->deplace(this->nom, x1, y1, x2, y2);
                    }
                }


                if (this->grilleDeJeu->lireCase(x1, y1) == this->grilleDeJeu->reines(this->nom)) {

                    resultat = this->grilleDeJeu->mangereine(this->nom, x1, y1, x2, y2);

                    if (!resultat) {
                        resultat = this->grilleDeJeu->deplacereine(this->nom, x1, y1, x2, y2);
                    }

                }

                apres = this->grilleDeJeu->score(inverse);

                if (apres - avant != 0) {

                    if (this->grilleDeJeu->lireCase(x2, y2) == this->grilleDeJeu->reines(this->nom)) {

                        if (this->grilleDeJeu->cherchereine(this->nom, x2, y2)) {
                            cont = true;
                        } else {
                            cont = false;
                            res = false;
                        }
                    }

                }

                if (this->grilleDeJeu->lireCase(x2, y2) == this->nom) {

                    if (this->grilleDeJeu->cherche(this->nom, x2, y2)) {
                        cont = true;
                    } else {
                        cont = false;
                        res = false;
                    }

                }

                if ((apres - avant == 0)&&(resultat == true)) {
                    cont = false;
                    res = false;
                }



            } else {
                if (x2 == 100) {
                    this->quit = false;
                    res = false;
                } else {
                    this->quit = true;
                    res = false;
                }
            }
        }

    }
}
