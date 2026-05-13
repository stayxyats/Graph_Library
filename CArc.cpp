#include "CArc.h"
#include <iostream>
using namespace std;

CArc::CArc(unsigned int uiARCSomD, unsigned int uiARCSomA) {
	uiARCSommetD = uiARCSomD;
	uiARCSommetA = uiARCSomA;
}

void CArc::ARCAfficher() const {
	cout << "Arc : " << uiARCSommetD << " -> " << uiARCSommetA << endl;
}