#ifndef MOD_A9RSHPIHSNDK_A9RSHPIHSNDK_H
#define MOD_A9RSHPIHSNDK_A9RSHPIHSNDK_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration);
#endif // MOD_A9RSHPIHSNDK_A9RSHPIHSNDK_H
