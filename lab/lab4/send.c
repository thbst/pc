#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10000

int main(int argc, char *argv[])
{
	msg t;
	int i, res;
	int seq=0;
	printf("[SENDER] Starting.\n");	
	init(HOST, PORT);
  int nAck = 0; 
	/* printf("[SENDER]: BDP=%d\n", atoi(argv[1])); */
	printf("%d\n",atoi(argv[1]));
	int dimF = (atoi(argv[1]) * pow(1000,1))/(MSGSIZE * 8);
	dimF = 1;
	printf("%d\n", COUNT);
	i=0;
	while (i < COUNT) {
		/* cleanup msg */
		
		while(nAck < dimF) {
			memset(&t, 0, sizeof(msg));
		
		/* gonna send an empty msg */
			t.len = MSGSIZE;
			printf("Send %d \n", i);
		/* send msg */
		  t.s = i;
			res = send_message(&t);
			nAck++;
			i++;
		
		if (res < 0) {
			perror("[SENDER] Send error. Exiting.\n");
			return -1;
			}
			}
		/* wait for ACK */

		res = recv_message(&t);
		
		if (res >0) {

		if(strcmp (t.payload, "ACK") == 0  && t.s == seq) {
		       printf("ACK %d\n", seq);
		       nAck --;
		       seq++;
		  }
		  }
	}
	
    while(nAck>0) {
    res = recv_message(&t);
		
		if (res < 0) {
			perror("[SENDER] Receive error. Exiting.\n");
			return -1;
		}
		
		if(strcmp (t.payload, "ACK") == 0)
		       nAck --;
		}
	printf("[SENDER] Job done, all sent.\n");
		
	return 0;
}
