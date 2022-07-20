# write your program here

from mpi4py import MPI
COMM = MPI.COMM_WORLD
RANK = COMM.Get_rank()

import sys
    
if RANK == 0:
    data_to_send = int(sys.argv[1])
else:
    data_to_send = None

recv_data = COMM.bcast(data_to_send, root = 0)
print("The process {rank} got value {value} from 0".format(rank=RANK, value=recv_data))
