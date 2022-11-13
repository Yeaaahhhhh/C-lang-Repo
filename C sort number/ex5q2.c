/* Purpose(s):
 * Author: Dexter
 * Date: 2021.10.03
 * Persons discussed w/:
 * References:
 */

#include "lab05.h"

int main() {

	testing(15, __LINE__, __FILE__);
	testing(20, __LINE__, __FILE__);
	testing(30, __LINE__, __FILE__);
	testing(50, __LINE__, __FILE__);
	testing(100, __LINE__, __FILE__);

	return 0;
}

//the following function returns the number at position n;
//complete the function definition:
// 1) should be a recursion
int mem[1000];
int modified_Fibonacci(int n) {
    if(n==0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else if (n == 2){
        return 2;
    }
    else{
        if(!mem[n]){
            mem[n] = modified_Fibonacci(n-1)+modified_Fibonacci(n-2)+modified_Fibonacci(n-3);
        }
        return mem[n];
    }

}







