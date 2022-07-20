#ifndef MOD_Y7VT326CNA24_Y7VT326CNA24_H
#define MOD_Y7VT326CNA24_Y7VT326CNA24_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi_with_openmp(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, int64_t nb_tasks, double *stand, int64_t *iteration);
#endif // MOD_Y7VT326CNA24_Y7VT326CNA24_H
