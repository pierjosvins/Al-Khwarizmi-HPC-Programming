def f(a: 'float'):
    return 4.0 / (1. + a * a)


def pi(n : 'int', h: 'float'):
    print("Execution of PI in parallel with", nb_tasks,"threads")
    
    for k in range(100):
        Pi_calc = 0.
        for i in range(n):
            x = h * (i + 0.5)
            Pi_calc += f(x)

        Pi_calc = h * Pi_calc
    
    return Pi_calc

def pi_openmp(n : 'int', h: 'float', nb_tasks: 'int'):
    print("Execution of PI in parallel with", nb_tasks,"threads")
    
    #$ omp parallel num_threads(nb_tasks)
    
    #$ omp for firstprivate(Pi_calc)
    for k in range(100):
        Pi_calc = 0.
        for i in range(n):
            x = h * (i + 0.5)
            #$ omp critical
            Pi_calc += f(x)
            #$ omp end critical

        Pi_calc = h * Pi_calc
    #$ omp end parallel
    
    return Pi_calc
