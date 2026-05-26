#include <iostream>
#include "CGraph.h"
#include "CSCouleur.h"
#include "CArc.h"
#include "CColoration.h"

using namespace std;

int main() // Test triangle
{
    CGraph<CSCouleur, CArc> g;
    g.GROAjouterSommet(1);
    g.GROAjouterSommet(2);
    g.GROAjouterSommet(3);
    g.GROAjouterSommet(4);
    g.GRAAjouterArete(1, 2);
    g.GRAAjouterArete(2, 3);
    g.GRAAjouterArete(3, 4);
    g.GRAAjouterArete(4, 1);

    CColoration col;
    unsigned int k = col.COLColoration(g);
    cout << "C4 k = " << k << endl;
}