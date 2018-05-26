#include "attaque.h"

//Renvoie True si l'attaquant a réussi son attaque
bool attaque(bateau atq, bateau cible, carte map, Window W){
    //Ouverture de la fenetre ou se joue l'attaque
    Window W_ATT= openWindow(w_attaque,h_attaque,"A l'abordage");
    setActiveWindow(W_ATT);
    fillRect(0,0,w_attaque,h_attaque,BLUE);

    //Position de l'attaquant en haut de la fenetre
    IntPoint2 p_atq={w_attaque/2,0};
    fillRect(p_atq,z,z,BLACK);
    //Position de la cible aléatoirement sur un cercle (dont le rayon
    //dépend de la distance de l'attaquant à la cible
    IntPoint2 p_cible=pos_cible(atq,cible);
    //temps d'attente pour faire apparaitre le second bateau
    int attente=rand()%5000;
    milliSleep(attente);

    //Affichage du bateau adverse
    fillRect(p_cible,z,z,BLACK);
    double dist=dist_interbateaux(atq,cible);
    drawCircle(p_atq,dist/2+visee,RED);
    auto t1 = Clock::now();
    //L'attaquant calibre son tir et est chronométré
    IntPoint2 p_mouse;
    getMouse(p_mouse);
    auto t2 = Clock::now();
    drawLine(p_atq,p_mouse,MAGENTA); //Tracé de la trajectoire du tir
    milliSleep(2000);

    //Temps pris par le joueur pour tirer
    int temps=std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    vector<double> tir=tab_droite(p_atq.x(),p_atq.y(),p_mouse.x(),p_mouse.y());

    //Si le joueur a pris trop de temps pour tirer ou si il a visé à côté ...
    if (((temps>lim_temps))||(shoot_fail(map,tir,p_cible))){
        fillRect(0,0,w_attaque,h_attaque,WHITE);  //c'est la défaite, je prépare une image pour ça
        milliSleep(1000);
        //endGraphics();
        closeWindow(W_ATT);
        return false;
    }

    fillRect(0,0,w_attaque,h_attaque,RED); //c'est la victoire, je prépare une image pour ça
    return true;
}

//Renvoie true si la droite entre le clic et l'attaquant ne passe pas par le bateau adverse
bool shoot_fail(carte map, vector<double> tab, IntPoint2 p_cible){ //taille_tab est la taille de tab, de 1 à taille/2 c'est les x, et après c'est y
    for (int k=0; k<tab.size()/2; k++){
        int L=tab.size();
        int i=(int) floor(tab[k]);
        int j=(int) floor(tab[L/2+k]);
        if ((p_cible.x()+z>=i)&&(i>=p_cible.x())&&(p_cible.y()+z>=j)&&(j>=p_cible.y())){
            return false; // Le tir a bien touché le navire adverse
        }
    }
    return true; // Le tir est effectivement raté
}

//Calcule la distance entre deux bateaux
double dist_interbateaux(bateau atq, bateau cible){
    int dist_x = atq.getx()-cible.getx();
    int dist_y = atq.gety()-cible.gety();
    double dist=sqrt(dist_x*dist_x+dist_y*dist_y);
    return dist;
}

//Renvoie la position du bateau cible sur la nouvelle carte;
IntPoint2 pos_cible(bateau atq, bateau cible){

    double dist=dist_interbateaux(atq,cible);
    int theta=rand()%181;
    double theta_rad=(double) theta*M_PI/180;
    double pos_cible_x=(double)w_attaque/2-dist/2*cos(theta_rad);
    double pos_cible_y=(double) dist/2*sin(theta_rad);
    IntPoint2 pos={(int)floor(pos_cible_x),(int) floor(pos_cible_y)};
    return pos;
}

//Partie graphique
