#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFF_SIZE    100
#define DATA_TYPE    1
#define MSGQ_KEY     (key_t)9876

typedef struct {
    long data_type;
    unsigned char data[BUFF_SIZE];
}msgq_data_t;

int main() {
    int         msgqId;
    msgq_data_t r_data;
    int         ret;
    
    msgqId = msgget(MSGQ_KEY, IPC_CREAT | 0666);
    if(-1 == msgqId ) {
        perror("msgget");
        exit(1);
    }

    printf("msgqId:%d created.\n", msgqId);

    while(1) {
		memset(&r_data, 0, sizeof(r_data));                                  /* Clean data receive buffer. */
        ret = msgrcv(msgqId, &r_data, BUFF_SIZE, DATA_TYPE, MSG_NOERROR);    /* Dequeue data from msg Q. */ 
        if(-1 == ret) {
            perror("msgrcv");
            exit(1);
        }
        printf("Msg rcvd : %s.\n", r_data.data);
    }
}

 