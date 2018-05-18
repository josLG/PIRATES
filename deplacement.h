#pragma once
#include "carte.h"
#include "bateau.h"

const int rmax=100; //la distance maximale que peut atteindre le bateau en 1 tour.

void zone_possible(bateau B);
void deplace_bateau(bateau &B);
void droite(int x1, int y1, int x2, int y2);
bool hors_du_champs(int x1, int y1, int x2, int y2);
