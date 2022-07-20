# write your program here

import numpy as np
import random 
import timeit
from mpi4py import MPI

COMM = MPI.COMM_WORLD
SIZE = COMM.Get_size()
RANK = COMM.Get_rank()

INTERVAL= 1000
random.seed(42)  

if RANK == 0:
    values_sum = np.array([0.])
else:
    values_sum = None
    
def compute_points():
    
    random.seed(42)  
    
    circle_points= np.array([0.])

    # Total Random numbers generated= possible x 
    # values* possible y values 
    num_rank = int(INTERVAL**2 / SIZE)
    inf_val = 1 + (RANK * num_rank)
    sup_val = 1 + (RANK +1) * num_rank

    COMM.Barrier()
    for i in range(inf_val, sup_val): 
      
        # Randomly generated x and y values from a 
        # uniform distribution 
        # Rannge of x and y values is -1 to 1 
                
        rand_x= random.uniform(-1, 1) 
        rand_y= random.uniform(-1, 1) 
      
        # Distance between (x, y) from the origin 
        origin_dist= rand_x**2 + rand_y**2
      
        # Checking if (x, y) lies inside the circle 
        if origin_dist<= 1: 
            circle_points[0] += 1
      
        # Estimating value of pi, 
        # pi= 4*(no. of points generated inside the  
        # circle)/ (no. of points generated inside the square) 
    
         
    COMM.Barrier()
    
    # Get partial results from all processors then calculate the sum
    COMM.Reduce(circle_points, values_sum, op=MPI.SUM, root=0)
    
    return values_sum



start = timeit.default_timer()
circle_points = compute_points()
end = timeit.default_timer()

if RANK == 0:
    print("I am process 0")
    pi = 4* circle_points[0]/ INTERVAL**2 
    print("Circle points number :",circle_points[0])
    print("Final Estimation of Pi=", pi, "cpu time :",end-start)
