#ifndef GRILLEFIVEMORE_H
#define GRILLEFIVEMORE_H

#include "Grille.hpp"

class GrilleFiveMore : public Grille
{
    public:

        /* CONSTANTES DE CLASSE  */
        static const int COULEUR_ROUGE      = 1;
        static const int COULEUR_JAUNE      = 2;
        static const int COULEUR_VERT       = 3;
        static const int COULEUR_BLEU       = 4;
        static const int COULEUR_ORANGE     = 5;
        static const int NB_COULEURS        = 5;
        static const int VARIANTE_1         = 1001;
        /* FIN CONSTANTES DE CLASSE */

        GrilleFiveMore(int dimLigne, int dimColonne, int variante);
        virtual ~GrilleFiveMore();

        /* Deplacement complexe */
        virtual bool deplacerJeton(int ligneDepart, int colonneDepart, int ligneArrive, int colonneArrive); //Jeu original

        virtual bool changerCouleurJeton(int Ligne, int Colonne, int couleur); //Variante 1

        virtual int viderAlignements(); // Tous

        virtual int getNumVariante();
        virtual void initialiserGrille();
        virtual bool finPartie();

    protected:
        const int numVariante;
    private:
};

#endif // GRILLEFIVEMORE_H
