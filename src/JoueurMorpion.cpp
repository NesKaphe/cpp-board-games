#include "JoueurMorpion.hpp"

JoueurMorpion::JoueurMorpion(GrilleMorpion *grilleDeJeu, int _couleur) : couleur(_couleur) {
    this->setGrilleDeJeu(grilleDeJeu);
}

JoueurMorpion::~JoueurMorpion() {

}

void JoueurMorpion::setGrilleDeJeu(GrilleMorpion *grilleDeJeu) {
    this->grilleDeJeu = grilleDeJeu;
}

int JoueurMorpion::getCouleur() {
    return this->couleur;
}
