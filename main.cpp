#include <iostream>
#include "Jeu.hpp"
#include "FiveOrMore.hpp"
#include "Othello.hpp"
#include "fonctions.hpp"
#include "Puissance4.hpp"
#include "Morpion.hpp"
#include "Dames.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
/* DEBUG DIAGONALES
    GrillePuissance4 uneGrille(GrillePuissance4::VARIANTE_ORIGINALE);
    uneGrille.setJeton(2,3,GrillePuissance4::COULEUR_ROUGE);
    uneGrille.setJeton(3,4,GrillePuissance4::COULEUR_ROUGE);
    uneGrille.setJeton(4,5,GrillePuissance4::COULEUR_ROUGE);
    uneGrille.setJeton(5,6,GrillePuissance4::COULEUR_ROUGE);
    if(alignementN(&uneGrille, 4)) {
	std::cout << "oui diag descendante" << std::endl;
    }
    else {
	std::cout << "non diag descendante" << std::endl;
    }
    pause();
    GrillePuissance4 uneGrille2(GrillePuissance4::VARIANTE_ORIGINALE);
    uneGrille2.setJeton(3,3,GrillePuissance4::COULEUR_ROUGE);
    uneGrille2.setJeton(2,4,GrillePuissance4::COULEUR_ROUGE);
    uneGrille2.setJeton(1,5,GrillePuissance4::COULEUR_ROUGE);
    uneGrille2.setJeton(0,6,GrillePuissance4::COULEUR_ROUGE);
    if(alignementN(&uneGrille2, 4)) {
	std::cout << "oui diag montante" << std::endl;
    }
    else {
	std::cout << "non diag montante" << std::endl;
    }
    pause();
*/
    srand(time(0));
    int choix;
    Jeu *unJeu;
    while(true) {
	clear_screen();
	//Message d'intro
	std::cout << "Jeux en C++" << std::endl;
	std::cout << "Réalisé par Sebastien Ciupek, Yapo Gayllord, Alain Dias" << std::endl << std::endl;

	//Menu de selection du jeu
	std::cout << "MENU SELECTION" <<std::endl;
	std::cout << "1 - Quitter" << std::endl;
	std::cout << "2 - Jouer à Othello" << std::endl;
	std::cout << "3 - Jouer au Five or More" << std::endl;
	std::cout << "4 - Jouer au Puissance 4" << std::endl;
	std::cout << "5 - Jouer au Morpion" << std::endl;
	std::cout << "6 - Jouer aux Dames" << std::endl;
	choix = saisieChiffre("Quel est votre choix ? ");

	switch(choix) {
	case 1:
	    std::cout << "A bientôt !" <<std::endl;
	    return 0; //Fin du programme
	case 2:
	    unJeu = new Othello(); //On crée le jeu
	    unJeu->lancerJeu();
	    break;
	case 3:
	    unJeu = new FiveOrMore(); //On crée le jeu
	    unJeu->lancerJeu(); //On lance le jeu
	    break;
	case 4:
	    unJeu = new Puissance4(); //On crée le jeu
	    unJeu->lancerJeu(); //On lance le jeu
	    break;
	case 5:
	    unJeu = new Morpion(); //On crée le jeu
	    unJeu->lancerJeu(); //On lance le jeu
	    break;
	case 6:
	    unJeu = new Dames();
	    unJeu->lancerJeu();
	    break;
	default:
	    continue;
	}
	std::cout << "delete" << std::endl;
	delete unJeu; //Ici, on libère la memoire pour le prochain choix de jeu de l'utilisateur
    }

    return 0;
}
