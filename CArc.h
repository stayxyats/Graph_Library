#ifndef CArc_H
#define CArc_H
class CArc
{
private:
	// Attributs
	unsigned int uiARCSommetD;
	unsigned int uiARCSommetA;

public:
	//Constructeur
	/********************************
	* CArc
	*********************************
	* Entrée : 2 entiers uiARCSomD, uiARCSomA
	* Nécessite : uiARCSomD et uiARCSomA sont des numéros de sommet existants
	* Sortie : rien
	* Entraine : l'objet est initialisé correctement
	*********************************/
	CArc(unsigned int uiARCSomD, unsigned int uiARCSomA);

	// Méthodes
	/********************************
	* ARCGetSomD
	*********************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : un entier uiARCSommetD
	* Entraine : on renvoie le sommet de départ de l'arc
	*********************************/
	unsigned int ARCGetSomD() const { return uiARCSommetD; };

	/********************************
	* ARCGetSomA
	*********************************
	* Entrée : rien
	* Nécessite : rien
	* Sortie : un entier uiARCSommetA
	* Entraine : on renvoie le sommet d'arrive de l'arc
	*********************************/
	unsigned int ARCGetSomA() const { return uiARCSommetA; };

	/********************************
	* ARCAfficher
	*********************************
	* Entrée : rien
	* Nécessite : rien
	* Sortie : rien
	* Entraine : affiche l'arc dans la console
	*********************************/
	void ARCAfficher() const;
};

#endif