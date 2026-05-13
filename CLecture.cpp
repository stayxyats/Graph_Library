#include "CLecture.h"
#include <fstream>
#include <string>
using namespace std;

CGraphOrient<CSommet, CArc> CLecture::LECFichier(const string& strNomFichier)
{
	CGraphOrient<CSommet, CArc> GROGraphe;
	ifstream ifsFichier(strNomFichier);
	string strLigne;
	unsigned int uiNBSommets;
	unsigned int uiNBArcs;
	unsigned int uiBoucle;
	unsigned int uiNumero;
	unsigned int uiD;
	unsigned int uiA;

	// Verification ouverture fichier
	if (!ifsFichier.is_open()) {
		throw CException(EXC_FICHIER_INTROUVABLE);
	}

	// Lecture NBSommet
	getline(ifsFichier, strLigne);
	if (strLigne.find("NBSommets=") == string::npos) {
		throw CException(EXC_FICHIER_FORMAT_INVALIDE);
	}
	uiNBSommets = stoi(strLigne.substr(strLigne.find("=") + 1));

	// Lecture NBArcs
	getline(ifsFichier, strLigne);
	if (strLigne.find("NBArcs=") == string::npos) {
		throw CException(EXC_FICHIER_FORMAT_INVALIDE);
	}
	uiNBArcs = stoi(strLigne.substr(strLigne.find("=") + 1));

	// Lecture balise Sommets=[
	getline(ifsFichier, strLigne);
	if (strLigne.find("Sommets=[") == string::npos) {
		throw CException(EXC_FICHIER_FORMAT_INVALIDE);
	}

	// Lecture des sommets
	for (uiBoucle = 0; uiBoucle < uiNBSommets; uiBoucle++) {
		getline(ifsFichier, strLigne);
		if (strLigne.find("Numero=") == string::npos) {
			throw CException(EXC_FICHIER_FORMAT_INVALIDE);
		}

		uiNumero = stoi(strLigne.substr(strLigne.find("=") + 1));

		if (GROGraphe.GROSommetExiste(uiNumero)) {
			throw CException(EXC_SOMMET_DEJA_PRESENT);
		}

		GROGraphe.GROAjouterSommet(uiNumero);
	}

	// Lecture balise ] fin sommets
	getline(ifsFichier, strLigne);
	if (strLigne.find("]") == string::npos) {
		throw CException(EXC_FICHIER_FORMAT_INVALIDE);
	}

	// Lecture balise Arcs=[
	getline(ifsFichier, strLigne);
	if (strLigne.find("Arcs=[") == string::npos) {
		throw CException(EXC_FICHIER_FORMAT_INVALIDE);
	}

	// Lecture des arcs
	for (uiBoucle = 0; uiBoucle < uiNBArcs; uiBoucle++) {
		getline(ifsFichier, strLigne);
		if (strLigne.find("Debut=") == string::npos || strLigne.find("Fin=") == string::npos) {
			throw CException(EXC_FICHIER_FORMAT_INVALIDE);
		}

		uiD = stoi(strLigne.substr(strLigne.find("Debut=") + 6, strLigne.find(",") - strLigne.find("Debut=") - 6));
		uiA = stoi(strLigne.substr(strLigne.find("Fin=") + 4));

		if (!GROGraphe.GROSommetExiste(uiD) || !GROGraphe.GROSommetExiste(uiA)) {
			throw CException(EXC_SOMMET_INEXISTANT);
		}

		if (GROGraphe.GROArcExiste(uiD, uiA)) {
			throw CException(EXC_ARC_DEJA_PRESENT);
		}

		GROGraphe.GROAjouterArc(uiD, uiA);
	}

	// Lecture balise ] fin arcs
	getline(ifsFichier, strLigne);
	if (strLigne.find("]") == string::npos) {
		throw CException(EXC_FICHIER_FORMAT_INVALIDE);
	}

	ifsFichier.close();
	return GROGraphe;
}