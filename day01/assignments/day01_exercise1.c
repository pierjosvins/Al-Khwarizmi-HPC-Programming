#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50000000
#define MAX_STRIDE 20

void main()
{
    
  double *data, mean, rate, msec;
    
  struct timeval tm1, tm2;
    
  data = malloc(N*MAX_STRIDE*sizeof(double));
    
  for (int i = 0; i <= N*MAX_STRIDE; i++){
    data[i] = (rand() + 1);
  }
  
  printf(" istride CPU Bandwidth \n");
  for (int istride = 1; istride <= MAX_STRIDE; istride++) {
      
    mean = 0.0;
    clock_t start_t = clock();

    for (int i = 0; i < N*istride; i += istride) {
      mean = mean + data[i];
    }
    mean = mean / N;
    clock_t end_t = clock();

    msec = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*1000.0;
    rate = sizeof(double)*N*(1000.0/msec) / (1024*1024);
      
    printf(" %d, %f, %f \n",istride , msec, rate);
  }
}
