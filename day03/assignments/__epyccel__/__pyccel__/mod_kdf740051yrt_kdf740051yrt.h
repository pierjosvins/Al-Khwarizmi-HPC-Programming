#ifndef MOD_KDF740051YRT_KDF740051YRT_H
#define MOD_KDF740051YRT_KDF740051YRT_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_KDF740051YRT_KDF740051YRT_H
