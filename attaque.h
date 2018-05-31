#pragma once
#include "deplacement.h"
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

const int w_attaque= 800;
const int h_attaque=500;

const int visee=200;
const int lim_temps=1500;
bool attaque(bateau atq, bateau cible, carte map, Window W);
double dist_interbateaux(bateau atq, bateau cible);
IntPoint2 pos_cible(bateau atq, bateau cible);
bool shoot_fail(carte map, vector<double> tab, IntPoint2 p_cible);
void attaque_success();
void attaque_failure();
double dist_interpoints(int x1, int y1, int x2, int y2);
bool mauvais_clic(IntPoint2 p, double dist_carte);
void debut_attaque();
void wait_any_clic();
void carte_attaque();
