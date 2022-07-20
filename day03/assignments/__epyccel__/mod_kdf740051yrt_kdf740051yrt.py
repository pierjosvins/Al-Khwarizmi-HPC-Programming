def matrix_prod(A : 'float[:,:]', B :'float[:,:]', C : 'float[:,:]', N: 'int', M: 'int', nb_threads: 'int'):
    
    """
    if there is a n consecutive for loops, we will add collapse(n).
    We will also reduce some operators applied on like +, * in our case.
    """
    
    #$ omp parallel num_threads(nb_threads)
    #$ omp for collapse(2) reduction (+: A) schedule(runtime)
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)

    #$ omp for collapse(2) reduction (+: B) schedule(runtime)
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)

    #$ omp for collapse(2) schedule(runtime)
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0

    # Matrix Production
    #$ omp for collapse(3) reduction (+: C) reduction (*: C) schedule(runtime)    
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
    #$ omp end parallel
    print("Execution of Matrix production in parallele with",nb_threads, "threads")
