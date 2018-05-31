#include "deplacement.h"
#include <cmath>



//Renvoie un tableau des points constituant la droite entre deux points donnés.
//Les coordonnées x occupent la premiere moitie du tableau. Les y, la seconde moitie.
vector<double> tab_droite(int x1, int y1, int x2, int y2){
    int it_x=abs(x1-x2);
    int it_y=abs(y1-y2);
    int M= std::max(it_x,it_y);

    int taille_tab=2*M;
    vector<double> tab (2*M,0);

    double m=(double) (y1-y2)/(x1-x2);
    //coefficient directeur de la droite reliant les deux points
    double p= (double) y1-m*x1; //ordonnée à l'origine

    if (abs(it_y)>abs(it_x)){
        for (int i=0;i<it_y;i++){
            double yi= (double) y1+(y2-y1)*i/it_y;
            double xi=(double) (yi-p)/m;
            tab[i]=xi;
            tab[M+i]=yi;
            }
    }
    else{
        for (int i=0;i<it_x;i++){
            double xi= (double) x1+(x2-x1)*i/it_x;
            double yi=(double) m*xi+p;
            tab[i]=xi;
            tab[M+i]=yi;
            }
        }
    return tab;
}


//Fait bouger formellement le bateau
//Modification de ses coordonnees de position
void deplace_bateau(bateau &B, carte map){
    int mouse_x,mouse_y;
    getMouse(mouse_x,mouse_y);//On récupère la position désirée par l'utilisateur
    while(no_move(B.getx(),B.gety(),mouse_x-z/2,mouse_y-z/2,map))
         getMouse(mouse_x,mouse_y);

    move_graphique(B.getx(),B.gety(),mouse_x,mouse_y);
    B.setx(mouse_x);
    B.sety(mouse_y);

}

///Fonctions de test intervenant lors du clic de destination

//Renvoie True si le point cliqué est hors du champs de navigation
bool hors_du_champs(int x1, int y1, int x2, int y2,carte map){
    if (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>rmax){
        fillCircle(x2,y2,1,Imagine::RED); //Dessine un petit carré rouge pour dire que c'est impossible d'aller là
        milliSleep(100);
        fillCircle(x2,y2,1,(map(x2,y2)).getColor());
        return true;
    }
    return false;
}

//Renvoie True si il y a une case Terre sur l'itinéraire de droite prévue
bool route_impossible(carte map, vector<double> tab){ //taille_tab est la taille de tab, de 1 à taille/2 c'est les x, et après c'est y
    for (int k=0; k<tab.size()/2; k++){
        int L=tab.size();
        int i=(int) floor(tab[k]);
        int j=(int) floor(tab[L/2+k]);
        if (map(i,j).getTerre()){
            fillCircle(tab[L/2-1],tab[L-1],1,Imagine::RED); //Dessine un petit carré rouge pour dire que c'est impossible d'aller là
            milliSleep(100);
            fillCircle(tab[L/2-1],tab[L-1],1,(map(tab[L/2-1],tab[L-1]).getColor()));
            return true; // Itinéraire non navigable
        }
    }
    return false; // itinéraire navigable
}

//Rassemble la fonction hors_du_champ et route_impossible
//Renvoie True si le déplacement ne se fait pas.
bool no_move(int x1, int y1 ,int x2, int y2,carte map){
    if (hors_du_champs(x1,y1,x2,y2,map))
        return true;
    vector<double> tab=tab_droite(x1,y1,x2,y2);
    if (route_impossible(map,tab))
        return true;
    return false;
}


///Fonctions graphiques

//Dessine un cercle rouge pour la zone atteignable par le bateau
void zone_possible(bateau B){
    drawCircle(B.getx(),B.gety(),rmax,Imagine::RED,3);
    B.affiche();
}

//Simule un déplacement graphique continu du bateau
void move_graphique(int x1, int y1, int x2, int y2){
    vector<double> trajet=tab_droite(x1,y1,x2,y2);
    fillRect(x1,y1,z,z,Imagine::BLUE); //On efface la position initiale du bateau
    for (int i=0; i<trajet.size()/2;i++){
        fillRect(trajet[i],trajet[trajet.size()/2+i],z,z,Imagine::BLACK);
        milliSleep(10);
        fillRect(trajet[i],trajet[trajet.size()/2+i],z,z,Imagine::BLUE);//On laisse afficher la position finale du bateau
    }
}
