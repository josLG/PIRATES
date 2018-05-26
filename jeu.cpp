#include "pixel.h"
#include "attaque.h"
#include "bateau.h"
#include "carte.h"
#include "evenement.h"
#include "deplacement.h"

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
//Attend un clic dans la zone JOUER
void waiting_click(int x1, int y1, int x2, int y2){
    int mouse_x, mouse_y;
    getMouse(mouse_x,mouse_y);
    while((mouse_x<x1)||(mouse_x>x2)||(mouse_y<y1)||(mouse_y>y2))
        getMouse(mouse_x,mouse_y);
}

int main() {
    srand((unsigned int)time(0));

    openWindow(W,H);
    //Génération de la carte
    carte map(W,H);

    bienvenue();
    waiting_click(250,282,443,347);
    fillRect(0,0,W,H,BLUE);
    /*carte_gen_aleat(map);
    cout << "done2" <<endl;
    affiche_carte(map);
    cout << "done";
    gen_bases(); //les bases de départ
    tresor(map);    //la position initiale du trésor
    //IntPoint2* dd=gen_aleat();*/
    /*map(20,13).setTerre(true);
    map(20,14).setTerre(true);
    map(20,15).setTerre(true);
    map(20,6).setTerre(true);
    map(20,17).setTerre(true);
    map(20,18).setTerre(true);
    map(20,19).setTerre(true);
    map(20,20).setTerre(true);
    map(20,21).setTerre(true);
    affiche_carte(map);

    //Génération des bateaux
    bateau boats [2];
    gen_bateau(boats);
    boats[0].affiche();
    boats[1].affiche();
    zone_possible(boats[0]);
    deplace_bateau(boats[0],map);
    boats[0].affiche();*/
    endGraphics();

 return (0);
}

