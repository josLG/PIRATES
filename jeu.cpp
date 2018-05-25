#include "pixel.h"
#include "attaque.h"
#include "bateau.h"
#include "carte.h"
#include "evenement.h"
#include "deplacement.h"


int main() {
    srand((unsigned int)time(0));
    //Génération de la carte
    carte map(W, H);
    openWindow(W,H);
    fillRect(0,0,W,H,BLUE);
    cout << "done1" <<endl;
    carte_gen_aleat(map);
    cout << "done2" <<endl;
    affiche_carte(map);
    cout << "done";
    //gen_bases(); //les bases de départ
    //tresor(map);    //la position initiale du trésor
    //IntPoint2* dd=gen_aleat();

    //Génération des bateaux
    bateau boats [2];
    gen_bateau(boats);
    boats[0].affiche();
    boats[1].affiche();
    zone_possible(boats[0]);
    deplace_bateau(boats[0]);
    boats[0].affiche();
    endGraphics();

 return (0);
}

