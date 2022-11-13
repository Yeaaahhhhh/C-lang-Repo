
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#define MAX_NUM 1000  //upper bound on the number of points in a shape
#define MAX_COOR 1000 //all valid points in the area [0.0, MAX_COOR] x [0.0, MAX_COOR]

struct point {
	float x;
	float y;
	struct point *next; //pointer to the succeeding point in the same shape, if any; otherwise NULL
};

struct point *generate(int);
void cleanup(struct point *);
struct point *index_sample(struct point *, int);
float sample_distance(struct point *, struct point *, int);

void check_generate(struct point **, int *, struct point **, int *, int, char *);
void check_cleanup(struct point *, int, int, char *);
void check_sampling(struct point *, struct point *, int, int, char *);
void check_distance(struct point *, struct point *, int, float, int, char *);
