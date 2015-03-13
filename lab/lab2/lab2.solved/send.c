#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include "lib.h"
#define HOST "127.0.0.1"
#define PORT 10000

int main(int argc,char** argv) {
  init(HOST,PORT);
  msg t;
  mesaj m;

  int i;
  char *test = strdup("TEST");
  for(i = 0; i < 40; i++) { 
    memcpy(m.payload, test, 4);
    m.parity = pkt_parity(test, 4);
    t.len = 4 + sizeof(int);
    memcpy(t.payload, &m, t.len);
    send_message(&t);
    /*
    assert(recv_message(&r) >= 0);
    m = *(mesaj*)r.payload;
    if(pkt_parity(m.payload, r.len - 1) == m.parity)
      printf("Pachetul este OK\n");
    else
      printf("Pachetul este eronat\n");
    */
  }

  /*
  assert(recv_message(&r) >= 0);
  m = *(mesaj*)r.payload;
  assert(m.type == ACC);

  struct stat st;
  stat(argv[1], &st);
  m.type = LENGTH;
  memcpy(m.payload, &st.st_size, sizeof(int));
  memcpy(t.payload, &m, sizeof(int) * 2);
  t.len = sizeof(int) * 2;
  send_message(&t);

  assert(recv_message(&r) >= 0);
  m = *(mesaj*)r.payload;
  assert(m.type == ACC);

  const int bucket_size = PAYLOAD_SIZE - 4;
  FILE *f = fopen(argv[1], "rb");
  int i;
  for (i = 0; i < st.st_size; i += bucket_size) {
    m.type = INFO;
    int bytesRead = fread(m.payload, 1, bucket_size, f); 
    t.len = bytesRead + sizeof(int);
    memcpy(t.payload, &m, t.len); 
    send_message(&t);
    assert(recv_message(&r) >= 0);
    m = *(mesaj*)r.payload;
    assert(m.type == ACC);
  } */

  return 0;
}
