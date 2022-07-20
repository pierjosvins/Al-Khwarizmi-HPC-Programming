#ifndef MOD_YWBSP8KZ7T50_YWBSP8KZ7T50_H
#define MOD_YWBSP8KZ7T50_YWBSP8KZ7T50_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi_with_openmp(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, int64_t nb_tasks, double *stand, int64_t *iteration);
#endif // MOD_YWBSP8KZ7T50_YWBSP8KZ7T50_H
