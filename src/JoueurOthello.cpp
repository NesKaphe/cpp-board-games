#include "JoueurOthello.hpp"

JoueurOthello::JoueurOthello(GrilleOthello *grilleDeJeu, int _couleur) : couleur(_couleur) {
    this->setGrilleDeJeu(grilleDeJeu);
    this->quit = false;
}

JoueurOthello::~JoueurOthello() {

}

void JoueurOthello::setGrilleDeJeu(GrilleOthello *grilleDeJeu) {
    this->grilleDeJeu = grilleDeJeu;
}

int JoueurOthello::getCouleur() {
    return this->couleur;
}
