#include "pixel.h"
#include "attaque.h"
#include "bateau.h"
#include "carte.h"
#include "evenement.h"
#include "deplacement.h"

const int pasdaff = 50;

//Affiche l'image d'accueil du jeu
void bienvenue(){
    byte* r=new byte[500*500];
    byte* g=new byte[500*500];
    byte* b=new byte[500*500];
    int w_bienvenue, h_bienvenue;
    loadColorImage(srcPath("bienvenue.bmp"),r,g,b,w_bienvenue,h_bienvenue);
    putColorImage(0,0,r,g,b,w_bienvenue,h_bienvenue);
    delete r;
    delete g;
    delete b;
}

//Affiche le menu de choix du jeu
void menu_choix(){
    byte* r=new byte[500*100];
    byte* g=new byte[500*100];
    byte* b=new byte[500*100];
    int w_bienvenue, h_bienvenue;
    loadColorImage(srcPath("Choix.bmp"),r,g,b,w_bienvenue,h_bienvenue);
    putColorImage(0,500,r,g,b,w_bienvenue,h_bienvenue);
    delete r;
    delete g;
    delete b;
}


//Attend un clic dans la zone JOUER
void waiting_click(int x1, int y1, int x2, int y2){
    int mouse_x, mouse_y;
    getMouse(mouse_x,mouse_y);
    while((mouse_x<x1)||(mouse_x>x2)||(mouse_y<y1)||(mouse_y>y2))
        getMouse(mouse_x,mouse_y);
}

//Attend un clic dans une des deux zones de choix
int choix(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int mouse_x, mouse_y;
    getMouse(mouse_x,mouse_y);
    while((mouse_x<x1)||(mouse_x>x2)||(mouse_y<y1)||(mouse_y>y2)&&(mouse_x<x3)||(mouse_x>x4)||(mouse_y<y3)||(mouse_y>y4)){
        getMouse(mouse_x,mouse_y);
    }
    if ((mouse_x>=x1)||(mouse_x<=x2)||(mouse_y>=y1)||(mouse_y<=y2)){
        return(0);
    }
    if ((mouse_x>=x3)||(mouse_x<=x4)||(mouse_y>=y3)||(mouse_y<=y4)){
        return(1);
    }
}


int main()
{
    srand((unsigned int)time(0));
    bool partiefinie = false;

    Window W_MAIN=openWindow(W,H+100);

    //Génération de la carte
    carte map(W,H);

    bienvenue();
    waiting_click(250,282,443,347);
    fillRect(0,0,W,H,BLUE);
    carte_gen_aleat(map);
    affiche_carte(map);
    menu_choix();
    int c = choix(17, 500+16, 221, 500+79, 276, 500+16, 481, 500+79);
    cout <<c;
    gen_bases(); //les bases de départ
    tresor(map);    //la position initiale du trésor*/

    //Génération des bateaux
    bateau boats [2];
    gen_bateau(boats);
//    boats[0].affiche();
//    boats[1].affiche();
//    zone_possible(boats[0]);
//    deplace_bateau(boats[0],map);
//    boats[0].affiche();
    //bool k = attaque(boats[0],boats[1],map,W_MAIN);

    int tour = 0;

    while (partiefinie==false) //si la partie n'est pas finie, un nouveau tour commence
    {
        fillRect(0,0,W,H,BLUE);
        affiche_carte(map);
        boats[0].affiche();
        boats[1].affiche();
        bool k = false;
        int c = choix(17, 500+16, 221, 500+79, 276, 500+16, 481, 500+79);
        if (c=0){
            zone_possible(boats[tour]);
            deplace_bateau(boats[tour],map);
            boats[tour].affiche();
        }
        if (c=1){
            k = attaque(boats[tour], boats[(tour+1)%2], map, W_MAIN);
        }


        tour = (tour+1)%2;
    }
    endGraphics();

    return 0;
}

