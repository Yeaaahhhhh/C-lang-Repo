
#include "lab09.h"

//the following function computes the k-sample of a given shape pointed to by `shape`
//complete the function definition:
// 0) you can assume `k` is valid, i.e., in [2, 1000];
// 1) return NULL if the given shape is NULL;
// 2) do not alter the given shape, i.e. `shape` still points to the original shape;
// 3) you do not need to free the dynamically allocate memory for the new shape;
struct point *index_sample(struct point *shape, int k) {
    //this lab is worked together with Junzhuo Huang, Joseph.
    struct point *first = NULL, *last = NULL;

    int n;
    int m;
    m = 0;
    while (shape){
        shape = shape->next;
        m++;
    }
    n = m;
    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            first = calloc (1, sizeof (struct point));
            last = first;
        }
        else {
            last->next = calloc (1, sizeof (struct point));
            last = last->next;
        }


        for(int index = 0;index<i*n/(k-1);i++){
            if (shape->next==NULL){
                break;
            }
            shape = shape->next;
        }
        struct point *member = shape;
        last->x = member->x;
        last->y = member->y;
        last->next = NULL;
    }
    return (first);



}
