/* Purpose(s):
 * Author: Dexter
 * Date: 2021.10.4
 * Persons discussed w/: Junzhuo Huang
 * References:https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
 */

#include "lab05.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int n = 40;
	int matrix[n][n];
	counting(n, matrix, __LINE__, __FILE__);

	return 0;
}

//the following function returns an nxn (0,1)-matrix, where each row contains n/2 1's
//complete the function definition:
// 1) ideally, each entry has 0.5 probability to be 1 (but not strict);
// 2) should be random enough so that two calls to the function generate two different matrices with high probability
void initialization(int n, int matrix[n][n]){
    srand(time(NULL));
    for (int i =0; i<n;i++){
        for(int j = 0; j<n;j++){
            matrix[i][j] =0;
        }
    }
    int numOfOne,pos;
    for (int i = 0; i<n;i++){
        numOfOne = 0;
        while (numOfOne < n/2){
            pos = rand() %n;
            if (matrix[i][pos]!= 1){
                matrix[i][pos] = 1;
                numOfOne += 1;    //after set a '1',then plus 1
            }
        }
    }

}

extern int counter;

//the following function swaps the contents in two matrix positions in the same row
//complete the function definition:
// 1) the two positions are [row][pos1] and [row][pos2];
// 2) do not use the variable "counter" in your inserted code.
void swap(int n, int row, int pos1, int pos2, int matrix[n][n]){
	counter++;
	int temp;
	temp = matrix[row][pos1];
	matrix[row][pos1] = matrix[row][pos2];
	matrix[row][pos2] = temp;

}

//the following function makes the number of 1's in each column to be n/2
//complete the function definition:
// 0) the argument `matrix` is generated by `initialization()`;
// 1) inside this function, you are not allowed to use any assignment operator on the array elements;
// 2) call swap() function if you want to swap two matrix entries in the same row;
// 3) the number of calls to swap() function should be at most n^2/4; you will be warned if too many.
void balance1(int n, int matrix[n][n]){
    // check number of 1 in a column
    matrix = initialization(n,matrix);
    for (int row = 0;row<n;row++){
        int numOf1 = 0;
        for (int col = 0; col<n;col++){
            if (matrix[col][row]==1){  //while the matrix will get the row first, so here col is the 'row'
                numOf1 += 1;
            }
        }
        if (numOf1 == n/2){
            break;
        }
        else if(numOf1 > n/2){
            int swapNeeded =  0;
            int ro=0;
            while(swapNeeded != numOf1 - n/2){
                if (matrix[ro][row]== 1){
                    for(int k = row+1;k<n;k++){
                        swap(n,ro,row,k,matrix);
                        if (matrix[ro][row]==0){
                            swapNeeded += 1;
                            break;
                        }
                    }
                }
                ro += 1;
            }
        }
        else if (numOf1 < n/2){
            int swapNeeded =  0;
            int ro=0;
            while(swapNeeded != n/2-numOf1){
                if (matrix[ro][row]== 0){
                    for(int k = row+1;k<n;k++){
                        swap(n,ro,row,k,matrix);
                        if (matrix[ro][row]==1){
                            swapNeeded += 1;
                            break;
                        }
                    }
                }
                ro += 1;
            }
        }
    }
}