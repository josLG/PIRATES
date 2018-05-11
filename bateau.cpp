#include "bateau.h"
bateau::bateau(){
}

bateau::bateau(int n_x, int n_y, int n_joueur, bool n_tresor){
    xb=n_x;
    yb=n_y;
    joueur=n_joueur;
    tresor=n_tresor;
}


void bateau::affiche(){
    fillRect(xb,yb,z,z,Imagine::BLACK);
}

void bateau::setx(int n_x){
    xb=n_x;
}

void bateau::sety(int n_y){
    yb=n_y;
}

int bateau::getx(){
    return xb;
}

int bateau::gety(){
    return yb;
}
