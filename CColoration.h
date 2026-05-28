#ifndef CCOLORATION_H
#define CCOLORATION_H

#include "CSCouleur.h"
#include "CGraph.h"

#include <vector>

class CColoration
{
public:
	// Méthodes
	/********************************
	* COLColoration
	*********************************
	* Entrée : graphe non orientée
	* Nécessite : un graphe non orienté
	* Sortie : un unsigned int k correspondant au nombre de couleurs utilisée
	* Entraine : rien
	*********************************/
	unsigned int COLColoration(const CGraph<CSCouleur, CArc>& GRAGraph);
	
	/********************************
	* COLExisteColoration
	*********************************
	* Entrée : un graphe non orientée et unsigned int uik
	* Nécessite : un graphe non orienté
	* Sortie : un booleen vrai si une coloration de k couleurs est possible, faux sinon
	* Entraine : rien
	*********************************/
	bool COLExisteColoration(unsigned int uik, const CGraph<CSCouleur, CArc>& GRAGraph);
	
	/********************************
	* COLAllColored
	*********************************
	* Entrée : un graphe non orientée 
	* Nécessite : un graphe non orienté
	* Sortie : un booleen vrai si tous les sommets sont colorés, faux sinon
	* Entraine : rien
	*********************************/
	bool COLAllColored(const CGraph<CSCouleur, CArc>& GRAgraphe);

	/********************************
	* COLListeCouleurs
	*********************************
	* Entrée : un CSCCouleur
	* Nécessite : un CSCouleur
	* Sortie : une liste de couleurs
	* Entraine : rien
	*********************************/
	vector<unsigned int> COLListeCouleurs(const CSCouleur* SCOsommet, const CGraph<CSCouleur, CArc>& GRAgraphe);

	/********************************
	* COLDecolorer
	*********************************
	* Entrée : un graphe non orienté
	* Nécessite : un graphe non orienté
	* Sortie : rien
	* Entraine : décoloration du graphe
	*********************************/
	void COLDecolorer(const CGraph<CSCouleur, CArc>& GRAgraphe);
};

#endif