#include "pixel.h"
#include "attaque.h"
#include "bateau.h"
#include "carte.h"
#include "evenement.h"
#include "deplacement.h"


//Affiche l'image d'accueil du jeu
void bienvenue(){
    Image<AlphaColor> Ib;
    load(Ib,srcPath("bienvenue.png"));
    display(Ib,0,0);
}


//Affiche le menu de choix du jeu
void menu_choix(){
    byte* r=new byte[500*100];
    byte* g=new byte[500*100];
    byte* b=new byte[500*100];
    int w_c, h_c;
    loadColorImage(srcPath("Choix.bmp"),r,g,b,w_c,h_c);
    putColorImage(0,500,r,g,b,w_c,h_c);
    delete r;
    delete g;
    delete b;
}

//Affiche le message de capture du trésor
void capture_tresor(){
    byte* r=new byte[500*100];
    byte* g=new byte[500*100];
    byte* b=new byte[500*100];
    int w_tres, h_tres;
    loadColorImage(srcPath("tresor.bmp"),r,g,b,w_tres,h_tres);
    putColorImage(0,500,r,g,b,w_tres,h_tres);
    delete r;
    delete g;
    delete b;
}

//Affiche le message de victoire du joueur 1 s'il a gagné
void victoire_j1(bateau boat, bool &partiefinie){
    if (boat.getTresor() && (boat.getx()<w_base) && (boat.gety() < w_base)){
        byte* r=new byte[500*600];
        byte* g=new byte[500*600];
        byte* b=new byte[500*600];
        int w_j1, h_j1;
        loadColorImage(srcPath("j1.bmp"),r,g,b,w_j1,h_j1);
        putColorImage(0,0,r,g,b,w_j1,h_j1);
        milliSleep(2000);
        delete r;
        delete g;
        delete b;
        partiefinie=true;
    }
}

//Affiche le message de victoire du joueur 2 s'il a gagné
void victoire_j2(bateau boat, bool &partiefinie){
    if (boat.getTresor() && (boat.getx()> W-w_base) && (boat.gety() > W-w_base)){
        byte* r=new byte[500*600];
        byte* g=new byte[500*600];
        byte* b=new byte[500*600];
        int w_j2, h_j2;
        loadColorImage(srcPath("j2.bmp"),r,g,b,w_j2,h_j2);
        putColorImage(0,0,r,g,b,w_j2,h_j2);
        milliSleep(2000);
        delete r;
        delete g;
        delete b;
        partiefinie=true;
    }
}

//Attend un clic dans la zone JOUER
void waiting_click(int x1, int y1, int x2, int y2){
    int mouse_x, mouse_y;
    getMouse(mouse_x,mouse_y);
    while((mouse_x<x1)||(mouse_x>x2)||(mouse_y<y1)||(mouse_y>y2))
        getMouse(mouse_x,mouse_y);
}

//Attend un clic dans une des deux zones de choix
int choix(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int mouse_x, mouse_y;
    getMouse(mouse_x,mouse_y);
    while(((mouse_x<x1)||(mouse_x>x2)||(mouse_y<y1)||(mouse_y>y2))&&((mouse_x<x3)||(mouse_x>x4)||(mouse_y<y3)||(mouse_y>y4))){
        getMouse(mouse_x,mouse_y);
    }
    if ((mouse_x>=x1)&&(mouse_x<=x2)&&(mouse_y>=y1)&&(mouse_y<=y2)){
        return(0);
    }
    if ((mouse_x>=x3)&&(mouse_x<=x4)&&(mouse_y>=y3)&&(mouse_y<=y4)){
        return(1);
    }
}

//renvoie true si le bateau est à portée du trésor
bool atteint_tresor(bateau boat, IntPoint2 t){
    int xb = boat.getx();
    int yb = boat.gety();
    int xt = t.x();
    int yt = t.y();
    if (((xb-xt)*(xb-xt)+(yb-yt)*(yb-yt))<= 16*range_bateau){
        return(true);
    }
    else
        return(false);

}

int main()
{
    srand((unsigned int)time(0));
    bool partiefinie = false;

    Window W_MAIN=openWindow(W,H+100);

    //Génération de la carte
    carte map(W,H);

    bienvenue();
    waiting_click(250,282,443,347);
    fillRect(0,0,W,H,BLUE);
    carte_gen_aleat(map);
    affiche_carte(map);
    menu_choix();
    capture_tresor();
    gen_bases(); //les bases de départ
    tresor(map);    //la position initiale du trésor*/

    IntPoint2 t;
    for (int i=0; i<H; i++){
        for (int j=0;j<W; j++){
            if ((map(i, j)).getTresor()){
                t = {i, j};
            }
        }
    }

    //Génération des bateaux
    bateau boats [2];
    gen_bateau(boats);
    boats[0].affiche(0);
    boats[1].affiche(0);

    int tour = 0;

    while (partiefinie==false) //si la partie n'est pas finie, un nouveau tour commence
    {
        setActiveWindow(W_MAIN);
        menu_choix();
        fillRect(0,0,W,H,BLUE);
        affiche_carte(map);
        gen_bases();
        boats[0].affiche(0);
        boats[1].affiche(1);
        bool k = false;
        int c = choix(17, 500+16, 221, 500+79, 276, 500+16, 481, 500+79);
        if (c==0){
            zone_possible(boats[tour], tour);
            menu_choix();
            deplace_bateau(boats[tour],map, tour);
            boats[tour].affiche(tour);
        }
        if (c==1){
            k = attaque(boats[tour], boats[(tour+1)%2], map, W_MAIN);
        }
        setActiveWindow(W_MAIN);

        if (atteint_tresor(boats[tour], t)){
            boats[tour].capture_tresor(true);
            (map(t.x(), t.y())).setTresor(false);
            capture_tresor();
            milliSleep(2000);
        }
        if (k){
            if (boats[(tour+1)%2].getTresor()){
                boats[(tour+1)%2].capture_tresor(false);
                tresor(map);
            }
            int nx = w_base/2;
            int ny = w_base/2;
            if (tour = 0){
                nx = W-w_base/2;
                ny = W-w_base/2;
            }
            boats[(tour+1)%2].setx(nx);
            boats[(tour+1)%2].sety(ny);
            fillRect(0,0,W,H,BLUE);
            affiche_carte(map);
            gen_bases();
            boats[0].affiche(0);
            boats[1].affiche(1);
        }
        if (tour==0){
            victoire_j1(boats[0], partiefinie);
        }
        if (tour==1){
            victoire_j2(boats[1], partiefinie);
        }

        tour = (tour+1)%2;

    }
    endGraphics();

    return 0;
}

