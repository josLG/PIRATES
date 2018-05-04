#include "pixel.h"

pixel();   //constructeur par défaut
pixel(Imagine::Color n_c, bool n_terre, bool n_occupe, bool n_surbrillance);
Imagine::Color getColor();
bool getTerre();
bool getOccupe();
bool getSurbrillance();
void passagebateau();
void departbateau();
void changesurbrillance();
