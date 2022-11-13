/* Purpose(s):
 * Author: Habibur Rahman
 * Date: Oct 06, 2021
 * Persons discussed w/: N/A
 * References: N/A
 */

#include "lab06.h"

int main(int argc, char **argv) {
    int a[N];
    int *b = a;
    int *c = b;

    check_foo1(a, N, __LINE__, __FILE__);
    check_foo2(b, N, __LINE__, __FILE__);
    check_foo3(c, N, __LINE__, __FILE__);
    return 0;
}

//the following function sets n-i to the position i in the sequence of n integers, stored from the address pointed by p;
//complete the function definition:
// 1) you can assume that the entire chunk of memory is owned by your program;
// 2) you cannot use squared parentheses "[]" inside;
void foo1(int *p, int n) {
    int i;
    
    for (i = 0; i< n; i++) {
        *p = n - i;
        p++;
    }//end for
}

//the following function reverses the sequence of n integers, stored from the address pointed by p;
//complete the function definition:
// 1) you can assume that the entire chunk of memory is owned by your program;
// 2) you cannot use squared parentheses "[]" inside;
void foo2(int *p, int n) {
    int i;

    for(i = 0; i < n/2; i++){
        // swapping with the help of temporary
        int temp = *(p+n-i-1);
        *(p+n-i-1) = *(p+i);
        *(p+i) = temp;
    }//end for
}

//the following function returns the maximum value among the sequence of n integers, stored from the address pointed by p;
//complete the function definition:
// 1) you can assume that the entire chunk of memory is owned by your program;
// 2) you cannot use squared parentheses "[]" inside;
int foo3(const int *p, int n) {
    //considering the first element as maximum
    int mx = *p, i;

    for (i = 1; i < n; i++){
        if ( *(p + i) > mx){
            mx = *(p + i);
        }//end if
    }//end for
    return mx;
}
