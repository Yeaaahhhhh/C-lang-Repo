/* Purpose(s):
 * Author: Dexter
 * Date: 2021.10.3
 * Persons discussed w/:
 * References:
 */

#include "lab05.h"

int main() {

    int a[10] = {3, 4, 11, 100, 2, 7, 1, -1, 99, 6};

    check(min_in_array(a, 10), -1, __LINE__, __FILE__);
    check(min_in_array(a, 7), 1, __LINE__, __FILE__);
    check(min_in_array(a, 6), 2, __LINE__, __FILE__);
    check(min_in_array(a, 2), 3, __LINE__, __FILE__);
    return 0;
}

//the following function returns the smaller value between two given integers;
//complete the function definition:
int min_between_two(int a, int b) {
    if (a>b){
        return b;
    }
    else{
        return a;
    }

}

//the following function returns the minimum value among the first n elements of a given array;
//complete the function definition:
// 1) you cannot compare between any two elements in the array;
// 2) you can use the `min_between_two()` functions defined in the above;
// 3) running time should be in O(n).
int min_in_array(const int a[], int n) {
    int mini;
    mini = a[0];
    for (int i = 0; i <n-1; i++){
        if min_between_two(a[i],a[i+1]) < mini{
            mini = min_between_two(a[i],a[i+1]);
        }
    }
    return mini;

}
