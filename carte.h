#pragma once;
#include <Imagine/Graphics.h>
#include "pixel.h"

const int W=500;
const int H=500;
const int z=10;

struct carte{
    pixel grille[W*H];
};

IntPoint2* gen_aleat();
void affiche_carte(carte map);
IntPoint2 gen_point(int x,int y,int l);
