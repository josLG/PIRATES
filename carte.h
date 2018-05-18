#include <Imagine/Graphics.h>
#include "pixel.h"

#include <cstdlib>
using namespace std ;

#include <ctime>
using namespace std ;

#include <queue>          // std::queue
using namespace std;


const int W=300;
const int H=300;
const int z=5;
const int taille_max_ile = 10;
const double t_max = (double)taille_max_ile;

struct carte{
    pixel grille[W*H];
};

void gen_aleat(IntPoint2* ile);

void affiche_carte(carte map);

IntPoint2 gen_point(int x,int y,int l);

int dist_max(IntPoint2 p, IntPoint2 q);

void carte_gen_aleat(carte &map);

void gen_ile(IntPoint2 p, carte &map);

int bernoulli(double p);
