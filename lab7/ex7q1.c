
#include "lab07.h"

//the following function creates an int-type array starting at the address where `var` starts
//complete the function definition:
// 1) parameter `var` is a pointer, and its value should be protected;
// 2) you need to decide how to set up a parameber using `var`;
// 3) parameter `length` is the total number of bytes you can use for creating the int-type array;
// 4) you can assume that the entire chunk of memory is owned by your program;
// 5) the length of the created int-type array should be the largest possible, which is function return value;
// 6) after function call, we should be able to use `p` as the name of the created int-type array;
// 7) you need to decide how to set up a parameber using `p`;
size_t any_2_int(int *var, int length, int **p) {

    return length/4;
}

//fill in below all the calls to function `any_2_int()`:
int main() {
	int *p1, *p2, *p3, *p4;
	int n = 1;
	double x = 2.0;
	float a[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
	char c[10] = "abcdefghij";
    size_t length1 = any_2_int(&n, sizeof(n), &p1); //use `p1` as the array name, replace `?` with a proper form of `p1`
    size_t length2 = any_2_int(&x, sizeof(x), &p2); //use `p2` as the array name, replace `?` with a proper form of `p2`
    size_t length3 = any_2_int(a, sizeof(a), &p3); //use `p3` as the array name, replace `?` with a proper form of `p3`
    size_t length4 = any_2_int(c, sizeof(c), &p4); //use `p4` as the array name, replace `?` with a proper form of `p4`

	check(&n, sizeof(n), p1, length1, __LINE__, __FILE__);
	check(&x, sizeof(x), p2, length2, __LINE__, __FILE__);
	check(a, sizeof(a), p3, length3, __LINE__, __FILE__);
	check(c, sizeof(c), p4, length4, __LINE__, __FILE__);

	return 0;
}
