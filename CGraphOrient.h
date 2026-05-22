#ifndef CGraphOrient_h
#define CGraphOrient_h

#include "CArc.h"
#include "CSommet.h"
#include <vector>
#include <algorithm>
#include <iostream> 
using namespace std;

template<class TSommet, class TArc>
class CGraphOrient
{
private:
	// Attributs
	vector<TSommet*> pGROSommets;
	vector<TArc*> pGROArcs;

	/********************************
	* GROTrouverSommet
	*********************************
	* Entrée : un entier uiNumero
	* Nécessite :rien
	* Sortie : un pointeur TSommet* ou un pointeur null
	* Entraine : on renvoie le sommet correspondant au numéro
	*********************************/
	TSommet* GROTrouverSommet(unsigned int uiNumero) const {
		unsigned int uiTaille = pGROSommets.size();
		unsigned int uiBoucle;
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			if (pGROSommets[uiBoucle]->SOMGetNumSommet() == uiNumero) {
				return pGROSommets[uiBoucle];
			}
		}
		return nullptr;
	}


	/********************************
	* GROTrouverArc
	*********************************
	* Entrée : 2 entiers uiD, uiA
	* Nécessite : Rien
	* Sortie : un pointeur TArc* ou un pointeur null
	* Entraine : on renvoie l'arc correspondant aux sommets départ/arrivée
	*********************************/
	TArc* GROTrouverArc(unsigned int uiD, unsigned int uiA) const {
		unsigned int uiTaille = pGROArcs.size();
		unsigned int uiBoucle;
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			if (pGROArcs[uiBoucle]->ARCGetSomD() == uiD && pGROArcs[uiBoucle]->ARCGetSomA() == uiA) {
				return pGROArcs[uiBoucle];
			}
		}
		return nullptr;
	}
public:
	/********************************
	* GROGetSommets
	*********************************
	* Entrée : rien
	* Nécessite : rien
	* Sortie : pGROSommets par reference constante
	* Entraine : on renvoie la liste des sommets du graphe, accessible uniquement par les classes filles
	*********************************/
	const vector<TSommet*>& GROGetSommets() const { return pGROSommets; };

	/********************************
	* GROGetArcs
	*********************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : pGROArcs par reference constante
	* Entraine : On renvoie la liste des arcs du graphe, accessible uniquement par les classes filles
	*********************************/
	const vector<TArc*>& GROGetArcs() const { return pGROArcs; };

