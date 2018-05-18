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
    cout << "done1" <<endl;
    IntPoint2 p = {100, 100};
    carte_gen_aleat(map);
    //gen_ile(p, map);
    cout << "done2" <<endl;
    affiche_carte(map);
    cout << "done";
    endGraphics();

 return (0);
}

