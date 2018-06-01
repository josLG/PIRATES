#include "carte.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

<<<<<<< Updated upstream
IntPoint2* gen_aleat(){
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
=======
carte gen_aleat(){
    carte map;
    return map;
>>>>>>> Stashed changes
}


void affiche_carte(carte map){
    for (int i=0; i<H; i++){
        for (int j=0;j<W; j++){
            if (map.grille[i].getColor()==YELLOW){
                fillRect(i,j,z,z,Imagine::YELLOW);
            }
        }
    }
}

<<<<<<< Updated upstream
//Renvoie les coordonnées d'un point aléatoirement placé dans un carré de côté l dont le coin sup gauche est en x,y
IntPoint2 gen_point(int x,int y,int l){
    int nb_x=x+rand()%l;
    int nb_y=y+rand()%l;
    IntPoint2 p={nb_x,nb_y};
    return p;
}

=======

void gen_ile(IntPoint2 p, carte map){

    stack<IntPoint2> file;
    file.push(p);

    int a = gen_ile_rec(file, p, map);
}

int gen_ile_rec(stack<IntPoint2> file, IntPoint2 p, carte map){
    //si la file n'est pas vide
    if (file.empty()) {
        return(0);
    }
    else {
        //on prend le point en haut de la pile
        IntPoint2 q = file.top();
        file.pop();
        int x = q.x();
        int y = q.y();
        //on définit qu'il est de la terre
        (map.grille[x+W*y]).setTerre(true);
        //on regarde ses voisins
        IntPoint2 v1 = {x-1, y};
        IntPoint2 v2 = {x, y-1};
        IntPoint2 v4 = {x+1, y};
        IntPoint2 v3 = {x, y+1};
        IntPoint2 listevoisins[4] = {v1, v2, v3, v4};
        for(int i=0; i<4; i++){
            IntPoint2 v = listevoisins[i];
            if (((map.grille[x+W*y]).getTerre == false) & (dist_max(v, p)<taille_max_ile)){            //s'ils sont de l'eau et pas trop loin, on tire un Bernoulli
                double d = (double)(dist_max(v, p));
                bool retenu = (bernoulli(d/t_max)==1);
                //si le Bernoulli est 1, ils vont dans la file
                if (retenu){
                    file.push(v);
                }
                //sinon on passe au voisin suivant
            }
        }
        return(gen_ile_rec(file, p, map));
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
    double d1 = abs(p.x() - q.x());
    double d2 = abs(p.y() - q.y());
    if (d1<d2){
        return(d2);
    }
    else{
        return(d1);
    }
}
>>>>>>> Stashed changes
