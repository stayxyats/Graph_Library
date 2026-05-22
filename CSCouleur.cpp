#include "CSommet.h"
#include "CSCouleur.h"
#include <iostream>
#include <algorithm>


void CSCouleur::SCOAjouterCouleur(unsigned int uiC) {
	uiSCOcouleur = uiC;
}

unsigned int CSCouleur::SCOGetCouleur() const{
	return uiSCOcouleur;
}

