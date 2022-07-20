# write your program here

from mpi4py import MPI

# Communication, Rank, Size
COMM = MPI.COMM_WORLD
SIZE = COMM.Get_size()
RANK = COMM.Get_rank()
LAST_RANK = SIZE - 1
print("Hello from the rank", RANK, "process")

if RANK == LAST_RANK:
   print("Parallel execution of hello_world with", SIZE, "process")
