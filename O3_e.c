#include "Q3_e.h"

Solution* Q3_e(int numOfItems, int* values, int* weights, int totalweight) {
	Solution* pSol = NULL;

	if (!(pSol = initSol(numOfItems + 1, totalweight + 1, pSol, weights))) return NULL;
	initXTable(pSol, values, weights, numOfItems + 1, totalweight + 1);
	for (int i = 1; i < numOfItems + 1; i++) {
		for (int j = 1; j < totalweight + 1; j++) {
			if (weights[i - 1] > j) {
				pSol->t[i][j] = pSol->t[i - 1][j];
			}
			else {
				pSol->t[i][j] = findMax(pSol->t[i - 1][j - weights[i - 1]] + values[i - 1],
					pSol->t[i - 1][j], pSol->s[i][j] * values[i - 1]);
			}
		}
	}
	pSol->optSol = pSol->t[numOfItems][totalweight];
	printSolution(pSol, numOfItems + 1, totalweight + 1);
	return pSol;
}