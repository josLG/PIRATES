#pragma once
#include <Imagine/Graphics.h>
#include "pixel.h"
#include <math.h>

#include <cstdlib>
using namespace std ;

#include <ctime>
using namespace std ;

#include <queue>          // std::queue
using namespace std;


const int W=300;
const int H=300;
const int taille_max_ile = 30;
const double t_max = (double)taille_max_ile;
const int z=10;
const int w_base= 30;

struct carte{
    pixel grille[W*H];
};

void gen_aleat(IntPoint2* ile);

void affiche_carte(carte map);

IntPoint2 gen_point(int x,int y,int l);

int dist_max(IntPoint2 p, IntPoint2 q);

void carte_gen_aleat(carte &map);

void gen_ile(IntPoint2 p, carte &map);

int bernoulli(double p);

void gen_bases();
