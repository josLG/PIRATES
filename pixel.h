#pragma once
#include <Imagine/Graphics.h>
using namespace Imagine;


class pixel {
    Imagine::Color c;
    bool terre;
    bool occupe;
    bool surbrillance;
public:
    pixel();   //constructeur par défaut
    pixel(Imagine::Color n_c, bool n_terre, bool n_occupe, bool n_surbrillance);
    bool tresor;
    Imagine::Color getColor();
    bool getTerre();
    bool getOccupe();
    bool getSurbrillance();
    void passagebateau();
    void departbateau();
    void changesurbrillance();
    void setTerre(bool b);
};
