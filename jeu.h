#ifndef JEU_H
#define JEU_H

#include <list>
using namespace std;

typedef enum {VIDE, MUR} Case;
typedef enum {GAUCHE, DROITE, HAUT, BAS} Direction;

class Jeu;

class Fantome
{
    friend class Jeu;

  protected:
    int posX, posY;
    Direction dir;

  public:
    Fantome();
    int getPosX() const;
    int getPosY() const;
};

class Jeu
{
  protected:
    Case *terrain;
    int largeur, hauteur; // Nombre de cases en largeur et en hauteur
    int posPacmanX, posPacmanY;

  public:
    list<Fantome> fantomes;

  public:
    Jeu();
    Jeu(const Jeu &)=delete;
    ~Jeu();

    Jeu &operator=(const Jeu &)=delete;

    bool init();
    void evolue();

    // Retourne les dimensions (en nombre de cases)
    int getNbCasesX() const;
    int getNbCasesY() const;

    // Retourne la position du Pacman
    int getPacmanX() const;
    int getPacmanY() const;

    // Retourne la case � une position donn�e
    Case getCase(int, int) const;

    // Indique si la case � une position donn�e existe et est vide
    // (Pacman ou les fantomes peuvent l'occuper)
    bool posValide(int, int) const;

    // D�place Pacman dans une direction (si la case � atteindre est valide)
    bool deplacePacman(Direction);
};

#endif
