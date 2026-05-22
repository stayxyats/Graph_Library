#ifndef CCOLORATION_H
#define CCOLORATION_H

#include "CSCouleur.h"
#include "CGraph.h"

#include <vector>
using namespace std;

class CColoration
{
public:
	// Méthodes
	/********************************
	* COLColoration
	*********************************
	* Entrée : graphe non-orientée
	* Nécessite : un graphe non orienté
	* Sortie : un unsigned int k correspondant au nombre de couleurs utilisées
	* Entraine : rien
	*********************************/
	unsigned int COLColoration(const CGraph<CSCouleur, CArc>& GRAGraph);
	
	/********************************
	* COLExisteColoration
	*********************************
	* Entrée : graphe non-orientée et unsigned int
	* Nécessite : un graphe non orienté
	* Sortie : un booleen vrai si une coloration de k couleurs est possible, faux sinon
	* Entraine : rien
	*********************************/
	bool COLExisteColoration(unsigned int uik, const CGraph<CSCouleur, CArc>& GRAGraph);
	
	/********************************
	* COLAllColored
	*********************************
	* Entrée : graphe non-orientée 
	* Nécessite : un graphe non orienté
	* Sortie : un booleen vrai si tous les sommets sont colorés, faux sinon
	* Entraine : rien
	*********************************/
	bool COLAllColored(const CGraph<CSCouleur, CArc>& GRAGraph);

};

#endif