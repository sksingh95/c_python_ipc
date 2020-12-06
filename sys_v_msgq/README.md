# System V message queue
## Setup
pip install sysv_ipc

## Compile
 $ gcc msgq_recv.c -o msgq_recv.out  
 $ gcc msgq_send.c -o msgq_send.out

## Run these command in different terminal
### C to Python
 $ python msgq_recv.py  
 $ ./msgq_send.out

### Python to C
 $ python msgq_send.py  
 $ ./msgq_recv.out
