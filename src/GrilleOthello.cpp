#include "GrilleOthello.hpp"
#include "fonctions.hpp"

GrilleOthello::GrilleOthello(int variante) : Grille(8,8), numVariante(variante) {
    //ctor
    this->initialiserGrille();
}

GrilleOthello::~GrilleOthello() {
    //dtor
}

void GrilleOthello::initialiserGrille() {
    int i, j;
    for(i = 0; i < this->nbLignes; i++) {
	for(j = 0; j < this->nbColonnes; j++) {
	    this->setJeton(i,j,GrilleOthello::CASE_VIDE);
	}
    }
    this->setJeton(3,3,GrilleOthello::CASE_BLANCHE);
    this->setJeton(3,4,GrilleOthello::CASE_NOIRE);
    this->setJeton(4,3,GrilleOthello::CASE_NOIRE);
    this->setJeton(4,4,GrilleOthello::CASE_BLANCHE);

    this->pileDeJeu.clear();
}

bool GrilleOthello::coupPossible(int ligne, int colonne, int valeur) {
    std::vector<case_t> cases;
    if(this->coordonneesValide(ligne,colonne)) {
	cases = this->listeCaseTouche(ligne,colonne,valeur);
    }

    return !cases.empty(); //Si on ne mange aucune piece, on renvoie faux car le coup est impossibl
}

