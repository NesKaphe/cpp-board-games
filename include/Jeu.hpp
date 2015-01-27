#ifndef JEU_H
#define JEU_H
#include "Grille.hpp"
#include "Joueur.hpp"

class Jeu
{
    public:

        virtual void partie()=0;
        virtual void afficherJeu()=0;
        virtual void initialiserJeu(int variante = Grille::VARIANTE_ORIGINALE)=0;
        virtual void lancerJeu() = 0;

        Jeu(int nbJoueurs);
        virtual ~Jeu();
    protected:
        const int nbJoueurs;
    private:
};

#endif // JEU_H
