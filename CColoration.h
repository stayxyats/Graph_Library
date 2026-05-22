#ifndef CCOLORATION_H
#define CCOLORATION_H

#include "CSCouleur.h"
#include "CGraph.h"

#include <vector>
using namespace std;

class CSommet
{
public:
	// Méthodes
	/********************************
	* COLExisteColoration
	*********************************
	* Entrée : graphe non-orientée et unsigned int
	* Nécessite : un graphe non orienter
	* Sortie : un booleen vrai si une coloration de k couleurs est possible, faux sinon
	* Entraine : rien
	*********************************/
	bool COLExisteColoration(unsigned int uik, const CGraph<CSCouleur, CArc>&);
};

#endif