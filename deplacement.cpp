#include "deplacement.h"


void zone_possible(bateau B){
    fillCircle(B.getx(),B.gety(),rmax,Imagine::GREEN);
    B.affiche();
}

//Fait bouger graphiquement le bateau entre deux sets de coordoonées
void droite(int x1, int y1, int x2, int y2){
    int it_x=abs(x1-x2);
    int it_y=abs(y1-y2);
    int M= std::max(it_x,it_y);
    double m=(x1-x2)/(y1-y2); //coefficient directeur de la droite reliant les deux points
    double p= y1-m*x1; //ordonnée à l'origine
    fillRect(x1,y1,z,z,Imagine::BLUE); //On efface la position initiale du bateau
    for (int i=1;i<M-1;i++){
        double xi=x1+it_x/M*i;
        double yi=m*xi+p;
        int xii = static_cast<int>(xi);
        int yii = static_cast<int>(yi);
        fillRect(xii,yii,z,z,Imagine::BLACK);
        milliSleep(40);
        fillRect(xii,yii,z,z,Imagine::GREEN);
    }
    fillRect(x2,y2,z,z,Imagine::BLACK); //On laisse afficher la position finale du bateau
}
//Fait bouger formellement le bateau
void deplace_bateau(bateau &B){
    int mouse_x,mouse_y;
    do
        getMouse(mouse_x,mouse_y); //On récupère la position désirée par l'utilisateur
    while(hors_du_champs(B.getx(),B.gety(),mouse_x,mouse_y));

    droite(B.getx(),B.gety(),mouse_x,mouse_y); //Déplacement en fondu
    B.setx(mouse_x);
    B.sety(mouse_y);
}

//Renvoie True si le point cliqué est hors du champs de navigation
bool hors_du_champs(int x1, int y1, int x2, int y2){
    if (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>rmax){
        fillRect(x2,y2,z,z,Imagine::RED);
        milliSleep(100);
        fillRect(x2,y2,z,z,Imagine::BLUE);
        return true;
    }
    return false;
}



