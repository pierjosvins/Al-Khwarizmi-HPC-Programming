#ifndef MOD_RC90HXBM7P9U_RC90HXBM7P9U_H
#define MOD_RC90HXBM7P9U_RC90HXBM7P9U_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod_with_openmp(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_RC90HXBM7P9U_RC90HXBM7P9U_H
