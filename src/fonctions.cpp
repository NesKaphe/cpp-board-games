#include "fonctions.hpp"
#include "couleurs.hpp"

bool alignementN(Grille *uneGrille, int n, std::vector<intPair> *vect) {
    int nbAlignDroite;
    int nbAlignDiag;
    int nbAlignDiag2;
    int nbAlignBas;
    int ligneCourante;
    int colonneCourante;
    int i;
    bool alignementTrouve = false;

    for(ligneCourante = 0; ligneCourante < uneGrille->getNbLignes(); ligneCourante++) {
        for(colonneCourante = 0; colonneCourante < uneGrille->getNbColonnes(); colonneCourante++) {
            nbAlignDroite = 1;
            nbAlignDiag = 1;
            nbAlignDiag2 = 1;
            nbAlignBas = 1;

            if(!uneGrille->caseVide(ligneCourante,colonneCourante)) {
                if(vect != 0)
                    vect->push_back(intPair(ligneCourante, colonneCourante));

                //on compte le nombre d'alignements vers la droite si on est pas deja a la derniere colonne
                for(i = colonneCourante + 1; i < uneGrille->getNbColonnes(); i++) {
                    if(uneGrille->lireCase(ligneCourante,colonneCourante) == uneGrille->lireCase(ligneCourante, i)) {
                        nbAlignDroite++;
                        if(vect !=0) {
                            vect->push_back(intPair(ligneCourante, i));
                        }
                    }
		    else {
			break;
		    }
                }
                if(nbAlignDroite < n) {
                    for(i = 1; i < nbAlignDroite && vect != 0; i++) {
                        vect->pop_back(); //On retire les cases qu'on a ajouté précédement
                    }
                }
                //on compte le nombre d'alignements sur la diagonale descendante
                for(i = 1; (colonneCourante + i) < uneGrille->getNbColonnes() && (ligneCourante + i) < uneGrille->getNbLignes(); i++) {
                    if(uneGrille->lireCase(ligneCourante,colonneCourante) == uneGrille->lireCase(ligneCourante + i, colonneCourante + i)) {
                        nbAlignDiag++;
                        if(vect != 0) {
                            vect->push_back(intPair(ligneCourante + i, colonneCourante + i));
                        }
                    }
		    else {
			break;
		    }
                }
                if(nbAlignDiag < n) {
                    for(i = 1; i < nbAlignDiag && vect !=0; i++) {
                        vect->pop_back();
                    }
                }
                //on compte le nombre d'alignements sur la diagonale montante
                for(i = 1; (ligneCourante - i) >= 0 && (colonneCourante +  i) < uneGrille->getNbColonnes(); i++) {
                    if(uneGrille->lireCase(ligneCourante,colonneCourante) == uneGrille->lireCase(ligneCourante - i, colonneCourante + i)) {
                        nbAlignDiag2++;
                        if(vect != 0) {
                            vect->push_back(intPair(ligneCourante - i, colonneCourante + i));
                        }
                    }
		    else {
			break;
		    }
                }
                if(nbAlignDiag2 < n) {
                    for(i = 1; i < nbAlignDiag2 && vect != 0; i++) {
                        vect->pop_back();
                    }
                }
                //on compte le nombre d'alignements vers le bas
                for(i = ligneCourante + 1; i < uneGrille->getNbLignes(); i++) {
                    if(uneGrille->lireCase(ligneCourante,colonneCourante) == uneGrille->lireCase(i, colonneCourante)) {
                        nbAlignBas++;
                        if(vect !=0) {
                            vect->push_back(intPair(i, colonneCourante));
                        }
                    }
		    else {
			break;
		    }
                }
                if(nbAlignBas < n) {
                    for(i = 1; i < nbAlignBas && vect != 0; i++) {
                        vect->pop_back();
                    }
                }

                if(nbAlignDroite >= n || nbAlignDiag >= n || nbAlignBas >= n || nbAlignDiag2 >=n ) { //Si on a rencontré un alignement de longueur n au minimum
                    alignementTrouve = true;
                }
                else {
                    if(vect != 0) {
                        vect->pop_back(); //On retire la case courante car elle ne nous interesse pas
                    }
                }
                //std::cout << "Etat : " << nbAlignDroite << ";" <<nbAlignDiag << ";" <<nbAlignBas << std::endl;
            }
        }
    }
    if(alignementTrouve && vect != 0) {
        retirerDoublons(vect); //On retire les eventuels doublons du vector avant de finir
    }
    return alignementTrouve;
}

void retirerDoublons(std::vector<intPair> *vect) {

    std::vector<intPair>::iterator it = vect->begin();
    std::vector<intPair>::iterator it2;

    while(it != vect->end()) {
        it2 = it + 1;
        while(it2 != vect->end()) {
            if(it->first == it2->first && it->second == it2->second) {
                vect->erase(it2);
            }
            else {
                it2++;
            }
        }
        it++;
    }
}

void clear_screen() {
    std::cout << "\033[2J\033[1;1H";
}

void setCouleur(std::string couleur) {
    std::cout << "\033[" << couleur << "m";
}

void vider_cin() {
    std::cin.clear();
    std::cin.seekg(0, std::ios::end);

    if(!std::cin.fail()) { //Si le flux a un état valide
        std::cin.ignore(std::numeric_limits<std::streamsize>::max());
    }
    else { //Sinon, il est dans un état invalide
        std::cin.clear();
    }
}

void pause() {
    vider_cin(); //On s'assure que cin est vide avant de marquer une pause

    std::cout << "Appuyez sur Entrer pour continuer...";
    std::cin.get(); //On attend une saisie clavier

    vider_cin(); //On s'assure que cin est vide apres pour une future saisie
}

void saisieString(std::string *saisie, std::string message) {

     while(true) {
	 std::cout << message;
	 // std::cin >> *saisie;
	 std::getline(std::cin, *saisie);

	 if(std::cin.eof() || std::cin.bad()) {
	     std::cerr << "Erreur de saisie" << std::endl;
	     
	     if(std::cin.eof()) {
		 break; //Fin du flux, on arrete la lecture
	     }
	     
	     vider_cin();
	     
	     continue;
	 }
	 
	 else if(std::cin.fail()) {
	     std::cerr << "Saisie incorrecte" << std::endl;
	     
	     vider_cin(); //On vide cin et le remet dans un etat valide
	     
	     continue;
	 }
	 
	 vider_cin(); // Dans tous les autres cas, on s'assure de vider cin
	 break;
     }

}

int saisieChiffre(std::string message) {
    int chiffre = 0;
    std::string saisie; //Variable temporaire pour la lecture

    while(true) {
	saisieString(&saisie, message);
	std::istringstream stream(saisie);
	stream >> chiffre;
	
	if(stream.fail() || !stream.eof()) { //Si on a pas reussi a lire le flux ou que l'on ne l'a pas lu completement, c'est que la saisie est incorrecte
	    std::cerr << "Nombre incorrect" << std::endl;
	}
	else { //On a reussi notre saisie
	    break; //On peut sortir de la boucle
	}
    }

    return chiffre;
}
