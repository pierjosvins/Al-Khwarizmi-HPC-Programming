def matrix_prod_with_openmp(A:'float[:,:]', B:'float[:,:]', C:'float[:,:]', N:'int', M:'int', nb_threads:'int'):
    
    """
    if there is a n consecutive for loops (nested loops) , we will add collapse(n).
    We will also reduce some operators applied on like +, * in our case.
    """
    
    #$ omp parallel num_threads(nb_threads)
    #$ omp for reduction(+:A) collapse(2) nowait
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)

    #$ omp for reduction(-:B) collapse(2) nowait
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)

    #$ omp for collapse(2)
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0

    # Matrix Production
    #$ omp for collapse(3)
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
    #$ omp end parallel
    print("Execution of Matrix production in parallele with",nb_threads, "threads")
