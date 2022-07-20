#ifndef PI_GBUYL2HWSJZB_GBUYL2HWSJZB_H
#define PI_GBUYL2HWSJZB_GBUYL2HWSJZB_H

#include <stdlib.h>
#include <stdint.h>


double f(double a);
double pi(int64_t n, double h);
double pi_openmp(int64_t n, double h, int64_t nb_tasks);
#endif // PI_GBUYL2HWSJZB_GBUYL2HWSJZB_H
