#ifndef CSCOULEUR_H
#define CSCOULEUR_H
#include "CArc.h"
#include "CSommet.h"

class CSCouleur: public CSommet
{
private:
	// Attribut
	unsigned int uiSCOcouleur;
 
	//pas de constructeur, les couleurs sont attribués directement par le système
	
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

