#include "pi_nm1qs6ga3nph_nm1qs6ga3nph.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


/*........................................*/
double f(double a)
{
    return 4.0 / (1.0 + a * a);
}
/*........................................*/
/*........................................*/
double pi(int64_t n, double h, int64_t nb_tasks)
{
    int64_t k;
    int64_t i;
    double x;
    double Pi_calc;
    printf("%s %ld %s\n", "Execution of PI in parallel with", nb_tasks, "threads");
    #pragma omp parallel num_threads(nb_tasks)
    {
        #pragma omp for
        for (k = 0; k < 100; k += 1)
        {
            Pi_calc = 0.0;
            for (i = 0; i < n; i += 1)
            {
                x = h * (i + 0.5);
                Pi_calc += f(x);
            }
            Pi_calc = h * Pi_calc;
        }
    }
    return Pi_calc;
}
/*........................................*/

