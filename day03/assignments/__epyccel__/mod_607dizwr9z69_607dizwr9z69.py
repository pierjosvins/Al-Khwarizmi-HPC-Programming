def matrix_prod(A : 'int[:, :]', B :'int[:;, :]', C : 'int[:, :]', N: 'int', M: 'int'):
    for i in range( M ):
        for j in range( N ):
            A[i, j] = (i + 1) + (j + 1)

    
    for i in range( N ):
        for j in range( M ):
            B[i, j] = (i + 1) - (j + 1)

    
    for i in range( M ):
        for j in range( M ):
            C[i, j] = 0
    # ...
    print(C)
    # Matrix Production
    
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[i, j] += A[i, k] * B[k,j]
