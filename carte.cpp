#include "carte.h"

carte gen_aleat(){
    carte map;
    return map;
    }


void affiche_carte(carte map){
    fillRect(0,0,W,H,Imagine::BLUE);
    for (int i=0; i<H; i++){
        for (int j=0;j<W; j++){
            if (map.grille[i].getColor()==YELLOW){
                fillRect(i,j,z,z,Imagine::YELLOW);
            }
        }
    }
}

