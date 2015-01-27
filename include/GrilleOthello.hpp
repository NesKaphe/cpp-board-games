#ifndef GRILLEOTHELLO_HPP
#define GRILLEOTHELLO_HPP

#include "Grille.hpp"

#include <utility>
#include <iterator>
#include <vector>

struct case_t {

    int ligne;
    int colonne;
    int valeur;

};
typedef struct case_t case_t;

class GrilleOthello : public Grille
{

public:

/* CONSTANTES DE CLASSE */
    static const int CASE_NOIRE = 1;
    static const int CASE_BLANCHE = 2;
/* FIN CONSTANTES DE CLASSE */

    GrilleOthello(int variante);
    virtual ~GrilleOthello();

    bool coupPossible(int ligne, int colonne, int valeur);
    std::vector<case_t> listeCaseTouche(int ligne, int colonne, int valeur);
    std::vector<intPair> listeCoupsPossible(int couleur);
    bool jouerCoup(int ligne, int colonne, int valeur);
    bool annulerCoup(); //Annule le dernier coup de la pile de jeu
    virtual void initialiserGrille();
    virtual bool finPartie();

protected:
    const int numVariante;
    std::vector<std::vector<case_t> > pileDeJeu;
};

#endif // GRILLEOTHELLO_HPP
