#include "carte.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

/*IntPoint2* gen_aleat(){
    int l=int(W/4); //côté du sous-carré
    IntPoint2 ile[7]; //lieu des points qui vont générer les différentes îles
    int k=0;
    for(int i=0;i<=2;i++){
        for (int j=0;j<=2;j++){
            if (((i==0)&&(j==0))||(i==2)&&(j==2))
                continue;
            ile[k]=gen_point(int(W*i/3),int(W*j/3),l);
            cout << ile[k] << endl;
            fillRect(ile[k].x(),ile[k].y(),z,z,RED);
            k++;
        }
    }
    return ile;
}*/


void affiche_carte(carte map){
    for (int i=0; i<H; i++){
        for (int j=0;j<W; j++){
            if (map.grille[i].getColor()==YELLOW){
                fillRect(i,j,z,z,Imagine::YELLOW);
            }
        }
    }
}

//Renvoie les coordonnées d'un point aléatoirement placé dans un carré de côté l dont le coin sup gauche est en x,y
IntPoint2 gen_point(int x,int y,int l){
    int nb_x=x+rand()%l;
    int nb_y=y+rand()%l;
    IntPoint2 p={nb_x,nb_y};
    return p;
}

