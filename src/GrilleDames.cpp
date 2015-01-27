#include "GrilleDames.hpp"
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

GrilleDames::GrilleDames(int dimLigne, int dimColonne, int variante) : Grille(dimLigne, dimColonne), numVariante(variante) {
    //ctor
    this->initialiserGrille();
}

void GrilleDames::initialiserGrille() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            this->setJeton(i, j, GrilleDames::CASE_VIDE);
        }
    }
    this->setJeton(0, 1, GrilleDames::N);
    this->setJeton(0, 3, GrilleDames::N);
    this->setJeton(0, 5, GrilleDames::N);
    this->setJeton(0, 7, GrilleDames::N);
    this->setJeton(0, 9, GrilleDames::N);
    this->setJeton(1, 0, GrilleDames::N);
    this->setJeton(1, 2, GrilleDames::N);
    this->setJeton(1, 4, GrilleDames::N);
    this->setJeton(1, 6, GrilleDames::N);
    this->setJeton(1, 8, GrilleDames::N);
    this->setJeton(2, 1, GrilleDames::N);
    this->setJeton(2, 3, GrilleDames::N);
    this->setJeton(2, 5, GrilleDames::N);
    this->setJeton(2, 7, GrilleDames::N);
    this->setJeton(2, 9, GrilleDames::N);
    this->setJeton(3, 0, GrilleDames::N);
    this->setJeton(3, 2, GrilleDames::N);
    this->setJeton(3, 4, GrilleDames::N);
    this->setJeton(3, 6, GrilleDames::N);
    this->setJeton(3, 8, GrilleDames::N);
    this->setJeton(6, 1, GrilleDames::B);
    this->setJeton(6, 3, GrilleDames::B);
    this->setJeton(6, 5, GrilleDames::B);
    this->setJeton(6, 7, GrilleDames::B);
    this->setJeton(6, 9, GrilleDames::B);
    this->setJeton(7, 0, GrilleDames::B);
    this->setJeton(7, 2, GrilleDames::B);
    this->setJeton(7, 4, GrilleDames::B);
    this->setJeton(7, 6, GrilleDames::B);
    this->setJeton(7, 8, GrilleDames::B);
    this->setJeton(8, 1, GrilleDames::B);
    this->setJeton(8, 3, GrilleDames::B);
    this->setJeton(8, 5, GrilleDames::B);
    this->setJeton(8, 7, GrilleDames::B);
    this->setJeton(8, 9, GrilleDames::B);
    this->setJeton(9, 0, GrilleDames::B);
    this->setJeton(9, 2, GrilleDames::B);
    this->setJeton(9, 4, GrilleDames::B);
    this->setJeton(9, 6, GrilleDames::B);
    this->setJeton(9, 8, GrilleDames::B);

}

bool GrilleDames::finPartie() {

    int compteur = this->score(GrilleDames::N);
    int compteur1 = this->score(GrilleDames::B);

    if (compteur == 0)return true;
    else if (compteur1 == 0)return true;
    else return false;

}

GrilleDames::~GrilleDames() {
    //dtor
}

int GrilleDames::score(int a) {
    int compteur = 0;
    int i;
    int j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (this->lireCase(i, j) == a) {
                compteur++;
            }
            if (this->lireCase(i, j) == reines(a)) {
                compteur++;
            }

        }
    }
    return compteur;
}

int GrilleDames::reines(int j) {
    if (j == GrilleDames::N)return GrilleDames::RN;
    else return GrilleDames::RB;
}

