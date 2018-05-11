#include "deplacement.h"


void zone_possible(bateau B){
    fillCircle(B.getx(),B.gety(),rmax,Imagine::GREEN);
    B.affiche();
}

void deplace_bateau(bateau &B){
    int mouse_x,mouse_y;
    getMouse(mouse_x,mouse_y);
    B.setx(mouse_x);
    B.sety(mouse_y);
}




