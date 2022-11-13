
#include "lab09.h"

//the following function computes the k-sample distance between two shapes pointed to by `shape1` and `shape2`, respectively
//complete the function definition:
// 0) you can assume `k` is valid, i.e., in [2, 1000];
// 1) abort or terminate if any given shape is NULL;
// 2) do not alter the given shape, i.e. `shape1/2` still points to the original shape1/2;
// 3) if you dynamically allocate some memory, even by calling other functions, then you need to free them before return;
float sample_distance(struct point *shape1, struct point *shape2, int k) {\
    //this lab is worked together with Junzhuo Huang, Joseph.
    float dist = 0;

    struct point *one = index_sample (shape1, k);
    struct point *two = index_sample (shape2, k);

    for (int i = 0; i < k; i++) {
        dist += sqrt ((one->x - two->x) * (one->x - two->x) + (one->y - two->y) * (one->y - two->y));
    }
    return (dist);


}
