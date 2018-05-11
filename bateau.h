#pragma once
#include <Imagine/Graphics.h>
#include "carte.h"

class bateau {
    int xb;
    int yb;
    int joueur;
    bool tresor;
public:
    bateau();
    bateau(int n_x, int n_y, int n_joueur, bool n_tresor);
    void affiche();
    void setx(int n_x);
    void sety(int n_y);
    int getx();
    int gety();
};
