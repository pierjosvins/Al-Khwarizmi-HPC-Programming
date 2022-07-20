#ifndef MOD_74Q3NL51TR7M_74Q3NL51TR7M_H
#define MOD_74Q3NL51TR7M_74Q3NL51TR7M_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void matrix_prod_with_openmp(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads);
#endif // MOD_74Q3NL51TR7M_74Q3NL51TR7M_H
