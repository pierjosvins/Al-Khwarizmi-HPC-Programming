#include "mod_4tc65j50c93q_4tc65j50c93q.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t pressure_poisson_pyccel(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nit)
{
    t_ndarray pn = {.shape = NULL};
    int64_t q;
    int64_t i_0001;
    int64_t i_0002;
    int64_t i_0003;
    int64_t i_0004;
    pn = array_create(2, (int64_t[]){p.shape[0], p.shape[1]}, nd_double);
    for (i_0001 = 0; i_0001 < p.shape[0]; i_0001 += 1)
    {
        for (i_0002 = 0; i_0002 < p.shape[1]; i_0002 += 1)
        {
            GET_ELEMENT(pn, nd_double, (int64_t)i_0001, (int64_t)i_0002) = GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)i_0002);
        }
    }
    #pragma omp parallel
    {
        #pragma omp for
        for (q = 0; q < nit; q += 1)
        {
            for (i_0003 = 0; i_0003 < p.shape[0]; i_0003 += 1)
            {
                for (i_0004 = 0; i_0004 < p.shape[1]; i_0004 += 1)
                {
                    GET_ELEMENT(pn, nd_double, (int64_t)i_0003, (int64_t)i_0004) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)i_0004);
                }
            }
            for (i_0003 = 0; i_0003 < p.shape[0] - 1 - 1; i_0003 += 1)
            {
                for (i_0004 = 0; i_0004 < p.shape[1] - 1 - 1; i_0004 += 1)
                {
                    GET_ELEMENT(p, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) = ((GET_ELEMENT(pn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 2) + GET_ELEMENT(pn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004)) * pow(dy, 2.0) + (GET_ELEMENT(pn, nd_double, (int64_t)i_0003 + 2, (int64_t)i_0004 + 1) + GET_ELEMENT(pn, nd_double, (int64_t)i_0003, (int64_t)i_0004 + 1)) * pow(dx, 2.0)) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) - pow(dx, 2.0) * pow(dy, 2.0) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) * GET_ELEMENT(b, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1);
                }
            }
            for (i_0003 = 0; i_0003 < p.shape[0]; i_0003 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)p.shape[1] - 1) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)p.shape[1] - 2);
            }
            for (i_0003 = 0; i_0003 < p.shape[1]; i_0003 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)0, (int64_t)i_0003) = GET_ELEMENT(p, nd_double, (int64_t)1, (int64_t)i_0003);
            }
            for (i_0003 = 0; i_0003 < p.shape[0]; i_0003 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)0) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)1);
            }
            for (i_0003 = 0; i_0003 < p.shape[1]; i_0003 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)p.shape[0] - 1, (int64_t)i_0003) = 0;
            }
        }
    }
    free_array(pn);
    return 0;
}
/*........................................*/

