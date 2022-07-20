#ifndef MOD_UG1D1JP8JHSU_UG1D1JP8JHSU_H
#define MOD_UG1D1JP8JHSU_UG1D1JP8JHSU_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod_with_openmp(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_UG1D1JP8JHSU_UG1D1JP8JHSU_H
