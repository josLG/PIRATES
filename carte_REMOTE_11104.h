#include <Imagine/Graphics.h>
#include "pixel.h"

#include <cstdlib>
using namespace std ;

#include <ctime>
using namespace std ;

#include <stack>
using namespace std;


const int W=300;
const int H=300;
const int z=5;
const int taille_max_ile = 20;
const double t_max = (double)taille_max_ile;

struct carte{
    pixel grille[W*H];
};

carte gen_aleat();
void affiche_carte(carte map);

int dist_max(IntPoint2 p, IntPoint2 q);

void gen_ile_rec( stack<IntPoint2> file, IntPoint2 p);

int bernoulli(double p);
