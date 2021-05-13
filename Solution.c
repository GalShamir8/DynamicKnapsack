#include "Solution.h"


Solution* initSol(int numOfItems, int totalWeight, Solution* pSol, int* weights) {
	pSol = (Solution*)calloc(1, sizeof(Solution));
	if (!pSol) return NULL;
	return initTables(pSol, numOfItems, totalWeight, weights);
}

Solution* initTables(Solution* pSol, int numOfItems, int totalWeight, int* weights) {
	pSol->s = (int**)calloc(numOfItems, sizeof(int*));
	pSol->t = (int**)calloc(numOfItems, sizeof(int*));
	if (!pSol->s || !pSol->t) return NULL;

	for (int i = 0; i < numOfItems; i++) {
		pSol->s[i] = (int*)calloc(totalWeight, sizeof(int));
		pSol->t[i] = (int*)calloc(totalWeight, sizeof(int));
		if (!pSol->s || !pSol->t) return NULL;
	}
		/* indexing sequence of items
		pSol->t[i][0] = i;
		pSol->s[i][0] = i;
	}

	for (int i = 0; i < totalWeight; i++) {
		pSol->t[0][i] = i;
		pSol->s[0][i] = i;
	}*/
	return pSol;
}

void printSolution(Solution* pSol, int numOfItems, int totalWeight) {
	printf("------Table T-------\n");
	for (int i = 0; i < numOfItems; i++) {
		for (int j = 0; j < totalWeight; j++) {
			printf("%5d", pSol->t[i][j]);
		}
		printf("\n");
	}
	printf("\n------Table S-------\n");
	for (int i = 0; i < numOfItems; i++) {
		for (int j = 0; j < totalWeight; j++) {
			printf("%5d", pSol->s[i][j]);
		}
		printf("\n");
	}
	printf("\nOptimal solution: %d\n", pSol->optSol);
}

void initXTable(Solution* pSol, int* values, int* weights,int numOfItems, int totalWeight) {
	for (int i = 1; i < numOfItems; i++) {
		for (int j = 1; j < totalWeight; j++) {
			float isInteger = j / weights[i - 1] - (int)j / weights[i - 1];
			if (isInteger == 0)
				pSol->s[i][j] = j / weights[i - 1];
			else
				pSol->s[i][j] = 0;
		}
	}
}

int findMax(int n1, int n2, int n3) {
	if (n1 > n2 && n1 > n3)
		return n1;
	if (n2 > n1 && n2 > n3)
		return n2;
	if (n3 > n2 && n3 > n1)
		return n3;
	return n1;
}
