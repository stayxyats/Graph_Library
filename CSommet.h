#ifndef CSommet_h
#define CSommet_h

#include "CArc.h"
#include <vector>
using namespace std;

class CSommet
{
private:
	// Attribut
	unsigned int uiSOMNumSommet;
	vector<CArc*> lSOMArcD;
	vector<CArc*> lSOMArcA;

public:
	// Constructeur
	/********************************
	* CSommet
	*********************************
	* Entrée : un entier uiNumero
	* Nécessite : uiNumero est un numero de sommet valide
	* Sortie : rien
	* Entraine : l'objet est initialisé correctement
	*********************************/
	CSommet(unsigned int uiNumero);

	// Méthodes
	/********************************
	* SOMAjouterArcD
	*********************************
	* Entrée : un pointeur pARC vers un CArc
	* Nécessite : pARC non nul
	* Sortie : rien
	* Entraine : pARC est ajoute dans lSOMArcD
	*********************************/
	void SOMAjouterArcD(CArc* pARC);

	/********************************
	*SOMAjouterArcA
	*********************************
	* Entrée : un pointeur pARC vers un CArc
	* Nécessite : pARC non nul
	* Sortie : rien
	* Entraine : pARC est ajoute dans lSOMArcA
	*********************************/
	void SOMAjouterArcA(CArc* pARC);

	/********************************
	* SOMSupprimerArcD
	*********************************
	* Entrée : un pointeur pARC vers un CArc
	* Nécessite : pARC present dans lSOMArcD
	* Sortie : rien
	* Entraine : pARC est retire de lSOMArcD
	*********************************/
	void SOMSupprimerArcD(CArc* pARC);

	/********************************
	* SOMSupprimerArcA
	*********************************
	* Entrée : un pointeur pARC vers un CArc
	* Nécessite : pARC présent dans lSOMArcA
	* Sortie : rien
	* Entraine : pARC est retiré de lSOMArcA
	*********************************/
	void SOMSupprimerArcA(CArc* pARC);

	/********************************
	*SOMGetNumSommet
	*********************************
	* Entrée :rien
	* Nécessite : rien
	* Sortie : uiSOMNumSommet
	* Entraine : On renvoie le numero du sommet
	*********************************/
	unsigned int SOMGetNumSommet() const { return uiSOMNumSommet; };

	/********************************
	* SOMModifierNumSommet
	*********************************
	* Entrée : un entier uiNouveau
	* Nécessite : Rien
	* Sortie : Rien
	* Entraine : le numero est change
	*********************************/
	void SOMModifierNumSommet(unsigned int uiNouveau);

	/********************************
	* SOMGetArcD
	*********************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : lSOMArcD par reference
	* Entraine : On renvoie la liste des arcs partant
	*********************************/
	const vector<CArc*>& SOMGetArcD() const { return lSOMArcD; };

	/********************************
	* SOMGetArcA
	*********************************
	* Entrée : rien
	* Nécessite : rien
	* Sortie : lSOMArcA par reference
	* Entraine : on renvoie la liste des arcs arrivants
	*********************************/
	const vector<CArc*>& SOMGetArcA() const { return lSOMArcA; };

	/********************************
	*SOMAfficher
	*********************************
	* Entrée : rien
	* Nécessite : rien
	* Sortie : rien
	* Entraine : affiche le sommet et ses arcs dans la console
	*********************************/
	void SOMAfficher() const;
};

#endif