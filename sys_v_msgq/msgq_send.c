#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
    msgq_data_t s_data;
    int         ret;
	int         count = 0;
    
    msgqId = msgget(MSGQ_KEY, IPC_CREAT | 0666);
    if(-1 == msgqId ) {
        perror("msgget");
        exit(1);
    }
    printf("msgqId:%d created.\n", msgqId);

    while(1) {
        s_data.data_type = DATA_TYPE;
        sprintf(s_data.data, "Sent from C program  [%d].", count);
		printf("Sending data... %s\n", s_data.data);
        ret = msgsnd(msgqId, &s_data, strlen(s_data.data), MSG_NOERROR);
        if(-1 == ret) {
            perror("msgsnd");
            exit(1);
        }
		count++;
		sleep(1);
    }
}

 