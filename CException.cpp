#include "CException.h"

CException::CException(unsigned int uiValeur) {
	uiEXCValeur = uiValeur;
}

void CException::EXCModifierValeur(unsigned int uiP) {
	uiEXCValeur = uiP;
}

unsigned int CException::EXCLireValeur() const {
	return uiEXCValeur;
}