#include "pixel.h"
#include "attaque.h"
#include "bateau.h"
#include "carte.h"
#include "evenement.h"
#include "deplacement.h"
#include <iostream>
using namespace std;


int main() {
    srand((unsigned int)time(0));
    carte map;
    openWindow(W,H);
    fillRect(0,0,W,H,BLUE);
    //IntPoint2* dd=gen_aleat();
    bateau boats [2];
    gen_bateau(boats);
    boats[1].affiche();
    zone_possible(boats[1]);
    deplace_bateau(boats[1]);
    boats[1].affiche();
    endGraphics();

 return (0);
}

