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

void bateau::capture_tresor(bool B){
    tresor=B; // le bateau possède le trésor <-> B=true
}

bool bateau::getTresor(){
    return(tresor);
}

void gen_bateau(bateau* boats){
    bateau pirate1=bateau(w_base/2, w_base/2,0,false);
    bateau pirate2=bateau(W-w_base/2,W-w_base/2,1,false);
    boats[0]=pirate1;
    boats[1]=pirate2;
}

//Affiche un bateau
void bateau::dessine_png(){
    Image<AlphaColor> Ib;
    load(Ib,srcPath("boat0rose.bmp"));                // Load Image
    createMaskFromColor(Ib,Color(243,20,255));
    display(Ib,xb,yb);
}
