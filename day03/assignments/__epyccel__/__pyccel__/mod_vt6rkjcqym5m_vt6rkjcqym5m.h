#ifndef MOD_VT6RKJCQYM5M_VT6RKJCQYM5M_H
#define MOD_VT6RKJCQYM5M_VT6RKJCQYM5M_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration);
#endif // MOD_VT6RKJCQYM5M_VT6RKJCQYM5M_H
