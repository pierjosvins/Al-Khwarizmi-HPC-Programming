#include "mod_i7xkuc61pz87_i7xkuc61pz87.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>


/*........................................*/
int jacobi_with_openmp(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, int64_t nb_tasks, double *stand, int64_t *iteration)
{
    t_ndarray x_courant = {.shape = NULL};
    int64_t i;
    int64_t j;
    double absmax;
    double curr;
    printf("%s %ld %s\n", "Execution of Jacobi in parallel with", nb_tasks, "threads");
    /*Jacobi method resolution*/
    x_courant = array_create(1, (int64_t[]){n}, nd_double);
    (*iteration) = 0;
    /*___________________________________CommentBlock___________________________________*/
    /*                                                                                   */
    /*    if there is a n consecutive for loops (nested loops), we will add collapse(n). */
    /*    We will also reduce some operators applied on like +, * in our case.           */
    /*                                                                                   */
    /*___________________________________________________________________________________*/
    #pragma omp parallel num_threads(nb_tasks)
    {
        while((1 != 0))
        {
            (*iteration) += 1;
            #pragma omp for
            for (i = 0; i < n; i += 1)
            {
                GET_ELEMENT(x_courant, nd_double, (int64_t)i) = 0;
                for (j = 0; j < i; j += 1)
                {
                    GET_ELEMENT(x_courant, nd_double, (int64_t)i) += GET_ELEMENT(a, nd_double, (int64_t)j, (int64_t)i) * GET_ELEMENT(x, nd_double, (int64_t)j);
                }
                for (j = i + 1; j < n; j += 1)
                {
                    GET_ELEMENT(x_courant, nd_double, (int64_t)i) += GET_ELEMENT(a, nd_double, (int64_t)j, (int64_t)i) * GET_ELEMENT(x, nd_double, (int64_t)j);
                }
                GET_ELEMENT(x_courant, nd_double, (int64_t)i) = (GET_ELEMENT(b, nd_double, (int64_t)i) - GET_ELEMENT(x_courant, nd_double, (int64_t)i)) / GET_ELEMENT(a, nd_double, (int64_t)i, (int64_t)i);
            }
            /*Convergence test*/
            absmax = 0.0;
            #pragma omp for
            for (i = 0; i < n; i += 1)
            {
                curr = fabs(GET_ELEMENT(x, nd_double, (int64_t)i) - GET_ELEMENT(x_courant, nd_double, (int64_t)i));
                if (curr > absmax)
                {
                    absmax = curr;
                }
            }
            (*stand) = absmax / n;
            if ((*stand) <= eps || (*iteration) > n)
            {
                break;
            }
            /*copy x_courant into x*/
            #pragma omp for
            for (i = 0; i < n; i += 1)
            {
                GET_ELEMENT(x, nd_double, (int64_t)i) = GET_ELEMENT(x_courant, nd_double, (int64_t)i);
            }
        }
    }
    free_array(x_courant);
    return 0;
}
/*........................................*/

