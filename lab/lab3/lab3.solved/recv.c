#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10001
#define VERBOSE

int main(void)
{
#undef VERBOSE
	msg r;
  mesaj m;
	int i;
	
	printf("[RECEIVER] Starting.\n");
	init(HOST, PORT);
	
	for (i = 0; i < COUNT; i++) {
    assert(recv_message(&r) > 0);
    m = *(mesaj*)r.payload;
#ifdef VERBOSE
    printf("Received message %d\n", i);
#endif
    assert(m.type == SEND);
    m.type = ACK;
    memcpy(r.payload, &m, sizeof(m));
    assert(send_message(&r) > 0);
	}

	printf("[RECEIVER] Finished receiving..\n");
	return 0;
}
