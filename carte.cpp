#include "carte.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void gen_aleat(IntPoint2* ile){
    int l=int(W/4); //côté du sous-carré
    int k=0;
    for(int i=0;i<=2;i++){
        for (int j=0;j<=2;j++){
            if (((i==0)&&(j==0))||(i==2)&&(j==2))
                continue;
            ile[k]=gen_point(int(W*i/3),int(W*j/3),l);
            //cout << ile[k] << endl;
            fillRect(ile[k].x(),ile[k].y(),z,z,RED);
            k++;
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


void carte_gen_aleat(carte &map){
    IntPoint2 ile[7]; //lieu des points qui vont générer les différentes îles
    gen_aleat(ile);
    for(int i=0; i<7; i++){
        IntPoint2 p = ile[i];
        gen_ile(p, map);
    }
}

void gen_ile(IntPoint2 p, carte &map){
    int x = p.x();
    int y = p.y();

    for (int i=0; i<2*taille_max_ile+1; i++){
        for (int j=0; j<2*taille_max_ile+1; j++){
            IntPoint2 q = {x+i, y+i};
            int in = i-10;
            int jn = j-10;
            if ((x+in >=0) && (x+in < W) && (y+jn >=0) && (y+jn < H)){
                if (((map.grille[(x+in)+W*(y+jn)]).getTerre() == false) & (dist_max(q, p)<taille_max_ile)){            //s'ils sont de l'eau et pas trop loin, on tire un Bernoulli
                    double d = (double)(dist_max(q, p));
                    bool retenu = (bernoulli(d/t_max)==1);
                    cout <<retenu;
                    //si le Bernoulli est 1 ou la distance est inférieure à 5, ils deviennent de la terre
                    if (retenu or dist_max(p, q)<10){
                        (map.grille[(x+in)+W*(y+jn)]).setTerre(true);
                    }
                }
            }
        }
    }
}


void affiche_carte(carte map){
    for (int i=0; i<H; i++){
        for (int j=0;j<W; j++){
            //cout <<(map.grille[i+W*j].getTerre());
            if (map.grille[i+W*j].getTerre()){
                fillRect(i,j,z,z,Imagine::YELLOW);
            }
        }
    }
}


int bernoulli(double p){
    int retour = 0;
    double nb = (double)rand()/RAND_MAX;
    if ( nb < p )
    {
        retour = 1;
    }
    return retour;
}


int dist_max(IntPoint2 p, IntPoint2 q){   //distance (au sens des iles) entre les points p et q
    int d1 = abs(p.x() - q.x());
    int d2 = abs(p.y() - q.y());
    if (d1<d2){
        return(d2);
    }
    else{
        return(d1);
    }
}
