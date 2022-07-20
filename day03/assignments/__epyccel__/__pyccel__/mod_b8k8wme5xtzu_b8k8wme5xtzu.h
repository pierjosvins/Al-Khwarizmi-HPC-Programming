#ifndef MOD_B8K8WME5XTZU_B8K8WME5XTZU_H
#define MOD_B8K8WME5XTZU_B8K8WME5XTZU_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi_with_openmp(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, int64_t nb_tasks, double *stand, int64_t *iteration);
#endif // MOD_B8K8WME5XTZU_B8K8WME5XTZU_H
