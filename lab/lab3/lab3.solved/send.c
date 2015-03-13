#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10000
#define VERBOSE

int main(int argc, char *argv[])
{
#undef VERBOSE
	msg t;
	int i;
	
	printf("[SENDER] Starting.\n");	
	init(HOST, PORT);

  int bdp = atoi(argv[1]) * 1024;
	printf("[SENDER]: BDP=%d\n", bdp);
  int packetsCount = bdp / (sizeof(msg)) * 10;
  printf("packets count %d\n", packetsCount);

  mesaj m;
  for (i = 0; i < packetsCount; i++) {
    m.type = SEND;
    m.number = i; 
    t.len = MSGSIZE;
    memset(m.payload, 1, sizeof(m.payload));
    memcpy(t.payload, &m, sizeof(mesaj));
    assert(send_message(&t));
#ifdef VERBOSE
    printf("Sent message %d\n", i);
#endif
  }

	for (i = 0; i < COUNT; i++) {
    assert(recv_message(&t) > 0);
		m = *(mesaj*)t.payload;
    assert(m.type == ACK);
#ifdef VERBOSE
    printf("Sender received ack for %d\n", i);
#endif
    if(m.number == i) {
      m.number = packetsCount + i;
      if(packetsCount + i < COUNT) {
        m.type = SEND;
        t.len = MSGSIZE;
        memcpy(t.payload, &m, sizeof(mesaj));
        assert(send_message(&t) > 0);
      }
    }
	}

	printf("[SENDER] Job done, all sent.\n");	
	return 0;
}
