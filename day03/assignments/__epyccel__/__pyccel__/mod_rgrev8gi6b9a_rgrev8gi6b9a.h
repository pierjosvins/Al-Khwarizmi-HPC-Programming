#ifndef MOD_RGREV8GI6B9A_RGREV8GI6B9A_H
#define MOD_RGREV8GI6B9A_RGREV8GI6B9A_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi_with_openmp(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, int64_t nb_tasks, double *stand, int64_t *iteration);
#endif // MOD_RGREV8GI6B9A_RGREV8GI6B9A_H
