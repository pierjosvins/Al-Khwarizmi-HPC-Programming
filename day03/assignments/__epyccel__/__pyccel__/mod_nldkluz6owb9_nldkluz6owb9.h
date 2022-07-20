#ifndef MOD_NLDKLUZ6OWB9_NLDKLUZ6OWB9_H
#define MOD_NLDKLUZ6OWB9_NLDKLUZ6OWB9_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration);
#endif // MOD_NLDKLUZ6OWB9_NLDKLUZ6OWB9_H
