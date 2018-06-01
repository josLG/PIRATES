#pragma once
#include "carte.h"
#include "bateau.h"
#include <algorithm>
#include <vector>

const int rmax=100-z; //la distance maximale que peut atteindre le bateau en 1 tour.

void zone_possible(bateau B, int tour);
void deplace_bateau(bateau &B, carte map, int tour);
void move_graphique(int x1, int y1, int x2, int y2, int tour);
bool hors_du_champs(int x1, int y1, int x2, int y2, carte map);
vector<double> tab_droite(int x1, int y1, int x2, int y2);
bool route_impossible(carte map, vector<double> tab);
bool no_move(int x1, int y1 ,int x2, int y2,carte map);
