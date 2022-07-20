#include "hello.h"
#include "omp.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
int main()
{
    int64_t rank;
    int64_t total;
    #pragma omp parallel
    {
        rank = omp_get_thread_num();
        total = omp_get_num_threads();
        printf("%s %ld %s\n", "Hello from the rank", rank, "thread");
    }
    printf("%s %ld %s\n", "Parallel execution of hello_world with", total, "threads");
    return 0;
}