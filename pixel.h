#pragma once
#include <Imagine/Graphics.h>
using namespace Imagine;
#include <iostream>
using namespace std;


class pixel {
    Imagine::Color c;
    bool terre;
    bool occupe;
    bool surbrillance;
    bool tresor;
public:
    pixel();   //constructeur par défaut
    pixel(Imagine::Color n_c, bool n_terre, bool n_occupe, bool n_surbrillance);
    Imagine::Color getColor();
    void setColor(Color n_c);
    bool getTerre();
    bool getTresor();
    bool getOccupe();
    bool getSurbrillance();
    void passagebateau();
    void departbateau();
    void changesurbrillance();
    void setTerre(bool b);
    void setTresor(bool b);
};
