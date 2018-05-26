#pragma once
#include <Imagine/Graphics.h>
#include "pixel.h"

const int W=500;
const int H=500;
const int z=10;
const int w_base= 30;

typedef MultiArray<pixel,2> carte;

IntPoint2* gen_aleat();
void affiche_carte(carte map);
IntPoint2 gen_point(int x,int y,int l);
void gen_bases();
