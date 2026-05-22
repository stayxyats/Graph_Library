#include "CColoration.h"
#include "CGraph.h"


bool CColoration::COLExisteColoration(unsigned int uik, const CGraph<CSCouleur, CArc>&) {

}








































































unsigned int CColoration::COLColoration(const CGraph<CSCouleur, CArc>& GRAGraph) {
	// calcul du nombre de sommets
	unsigned int uik = GRAGraph.GROGetSommets().size();
	bool bcolor = true;
	while (bcolor == true) {
		bcolor = CColoration::COLExisteColoration(unsigned int uik, const CGraph<CSCouleur, CArc>& GRAGraph)
		if (bcolor == true) {
			uik -= 1;
		}
	}
	return uik;
}