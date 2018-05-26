#pragma once
#include "deplacement.h"
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

const int w_attaque= 800;
const int h_attaque=500;

const int visee=200;
const int lim_temps=1200;
bool attaque(bateau atq, bateau cible, carte map);
double dist_interbateaux(bateau atq, bateau cible);
IntPoint2 pos_cible(bateau atq, bateau cible);
bool shoot_fail(carte map, vector<double> tab, IntPoint2 p_cible);
