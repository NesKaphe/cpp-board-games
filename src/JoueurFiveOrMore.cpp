#include "JoueurFiveOrMore.hpp"
#include "GrilleFiveMore.hpp"
#include "fonctions.hpp"
#include <iostream>

JoueurFiveOrMore::JoueurFiveOrMore(GrilleFiveMore *grilleDeJeu) {
    this->grilleDeJeu = grilleDeJeu;
}

JoueurFiveOrMore::~JoueurFiveOrMore()
{
    //dtor
}

void JoueurFiveOrMore::jouer() {
    int ligne,colonne;
    bool boucle = false;
    std::cout << "Choix du prochain coup" << std::endl;
    switch(this->grilleDeJeu->getNumVariante()) {
        case GrilleFiveMore::VARIANTE_ORIGINALE:
            int ligneArrive,colonneArrive;
            do {
		ligne = saisieChiffre("Ligne du jeton à deplacer : ");
                colonne = saisieChiffre("Colonne du jeton à deplacer : ");
		ligneArrive = saisieChiffre("Ligne d'arrivé du jeton : ");
                colonneArrive = saisieChiffre("Colonne d'arrivé du jeton : ");
                boucle = false;
                if(!this->grilleDeJeu->deplacerJeton(ligne-1,colonne-1,ligneArrive-1,colonneArrive-1)) {
                    std::cout << "Déplacement impossible" << std::endl;
                    boucle = true;
                }
            }
            while(boucle);
            break;
        case GrilleFiveMore::VARIANTE_1:
            int couleur;
            do {
                ligne = saisieChiffre("Ligne du jeton à modifier : ");
                colonne = saisieChiffre("Colonne du jeton à modifier");
                std::cout << "Menu" << std::endl;
                std::cout << "1-Rouge" << std::endl << "2-Jaune" << std::endl << "3-Vert" << std::endl << "4-Bleu" << std::endl << "5-Orange" << std::endl;
                couleur = saisieChiffre("Quelle couleur voulez vous ? ");
                boucle = false;
                if(!this->grilleDeJeu->changerCouleurJeton(ligne-1,colonne-1,couleur)) {
                    std::cout << "Impossible d'effectuer ce changement de couleur" << std::endl;
                }
            }
            while(boucle);
            break;
        //On pourra ajouter ici d'autres variantes
    }
}

void JoueurFiveOrMore::setGrilleDeJeu(GrilleFiveMore *uneGrille) {
    this->grilleDeJeu = uneGrille;
}
