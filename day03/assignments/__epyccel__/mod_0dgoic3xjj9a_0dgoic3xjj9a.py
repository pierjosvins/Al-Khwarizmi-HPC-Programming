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
