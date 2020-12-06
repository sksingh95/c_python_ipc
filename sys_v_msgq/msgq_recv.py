import sysv_ipc

try:
    mq = sysv_ipc.MessageQueue(9876, sysv_ipc.IPC_CREAT)
    
except sysv_ipc.ExistentialError:
    print "ERROR: message queue creation failed"
    
while True:
    message = mq.receive(type=1)
    print message[0]




