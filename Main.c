#include"Q3_d.h"

int main(int argc, char* argv[]) {
	int values[5] = {8, 16, 28, 14, 15};
	int weights[5] = { 1, 4, 5, 2, 4 };

	Solution* pSol = Q3_d(5, values, weights, 11);
	printf("%d", pSol->optSol);
}