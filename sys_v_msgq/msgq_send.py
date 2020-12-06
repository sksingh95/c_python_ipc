import sysv_ipc
import time

DATA_TYPE = 1
MSGQ_KEY  = 9876

count = 0
try:
    mq = sysv_ipc.MessageQueue(MSGQ_KEY, sysv_ipc.IPC_CREAT)
except sysv_ipc.ExistentialError:
    print "ERROR: message queue creation failed"   
    
while(True):
    data = "Sent from Python program [{}].".format(count)
    print(data)
    mq.send(data, True, type=DATA_TYPE)
    count+=1
    time.sleep(1)