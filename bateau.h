#pragma once
#include <Imagine/Graphics.h>

class bateau {
    int xb;
    int yb;
    int joueur;
    bool tresor;
public:
    bateau();
    bateau(int n_x, int n_y, int n_joueur, bool n_tresor);
    void affiche();
    void setx(int x);
    void sety(int y);
    int getx();
    int gety();
};
