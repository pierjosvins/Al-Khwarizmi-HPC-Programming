#ifndef MOD_4N7BQ7D3KHDM_4N7BQ7D3KHDM_H
#define MOD_4N7BQ7D3KHDM_4N7BQ7D3KHDM_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod_with_openmp(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_4N7BQ7D3KHDM_4N7BQ7D3KHDM_H
