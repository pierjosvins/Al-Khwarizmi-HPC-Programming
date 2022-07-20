#include "mod_hp2n2otdoqg8_hp2n2otdoqg8.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include <stdio.h>


/*........................................*/
/*__________________________________________________________________________________*/
/*                                                                                   */
/*    if there is a n consecutive for loops (nested loops) , we will add collapse(n).*/
/*    We will also reduce some operators applied on like +, * in our case.           */
/*                                                                                   */
/*___________________________________________________________________________________*/
void matrix_prod_with_openmp(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t nb_threads)
{
    int64_t i;
    int64_t j;
    int64_t k;
    #pragma omp parallel num_threads(nb_threads)
    {
        #pragma omp for collapse(2) nowait
        for (i = 0; i < M; i += 1)
        {
            for (j = 0; j < N; j += 1)
            {
                GET_ELEMENT(A, nd_double, (int64_t)i, (int64_t)j) = i + 1 + (j + 1);
            }
        }
        #pragma omp for collapse(2) nowait
        for (i = 0; i < N; i += 1)
        {
            for (j = 0; j < M; j += 1)
            {
                GET_ELEMENT(B, nd_double, (int64_t)i, (int64_t)j) = i + 1 - (j + 1);
            }
        }
        #pragma omp for collapse(2)
        for (i = 0; i < M; i += 1)
        {
            for (j = 0; j < M; j += 1)
            {
                GET_ELEMENT(C, nd_double, (int64_t)i, (int64_t)j) = 0;
            }
        }
        /*Matrix Production*/
        #pragma omp for collapse(3)
        for (i = 0; i < M; i += 1)
        {
            for (j = 0; j < M; j += 1)
            {
                for (k = 0; k < N; k += 1)
                {
                    GET_ELEMENT(C, nd_double, (int64_t)i, (int64_t)j) += GET_ELEMENT(A, nd_double, (int64_t)i, (int64_t)k) * GET_ELEMENT(B, nd_double, (int64_t)k, (int64_t)j);
                }
            }
        }
    }
    printf("%s %ld %s\n", "Execution of Matrix production in parallele with", nb_threads, "threads");
}
/*........................................*/

