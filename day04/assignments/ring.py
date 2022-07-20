# filename = sending_ring.py
from mpi4py import MPI

COMM = MPI.COMM_WORLD
SIZE = COMM.Get_size()
RANK = COMM.Get_rank()
LAST_RANK = SIZE - 1
tag = 0
data = 10

if RANK == 0:
    COMM.send(data, dest = RANK + 1, tag = tag)
    print("Process {rank} send data = {data} to process {dest}".format(rank=RANK, data=data, dest=RANK + 1))
    
    
elif RANK < LAST_RANK:
    recv_data = COMM.recv(source = RANK - 1, tag=tag)
    COMM.send(recv_data, dest = RANK + 1, tag = tag)
    print("Process {rank} received data = {data} from process {source} and sends it to process {dest}".format(rank=RANK, data = recv_data, source = RANK -1, dest=RANK + 1))
    
else:
    recv_data = COMM.recv(source = RANK - 1, tag=tag)
    print("Process {rank} receive data = {data} from process {source}".format(rank=RANK, data = recv_data, source = RANK -1))
    
