
#include "lab08.h"

int main() {
	int coef1, coef2;
	gcd(446, 39, &coef1, &coef2);
	check_gcd(446, 39, coef1, coef2, __LINE__, __FILE__);
	gcd(48, 112, &coef1, &coef2);
	check_gcd(48, 112, coef1, coef2, __LINE__, __FILE__);
	gcd(6, 9, &coef1, &coef2);
	check_gcd(6, 9, coef1, coef2, __LINE__, __FILE__);
	return 0;
}

//the following function computes the coefficients a and b so that a * i + b * j = GCD(i, j)
//complete the function definition:
// 1) should be a recursion
//    hint: the coefficients can be determined from the coefficients for the pair (i, j-i) or (i-j, j)
void gcd(int i, int j, int *a, int *b) {
// Base Case
    if (i == j){
        *a = 1;
        *b = 0;
        return;
    }

    int a1, b1; // To store results of recursive call

    if(j>i){
        gcd(i, j-i, &a1, &b1);
        *a = a1-b1;
        *b = b1;
    }
    else{
        gcd(i-j, j, &a1, &b1);
        *a = a1;
        *b = b1-a1;
    }

    return;
}

