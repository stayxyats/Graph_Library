#include "CSommet.h"
#include <iostream>
#include <algorithm>
using namespace std;

CSommet::CSommet(unsigned int uiNumero) {
	uiSOMNumSommet = uiNumero;
}

void CSommet::SOMAjouterArcD(CArc* pARC) {
	// ajouté a la fin du vector
	lSOMArcD.push_back(pARC);
}

void CSommet::SOMAjouterArcA(CArc* pARC) {
	lSOMArcA.push_back(pARC);
}

void CSommet::SOMSupprimerArcD(CArc* pARC) {
	lSOMArcD.erase(remove(lSOMArcD.begin(), lSOMArcD.end(), pARC), lSOMArcD.end());
}

void CSommet::SOMSupprimerArcA(CArc* pARC) {
	lSOMArcA.erase(remove(lSOMArcA.begin(), lSOMArcA.end(), pARC), lSOMArcA.end());
}

void CSommet::SOMModifierNumSommet(unsigned int uiNouveau) {
	uiSOMNumSommet = uiNouveau;
}

void CSommet::SOMAfficher() const {
	cout << "Sommet " << uiSOMNumSommet << endl;
	cout << "  Arcs partants : " << endl;
	//calcul taille du vector
	unsigned int uiTaille = lSOMArcD.size();
	unsigned int uiBoucle = 0;
	for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
		lSOMArcD[uiBoucle]->ARCAfficher();
	}
	cout << "  Arcs arrivants : " << endl;
	uiTaille = lSOMArcA.size();
	for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
		lSOMArcA[uiBoucle]->ARCAfficher();
	}
}