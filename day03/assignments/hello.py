# write your program here

if __name__ == "__main__":
    from pyccel.stdlib.internal.openmp import omp_get_num_threads, omp_get_thread_num
    
    #$omp parallel
    rank = omp_get_thread_num()
    total = omp_get_num_threads()
    print("Hello from the rank", rank, "thread")
    #$omp end parallel
    print("Parallel execution of hello_world with", total , "threads")
