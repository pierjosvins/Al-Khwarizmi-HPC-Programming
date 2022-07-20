#ifndef PI_GDTVG7YLMKBP_GDTVG7YLMKBP_H
#define PI_GDTVG7YLMKBP_GDTVG7YLMKBP_H

#include <stdlib.h>
#include <stdint.h>


double f(double a);
double pi(int64_t n, double h);
double pi_openmp(int64_t n, double h, int64_t nb_tasks);
#endif // PI_GDTVG7YLMKBP_GDTVG7YLMKBP_H
