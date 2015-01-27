#ifndef OTHELLO_H
#define OTHELLO_H

#include "Jeu.hpp"
#include "GrilleOthello.hpp"
#include "JoueurOthello.hpp"
#include "HumainOthello.hpp"
#include "IAOthello.hpp"

class Othello : public Jeu {

public:
    /* CONSTANTES DE CLASSE */
    static const int JOUEUR1 = 1;
    static const int JOUEUR2 = 2;
    /* FIN CONSTANTES DE CLASSE */

    Othello();
    virtual ~Othello();
    virtual void lancerJeu();
    virtual void initialiserJeu(int variante = GrilleOthello::VARIANTE_ORIGINALE);
    virtual void partie();
    virtual void afficherJeu();
    virtual void afficherMessageFin();
    virtual void calculScore();

protected:
    GrilleOthello *grilleDeJeu;
    JoueurOthello *joueur1;
    JoueurOthello *joueur2;
    int tourJoueur;
    int scoreJoueur1;
    int scoreJoueur2;

};

#endif //OTHELLO_H
