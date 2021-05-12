#include "Q3_d.h"

Solution* Q3_d(int numOfItems, int* values, int* weights, int totalweight) {
	Solution* pSol = NULL; 

	if (!(pSol = initSol(numOfItems + 1, totalweight + 1, pSol, weights))) return NULL;
	for (int i = 1; i < numOfItems + 1; i++) {
		for (int j = 1; j < totalweight + 1; j++) {
			if (weights[i - 1] > j) {
				pSol->t[i][j] = pSol->t[i - 1][j];
				pSol->s[i][j] = 0;// 0 -> dont take this item
			}
			else {
				pSol->t[i][j] = MAX(pSol->t[i - 1][j - weights[i - 1]] + values[i - 1], pSol->t[i - 1][j]);
				if (pSol->t[i][j] == (pSol->t[i - 1][j - weights[i - 1]] + values[i - 1]))
					pSol->s[i][j] = 1;// 1 -> take this item
				else
					pSol->s[i][j] = 0;
			}
		}
	}
	printSolution(pSol, numOfItems + 1, totalweight + 1);
	pSol->optSol = pSol->t[numOfItems][totalweight];
	return pSol;
}


