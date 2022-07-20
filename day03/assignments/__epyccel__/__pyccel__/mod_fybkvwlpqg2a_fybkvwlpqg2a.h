#ifndef MOD_FYBKVWLPQG2A_FYBKVWLPQG2A_H
#define MOD_FYBKVWLPQG2A_FYBKVWLPQG2A_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_FYBKVWLPQG2A_FYBKVWLPQG2A_H
