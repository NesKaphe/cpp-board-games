#ifndef GRILLE_H
#define GRILLE_H


class Grille
{
    public:

        /* CONSTANTES DE CLASSE */
        static const int CASE_VIDE = 0;
        static const int PAS_DE_GAGNANT = 10;
        static const int VARIANTE_ORIGINALE = 1000; //On se laisse le choix d'avoir plus d'une variante
        /* FIN CONSTANTES DE CLASSE */

        virtual void initialiserGrille()=0;
        virtual bool finPartie()=0;

        //virtual int getGagnant()=0;
        bool caseVide(int ligne, int colonne);
        void viderCase(int ligne, int colonne);
        void setJeton(int ligne, int colonne, int valeur);
        int lireCase(int ligne, int colonne);
        bool coordonneesValide(int ligne, int colonne);

        int getNbLignes();
        int getNbColonnes();
        Grille(int nbLignes, int nbColonnes);
        virtual ~Grille();

    protected:
        int **tableau;
        const int nbLignes;
        const int nbColonnes;

    private:
};

#endif // GRILLE_H
