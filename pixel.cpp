#include "pixel.h"

pixel::pixel(){    //constructeur par défaut
    c = BLUE;
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
