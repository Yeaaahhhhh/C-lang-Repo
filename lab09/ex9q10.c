
#include "lab09.h"

//the following function generates a shape of `n` points uniformly randomly distributed in the area
//complete the function definition:
// 1) return NULL if the given number `n` is invalid;
// 2) you do not need to free the dynamically allocate memory for the new shape;
struct point *generate(int n) { //requires 1 <= n <= 1000

    sturct point *first = NULL, *last = NULL;

    for (int i = 0;i<n;i++){
        if (first == NULL){
            first = calloc(1,sizeof(struct point));
            last = first;
        }
        else{
            last -> next = calloc(sizeof(struct point));
            last = last ->next;
        }
        last->x = (rand () % 100001) / 100.0;
        last->y = (rand () % 100001) / 100.0;
        last->next = NULL;
    }
    return (first);



}

//the following function destroys a given shape pointed to by `head`
//complete the function definition:
// 1) do nothing if the given shape is NULL;
// 2) you need to free the dynamically allocated points in the shape;
void cleanup(struct point *head) {
    struct point* temp;
    while (head != NULL){
        temp = head;
        head = head ->next;
        free(temp);
    }

	return;
}
