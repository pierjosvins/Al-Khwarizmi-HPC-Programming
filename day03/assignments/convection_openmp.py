
import numpy as np
from pyccel.epyccel import epyccel
from pyccel.stdlib.internal.openmp import omp_in_parallel,omp_get_thread_num, omp_get_num_threads

def threads_num():
    n = omp_get_num_threads()
    return n

def solve_2d_linearconv_pyccel(u:'float[:,:]', un:'float[:,:]', nt:'int', dt:'float', dx:'float', dy:'float', c:'float'): 
    
    row, col = u.shape
    #$omp parallel 
    #$omp for
    for n in range(nt + 1):
        un[:] = u[:]
        row, col = u.shape
        #$omp for collapse(2)
        for j in range(1, row):
            for i in range(1, col):
                u[j, i] = (un[j, i] - (c * dt / dx * (un[j, i] - un[j, i - 1])) -
                                      (c * dt / dy * (un[j, i] - un[j - 1, i])))
                u[0, :] = 1
                u[-1, :] = 1
                u[:, 0] = 1
                u[:, -1] = 1
    #$omp end parallel   
    
    return 0



if __name__ == "__main__" :
    import time
        
    nx = 101
    ny = 101
    nt = 100
    c = 1.0
    dx = 2 / (nx - 1)
    dy = 2 / (ny - 1)
    sigma = .2
    dt = sigma * dx

    x = np.linspace(0, 2, nx)
    y = np.linspace(0, 2, ny)

    u0 = np.ones((ny, nx))
    u0[int(.5 / dy):int(1 / dy + 1),int(.5 / dx):int(1 / dx + 1)] = 2 
    u = u0.copy()
    un = np.ones((ny, nx))
    
    tcpu_0 = time.process_time()
    print(threads_num())
    solve_2d_linearconv_pyccel(u, un, nt, dt, dx, dy, c)
    tcpu_1 = time.process_time()
    tcpu = tcpu_1 - tcpu_0
    print("cpu time is ",tcpu)
