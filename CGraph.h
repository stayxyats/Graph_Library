#ifndef CGraph_h
#define CGraph_h
#include "CGraphOrient.h"

template<class TSommet, class TArc>
class CGraph : public CGraphOrient<TSommet, TArc>
{
private:
	/********************************
	* GROAjouterArc
	*********************************
	* Entrée : 2 entiers uiD, uiA
	* Nécessite : Rien
	* Sortie : rien
	* Entraine : methode bloquee dans CGraph, utiliser GRAAjouterArete à la place
	*********************************/
	void GROAjouterArc(unsigned int uiD, unsigned int uiA) = delete;

	/********************************
	* GROSupprimerArc
	*********************************
	* Entrée : 2 entiers uiD, uiA
	* Nécessite : rien
	* Sortie : rien
	* Entraine : methode bloquee dans CGraph, utiliser GRASupprimerArete à la place
	*********************************/
	void GROSupprimerArc(unsigned int uiD, unsigned int uiA) = delete;

	/********************************
	* GROModifierArc
	*********************************
	* Entrée : 4 entiers uiD, uiA, uiNvD, uiNvA
	* Nécessite : rien
	* Sortie : rien
	* Entraine : methode bloquee dans CGraph, utiliser GRAModifierArete à la place
	*********************************/
	void GROModifierArc(unsigned int uiD, unsigned int uiA, unsigned int uiNvD, unsigned int uiNvA) = delete;

public:
	// Constructeurs
	/********************************
	* CGraph
	*********************************
	* Entrée : rien
	* Nécessite : rien
	* Sortie : rien
	* Entraine : le graphe est initialise vide
	*********************************/
	CGraph() : CGraphOrient<TSommet, TArc>() {};

	/********************************
	* CGraph
	*********************************
	* Entrée : reference constante vers un CGraph
	* Nécessite : rien
	* Sortie : rien
	* Entraine : copie profonde via le constructeur de CGraphOrient
	*********************************/
	CGraph(const CGraph<TSommet, TArc>& GRAParam) {
		unsigned int uiTaille;
		unsigned int uiBoucle;

		// On recopie tous les sommets
		uiTaille = GRAParam.CGraphOrient<TSommet, TArc>::GROGetSommets().size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			this->GROAjouterSommet(GRAParam.GROGetSommets()[uiBoucle]->SOMGetNumSommet());
		}

		// On recopie toutes les aretes on prend un arc sur deux car GROAjouterArete cree deja les 2 arcs
		uiTaille = GRAParam.GROGetArcs().size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle += 2) {
			GRAAjouterArete(GRAParam.GROGetArcs()[uiBoucle]->ARCGetSomD(), GRAParam.GROGetArcs()[uiBoucle]->ARCGetSomA());
		}
	}

	// Méthodes
	/********************************
	* GROAjouterArete
	*********************************
	* Entrée : 2 entiers uiD, uiA
	* Nécessite : les deux sommets existent dans le graphe
	* Sortie : bool vrai si les 2 arcs ont ete supprime, faux sinon
	* Entraine : deux arcs sont crees uiD->uiA et uiA->uiD et ajoutes dans le graphe
	*********************************/
	bool GRAAjouterArete(unsigned int uiD, unsigned int uiA) {
		// Les 2 sommets doivent exister
		if (!this->GROSommetExiste(uiD) || !this->GROSommetExiste(uiA)) {
			return false;
		}

		// Les 2 arcs ne doivent pas deja exister
		if (this->GROArcExiste(uiD, uiA) || this->GROArcExiste(uiA, uiD)) {
			return false;
		}

		CGraphOrient<TSommet, TArc>::GROAjouterArc(uiD, uiA);
		CGraphOrient<TSommet, TArc>::GROAjouterArc(uiA, uiD);
		return true;
	}

	/********************************
	* GROSupprimerArete
	*********************************
	* Entrée : 2 entiers uiD, uiA
	* Nécessite : les deux arcs existent dans le graphe
	* Sortie : bool vrai si les 2 arcs ont ete supprime, faux sinon
	* Entraine : les deux arcs uiD->uiA et uiA->uiD sont supprimes
	*********************************/
	bool GRASupprimerArete(unsigned int uiD, unsigned int uiA) {
		// Les 2 arcs doivent exister
		if (!this->GROArcExiste(uiD, uiA) || !this->GROArcExiste(uiA, uiD)) {
			return false;
		}

		CGraphOrient<TSommet, TArc>::GROSupprimerArc(uiD, uiA);
		CGraphOrient<TSommet, TArc>::GROSupprimerArc(uiA, uiD);
		return true;
	}

	/********************************
	*GROModifierArete
	*********************************
	* Entrée : 4 entiers uiD, uiA, uiNvD, uiNvA
	* Nécessite : l'arête uiD-uiA existe et l'arête uiNvD-uiNvA n'existe pas
	* Sortie : bool vrai si la modification a réussi, faux sinon
	* Entraine : l'arête est supprimée puis recréée avec les nouveaux sommets
	*********************************/
	bool GRAModifierArete(unsigned int uiD, unsigned int uiA, unsigned int uiNvD, unsigned int uiNvA) {
		// L'arête à modifier doit exister
		if (!this->GROArcExiste(uiD, uiA) || !this->GROArcExiste(uiA, uiD)) {
			return false;
		}

		// La nouvelle arête ne doit pas deja exister
		if (this->GROArcExiste(uiNvD, uiNvA) || this->GROArcExiste(uiNvA, uiNvD)) {
			return false;
		}

		// Les nouveaux sommets doivent exister
		if (!this->GROSommetExiste(uiNvD) || !this->GROSommetExiste(uiNvA)) {
			return false;
		}

		GRASupprimerArete(uiD, uiA);
		GRAAjouterArete(uiNvD, uiNvA);
		return true;
	}
};


#endif