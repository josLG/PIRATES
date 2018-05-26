#include "pixel.h"

pixel::pixel(){    //constructeur par défaut
    c = Imagine::BLUE;
    terre = false;
    occupe = false;
    surbrillance = false;
}

pixel::pixel(Imagine::Color n_c, bool n_terre, bool n_occupe, bool n_surbrillance){
    c = n_c;
    terre = n_terre;
    occupe = n_occupe;
    surbrillance = n_surbrillance;
}

Imagine::Color pixel::getColor(){
    return(c);
}

bool pixel::getTerre(){    //renvoie la valeur du bool terre
    return(terre);
}


bool pixel::getOccupe(){   //renvoie la valeur du bool occupe
    return(occupe);
}

bool pixel::getSurbrillance(){ //renvoie la valeur du bool surbrillance
    return(surbrillance);
}

void pixel::setTerre(bool b){    //modifie la valeur du bool terre
    if (b)
        c=Imagine::YELLOW;
    else
        c=Imagine::BLUE;
     terre = b;
}

void pixel::passagebateau(){   //change la valeur du bool occupe pour true
    occupe = true;
}

void pixel::departbateau(){    //change la valeur du bool occupe pour false
    occupe = false;
}

void pixel::changesurbrillance(){  //change la valeur du bool surbrillance
    bool n_surbrillance = !(surbrillance);
    surbrillance = n_surbrillance;
}

bool pixel::getTresor(){    //renvoie la valeur du bool tresor
    return(tresor);
}

void pixel::setTresor(bool b){    //modifie la valeur du bool tresor
    if (b)
        c=Imagine::GREEN;
    tresor = b;
}

void pixel::setColor(Color n_c){
    c=n_c;
}
