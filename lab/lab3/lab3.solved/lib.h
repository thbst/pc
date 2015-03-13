#ifndef LIB
#define LIB

#define MSGSIZE		1400
#define COUNT		2000
#define SEND 1
#define ACK 0

typedef struct {
  int len;
  char payload[MSGSIZE];
} msg;

typedef struct {
  int number, type;
  char payload[MSGSIZE - 2 * sizeof(int)];
} mesaj;

void init(char* remote,int remote_port);
void set_local_port(int port);
void set_remote(char* ip, int port);
int send_message(const msg* m);
int recv_message(msg* r);

#endif

