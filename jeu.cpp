#include "pixel.h"
#include "attaque.h"
#include "bateau.h"
#include "carte.h"
#include "evenement.h"
#include "deplacement.h"


int main() {
    srand((unsigned int)time(0));
    //Génération de la carte
    carte map;
    openWindow(W,H);
    fillRect(0,0,W,H,BLUE); //les océans
    gen_bases(); //les bases de départ
    //IntPoint2* dd=gen_aleat();

    //Génération des bateaux
    bateau boats [2];
    gen_bateau(boats);
    boats[0].affiche();
    boats[1].affiche();
   // zone_possible(boats[0]);
    //deplace_bateau(boats[0]);
    //boats[0].affiche();
    endGraphics();

 return (0);
}

