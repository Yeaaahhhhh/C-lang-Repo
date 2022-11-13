/* Purpose(s):
 * Author: Habibur Rahman
 * Date: Oct 06, 2021
 * Persons discussed w/: N/A
 * References: N/A
 */

#include "lab06.h"

extern int count_assign;
extern int count_comp;

//the following function swaps the values of the two variables;
//complete the function definition:
void keyassign(int *a, int b) {
    count_assign++;
    *a = b;
}

//the following function compares two integers, and returns true if a <= b;
//complete the function definition:
bool keycomp(int a, int b) {
    count_comp++;
    return (a <= b);
}
