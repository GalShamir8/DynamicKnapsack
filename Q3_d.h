#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Solution.h"
#define MAX(a,b) (a>b)? (a) : (b)
/**
values -> value array for each item
weights -> weights array for each item
*/
Solution* Q3_d(int numOfItems, int* values, int* weights, int totalweight);
