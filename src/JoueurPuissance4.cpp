#include "JoueurPuissance4.hpp"

JoueurPuissance4::JoueurPuissance4(GrillePuissance4 *grilleDeJeu, int _couleur) : couleur(_couleur) {
    this->setGrilleDeJeu(grilleDeJeu);
}

JoueurPuissance4::~JoueurPuissance4() {

}

void JoueurPuissance4::setGrilleDeJeu(GrillePuissance4 *grilleDeJeu) {
    this->grilleDeJeu = grilleDeJeu;
}

int JoueurPuissance4::getCouleur() {
    return this->couleur;
}
