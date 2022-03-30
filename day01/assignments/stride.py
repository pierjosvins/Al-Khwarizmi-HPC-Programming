import numpy as np
import time
from numba import njit

MAX_STRIDE = 10
SEED = 86456

N = 100000
a = np.zeros(N*MAX_STRIDE, dtype=np.double);
np.random.seed(SEED)



for i_stride in range(1,MAX_STRIDE):
    mean = 0.0

    start=time.time()
    for i in range(0, N*i_stride, i_stride):
    	mean = mean + a[i];
    end=time.time()
    
    msec = (end-start) * 1000.0; # time in milli-second;
    rate = 8 * N * (1000.0 / msec) / (1024*1024);
    
    print(i_stride, mean, msec, rate)
