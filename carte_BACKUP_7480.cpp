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
            if ((x+in >=0) && (x+in < W) && (y+jn >=0) && (y+jn < H)){
                if ((map(x+in,y+jn)).getTerre() == false){            //s'ils sont de l'eau et pas trop loin, on tire un Bernoulli
                    int d = (int) sqrt((double) in*in + jn*jn);
                    int a = bernoulli(d/t_max);
                    bool retenu = (a==1);
                    //cout <<"retenu = " <<retenu ;
                    //si le Bernoulli est 1 ou la distance est inférieure à 5, ils deviennent de la terre
                    if (retenu){
                        map(x+in,y+jn).setTerre(true);
                        for (int k=-taille_min_ile; k<taille_min_ile+1; k++){
                            for (int l=-taille_min_ile; l<taille_min_ile+1; l++){
                                if (k*k+l*l < taille_min_ile*taille_min_ile){
                                    cout <<"k= "<<k <<"l= " << l;
                                    map(x+in+k,y+jn+l).setTerre(true);
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



void affiche_carte(carte map){
    for (int i=0; i<H; i++){
        for (int j=0;j<W; j++){
            if (map(i,j).getColor()==YELLOW)
                fillRect(i,j,z,z,Imagine::YELLOW);
            if (map(i,j).getTerre())
                fillRect(i,j,1,1,Imagine::YELLOW);
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


int dist(IntPoint2 p, IntPoint2 q){   //distance (au sens des iles) entre les points p et q
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
            map(i,j).setTresor(true);
            fillRect(i-(range_bateau),j-(range_bateau),2*range_bateau,2*range_bateau,Imagine::GREEN);
            b = false;
        }
        cout <<"i =" <<i <<" "<<"j =" <<j <<" " <<endl;
    }
}

//renvoie true si le point p peut accueillir un trésor
bool convient_tresor(carte map, IntPoint2 p){
    int x = p.x();
    int y = p.y();
    bool d_ok = false;
    if (map(x,y).getTerre()){
        for (int i=0; i<2*range_bateau+1; i++){
            for (int j=0; j<2*range_bateau+1; j++){
                int in = i-range_bateau;
                int jn = j-range_bateau;
                int xn = x+in;
                int yn = y+jn;
                if (map(xn,yn).getTerre()==false){
                    fillRect(xn,yn,1,1,Imagine::MAGENTA);
                    cout<<"xn =" <<xn <<" "<<"yn =" <<yn <<" " <<endl;
                    d_ok = true;
                }
            }
        }
    }
    cout <<"x =" <<x <<" "<<"y =" <<y <<" " <<endl;
    return(d_ok);
}
