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
            int in = i-taille_max_ile;
            int jn = j-taille_max_ile;
            IntPoint2 q = {x+in, y+in};
            if ((x+in >=0) && (x+in < W) && (y+jn >=0) && (y+jn < H)){
                if (((map.grille[(x+in)+W*(y+jn)]).getTerre() == false)){            //s'ils sont de l'eau et pas trop loin, on tire un Bernoulli
                    int d = (int) sqrt((double) in*in + jn*jn);
                    int a = bernoulli(d/t_max);
                    //cout << " in=" << in <<" " << "jn=" << a <<" "<< " d=" << d <<" " << "d1=" << d1 <<" ";
                    bool retenu = (a==1);
                    //cout <<"retenu = " <<retenu ;
                    //si le Bernoulli est 1 ou la distance est inférieure à 5, ils deviennent de la terre
                    if (retenu){
                        (map.grille[(x+in)+W*(y+jn)]).setTerre(true);
                    }
                }
            }
            cout<<endl;
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
    int retour = 1;
    double nb = (double)rand()/RAND_MAX;
    if ( nb < p )
    {
        retour = 0;
    }
    return retour;
}


int dist_max(IntPoint2 p, IntPoint2 q){   //distance (au sens des iles) entre les points p et q
    double x1 = (double) p.x();
    double x2 = (double) q.x();
    double y1 = (double) p.y();
    double y2 = (double) q.y();
    double d1 = (x1-x2)*(x1-x2);
    double d2 = (y1-y2)*(y1-y2);
    int d = (sqrt(d1+d2));
    return(d);

}

//Génère 2 bases pour les joueurs 0 et 1
void gen_bases(){
    fillRect(1,1,w_base,w_base,Imagine::MAGENTA);
    fillRect(W-w_base,W-w_base,w_base,w_base, Imagine::MAGENTA);
}
