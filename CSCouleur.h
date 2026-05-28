#ifndef CSCOULEUR_H
#define CSCOULEUR_H
#include "CArc.h"
#include "CSommet.h"

class CSCouleur: public CSommet
{
private:
	// Attribut
	unsigned int uiSCOcouleur;
 
	
public:
	//Constructeur
	/********************************
	* CSCouleur
	*********************************
	* Entrée :1 entier uiNumero
	* Nécessite : uiNumero est un numero de sommet valide
	* Sortie : rien
	* Entraine : l'objet est initialisé correctement avec le numero et sa couleur à 0
	*********************************/
	CSCouleur(unsigned int uiNumero) : CSommet(uiNumero), uiSCOcouleur(0) {}
	
	// Methodes
	/********************************
	* SCOAjouterCouleur 
	*********************************
	* Entrée : 1 entier uiC
	* Nécessite : Rien
	* Sortie : rien
	* Entraine :la coloration du sommet
	*********************************/
	void SCOAjouterCouleur(unsigned int uiC);

	/********************************
	* SCOGetCouleur
	*********************************
	* Entrée : rien
	* Nécessite : Rien
	* Sortie : un unsigned int
	* Entraine : la couleur du sommet
	*********************************/
	unsigned int SCOGetCouleur() const;


};



#endif

