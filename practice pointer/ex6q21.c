/* Purpose(s):
 * Author: Habibur Rahman
 * Date: Oct 06, 2021
 * Persons discussed w/: N/A
 * References: https://www.geeksforgeeks.org/insertion-sort/
 */

#include "lab06.h"

//the following function implements insertionsort algorithm;
//complete the function definition:
// 1) to sort an array of n integers into the non-decreasing order;
// 2) if an assignment operation involves an array element, you should use keyassign();
// 3) if a comparison operation involves an array element, you should use keycomp();
// 4) should be in-space sorting, i.e.,
// 4.1) shuffle array elements around inside the array;
// 4.2) no extra array can be used for the sorting purpose;
void insertionsort(int a[], int n) {

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        //considering ith element of the array as the key
        key = *(a + i);
        j = i - 1;

        /* Move elements of a[0..i-1], that are greater than key, to one position ahead of their current position */
        while ( j >= 0 && keycomp(key, *(a + j)) )
        {
            keyassign((a + j + 1),  *(a + j));
            j = j - 1;
        } // end while

        keyassign((a + j + 1),  key);

    } // end for
}
