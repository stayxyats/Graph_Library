#include <iostream>
#include "CGraphOrient.h"
#include "CGraph.h"
#include "CSommet.h"
#include "CArc.h"
#include "CException.h"
#include "CLecture.h"
using namespace std;

int main(int argc, char* argv[])
{
	// Verification qu'un nom de fichier est passe en parametre
	if (argc < 2)
	{
		cout << "Usage : " << argv[0] << " <nom_fichier>" << endl;
		return 1;
	}

	try
	{
		//Lecture du fichier et creation du graphe
		CGraphOrient<CSommet, CArc> GROGraphe = CLecture::LECFichier(argv[1]);

		// Afichage du graphe original
		cout << "Graphe original :" << endl;
		GROGraphe.GROAfficher();

		// Inversion des arcs
		CGraphOrient<CSommet, CArc> GROGrapheInverse = GROGraphe.GROInverser();

		// Affichage du graphe inverse
		cout << "\nGraphe inverse :" << endl;
		GROGrapheInverse.GROAfficher();
	}
	catch (CException& EXCParam)
	{
		cout << "Erreur : code " << EXCParam.EXCLireValeur() << endl;
		return 1;
	}

	return 0;
}