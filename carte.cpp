#include "carte.h"

const int W=100;
const int H=100;
carte gen_aleat(){
    carte map;
    map.grille=new pixel [W*H];
    for (int i=0; i<W*H; i++){
        pixel map.grille[i](Imagine::BLUE,false,false,false);
        if ((i>200)||(i<250)){
            pixel map.grille[i](Imagine::YELLOW,true,false,false);
                     }
    }
}

void affiche_carte(carte map){
    fillRect(0,0,W,H,Imagine::BLUE);
    for (int i=0; i<H; i++){
        for (int j=0,j<W; j++){
            if (map.grille[i].getColor()==YELLOW){
                fillRect(i,j,z,z,Imagine::YELLOW);
            }
        }
    }
}

