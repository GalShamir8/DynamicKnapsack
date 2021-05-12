#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Solution{
int** t;
int** s;
int optSol;
}Solution;

Solution* initSol(int numOfItems, int totalWeight, Solution* pSol, int* weights);
Solution* initTables(Solution* pSol, int numOfItems, int totalWeight, int* weights);
void printSolution(Solution* pSol, int numOfItems, int totalWeight);
