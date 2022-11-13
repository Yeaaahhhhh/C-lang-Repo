/* Purpose(s): Merge Sort
 * Author: Habibur Rahman
 * Date: Oct 06, 2021
 * Persons discussed w/: N/A
 * References: https://www.geeksforgeeks.org/merge-sort/
 */

#include "lab06.h"

//the following function implements mergesort algorithm;
//complete the function definition as a recursion:
// 1) to sort an integer array from position `left` to position `right` (inclusive) into the non-decreasing order;
// 2) if an assignment operation involves an array element, you should use keyassign();
// 3) if a comparison operation involves an array element, you should use keycomp();
// 4) should be a recursion:
// 4.1) divide into two sub-arrays of the equal length (off by 1);
// 4.2) recursively sort each;
// 4.3) merge the sorted sub-arrays;
void mergesort(int a[], int left, int right) {
    if (left >= right)
        return; // end recursion

    int mid = (left + right) / 2; //divided the array into mid position
    mergesort(a, left, mid); //sort the left subarray
    mergesort(a, mid + 1, right); //sort the right subarray
    merge(a, left, mid, right); //merge the left and right subarray after sorting
}

//the following function merges a[left .. mid] and a[mid+1 .. right] into a sorted array a[left .. right];
//complete the function definition:
// 1) you can assume a[left .. mid] and a[mid+1 .. right] are sorted separately
void merge(int a[], int left, int mid, int right) {
    int lenLeftSubArray = mid - left + 1; //len of leftSubArray
    int lenRightSubArray = right - mid; //len of rightSubArray

    // Create temp arrays
    int *leftSubArray, *rightSubArray;
    leftSubArray = (int*) malloc(sizeof(int)*lenLeftSubArray);
    rightSubArray = (int*) malloc(sizeof(int)*lenRightSubArray);

    // Copy data to temporary arrays leftSubArray and rightSubArray
    for (int i = 0; i < lenLeftSubArray; i++)
        keyassign((leftSubArray + i),  *(a + left + i));
    for (int j = 0; j < lenRightSubArray; j++)
        keyassign((rightSubArray + j), *(a + mid + 1 + j));

    int indexOfLeftSubArray = 0, // Initial index of leftSubSrray
        indexOfRightSubArray = 0; // Initial index of rightSubArray
    int indexOfMergedArray = left; // Initial index of mergedArray

    // Merge the temp arrays back into a[left..right]
    while (indexOfLeftSubArray < lenLeftSubArray && indexOfRightSubArray < lenRightSubArray) {
        if (keycomp(*(leftSubArray + indexOfLeftSubArray), *(rightSubArray + indexOfRightSubArray))) {
            keyassign((a + indexOfMergedArray), *(leftSubArray + indexOfLeftSubArray));
            indexOfLeftSubArray++;
        }
        else {
            keyassign((a + indexOfMergedArray), *(rightSubArray + indexOfRightSubArray));
            indexOfRightSubArray++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of leftSubArray
    while (indexOfLeftSubArray <  lenLeftSubArray) {
        keyassign((a + indexOfMergedArray), *(leftSubArray + indexOfLeftSubArray));
        indexOfLeftSubArray++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of rightSubArray
    while (indexOfRightSubArray <  lenRightSubArray) {
        keyassign((a + indexOfMergedArray), *(rightSubArray + indexOfRightSubArray));
        indexOfRightSubArray++;
        indexOfMergedArray++;
    }
    free(leftSubArray);
    free(rightSubArray);
}
