#include "pixel.h"
#include "attaque.h"
#include "bateau.h"
#include "carte.h"
#include "evenement.h"
#include "deplacement.h"



int main() {
    carte map;
    openWindow(W,H);
    affiche_carte(map);
    endGraphics();
 return (0);
}

