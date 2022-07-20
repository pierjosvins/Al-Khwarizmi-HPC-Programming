def jacobi_with_openmp(a : 'float[:,:]', b : 'float[:]', x : 'float[:]', n :'int', eps: 'float', nb_tasks: 'int'):
    print("Execution of Jacobi in parallel with", nb_tasks, "threads")
    
    # Jacobi method resolution
    import numpy as np
    import math
    x_courant = np.empty(n, dtype=np.double)
    iteration = 0
    
    """
    if there is a n consecutive for loops (nested loops), we will add collapse(n).
    We will also reduce some operators applied on like +, * in our case.
    """
    
    #$ omp parallel num_threads(nb_tasks)
    while(1):
        iteration += 1
        
        #$ omp section
        for i in range(n):
            x_courant[i] = 0
            
            
            #$ omp section 
            for j in range(i):
                x_courant[i] += a[ j, i ] * x[j]
             #$ omp end section   
            
            #$ omp section
            for j in range(i + 1, n):
                x_courant[i] += a[ j, i ] * x[j]
            #$ omp end section
            
            x_courant[i] = (b[i] - x_courant[i]) / a[ i, i ]
        #$ omp end section
        # Convergence test
        absmax = 0.
        
        #$ omp for
        for i in range(n):
            curr = math.fabs(x[i] - x_courant[i])
            if curr > absmax:
                absmax = curr
                
        stand = absmax / n
        if stand <= eps or iteration > n:
            break

        # copy x_courant into x
        
        #$ omp for
        for i in range(n):
            x [i] = x_courant[i]
    
    #$ omp end parallel
    return stand, iteration
