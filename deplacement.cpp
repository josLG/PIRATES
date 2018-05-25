#include "deplacement.h"


void zone_possible(bateau B){
    drawCircle(B.getx(),B.gety(),rmax,Imagine::RED,3);
    B.affiche();
}

//Fait bouger graphiquement le bateau entre deux sets de coordoonées
void droite(int x1, int y1, int x2, int y2){
    int it_x=abs(x1-x2);
    int it_y=abs(y1-y2);
    double M= std::max(it_x,it_y);
    double m=(double) (y1-y2)/(x1-x2); //coefficient directeur de la droite reliant les deux points
    double p= (double) y1-m*x1; //ordonnée à l'origine
    fillRect(x1,y1,z,z,Imagine::BLUE); //On efface la position initiale du bateau
    if (abs(it_y)>abs(it_x)){
        for (int i=1;i<abs(it_y)-1;i++){
            double xi=(double) x1+(x2-x1)*i/M;
            double yi=(double) m*xi+p;
            fillRect(xi,yi,z,z,Imagine::BLACK);
            milliSleep(30);
            fillRect(xi,yi,z,z,Imagine::BLUE);
            }
    }
    else{
        for (int i=1;i<abs(it_x)-1;i++){
            double yi=(double) y1+(y2-y1)*i/M;
            double xi=(double) (yi-p)/m;
            fillRect(xi,yi,z,z,Imagine::BLACK);
            milliSleep(30);
            fillRect(xi,yi,z,z,Imagine::BLUE);
            }
        }
    fillRect(x2,y2,z,z,Imagine::BLACK); //On laisse afficher la position finale du bateau
}

//Fait bouger formellement le bateau
void deplace_bateau(bateau &B){
    int mouse_x,mouse_y;
    do
        getMouse(mouse_x,mouse_y); //On récupère la position désirée par l'utilisateur
    while(hors_du_champs(B.getx(),B.gety(),mouse_x,mouse_y));

    droite(B.getx(),B.gety(),mouse_x-z/2,mouse_y-z/2); //Déplacement en fondu
    B.setx(mouse_x-z/2);
    B.sety(mouse_y-z/2);
}

//Renvoie True si le point cliqué est hors du champs de navigation
bool hors_du_champs(int x1, int y1, int x2, int y2){
    if (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>rmax){
        fillRect(x2,y2,z,z,Imagine::RED); //Dessine un petit carré rouge pour dire que c'est impossible d'aller là
        milliSleep(100);
        fillRect(x2,y2,z,z,Imagine::BLUE);
        return true;
    }
    return false;
}



