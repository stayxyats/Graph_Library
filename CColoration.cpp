#include "CColoration.h"
#include "CGraph.h"
#include <set>


bool CColoration::COLAllColored(const CGraph<CSCouleur, CArc>& GRAgraphe) {
	unsigned int uiBoucle;
	const vector<CSCouleur*>& lCSCSommets = GRAgraphe.GROGetSommets();
	unsigned int uiTaille = lCSCSommets.size();
	for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle) {
		if (lCSCSommets[uiBoucle]->SCOGetCouleur() == 0)
			return false;
	}
	return true;
}



vector<unsigned int> CColoration::COLListeCouleurs(const CSCouleur* SCOsommet, const CGraph<CSCouleur, CArc>& GRAgraphe) {
    vector<unsigned int> luiCouleurs;
	// on recupere les arcs partant du sommet et tous les sommets du graphe
    const vector<CArc*>& lCArcs = SCOsommet->SOMGetArcD();
	const vector<CSCouleur*>& lCSCSommets = GRAgraphe.GROGetSommets();

	unsigned int uiBoucle;
	unsigned int uiTaille = lCArcs.size();
	// on parcourt les arcs du sommet
    for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle){
        unsigned int uiNumVoisin = lCArcs[uiBoucle]->ARCGetSomA();
		unsigned int uiTailleSommets = lCSCSommets.size();
		unsigned int uiBoucle2;
        for (uiBoucle2 = 0; uiBoucle2 < uiTailleSommets; ++uiBoucle2) {
            if (lCSCSommets[uiBoucle2]->SOMGetNumSommet() == uiNumVoisin) {
				// on ajoute la couleur du voisin si le sommet est deja colorie
                if (lCSCSommets[uiBoucle2]->SCOGetCouleur() != 0) {
					luiCouleurs.push_back(lCSCSommets[uiBoucle2]->SCOGetCouleur());
                }
                break;
            }
        }
    }
    return luiCouleurs;
}


bool CColoration::COLExisteColoration(unsigned int uik, const CGraph<CSCouleur, CArc>& GRAgraphe) {
	// on ragarde si le graphe est deja tout colorié
	if (COLAllColored(GRAgraphe)) {
		return true;
	}
	const vector<CSCouleur*>& lCSCSommets = GRAgraphe.GROGetSommets();
	unsigned int uiBoucle;
	unsigned int uiTaille = lCSCSommets.size();
	for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle) {
		CSCouleur* CSCSom = lCSCSommets[uiBoucle];
		// on recherche un sommet pas colorié
		if (CSCSom->SCOGetCouleur() == 0) {
			vector<unsigned int>Cs = COLListeCouleurs(CSCSom, GRAgraphe);

			//on enleve les doublons, pour un sommet qui a 2 voisins avec la meme couleur par exemple
			std::set<unsigned> CsClean(Cs.begin(), Cs.end());
			if (CsClean.size() == uik) {
				return false;
			}
			unsigned int uiBoucle2;
			for (uiBoucle2 = 1; uiBoucle2 <= uik; ++uiBoucle2) {
				// si la couleur est pas utilisé par ses voisins
				if (std::find(Cs.begin(), Cs.end(), uiBoucle2) == Cs.end()) {
					CSCSom->SCOAjouterCouleur(uiBoucle2);
					if (COLExisteColoration(uik, GRAgraphe)) {
						return true;
					}
					CSCSom->SCOAjouterCouleur(0);
				}
			}
			return false;

		}
	}
}

void CColoration::COLDecolorer(const CGraph<CSCouleur, CArc>& GRAgraphe) {
	const vector<CSCouleur*>& lCSCSommets = GRAgraphe.GROGetSommets();
	unsigned int uiBoucle;
	unsigned int uiTaille = lCSCSommets.size();
	for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle) {
		lCSCSommets[uiBoucle]->SCOAjouterCouleur(0);
	}
}


unsigned int CColoration::COLColoration(const CGraph<CSCouleur, CArc>& GRAGraph) {
	// on recherche le nombre de sommet du graphe
	unsigned int uiK = GRAGraph.GROGetSommets().size();
	bool bColor = true;
	while (bColor) {
		COLDecolorer(GRAGraph);
		bColor = COLExisteColoration(uiK, GRAGraph);
		if (bColor) {
			uiK -= 1;
		}
	}
	return uiK+1;
}