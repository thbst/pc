#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10001

/*
void sendAcc() {
  msg t;
  mesaj m;
  m.type = ACC;
  t.len = sizeof(int);
  memcpy(t.payload, &m, sizeof(int));
  send_message(&t);
} */

int main(int argc,char** argv){
  msg r;
  init(HOST,PORT);

  int i, j;
  for(i = 0; i < 40; i++) { 
    assert(recv_message(&r) >= 0);
    mesaj m = *(mesaj*)r.payload;
    if(m.parity == pkt_parity(m.payload, r.len - 4))
      printf("Pachetul este ok\n");
    else
      printf("Pachetul este eronat\n");
  }

  /*
  char *fname = (char*)calloc(strlen(m.payload) + 5, sizeof(char));
  strcpy(fname, m.payload);
  strcat(fname, ".rec");
  printf("Numele fisierului in care se scrie este : %s\n", fname);
  sendAcc();

  assert(recv_message(&r) >= 0);
  m = *(mesaj*)r.payload;
  assert(m.type == LENGTH);

  int file_size = *(int*)m.payload;
  printf("Dimensiunea fisierului trimis este : %d\n", file_size);
  sendAcc();

  FILE *f = fopen(fname, "wb");
  const int bucket_size = PAYLOAD_SIZE - sizeof(int); 
  int i;
  for(i = 0; i < file_size; i += bucket_size) {
    assert(recv_message(&r) >= 0);
    m = *(mesaj*)r.payload;
    assert(m.type == INFO);
    fwrite(m.payload, r.len - sizeof(int), 1, f);
    sendAcc();
  } */
  return 0;
}
