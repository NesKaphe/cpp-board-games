#ifndef FONCTIONS_HPP_INCLUDED
#define FONCTIONS_HPP_INCLUDED

#include <vector>
#include <limits>
#include <iostream>
#include <string>
#include <sstream>
#include "Grille.hpp"
#include "GrilleFiveMore.hpp"
#include "couleurs.hpp"

typedef std::pair<int, int> intPair;

bool alignementN(Grille *uneGrille, int n, std::vector<intPair> *vect = 0); //Renvoie un vecteur contenant la liste des n jetons identiques alignés sur la grille

void retirerDoublons(std::vector<intPair> *vect); //Retire les paires en double du vector

void saisieString(std::string *saisie, std::string message);

int saisieChiffre(std::string message); //Demande un chiffre entier positif au clavier de facon securisée

void setCouleur(std::string couleur); //Change la couleur du texte dans la console

void vider_cin(); //Pour vider cin en cas de mauvaise saisie clavier

void pause();

void clear_screen(); //Place le curseur en haut a gauche du terminal

#endif // FONCTIONS_HPP_INCLUDED