void GrilleDames::afficherJeu() {
    int i, j;

    cout << "\n";
    cout << "  ===============================\n";
    for (i = 0; i < 10; i++) {
        cout << i;
        // cout <<7-i+1;
        for (j = 0; j < 10; j++) {

            if (this->lireCase(i, j) == 1) {
                cout << "||N";
            }
            if (this->lireCase(i, j) == 2) {
                cout << "||B";
            }
            if (this->lireCase(i, j) == 3) {
                cout << "||O";
            }
            if (this->lireCase(i, j) == 4) {
                cout << "||C";
            }
            if (this->lireCase(i, j) == 0) {
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

bool GrilleDames::joueia(int j) {

    int i;
    int k;
    int l;
    int m;
    for (i = 0; i < 10; i++) {
        for (k = 0; k < 10; k++) {
            for (l = 0; l < 10; l++) {
                for (m = 0; m < 10; m++) {
                    if (this->lireCase(i, k) == reines(j)) {
                        if (mangereine(j, i, k, l, m))return true;
                    }

                }
            }
        }
    }
    for (i = 0; i < 10; i++) {
        for (k = 0; k < 10; k++) {
            for (l = 0; l < 10; l++) {
                for (m = 0; m < 10; m++) {
                    if (this->lireCase(i, k) == j) {
                        if (mange(j, i, k, l, m))return true;
                    }
                }
            }
        }
    }



    for (i = 0; i < 10; i++) {
        for (k = 0; k < 10; k++) {
            for (l = 0; l < 10; l++) {
                for (m = 0; m < 10; m++) {
                    if (this->lireCase(i, k) == reines(j)) {
                        if (deplacereine(j, i, k, l, m))return true;
                    }

                }
            }
        }
    }

    for (i = 0; i < 10; i++) {
        for (k = 0; k < 10; k++) {
            for (l = 0; l < 10; l++) {
                for (m = 0; m < 10; m++) {

                    if (this->lireCase(i, k) == j) {
                        if (deplace(j, i, k, l, m))return true;
                    }
                }
            }
        }
    }


    return false;
}

bool GrilleDames::cherche(int j, int x, int y) {

    int i;
    int k;
    for (i = 0; i < 10; i++) {
        for (k = 0; k < 10; k++) {
            if (this->lireCase(x, y) == j) {
                if (canmange(j, x, y, i, k))return true;
            }
        }
    }

    return false;
}

bool GrilleDames::cherchereine(int j, int x, int y) {

    int i;
    int k;
    for (i = 0; i < 10; i++) {
        for (k = 0; k < 10; k++) {
            if (this->lireCase(x, y) == reines(j)) {
                if (canmangereine(j, x, y, i, k))return true;
            }
        }
    }
    return false;


}

bool GrilleDames::canmange(int j, int x, int y, int x2, int y2) {
    int j2;
    if (j == GrilleDames::N) {
        j2 = GrilleDames::B;
    } else {
        j2 = GrilleDames::N;
    }


    if (y >= 0 && y < 10 && x >= 0 && x < 10 && y2 >= 0 && y2 < 10 && x2 >= 0 && x2 < 10) {


        if (8 > x && 8 > y) {
            if ((this->lireCase(x + 1, y + 1) == j2) || (this->lireCase(x + 1, y + 1) == reines(j2))) {
                if (this->lireCase(x + 2, y + 2) == Grille::CASE_VIDE) {
                    if (x + 2 == x2 && y + 2 == y2) {
                        return true;
                    }
                }
            }
        }

        if (x > 1 && y > 1) {
            if ((this->lireCase(x - 1, y - 1) == j2) || (this->lireCase(x - 1, y - 1) == reines(j2))) {
                if (this->lireCase(x - 2, y - 2) == GrilleDames::CASE_VIDE) {
                    if (x - 2 == x2 && y - 2 == y2) {


                        return true;
                    }
                }
            }
        }

        if (8 > x && y > 1) {
            if ((this->lireCase(x + 1, y - 1) == j2) || (this->lireCase(x + 1, y - 1) == reines(j2))) {
                if (this->lireCase(x + 2, y - 2) == GrilleDames::CASE_VIDE) {
                    if (x + 2 == x2 && y - 2 == y2) {



                        return true;
                    }
                }

            }
        }
        if (x > 1 && 8 > y) {
            if ((this->lireCase(x - 1, y + 1) == j2) || (this->lireCase(x - 1, y + 1) == reines(j2))) {
                if (this->lireCase(x - 2, y + 2) == GrilleDames::CASE_VIDE) {
                    if (x - 2 == x2 && y + 2 == y2) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool GrilleDames::canmangereine(int j, int x, int y, int x2, int y2) {
    int j2;
    int iter;
    if (j == GrilleDames::N) {
        j2 = GrilleDames::B;
    } else {
        j2 = GrilleDames::N;
    }

    if (y >= 0 && y < 10 && x >= 0 && x < 10 && y2 >= 0 && y2 < 10 && x2 >= 0 && x2 < 10) {


        if (8 > x && 8 > y) {
            iter = 1;
            int nb = 0;
            while (x + iter != x2 && y + iter != y2 && x + iter >= 0 && x + iter < 10 && y + iter >= 0 && y + iter < 10) {
                if ((this->lireCase(x + iter, y + iter) == j2) || (this->lireCase(x + iter, y + iter) == reines(j2))) {
                    nb++;
                }
                if (this->lireCase(x + iter, y + iter) == j) {
                    return false;
                }
                if (this->lireCase(x + iter, y + iter) == reines(j)) {
                    return false;
                }
                iter++;
            }
            if (x + iter == x2 && y + iter == y2) {
                if (nb == 1) {
                    return true;
                }
            }
        }


        if (x > 1 && y > 1) {
            iter = 1;
            int nb = 0;
            while (x - iter != x2 && y - iter != y2 && x - iter >= 0 && x - iter < 10 && y - iter >= 0 && y - iter < 10) {
                if ((this->lireCase(x - iter, y - iter) == j2) || (this->lireCase(x - iter, y - iter) == reines(j2))) {
                    nb++;
                }
                if (this->lireCase(x - iter, y - iter) == j) {
                    return false;
                }
                if (this->lireCase(x - iter, y - iter) == reines(j)) {
                    return false;
                }
                iter++;
            }
            if (x - iter == x2 && y - iter == y2) {
                if (nb == 1) {
                    return true;
                }
            }
        }


        if (8 > x && y > 1) {
            iter = 1;
            int nb = 0;
            while (x + iter != x2 && y - iter != y2 && x + iter >= 0 && x + iter < 10 && y - iter >= 0 && y - iter < 10) {
                if ((this->lireCase(x + iter, y - iter) == j2) || (this->lireCase(x + iter, y - iter) == reines(j2))) {
                    nb++;
                }
                if (this->lireCase(x + iter, y - iter) == j) {
                    return false;
                }
                if (this->lireCase(x + iter, y - iter) == reines(j)) {
                    return false;
                }
                iter++;
            }
            if (x + iter == x2 && y - iter == y2) {
                if (nb == 1) {
                    return true;
                }
            }
        }

        if (x > 1 && 8 > y) {
            iter = 1;
            int nb = 0;
            while (x - iter != x2 && y + iter != y2 && x - iter >= 0 && x - iter < 10 && y + iter >= 0 && y + iter < 10) {
                if ((this->lireCase(x - iter, y + iter) == j2) || (this->lireCase(x - iter, y + iter) == reines(j2))) {
                    nb++;
                }
                if (this->lireCase(x - iter, y + iter) == j) {
                    return false;
                }
                if (this->lireCase(x - iter, y + iter) == reines(j)) {
                    return false;
                }
                iter++;
            }
            if (x - iter == x2 && y + iter == y2) {
                if (nb == 1) {
                    return true;
                }
            }
        }

    }

    return false;
}

bool GrilleDames::mange(int j, int x, int y, int x2, int y2) {
    int j2;
    if (j == GrilleDames::N) {
        j2 = GrilleDames::B;
    } else {
        j2 = GrilleDames::N;
    }

    if (y >= 0 && y < 10 && x >= 0 && x < 10 && y2 >= 0 && y2 < 10 && x2 >= 0 && x2 < 10) {


        if (8 > x && 8 > y) {
            if ((this->lireCase(x + 1, y + 1) == j2) || (this->lireCase(x + 1, y + 1) == reines(j2))) {
                if (this->lireCase(x + 2, y + 2) == Grille::CASE_VIDE) {
                    if (x + 2 == x2 && y + 2 == y2) {
                        this->setJeton(x, y, GrilleDames::CASE_VIDE);
                        this->setJeton(x + 1, y + 1, Grille::CASE_VIDE);

                        if ((x2 == 0) || (x2 == 9)) this->setJeton(x + 2, y + 2, reines(j));
                        else this->setJeton(x + 2, y + 2, j);
                        return true;
                    }
                }
            }
        }

        if (x > 1 && y > 1) {
            if ((this->lireCase(x - 1, y - 1) == j2) || (this->lireCase(x - 1, y - 1) == reines(j2))) {
                if (this->lireCase(x - 2, y - 2) == GrilleDames::CASE_VIDE) {
                    if (x - 2 == x2 && y - 2 == y2) {
                        this->setJeton(x, y, GrilleDames::CASE_VIDE);
                        this->setJeton(x - 1, y - 1, GrilleDames::CASE_VIDE);
                        if ((x2 == 0) || (x2 == 9)) this->setJeton(x - 2, y - 2, reines(j));
                        else this->setJeton(x - 2, y - 2, j);
                        return true;
                    }
                }
            }
        }

        if (8 > x && y > 1) {
            if ((this->lireCase(x + 1, y - 1) == j2) || (this->lireCase(x + 1, y - 1) == reines(j2))) {
                if (this->lireCase(x + 2, y - 2) == GrilleDames::CASE_VIDE) {
                    if (x + 2 == x2 && y - 2 == y2) {
                        this->setJeton(x, y, GrilleDames::CASE_VIDE);
                        this->setJeton(x + 1, y - 1, GrilleDames::CASE_VIDE);
                        if ((x2 == 0) || (x2 == 9)) this->setJeton(x + 2, y - 2, reines(j));
                        else this->setJeton(x + 2, y - 2, j);
                        return true;
                    }
                }

            }
        }
        if (x > 1 && 8 > y) {
            if ((this->lireCase(x - 1, y + 1) == j2) || (this->lireCase(x - 1, y + 1) == reines(j2))) {
                if (this->lireCase(x - 2, y + 2) == GrilleDames::CASE_VIDE) {
                    if (x - 2 == x2 && y + 2 == y2) {
                        this->setJeton(x, y, GrilleDames::CASE_VIDE);
                        this->setJeton(x - 1, y + 1, GrilleDames::CASE_VIDE);

                        if ((x2 == 0) || (x2 == 9)) this->setJeton(x - 2, y + 2, reines(j));
                        else {
                            this->setJeton(x - 2, y + 2, j);
                        };

                        return true;

                    }
                }

            }

        }
    }
    return false;
}

bool GrilleDames::deplace(int j, int x, int y, int x2, int y2) {



    if (y >= 0 && y < 10 && x >= 0 && x < 10 && y2 >= 0 && y2 < 10 && x2 >= 0 && x2 < 10) {


        if (j == 1) {
            if (9 > x && 9 > y) {
                if (this->lireCase(x + 1, y + 1) == GrilleDames::CASE_VIDE) {
                    if (x + 1 == x2 && y + 1 == y2) {

                        this->setJeton(x, y, GrilleDames::CASE_VIDE);
                        if ((x2 == 0) || (x2 == 9)) this->setJeton(x + 1, y + 1, reines(j));
                        else this->setJeton(x + 1, y + 1, j);
                        return true;
                    }
                }
            }
        }
        if (j == 2) {
            if (x > 0 && y > 0) {
                if (this->lireCase(x - 1, y - 1) == GrilleDames::CASE_VIDE) {
                    if (x - 1 == x2 && y - 1 == y2) {
                        this->setJeton(x, y, GrilleDames::CASE_VIDE);

                        if ((x2 == 0) || (x2 == 9)) this->setJeton(x - 1, y - 1, reines(j));
                        else this->setJeton(x - 1, y - 1, j);
                        return true;
                    }
                }
            }
        }

        if (j == 1) {
            if (9 > x && y > 0) {

                if (this->lireCase(x + 1, y - 1) == GrilleDames::CASE_VIDE) {
                    if (x + 1 == x2 && y - 1 == y2) {

                        this->setJeton(x, y, GrilleDames::CASE_VIDE);
                        if ((x2 == 0) || (x2 == 9)) this->setJeton(x + 1, y - 1, reines(j));
                        else this->setJeton(x + 1, y - 1, j);
                        return true;

                    }

                }
            }
        }
        if (j == 2) {
            if (x > 0 && 9 > y) {
                if (this->lireCase(x - 1, y + 1) == GrilleDames::CASE_VIDE) {
                    if (x - 1 == x2 && y + 1 == y2) {

                        this->setJeton(x, y, GrilleDames::CASE_VIDE);
                        if ((x2 == 0) || (x2 == 9)) this->setJeton(x - 1, y + 1, reines(j));
                        else this->setJeton(x - 1, y + 1, j);
                        return true;

                    }
                }
            }
        }

    }
    return false;
}

bool GrilleDames::mangereine(int j, int x, int y, int x2, int y2) {
    int j2;
    int iter;
    if (j == GrilleDames::N) {
        j2 = GrilleDames::B;
    } else {
        j2 = GrilleDames::N;
    }

    if (y >= 0 && y < 10 && x >= 0 && x < 10 && y2 >= 0 && y2 < 10 && x2 >= 0 && x2 < 10) {


        if (8 > x && 8 > y) {
            iter = 1;
            int nb = 0;
            int mx;
            int my;
            while (x + iter != x2 && y + iter != y2 && x + iter >= 0 && x + iter < 10 && y + iter >= 0 && y + iter < 10) {
                if ((this->lireCase(x + iter, y + iter) == j2) || (this->lireCase(x + iter, y + iter) == reines(j2))) {
                    nb++;
                    mx = x + iter;
                    my = y + iter;
                }
                if (this->lireCase(x + iter, y + iter) == j) {
                    return false;
                }
                if (this->lireCase(x + iter, y + iter) == reines(j)) {
                    return false;
                }
                iter++;
            }
            if (x + iter == x2 && y + iter == y2) {
                if (nb == 1) {
                    this->setJeton(x, y, GrilleDames::CASE_VIDE);
                    this->setJeton(mx, my, GrilleDames::CASE_VIDE);
                    this->setJeton(x2, y2, reines(j));
                    ;
                }
            }
        }


        if (x > 1 && y > 1) {
            iter = 1;
            int nb = 0;
            int mx;
            int my;
            while (x - iter != x2 && y - iter != y2 && x - iter >= 0 && x - iter < 10 && y - iter >= 0 && y - iter < 10) {
                if ((this->lireCase(x - iter, y - iter) == j2) || (this->lireCase(x - iter, y - iter) == reines(j2))) {
                    nb++;
                    mx = x - iter;
                    my = y - iter;
                }
                if (this->lireCase(x - iter, y - iter) == j) {
                    return false;
                }
                if (this->lireCase(x - iter, y - iter) == reines(j)) {
                    return false;
                }
                iter++;
            }
            if (x - iter == x2 && y - iter == y2) {
                if (nb == 1) {
                    this->setJeton(x, y, GrilleDames::CASE_VIDE);
                    this->setJeton(mx, my, GrilleDames::CASE_VIDE);
                    this->setJeton(x2, y2, reines(j));
                    ;
                }
            }
        }


        if (8 > x && y > 1) {
            iter = 1;
            int nb = 0;
            int mx;
            int my;
            while (x + iter != x2 && y - iter != y2 && x + iter >= 0 && x + iter < 10 && y - iter >= 0 && y - iter < 10) {
                if ((this->lireCase(x + iter, y - iter) == j2) || (this->lireCase(x + iter, y - iter) == reines(j2))) {
                    nb++;
                    mx = x + iter;
                    my = y - iter;
                }
                if (this->lireCase(x + iter, y - iter) == j) {
                    return false;
                }
                if (this->lireCase(x + iter, y - iter) == reines(j)) {
                    return false;
                }
                iter++;
            }
            if (x + iter == x2 && y - iter == y2) {
                if (nb == 1) {
                    this->setJeton(x, y, GrilleDames::CASE_VIDE);
                    this->setJeton(mx, my, GrilleDames::CASE_VIDE);
                    this->setJeton(x2, y2, reines(j));
                    ;
                }
            }
        }

        if (x > 1 && 8 > y) {
            iter = 1;
            int nb = 0;
            int mx;
            int my;
            while (x - iter != x2 && y + iter != y2 && x - iter >= 0 && x - iter < 10 && y + iter >= 0 && y + iter < 10) {
                if ((this->lireCase(x - iter, y + iter) == j2) || (this->lireCase(x - iter, y + iter) == reines(j2))) {
                    nb++;
                    mx = x - iter;
                    my = y + iter;
                }
                if (this->lireCase(x - iter, y + iter) == j) {
                    return false;
                }
                if (this->lireCase(x - iter, y + iter) == reines(j)) {
                    return false;
                }
                iter++;
            }
            if (x - iter == x2 && y + iter == y2) {
                if (nb == 1) {
                    this->setJeton(x, y, GrilleDames::CASE_VIDE);
                    this->setJeton(mx, my, GrilleDames::CASE_VIDE);
                    this->setJeton(x2, y2, reines(j));
                    ;
                }
            }
        }


    }

    return false;
}

bool GrilleDames::deplacereine(int j, int x, int y, int x2, int y2) {
    int iter;


    if (y >= 0 && y < 10 && x >= 0 && x < 10 && y2 >= 0 && y2 < 10 && x2 >= 0 && x2 < 10) {




        if (8 > x && 8 > y) {
            iter = 1;
            while (x + iter != x2 && y + iter != y2 && x + iter >= 0 && x + iter < 10 && y + iter >= 0 && y + iter < 10) {
                if (this->lireCase(x + iter, y + iter) != GrilleDames::CASE_VIDE)return false;
                iter++;
            }
            if (x + iter == x2 && y + iter == y2) {

                this->setJeton(x, y, GrilleDames::CASE_VIDE);
                this->setJeton(x2, y2, reines(j));
                ;

            }

        }

        if (x > 1 && y > 1) {
            iter = 1;
            while (x - iter != x2 && y - iter != y2 && x - iter >= 0 && x - iter < 10 && y - iter >= 0 && y - iter < 10) {
                if (this->lireCase(x + iter, y + iter) != GrilleDames::CASE_VIDE)return false;
                iter++;
            }
            if (x - iter == x2 && y - iter == y2) {

                this->setJeton(x, y, GrilleDames::CASE_VIDE);
                this->setJeton(x2, y2, reines(j));
                ;

            }

        }

        if (8 > x && y > 1) {
            iter = 1;
            while (x + iter != x2 && y - iter != y2 && x + iter >= 0 && x + iter < 10 && y - iter >= 0 && y - iter < 10) {
                if (this->lireCase(x + iter, y + iter) != GrilleDames::CASE_VIDE) {
                    return false;
                }
                iter++;
            }
            if (x + iter == x2 && y - iter == y2) {
                this->setJeton(x, y, GrilleDames::CASE_VIDE);
                this->setJeton(x2, y2, reines(j));
                ;

            }
        }

        if (x > 1 && 8 > y) {
            iter = 1;
            while (x - iter != x2 && y + iter != y2 && x - iter >= 0 && x - iter < 10 && y + iter >= 0 && y + iter < 10) {
                if (this->lireCase(x + iter, y + iter) != GrilleDames::CASE_VIDE) {
                    return false;
                }
                iter++;
            }
            if (x - iter == x2 && y + iter == y2) {

                this->setJeton(x, y, GrilleDames::CASE_VIDE);
                this->setJeton(x2, y2, reines(j));
                ;

            }

        }

    }
    return false;
}
