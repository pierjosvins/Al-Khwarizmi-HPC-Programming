#ifndef MOD_56S84ZWFPRYW_56S84ZWFPRYW_H
#define MOD_56S84ZWFPRYW_56S84ZWFPRYW_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi_with_openmp(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, int64_t nb_tasks, double *stand, int64_t *iteration);
#endif // MOD_56S84ZWFPRYW_56S84ZWFPRYW_H
