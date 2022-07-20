#ifndef MOD_U5LD3KTBP4T5_U5LD3KTBP4T5_H
#define MOD_U5LD3KTBP4T5_U5LD3KTBP4T5_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi_with_openmp(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, int64_t nb_tasks, double *stand, int64_t *iteration);
#endif // MOD_U5LD3KTBP4T5_U5LD3KTBP4T5_H
