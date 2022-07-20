#ifndef MOD_FVIR9MFUPSPG_FVIR9MFUPSPG_H
#define MOD_FVIR9MFUPSPG_FVIR9MFUPSPG_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M);
#endif // MOD_FVIR9MFUPSPG_FVIR9MFUPSPG_H
