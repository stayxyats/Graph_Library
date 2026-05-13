#ifndef CLecture_h
#define CLecture_h

#include "CGraphOrient.h"
#include "CSommet.h"
#include "CArc.h"
#include "CException.h"
#include <string>
using namespace std;

#define EXC_FICHIER_INTROUVABLE		1
#define EXC_FICHIER_FORMAT_INVALIDE	2
#define EXC_SOMMET_INEXISTANT		3
#define EXC_SOMMET_DEJA_PRESENT		4
#define EXC_ARC_DEJA_PRESENT		5

class CLecture
{
public:
	/********************************
	* LECFichier
	*********************************
	* Entrée : une string strNomFichier
	* Nécessite : Le fichier doit respecter le format imposé
	* Sortie : un CGraphOrient<CSommet, CArc> par valeur
	* Entraine : Lit le fichier et crée le graphe correspondant
	* /!\ Lève une CException si :
	*     - Le fichier est introuvable (EXC_FICHIER_INTROUVABLE)
	*     - Le format est invalide (EXC_FICHIER_FORMAT_INVALIDE)
	*     - Un sommet est en double (EXC_SOMMET_DEJA_PRESENT)
	*     - Un arc relie un sommet inexistant (EXC_SOMMET_INEXISTANT)
	*     - Un arc est en double (EXC_ARC_DEJA_PRESENT)
	*********************************/
	static CGraphOrient<CSommet, CArc> LECFichier(const string& strNomFichier);
};

#endif // !CLecture_h
