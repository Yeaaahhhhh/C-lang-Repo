
#include "lab09.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	struct point *shape1 = NULL, *shape2 = NULL;
	int length1, length2;

	check_generate(&shape1, &length1, &shape2, &length2, __LINE__, __FILE__);

	int k = 10;
	struct point *sample1 = NULL, *sample2 = NULL;
	sample1 = index_sample(shape1, k);
	sample2 = index_sample(shape2, k);
	check_sampling(shape1, sample1, k, __LINE__, __FILE__);
	check_sampling(shape2, sample2, k, __LINE__, __FILE__);
	check_cleanup(sample1, k, __LINE__, __FILE__);
	check_cleanup(sample2, k, __LINE__, __FILE__);

	float distance = sample_distance(shape1, shape2, k);
	check_distance(shape1, shape2, k, distance, __LINE__, __FILE__);

	check_cleanup(shape1, length1, __LINE__, __FILE__);
	check_cleanup(shape2, length2, __LINE__, __FILE__);

	return 0;
}
