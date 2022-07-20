#include "mod_tobg75ittf38_tobg75ittf38.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <stdio.h>


/*........................................*/
void matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M)
{
    int64_t i;
    int64_t j;
    int64_t k;
    int64_t i_0001;
    int64_t i_0002;
    int64_t i_0003;
    for (i = 0; i < M; i += 1)
    {
        for (j = 0; j < N; j += 1)
        {
            GET_ELEMENT(A, nd_int64, (int64_t)i, (int64_t)j) = i + 1 + (j + 1);
        }
    }
    for (i = 0; i < N; i += 1)
    {
        for (j = 0; j < M; j += 1)
        {
            GET_ELEMENT(B, nd_int64, (int64_t)i, (int64_t)j) = i + 1 - (j + 1);
        }
    }
    for (i = 0; i < M; i += 1)
    {
        for (j = 0; j < M; j += 1)
        {
            GET_ELEMENT(C, nd_int64, (int64_t)i, (int64_t)j) = 0;
        }
    }
    /*...*/
    printf("%s", "[");
    for (i_0001 = 0; i_0001 < C.shape[0] - 1; i_0001 += 1)
    {
        printf("%s", "[");
        for (i_0002 = 0; i_0002 < C.shape[1] - 1; i_0002 += 1)
        {
            printf("%ld ", GET_ELEMENT(C, nd_int64, (int64_t)i_0001, (int64_t)i_0002));
        }
        printf("%ld]\n", GET_ELEMENT(C, nd_int64, (int64_t)i_0001, (int64_t)C.shape[1] - 1));
    }
    printf("%s", "[");
    for (i_0003 = 0; i_0003 < C.shape[1] - 1; i_0003 += 1)
    {
        printf("%ld ", GET_ELEMENT(C, nd_int64, (int64_t)C.shape[0] - 1, (int64_t)i_0003));
    }
    printf("%ld]]\n", GET_ELEMENT(C, nd_int64, (int64_t)C.shape[0] - 1, (int64_t)C.shape[1] - 1));
    /*Matrix Production*/
    for (i = 0; i < M; i += 1)
    {
        for (j = 0; j < M; j += 1)
        {
            for (k = 0; k < N; k += 1)
            {
                GET_ELEMENT(C, nd_int64, (int64_t)i, (int64_t)j) += GET_ELEMENT(A, nd_int64, (int64_t)i, (int64_t)k) * GET_ELEMENT(B, nd_int64, (int64_t)k, (int64_t)j);
            }
        }
    }
}
/*........................................*/

