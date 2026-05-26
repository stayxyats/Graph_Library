#include "CColoration.h"
#include "CGraph.h"
#include <set>


bool CColoration::COLAllColored(const CGraph<CSCouleur, CArc>& GRAgraphe) {
	const vector<CSCouleur*>& sommets = GRAgraphe.GROGetSommets();
	for (unsigned int i = 0; i < sommets.size(); ++i) {
		if (sommets[i]->SCOGetCouleur() == 0)
			return false;
	}
	return true;
}



vector<unsigned int> CColoration::COLListeCouleurs(const CSCouleur* SCOsommet, const CGraph<CSCouleur, CArc>& GRAgraphe) {
    vector<unsigned int> list_couleurs;
    const vector<CArc*>& arcs = SCOsommet->SOMGetArcD();

    for (unsigned int i = 0; i < arcs.size(); ++i) {
        unsigned int uiNumVoisin = arcs[i]->ARCGetSomA();

        const vector<CSCouleur*>& sommets = GRAgraphe.GROGetSommets();
        for (unsigned int j = 0; j < sommets.size(); ++j) {
            if (sommets[j]->SOMGetNumSommet() == uiNumVoisin) {

                if (sommets[j]->SCOGetCouleur() != 0) {
                    list_couleurs.push_back(sommets[j]->SCOGetCouleur());
                }
                break;
            }
        }
    }
    return list_couleurs;
}


bool CColoration::COLExisteColoration(unsigned int uik, const CGraph<CSCouleur, CArc>& GRAgraphe) {
	if (COLAllColored(GRAgraphe)) {
		return true;
	}
	const vector<CSCouleur*>& sommets = GRAgraphe.GROGetSommets();
	for (unsigned int i = 0; i < sommets.size(); ++i) {
		CSCouleur* s = sommets[i];
		if (s->SCOGetCouleur() == 0) {
			vector<unsigned int>Cs = COLListeCouleurs(s, GRAgraphe);

			//on enleve les doublons, pour un sommet qui a 2 voisins avec la meme couleur par exemple
			std::set<unsigned> CsClean(Cs.begin(), Cs.end());
			if (CsClean.size() == uik) {
				return false;
			}
			for (unsigned int j = 1; j <= uik; ++j) {
				if (std::find(Cs.begin(), Cs.end(), j) == Cs.end()) {
					s->SCOAjouterCouleur(j);
					if (COLExisteColoration(uik, GRAgraphe)) {
						return true;
					}
					s->SCOAjouterCouleur(0);
				}
			}
			return false;

		}
	}
}

void CColoration::COLDecolorer(const CGraph<CSCouleur, CArc>& GRAgraphe) {
	const vector<CSCouleur*>& sommets = GRAgraphe.GROGetSommets();
	for (unsigned int i = 0; i < sommets.size(); ++i)
		sommets[i]->SCOAjouterCouleur(0);
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