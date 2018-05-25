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
const int taille_max_ile = 25;
const int taille_min_ile = 5;
const double t_max = (double)taille_max_ile;
const int z=10;
const int w_base= 30;
const int range_bateau = 10;

typedef MultiArray<pixel, 2> carte;

void gen_aleat(IntPoint2* ile);

void affiche_carte(carte map);

IntPoint2 gen_point(int x,int y,int l);

void carte_gen_aleat(carte &map);

void gen_ile(IntPoint2 p, carte &map);

int bernoulli(double p);

void gen_bases();

void tresor(carte map);

bool convient_tresor(carte map, IntPoint2 p);
