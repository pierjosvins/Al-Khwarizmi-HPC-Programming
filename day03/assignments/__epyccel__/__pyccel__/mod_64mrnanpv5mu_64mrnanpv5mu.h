#ifndef MOD_64MRNANPV5MU_64MRNANPV5MU_H
#define MOD_64MRNANPV5MU_64MRNANPV5MU_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod_openmp(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_64MRNANPV5MU_64MRNANPV5MU_H