std::vector<case_t> GrilleOthello::listeCaseTouche(int ligne, int colonne, int valeur) {
    std::vector<case_t> listeCases;
    int i = ligne;
    int j = colonne;
    bool boucle = true;
    int valeurCase;
    case_t uneCase;
    int compteurAjouts = 0;

    if(this->caseVide(ligne,colonne)) { 
        //On va rechercher dans toutes les directions une case de la même couleur de celle qu'on veut jouer
	//Vers le haut
	while(boucle) {

	    if(coordonneesValide(i-1,j)){
		valeurCase = lireCase(i-1,j);

		if(valeurCase == valeur) {
		    boucle = false;
		}
		else {
		    i--;
		    if(i == 0 || valeurCase == GrilleOthello::CASE_VIDE) {
			while(compteurAjouts > 0) {
			    listeCases.pop_back(); //On retire ce qu'on a ajouté
			    compteurAjouts--;
			}
			boucle = false;
		    }
		    else {
			uneCase.ligne = i;
			uneCase.colonne = j;
			uneCase.valeur = valeurCase;
			listeCases.push_back(uneCase);
			compteurAjouts++;
		    }
		}
	    }
	    else { //On est arrivé tout en haut
		boucle = false;
		while(compteurAjouts > 0) {
		    listeCases.pop_back(); //On retire ce qu'on a ajouté
		    compteurAjouts--;
		}
	    }

	}
	//Vers la diagonale montante droite
	boucle = true;
	i = ligne;
	j = colonne;
	compteurAjouts = 0;
	while(boucle) {
	    if(coordonneesValide(i-1,j+1)) {
		valeurCase = lireCase(i-1,j+1);
	    
		if(valeurCase == valeur) {
		    boucle = false;
		}
		else {
		    i--;
		    j++;
		    if(i == 0 || j == this->nbColonnes - 1 || valeurCase == GrilleOthello::CASE_VIDE) { //Si on touche un bord
			while(compteurAjouts > 0) {
			    listeCases.pop_back(); //On retire ce qu'on a ajouté
			    compteurAjouts--;
			}
			boucle = false;
		    }
		    else {
			uneCase.ligne = i;
			uneCase.colonne = j;
			uneCase.valeur = valeurCase;
			listeCases.push_back(uneCase);
			compteurAjouts++;
		    }
		}
	    }
	    else {
		boucle = false;
		while(compteurAjouts > 0) {
		    listeCases.pop_back(); //On retire ce qu'on a ajouté
		    compteurAjouts--;
		}
	    }
	}
	//Vers la droite
	boucle = true;
	i = ligne;
	j = colonne;
	compteurAjouts = 0;
	while(boucle) {
	    if(coordonneesValide(i,j+1)) {
		valeurCase = lireCase(i,j+1);

		if(valeurCase == valeur) {
		    boucle = false;
		}
		else {
		    j++;
		    if(j == this->nbColonnes - 1 || valeurCase == GrilleOthello::CASE_VIDE) {
			while(compteurAjouts > 0) {
			    listeCases.pop_back();
			    compteurAjouts--;
			}
			boucle = false;
		    }
		    else {
			uneCase.ligne = i;
			uneCase.colonne = j;
			uneCase.valeur = valeurCase;
			listeCases.push_back(uneCase);
			compteurAjouts++;
		    }
		}
	    }
	    else {
		boucle = false;
		while(compteurAjouts > 0) {
		    listeCases.pop_back(); //On retire ce qu'on a ajouté
		    compteurAjouts--;
		}
	    }
	}
	//Vers la diagonale descendante droite
	boucle = true;
	i = ligne;
	j = colonne;
	compteurAjouts = 0;
	while(boucle) {
	    if(coordonneesValide(i+1,j+1)) {
		valeurCase = lireCase(i+1,j+1);

		if(valeurCase == valeur) {
		    boucle = false;
		}
		else {
		    i++;
		    j++;
		    if(i == this->nbLignes - 1 || j == this->nbColonnes - 1 || valeurCase == GrilleOthello::CASE_VIDE) {
			while(compteurAjouts > 0) {
			    listeCases.pop_back();
			    compteurAjouts--;
			}
			boucle = false;
		    }
		    else {
			uneCase.ligne = i;
			uneCase.colonne = j;
			uneCase.valeur = valeurCase;
			listeCases.push_back(uneCase);
			compteurAjouts++;
		    }
		}
	    }
	    else {
		boucle = false;
		while(compteurAjouts > 0) {
		    listeCases.pop_back(); //On retire ce qu'on a ajouté
		    compteurAjouts--;
		}
	    }
	}

	//Vers le bas
	boucle = true;
	i = ligne;
	j = colonne;
	compteurAjouts = 0;
	while(boucle) {
	    if(coordonneesValide(i+1,j)) {
		valeurCase = lireCase(i+1,j);

		if(valeurCase == valeur) {
		    boucle = false;
		}
		else {
		    i++;
		    if(i == this->nbLignes - 1 || valeurCase == GrilleOthello::CASE_VIDE) {
			while(compteurAjouts > 0) {
			    listeCases.pop_back();
			    compteurAjouts--;
			}
			boucle = false;
		    }
		    else {
			uneCase.ligne = i;
			uneCase.colonne = j;
			uneCase.valeur = valeurCase;
			listeCases.push_back(uneCase);
			compteurAjouts++;
		    }
		}
	    }
	    else {
		boucle = false;
		while(compteurAjouts > 0) {
		    listeCases.pop_back(); //On retire ce qu'on a ajouté
		    compteurAjouts--;
		}
	    }
	}
	//Vers la diagonale descendante gauche
	boucle = true;
	i = ligne;
	j = colonne;
	compteurAjouts = 0;
	while(boucle) {
	    if(coordonneesValide(i+1,j-1)) {
		valeurCase = lireCase(i+1,j-1);

		if(valeurCase == valeur) {
		    boucle = false;
		}
		else {
		    i++;
		    j--;
		    if(i == this->nbLignes - 1 || j == 0 || valeurCase == GrilleOthello::CASE_VIDE) {
			while(compteurAjouts > 0) {
			    listeCases.pop_back();
			    compteurAjouts--;
			}
			boucle = false;
		    }
		    else {
			uneCase.ligne = i;
			uneCase.colonne = j;
			uneCase.valeur = valeurCase;
			listeCases.push_back(uneCase);
			compteurAjouts++;
		    }
		}
	    }
	    else {
		boucle = false;
		while(compteurAjouts > 0) {
		    listeCases.pop_back(); //On retire ce qu'on a ajouté
		    compteurAjouts--;
		}
	    }
	}

	//Vers la gauche
	boucle = true;
	i = ligne;
	j = colonne;
	compteurAjouts = 0;
	while(boucle) {
	    if(coordonneesValide(i,j-1)) {
		valeurCase = lireCase(i,j-1);

		if(valeurCase == valeur) {
		    boucle = false;
		}
		else {
		    j--;
		    if(j == 0 || valeurCase == GrilleOthello::CASE_VIDE) {
			while(compteurAjouts > 0) {
			    listeCases.pop_back();
			    compteurAjouts--;
			}
			boucle = false;
		    }
		    else {
			uneCase.ligne = i;
			uneCase.colonne = j;
			uneCase.valeur = valeurCase;
			listeCases.push_back(uneCase);
			compteurAjouts++;
		    }
		}
	    }
	    else {
		boucle = false;
		while(compteurAjouts > 0) {
		    listeCases.pop_back(); //On retire ce qu'on a ajouté
		    compteurAjouts--;
		}
	    }
	}

	//Vers la diagonale montante gauche
	boucle = true;
	i = ligne;
	j = colonne;
	compteurAjouts = 0;
	while(boucle) {
	    if(coordonneesValide(i-1,j-1)) {
		valeurCase = lireCase(i-1,j-1);

		if(valeurCase == valeur) {
		    boucle = false;
		}
		else {
		    i--;
		    j--;
		    if(i == 0 || j == 0 || valeurCase == GrilleOthello::CASE_VIDE) {
			while(compteurAjouts > 0) {
			    listeCases.pop_back();
			    compteurAjouts--;
			}
			boucle = false;
		    }
		    else {
			uneCase.ligne = i;
			uneCase.colonne = j;
			uneCase.valeur = valeurCase;
			listeCases.push_back(uneCase);
			compteurAjouts++;
		    }
		}
	    }
	    else {
		boucle = false;
		while(compteurAjouts > 0) {
		    listeCases.pop_back(); //On retire ce qu'on a ajouté
		    compteurAjouts--;
		}
	    }
	}
    }

    return listeCases;
}

