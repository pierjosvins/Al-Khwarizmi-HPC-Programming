#ifndef MOD_HGBIC6F5L78L_HGBIC6F5L78L_H
#define MOD_HGBIC6F5L78L_HGBIC6F5L78L_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi_with_openmp(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, int64_t nb_tasks, double *stand, int64_t *iteration);
#endif // MOD_HGBIC6F5L78L_HGBIC6F5L78L_H
