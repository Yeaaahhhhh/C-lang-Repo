/* Purpose(s):
 * Author:
 * Date:
 * Persons discussed w/:
 * References:
 */

#include "lab06.h"

int main(int argc, char **argv) {
    int a[N] = {1, 4, 11, 100, 11, 7, 3, -1, 99, 6};

	check_insert(a, N, __LINE__, __FILE__);
    check_merge(a, N, __LINE__, __FILE__);
    return 0;
}
