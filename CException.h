#ifndef CException_h
#define CException_h


class CException
{
private:
	unsigned int uiEXCValeur;

public:
	/********************************
	* CException
	*********************************
	* Entrée : un entier uiValeur
	* Nécessite : rien
	* Sortie : rien
	* Entraine : l'exception est initialisee avec le code d'erreur
	*********************************/
	CException(unsigned int uiValeur);

	/********************************
	* EXCModifierValeur
	*********************************
	* Entrée : un entier uiP
	* Nécessite : rien
	* Sortie : rien
	* Entraine : la valeur de l'exception est modife
	*********************************/
	void EXCModifierValeur(unsigned int uiP);

	/********************************
	* EXCLireValeur
	*********************************
	* Entrée : rien
	* Nécessite : rien
	* Sortie : un entier uiEXCValeur
	* Entraine : on renvoie le code d'erreur
	*********************************/
	unsigned int EXCLireValeur() const;
};

#endif