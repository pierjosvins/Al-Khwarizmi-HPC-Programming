def solve_2d_linearconv_pyccel(u:'float[:]', un:'float[:]', nt:'int', dt:'float', dx:'float', c:'float'):
    
    row, col = u.shape

    #fill the update of u and v
    for n in range(nt + 1):
        for i in range(nx): un[i] = u[i]

        for j in range(1, row):
            for i in range(1, col):
                u[j, i] = (un[j, i] - (c * dt / dx * (un[j, i] - un[j, i - 1])) - (c * dt / dy * (un[j, i] - un[j - 1, i])))
                u[0, :] = 1
                u[-1, :] = 1
                u[:, 0] = 1
                u[:, -1] = 1
    return 0
