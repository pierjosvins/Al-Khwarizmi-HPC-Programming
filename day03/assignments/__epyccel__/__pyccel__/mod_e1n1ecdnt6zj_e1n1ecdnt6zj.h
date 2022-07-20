#ifndef MOD_E1N1ECDNT6ZJ_E1N1ECDNT6ZJ_H
#define MOD_E1N1ECDNT6ZJ_E1N1ECDNT6ZJ_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration);
#endif // MOD_E1N1ECDNT6ZJ_E1N1ECDNT6ZJ_H