std::vector<intPair> GrilleOthello::listeCoupsPossible(int couleur) {

    int i,j;
    std::vector<intPair> listeCoups;

    for(i=0; i < this->nbLignes; i++) {
	for(j=0; j < this->nbColonnes; j++) {
	    if(this->coupPossible(i,j,couleur)) {
		listeCoups.push_back(intPair(i,j));
	    }
	}
    }

    return listeCoups;
}

bool GrilleOthello::finPartie() {

    std::vector<intPair> listeCoupsNoir;
    std::vector<intPair> listeCoupsBlanc;

    if(this->grillePleine()) {
	return true;
    }
    
    listeCoupsNoir = this->listeCoupsPossible(GrilleOthello::CASE_NOIRE);
    listeCoupsBlanc = this->listeCoupsPossible(GrilleOthello::CASE_BLANCHE);

    if(listeCoupsNoir.empty() && listeCoupsBlanc.empty()) {
	return true; //Aucun coup possible pour les deux joueurs
    }

    return false; //Dans tous les autres cas la partie n'est pas finie
}

bool GrilleOthello::jouerCoup(int ligne, int colonne, int valeur) {
    std::vector<case_t> listeCases;
    std::vector<case_t>::iterator it;
    case_t uneCase;
    if(this->coupPossible(ligne,colonne,valeur)) {
	listeCases = this->listeCaseTouche(ligne,colonne,valeur);
	it = listeCases.begin();
	while(it != listeCases.end()) {
	    this->setJeton(it->ligne,it->colonne,valeur); //On retourne toutes les pieces de la liste
	    it++;
	}
	this->setJeton(ligne,colonne,valeur);
	uneCase.ligne = ligne;
	uneCase.colonne = colonne;
	uneCase.valeur = GrilleOthello::CASE_VIDE;
	listeCases.push_back(uneCase);
	this->pileDeJeu.push_back(listeCases);
	return true;
    }
    return false;
}

bool GrilleOthello::annulerCoup() {
    std::vector<case_t> listeCases;
    std::vector<case_t>::iterator it;
    if(this->pileDeJeu.empty()) {
	return false; //On ne peut pas annuler un coup au premier tour
    }

    listeCases = this->pileDeJeu.back();
    it = listeCases.begin();
    while(it != listeCases.end()) {
	//On remet les cases comme elles etaient
	this->setJeton(it->ligne,it->colonne,it->valeur);
	it++;
    }
    this->pileDeJeu.pop_back();
    return true; //On a reussi a annuler le coup
}
