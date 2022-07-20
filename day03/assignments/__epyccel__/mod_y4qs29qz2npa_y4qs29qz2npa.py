def matrix_prod(A, B, C, N, M):
    
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)

    
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)

    
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0
    # ...

    # Matrix Production
    nb_threads = 0
    
    #$ omp parallel num_threads(8) firstprivate(nb_threads)
    #$ omp for schedule(runtime)
    p_matrix_prod(A, B, C, N, M)
    nb_threads += 1
    
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
    #$ omp end parallel
    print("Execution of Matrix production in parallele with", nb_threads, "threads")
