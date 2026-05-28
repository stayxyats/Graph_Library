#include <iostream>
#include "CGraph.h"
#include "CSCouleur.h"
#include "CArc.h"
#include "CColoration.h"

using namespace std;

int main() 
{
    //creation du graphe le meme que le sujet
    CGraph<CSCouleur, CArc> GRAGraphe;
    unsigned int uiBoucle;
    for (uiBoucle = 1; uiBoucle < 9; ++uiBoucle) {
        GRAGraphe.GROAjouterSommet(uiBoucle);
    }

    GRAGraphe.GRAAjouterArete(1, 2);
    GRAGraphe.GRAAjouterArete(1, 3);
    GRAGraphe.GRAAjouterArete(1, 4);
    GRAGraphe.GRAAjouterArete(2, 5);
    GRAGraphe.GRAAjouterArete(3, 6);
    GRAGraphe.GRAAjouterArete(3, 7);
    GRAGraphe.GRAAjouterArete(4, 7);
    GRAGraphe.GRAAjouterArete(5, 6);
    GRAGraphe.GRAAjouterArete(5, 8);
    GRAGraphe.GRAAjouterArete(6, 8);
    GRAGraphe.GRAAjouterArete(7, 8);

    CColoration CCCol;
    unsigned int k = CCCol.COLColoration(GRAGraphe);
    cout << "k = " << k << endl;
}