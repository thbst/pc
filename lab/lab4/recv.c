#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10001

int main(void)
{
	msg r;
	int i, res;
	int seq;
	printf("[RECEIVER] Starting.\n");
	init(HOST, PORT);
	printf("in recv %d\n", COUNT);
	for (i = 0; i < COUNT; i++) {
		/* wait for message */
		res = recv_message(&r);
		seq = r.s;
		if (res < 0) {
			perror("[RECEIVER] Receive error. Exiting.\n");
			return -1;
		}
		
		/* send dummy ACK */
		strcpy(r.payload, "ACK");
		r.payload[3] = '\0';
		r.len = 4;
		r.s = seq;
		res = send_message(&r);
		if (res < 0) {
			perror("[RECEIVER] Send ACK error. Exiting.\n");
			return -1;
		} 
		
	}

	printf("[RECEIVER] Finished receiving..\n");
	return 0;
}
