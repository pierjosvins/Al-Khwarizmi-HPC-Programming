#ifndef MOD_AS4F4KNUY2E2_AS4F4KNUY2E2_H
#define MOD_AS4F4KNUY2E2_AS4F4KNUY2E2_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_AS4F4KNUY2E2_AS4F4KNUY2E2_H
