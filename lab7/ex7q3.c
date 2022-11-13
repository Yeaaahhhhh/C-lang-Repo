
#include "lab07.h"
#include <string.h>

//the following function saves the coefficients into the array `a[s + 1]`
//complete the function definition:
// 1) note that char type is used since the coefficients and `s` are all very small;
// 2) you may assume k >= 1;
// 3) the function definition must be a recursion;
void coefficient(int k, char a[], char *s) {
    int i = 0;
    if ((k % 3) == 0){
        a[i] = 0;
        i++;
        coefficient(k/3,a,s);

    }
    if ((k % 3) == 1){
        a[i] = 1;
        i++;
        coefficient(k/3,a,s);
    }
    if ((k % 3) == 2){
        a[i] = -1;
        i++;
        coefficient((k+1)/3,a,s);
    }


}

int main() {
	char a[55] = {0}; //this array stores the coefficients, large enough for all integers
	char s = -1; //this stores the largest position of the array with non-zero element
	check_coefficient(555, a, s, __LINE__, __FILE__);
	return 0;
}
