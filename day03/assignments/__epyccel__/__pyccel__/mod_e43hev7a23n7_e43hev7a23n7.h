#ifndef MOD_E43HEV7A23N7_E43HEV7A23N7_H
#define MOD_E43HEV7A23N7_E43HEV7A23N7_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod_openmp(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_E43HEV7A23N7_E43HEV7A23N7_H
