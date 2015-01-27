#include <vector>
#include <iostream>
#include "GrilleFiveMore.hpp"
#include "fonctions.hpp"

GrilleFiveMore::GrilleFiveMore(int dimLigne, int dimColonne, int variante = GrilleFiveMore::VARIANTE_ORIGINALE) : Grille(dimLigne, dimColonne), numVariante(variante) {
    //ctor
    this->initialiserGrille();
}

GrilleFiveMore::~GrilleFiveMore()
{
    //dtor
}

void GrilleFiveMore::initialiserGrille() {
    int i,j;
    for(i = 0; i < this->nbLignes; i++) {
        for(j = 0; j < this->nbColonnes; j++) {
            this->setJeton(i,j,GrilleFiveMore::CASE_VIDE);
        }
    }
}

bool GrilleFiveMore::finPartie() {
    return this->grillePleine();
}

bool GrilleFiveMore::deplacerJeton(int ligneDepart, int colonneDepart, int ligneArrive, int colonneArrive) {

    if(ligneArrive < 0 || ligneArrive > this->nbLignes || colonneArrive < 0 || colonneArrive > this->nbColonnes) {
        return false; // On nous a demandé une case en dehors de la grille de jeu, c'est impossible
    }

    if(!this->caseVide(ligneArrive, colonneArrive) || this->caseVide(ligneDepart, colonneDepart)) {
        return false; // On ne peut pas se deplacer vers une case non vide ou a partir d'une case vide, ce cas englobe le deplacement vers la même case
    }


    std::vector<intPair> vect; //vecteur de parcours qui sera utilisé comme une Pile
    std::vector<intPair> casesVisite;
    casesVisite.push_back(intPair(ligneDepart, colonneDepart));

    if(ligneDepart < ligneArrive) {
        vect.push_back(intPair(ligneDepart-1, colonneDepart));
        if(colonneDepart < colonneArrive) {
            vect.push_back(intPair(ligneDepart, colonneDepart - 1));
            vect.push_back(intPair(ligneDepart, colonneDepart + 1));
        }
        else {
            vect.push_back(intPair(ligneDepart, colonneDepart + 1));
            vect.push_back(intPair(ligneDepart, colonneDepart - 1));
        }
        vect.push_back(intPair(ligneDepart + 1, colonneDepart));
        //On a ajouté les 4 cases adjacentes dans le vecteur de parcours de la grille dans un ordre qui nous rapproche de la case voulue
    }
    else {
        vect.push_back(intPair(ligneDepart + 1, colonneDepart));
        if(colonneDepart < colonneArrive) {
            vect.push_back(intPair(ligneDepart, colonneDepart - 1));
            vect.push_back(intPair(ligneDepart, colonneDepart + 1));
        }
        else {
            vect.push_back(intPair(ligneDepart, colonneDepart + 1));
            vect.push_back(intPair(ligneDepart, colonneDepart - 1));
        }
        vect.push_back(intPair(ligneDepart - 1, colonneDepart));
        //On a ajouté les 4 cases adjacentes dans le vecteur de parcours de la grille dans un ordre qui nous rapproche de la case voulue
    }

    intPair coordonneeTableau;
    int ligneCourante;
    int colonneCourante;

    std::vector<intPair>::iterator it;
    while(!vect.empty()) {
        coordonneeTableau = vect.back();

        ligneCourante = coordonneeTableau.first;
        colonneCourante = coordonneeTableau.second;
        vect.pop_back();

        it = casesVisite.begin(); //On va rechercher si la case a déja été parcourue
        while(it != casesVisite.end()) {
            if(it->first != coordonneeTableau.first || it->second != coordonneeTableau.second) {
                it++;
            }
            else {
                break;
            }
        }

        if(it == casesVisite.end()) { //Si on n'a pas deja parcouru la case courante
            casesVisite.push_back(coordonneeTableau); //On ajoute la case que l'on va traité a la liste de cases deja parcourues

            if(this->coordonneesValide(ligneCourante,colonneCourante)) {
                if(this->caseVide(ligneCourante,colonneCourante)) {

                    if(ligneCourante == ligneArrive && colonneCourante == colonneArrive) { //Si on a trouvé la bonne case, on se deplace
                        this->setJeton(ligneArrive, colonneArrive, this->lireCase(ligneDepart, colonneDepart));
                        this->viderCase(ligneDepart, colonneDepart);
                        return true;
                    }
                    else { //Si ce n'est toujours pas la case voulue, on ajoute les cases adjacentes a la pile
                        if(ligneCourante < ligneArrive) {
                            vect.push_back(intPair(ligneCourante-1, colonneCourante));
                            if(colonneCourante < colonneArrive) {
                                vect.push_back(intPair(ligneCourante, colonneCourante - 1));
                                vect.push_back(intPair(ligneCourante, colonneCourante + 1));
                            }
                            else {
                                vect.push_back(intPair(ligneCourante, colonneCourante + 1));
                                vect.push_back(intPair(ligneCourante, colonneCourante - 1));
                            }
                            vect.push_back(intPair(ligneCourante + 1, colonneCourante));
                            //On a ajouté les 4 cases adjacentes dans le vecteur de parcours de la grille dans un ordre qui nous rapproche de la case voulue
                        }
                        else {
                            vect.push_back(intPair(ligneCourante + 1, colonneCourante));
                            if(colonneCourante < colonneArrive) {
                                vect.push_back(intPair(ligneCourante, colonneCourante - 1));
                                vect.push_back(intPair(ligneCourante, colonneCourante + 1));
                            }
                            else {
                                vect.push_back(intPair(ligneCourante, colonneCourante + 1));
                                vect.push_back(intPair(ligneCourante, colonneCourante - 1));
                            }
                            vect.push_back(intPair(ligneCourante - 1, colonneCourante));
                            //On a ajouté les 4 cases adjacentes dans le vecteur de parcours de la grille dans un ordre qui nous rapproche de la case voulue
                        }
                    }
                }
            }
        }
    }

    //Aucun des chemins n'a reussi, on ne peut donc pas se deplacer vers la case demandé
    return false;
}

bool GrilleFiveMore::changerCouleurJeton(int ligne, int colonne, int couleur) {
    if(this->lireCase(ligne,colonne) == couleur) {
        return false; //remettre la même couleur dans la case reviendrait a ne pas jouer, c'est impossible
    }

    switch(couleur) {
        case GrilleFiveMore::COULEUR_ROUGE:

        case GrilleFiveMore::COULEUR_JAUNE:

        case GrilleFiveMore::COULEUR_VERT:

        case GrilleFiveMore::COULEUR_BLEU:

        case GrilleFiveMore::COULEUR_ORANGE:

            this->setJeton(ligne,colonne,couleur); //On change la couleur du jeton si on connait la couleur
            break;

        default:
            return false; //La couleur n'est pas valide, on ne valide pas le coup
    }

    return true;
}

int GrilleFiveMore::getNumVariante() {
    return this->numVariante;
}

int GrilleFiveMore::viderAlignements() {
    std::vector<intPair> vect;
    if(alignementN(this,5,&vect)) { //Si on a un alignement d'au moins 5, on va recuperer les coordonnées dans le vector
        std::vector<intPair>::iterator it = vect.begin();
        while(it != vect.end()) {
            this->viderCase(it->first,it->second);
            it++;
        }
    }
    return vect.size(); //On renvoie le nombre de jetons supprimés, 0 dans tous les cas, sauf si on a eu un alignement d'au moins 5 jetons quelque part
}
