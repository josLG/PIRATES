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
    IntPoint2* dd=gen_aleat();
    endGraphics();

 return (0);
}

