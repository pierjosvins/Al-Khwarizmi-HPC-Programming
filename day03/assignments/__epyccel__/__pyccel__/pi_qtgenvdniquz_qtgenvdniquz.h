#ifndef PI_QTGENVDNIQUZ_QTGENVDNIQUZ_H
#define PI_QTGENVDNIQUZ_QTGENVDNIQUZ_H

#include <stdlib.h>
#include <stdint.h>


double f(double a);
double pi(int64_t n, double h);
double pi_openmp(int64_t n, double h, int64_t nb_tasks);
#endif // PI_QTGENVDNIQUZ_QTGENVDNIQUZ_H
