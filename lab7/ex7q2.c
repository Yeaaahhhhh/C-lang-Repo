
#include "lab07.h"


//the following function returns the index i among 0, 1, ..., n-1 so that a[i] is the smallest element greater than `key`
//complete the function definition:
// 1) if you copy a[] into another array, then should not modify this new array
// 2) you may assume `key` is strictly less than at least one element of the array
int min_above_key(int const a[], int n, int key) {
    int pos = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] > key) {
            if((pos == -1) || (a[i] < a[pos])){
                pos = i;
            }
        }
    }
    return pos;


}

//the following function saves the ordered indices into the array `order[]`
//complete the function definition:
// 1) you cannot compare between the array elements
// 2) you should use the above function `min_above_key()`
void index_order(int const a[], int n, int order[]){
    int minimal[n] = {0};
    for(int i = 0; i < n; i++){
        minimal[i] = min_above_key(a, n, a[i]);
    }
    for(int i = n - 1; i >= 0; i--){
        int reqd = -1;
        if(i < n - 1) {
            reqd = order[i+1];
        }
        for(int j = 0; j < n; j++){
            if(minimal[j] == reqd){
                order[i] = j;
                break;
            }
        }
    }


}

int main() {
	int a[N] = {1, 12, 6, 8, 99, 2, 4, 11, 27, 5};
	int order[N] = {0};
	check_order(a, N, order, __LINE__, __FILE__);

	return 0;
}
