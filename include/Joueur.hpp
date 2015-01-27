#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur
{
    public:
        virtual void jouer()=0;
        virtual std::string getNom();
	virtual void setNom(std::string nom);
	virtual bool getquit();
        Joueur();
        virtual ~Joueur();
    protected:
	std::string nom;
	bool quit;
    private:
};

#endif // JOUEUR_H
