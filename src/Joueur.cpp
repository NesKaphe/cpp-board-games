#include "Joueur.hpp"

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}

std::string Joueur::getNom() {
    return this->nom;
}

void Joueur::setNom(std::string nom) {
    this->nom = nom;
}

bool Joueur::getquit() {
    return this->quit;
}
