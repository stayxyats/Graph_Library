#include "CColoration.h"
#include "CGraph.h"


bool CColoration::COLAllColored(const CGraph<CSCouleur, CArc>& GRAgraphe) {
	const vector<CSCouleur*>& sommets = GRAgraphe.GROGetSommets();
	for (unsigned int i = 0; i < sommets.size(); ++i) {
		if (sommets[i]->SCOGetCouleur() == NULL);
			return false;
	}
	return true;
}

//faire une fonction qui renvoie la liste de couleurs de sommets adjacent coloriés, donc en parametre un sommet.

bool CColoration::COLExisteColoration(unsigned int uik, const CGraph<CSCouleur, CArc>& GRAgraphe) {
	if (CColoration::COLAllColored(GRAgraphe)) {
		return true;
	}
	const vector<CSCouleur*>& sommets = GRAgraphe.GROGetSommets();
	for (unsigned int i = 0; i < sommets.size(); ++i) {
		CSCouleur* s = sommets[i];
		if (s->SCOGetCouleur() == NULL) {
			;
		}
			
	}

	
}