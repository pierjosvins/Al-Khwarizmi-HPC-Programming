#ifndef MOD_X6QV1WLVBY22_X6QV1WLVBY22_H
#define MOD_X6QV1WLVBY22_X6QV1WLVBY22_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod_with_openmp(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_X6QV1WLVBY22_X6QV1WLVBY22_H
