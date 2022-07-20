#ifndef PI_7ECMOPY473K1_7ECMOPY473K1_H
#define PI_7ECMOPY473K1_7ECMOPY473K1_H

#include <stdlib.h>
#include <stdint.h>


double f(double a);
double pi(int64_t n, double h);
double pi_openmp(int64_t n, double h, int64_t nb_tasks);
#endif // PI_7ECMOPY473K1_7ECMOPY473K1_H