public:
	// Constructeurs/Destructeur
	/********************************
	* CGraphOrient
	*********************************
	* Entrée : rien
	* Nécessite :rien
	* Sortie : rien
	* Entraine : le graphe est initialiser vide
	*********************************/
	CGraphOrient() {};

	/********************************
	* CGraphOrient
	*********************************
	* Entrée : reference constante vers un CGraphOrient
	* Nécessite : rien
	* Sortie : rien
	* Entraine : copie importante, les sommets et arcs sont recopie independament du graphe d'origine
	*********************************/
	CGraphOrient(const CGraphOrient<TSommet, TArc>& GROParam) {
		unsigned int uiTaille;
		unsigned int uiBoucle;

		// On recopie tous les sommets
		uiTaille = GROParam.pGROSommets.size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			GROAjouterSommet(GROParam.pGROSommets[uiBoucle]->SOMGetNumSommet());
		}

		// ON recopie tous les arcs
		// Les liens avec les sommets sont recree automatiquement
		// par GROAjouterArc qui appelle les methodes de CSommet
		uiTaille = GROParam.pGROArcs.size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			GROAjouterArc(GROParam.pGROArcs[uiBoucle]->ARCGetSomD(), GROParam.pGROArcs[uiBoucle]->ARCGetSomA());
		}
	}

	/********************************
	* ~CGraphOrient
	*********************************
	* Entrée : rien
	* Nécessite : rien
	* Sortie : rien
	* Entraine : tous les sommets et arcs sont détruit
	*********************************/
	~CGraphOrient() {
		unsigned int uiTaille;
		unsigned int uiBoucle;

		// on parcourt les sommets
		uiTaille = pGROSommets.size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			delete pGROSommets[uiBoucle];
		}

		// on parcourt les arcs
		uiTaille = pGROArcs.size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			delete pGROArcs[uiBoucle];
		}
	}

	// Méthodes
	/********************************
	* GROSommetExiste
	*********************************
	* Entrée : un entier uiNumero
	* Nécessite : rien
	* Sortie : un booléen
	* Entraine : On renvoie vrai si le sommet existe dans le graphe, faux sinon
	*********************************/
	bool GROSommetExiste(unsigned int uiNumero) {
		return GROTrouverSommet(uiNumero) != nullptr;
	}

	/********************************
	* GROArcExiste
	*********************************
	* Entrée : 2 entiers uiD, uiA
	* Nécessite : Rien
	* Sortie : un booléen
	* Entraine : On renvoie vrai si l'arc existe dans le graphe, faux sinon
	*********************************/
	bool GROArcExiste(unsigned int uiD, unsigned int uiA) {
		return GROTrouverArc(uiD, uiA) != nullptr;
	}

	/********************************
	* GROAjouterSommet
	*********************************
	* Entrée : un entier uiNumero
	* Nécessite : uiNumero pas deja present dans le graphe
	* Sortie :true ou false si sommet deja present
	* Entraine : un nouveau sommet est cree et ajoute dans pGROSommets
	*********************************/
	bool GROAjouterSommet(unsigned int uiNumero) {
		if (GROTrouverSommet(uiNumero) != nullptr) {
			return false;
		}
		TSommet* pSOM = new TSommet(uiNumero);
		pGROSommets.push_back(pSOM);
		return true;
	}

	/********************************
	* GROAjouterArc
	*********************************
	* Entrée : 2 entiers uiD, uiA
	* Nécessite : les deux sommets existent dans le graphe
	* Sortie : true ou false si arc deja existant
	* Entraine : Un arc est créé, ajoute dans pGROArcs et dans les listes des sommets de depart et arrive
	*********************************/
	bool GROAjouterArc(unsigned int uiD, unsigned int uiA) {
		TSommet* pSOMD = GROTrouverSommet(uiD);
		TSommet* pSOMA = GROTrouverSommet(uiA);
		// on verifie si les deux sommets existent 
		if (pSOMD == nullptr || pSOMA == nullptr) {
			return false;
		}
		if (GROTrouverArc(uiD, uiA) != nullptr) {
			return false;
		}

		TArc* pARC = new TArc(uiD, uiA);
		pGROArcs.push_back(pARC);
		pSOMD->SOMAjouterArcD(pARC);
		pSOMA->SOMAjouterArcA(pARC);
		return true;
	}

	/********************************
	* GROModifierSommet
	*********************************
	* Entrée : 2 entiers uiAncien, uiNouveau
	* Nécessite : uiAncien present dans le graphe
	* Sortie : false si sommet pas present true sinon
	* Entraine : le numéro du sommet est modifie
	*********************************/
	bool GROModifierSommet(unsigned int uiAncien, unsigned int uiNouveau) {
		TSommet* pSOM = GROTrouverSommet(uiAncien);
		// verifier ancien sommet existe
		if (pSOM == nullptr) {
			return false;
		}
		// verifier nouveau sommet n'existe pas 
		if (GROTrouverSommet(uiNouveau) != nullptr) {
			return false;
		}
		pSOM->SOMModifierNumSommet(uiNouveau);
		return true;
	}

	/********************************
	* GROModifierArc
	*********************************
	* Entrée : 4 entiers uiD, uiA, uiNvD, uiNvA
	* Nécessite : l'arc uiD->uiA existe et l'arc uiNvD->uiNvA n'existe pas
	* Sortie : false si arc pas present true sinon
	* Entraine : l'arc est modifie avec les nouveaux sommets
	*********************************/
	bool GROModifierArc(unsigned int uiD, unsigned int uiA, unsigned int uiNvD, unsigned int uiNvA) {
		// verifier nouveau sommet n'existe pas 
		if (GROTrouverArc(uiNvD, uiNvA) != nullptr) {
			return false;
		}
		// verifier ancien sommet existe
		if (GROTrouverArc(uiD, uiA) == nullptr) {
			return false;
		}
		// verifier que un des nouveaux sommet n'est pas present
		if (GROTrouverSommet(uiNvD) == nullptr || GROTrouverSommet(uiNvA) == NULL) {
			return false;
		}
		GROSupprimerArc(uiD, uiA);
		GROAjouterArc(uiNvD, uiNvA);
		return true;
	}

	/********************************
	* GROSupprimerSommet
	*********************************
	* Entrée : un entier uiNumero
	* Nécessite : uiNumero present dans le graphe
	* Sortie : false si sommet n'existe pas true sinon
	* Entraine : le sommet et tous ses arcs sont supprime du graphe
	*********************************/
	bool GROSupprimerSommet(unsigned int uiNumero) {
		TSommet* pSOM = GROTrouverSommet(uiNumero);
		if (pSOM == nullptr) {
			return false;
		}
		vector<TArc*> lArcD = pSOM->SOMGetArcD();
		vector<TArc*> lArcA = pSOM->SOMGetArcA();

		unsigned int uiTaille;
		unsigned int uiBoucle;

		// on supprime les arcs partant
		uiTaille = lArcD.size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			GROSupprimerArc(lArcD[uiBoucle]->ARCGetSomD(), lArcD[uiBoucle]->ARCGetSomA());
		}

		// on supprime les arcs arrivant
		uiTaille = lArcA.size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			GROSupprimerArc(lArcA[uiBoucle]->ARCGetSomD(), lArcA[uiBoucle]->ARCGetSomA());
		}

		// on enleve le sommet de la liste du graphe
		pGROSommets.erase(remove(pGROSommets.begin(), pGROSommets.end(), pSOM), pGROSommets.end());
		delete pSOM;
		return true;
	}

	/********************************
	* GROSupprimerArc
	*********************************
	* Entrée : 2 entiers uiD, uiA
	* Nécessite : l'arc existe dans le graphe
	* Sortie : false si arc n'existe pas true sinon
	* Entraine : l'arc est retire de pGROArcs et des listes des sommets concerne puis détruit
	*********************************/
	bool GROSupprimerArc(unsigned int uiD, unsigned int uiA) {
		TArc* pARC = GROTrouverArc(uiD, uiA);
		if (pARC == nullptr) {
			return false;
		}

		TSommet* pSOMD = GROTrouverSommet(uiD);
		TSommet* pSOMA = GROTrouverSommet(uiA);
		if (pSOMD != nullptr) {
			pSOMD->SOMSupprimerArcD(pARC);
		}
		if (pSOMA != nullptr) {
			pSOMA->SOMSupprimerArcA(pARC);
		}
		pGROArcs.erase(remove(pGROArcs.begin(), pGROArcs.end(), pARC), pGROArcs.end());
		delete pARC;
		return true;
	}

	/********************************
	* GROInverserGraphe
	*********************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : un nouveau graphe inverse
	* Entraine : Tous les arcs sont inverses (D->A devient A->D)
	*********************************/
	CGraphOrient<TSommet, TArc> GROInverser() const {
		CGraphOrient<TSommet, TArc> GROInverse;
		unsigned int uiTaille;
		unsigned int uiBoucle;

		uiTaille = pGROSommets.size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			GROInverse.GROAjouterSommet(pGROSommets[uiBoucle]->SOMGetNumSommet());
		}

		uiTaille = pGROArcs.size();
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) {
			GROInverse.GROAjouterArc(pGROArcs[uiBoucle]->ARCGetSomA(), pGROArcs[uiBoucle]->ARCGetSomD());
		}
		return GROInverse;
	}
	/********************************
	* GROAfficher
	*********************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraine : Affiche tous les sommets et arcs du graphe dans la console
	*********************************/
	void GROAfficher() const {
		unsigned int uiTaille = pGROSommets.size();
		unsigned int uiBoucle;
		cout << "=== Graphe Oriente ===" << endl;
		for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++)
			pGROSommets[uiBoucle]->SOMAfficher();
	}

};





#endif