#include <Imagine/Graphics.h>
#include "pixel.h"

const int W=100;
const int H=100;
const int z=4;

struct carte{
    pixel grille[W*H];
};

carte gen_aleat();
void affiche_carte(carte map);
