#pragma once
#include "carte.h"
#include "bateau.h"

const int rmax=30; //la distance maximale que peut atteindre le bateau en 1 tour.

void zone_possible(bateau B);
void deplace_bateau(bateau &B);
