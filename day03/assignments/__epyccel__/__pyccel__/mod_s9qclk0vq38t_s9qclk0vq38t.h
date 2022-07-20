#ifndef MOD_S9QCLK0VQ38T_S9QCLK0VQ38T_H
#define MOD_S9QCLK0VQ38T_S9QCLK0VQ38T_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_S9QCLK0VQ38T_S9QCLK0VQ38T_H
