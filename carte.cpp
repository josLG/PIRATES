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
            fillRect(ile[k].x(),ile[k].y(),1,1,RED);
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

//Génère une carte aléatoirement
void carte_gen_aleat(carte &map){
    IntPoint2 ile[7]; //lieu des points qui vont générer les différentes îles
    gen_aleat(ile);
    for(int i=0; i<7; i++){
        IntPoint2 p = ile[i];
        gen_ile(p, map);
    }
}

//Génère une île à partir d'un point qui sera le centre de l'île
void gen_ile(IntPoint2 p, carte &map){
    int x = p.x();
    int y = p.y();

    for (int i=0; i<2*taille_max_ile+1; i++){
        for (int j=0; j<2*taille_max_ile+1; j++){
            int in = i-taille_max_ile;
            int jn = j-taille_max_ile;
            if ((x+in >=0) && (x+in < W) && (y+jn >=0) && (y+jn < H)){
                if (((map(x+in, y+jn)).getTerre() == false)){            //s'ils sont de l'eau et pas trop loin, on tire un Bernoulli

                    int d = (int) sqrt((double) in*in + jn*jn);
                    int a = bernoulli(d/t_max);
                    bool retenu = (a==1);
                    //cout <<"retenu = " <<retenu ;
                    //si le Bernoulli est 1 ou la distance est inférieure à 5, ils deviennent de la terre
                    if (retenu){
                        (map((x+in), (y+jn))).setTerre(true);
                        for (int k=-taille_min_ile; k<taille_min_ile+1; k++){
                            for (int l=-taille_min_ile; l<taille_min_ile+1; l++){
                                if (k*k+l*l < taille_min_ile*taille_min_ile){
                                    if ((x+in+k >=0) && (x+in+k < W) && (y+jn+l >=0) && (y+jn+l < H)){
                                        (map((x+in+k), (y+jn+l))).setTerre(true);
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //on remplit les "trous" en faisant que tous les points à moins de taille_min_ile de distance d'un point qui est de la terre devienennt eux-mêmes de la terre

}

//Affiche la carte (jaune pour la terre, bleu pour l'eau, vert pour le trésor)
void affiche_carte(carte map){
    for (int i=0; i<H; i++){
        for (int j=0;j<W; j++){
            if (map(i, j).getTerre())
                fillRect(i,j,1,1,Imagine::YELLOW);
        }
    }
    for (int i=0; i<H; i++){
        for (int j=0;j<W; j++){
            if ((map(i, j)).getTresor())
                fillRect(i-(range_bateau),j-(range_bateau),2*range_bateau,2*range_bateau,Imagine::GREEN);
        }
    }
}

//Renvoie 0 avec un probabilité p
int bernoulli(double p){
    int retour = 1;
    double nb = (double)rand()/RAND_MAX;
    if ( nb < p )
    {
        retour = 0;
    }
    return retour;
}


//Génère 2 bases pour les joueurs 0 et 1
void gen_bases(){
    fillRect(0,0,w_base,w_base,Imagine::MAGENTA);
    fillRect(W-w_base,W-w_base,w_base,w_base, Imagine::MAGENTA);

}

//place un trésor sur la carte
void tresor(carte map){
    bool b = true;  //indique qu'on a pas encore placé le trésor
    while (b){
        int i = rand()%W;
        int j = rand()%H;
        IntPoint2 p = {i, j};
        if (convient_tresor(map, p)){
            (map(i, j)).setTresor(true);
            fillRect(i-(range_bateau),j-(range_bateau/2),range_bateau,range_bateau,Imagine::GREEN);
            b = false;
        }
    }
}



//renvoie true si le point p peut accueillir un trésor, c'est à dire s'il est de la terre à moins de range_bateau/2 de l'eau
bool convient_tresor(carte map, IntPoint2 p){
    int x = p.x();
    int y = p.y();
    bool d_ok = false;
    if ((map(x, y)).getTerre()){
        for (int i=0; i<range_bateau/2+1; i++){
            for (int j=0; j<range_bateau/2+1; j++){
                int in = i-range_bateau/4;
                int jn = j-range_bateau/4;
                int xn = x+in;
                int yn = y+jn;
                if ((xn >=0) && (xn < W) && (yn >=0) && (yn < H)){
                    if ((map(xn, yn)).getTerre()==false){
                        d_ok = true;
                    }
                }
            }
        }
    }
   return(d_ok);
}

