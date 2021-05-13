#include"Q3_d.h"
#include "Q3_e.h"

int main(int argc, char* argv[]) {
	int values[5] = {8, 16, 28, 14, 15};
	int weights[5] = { 1, 4, 5, 2, 4 };

	Solution* pSol = Q3_d(5, values, weights, 11);
	Solution* pSol2 = Q3_e(5, values, weights, 11);
}