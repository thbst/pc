#ifndef LIB
#define LIB

#define NAME 1
#define LENGTH 2
#define ACC 3
#define INFO 4
#define PAYLOAD_SIZE 1400

typedef struct {
  // int type;
  int len;
  char payload[PAYLOAD_SIZE];
} msg;

typedef struct {
  int parity;
  char payload[PAYLOAD_SIZE - sizeof(int)];
} mesaj; 

int byte_parity(char c) {
  int ret = 0, i = 0;
  for(i = 0; i < 8; i++)
    ret ^= (((1 << i) & c) >> i);
  return ret;
} 

int pkt_parity(char *payload, int len) {
  int ret = 0;
  int i = 0;
  for(i = 0; i < len; i++)
    ret ^= byte_parity(payload[i]);
  return ret;
} 

void print_bits(char ch) {
  char c = 0;
  for(c = 0; c < 8; c++)
    if(((1 << c) & ch))
      printf("1");
    else
      printf("0");
  printf("\n");
} 

char insert_bit(char *ch, char bit, int pos) {
  char carry = (((1 << 7) & (*ch)) >> 7);
  char right = (((1 << (7 - pos)) - 1) << pos);
  right &= (*ch);
  right <<= 1;
  char left = (1 << pos) - 1;
  left &= (*ch);
  char construct = 0;
  construct |= right;
  construct |= left;
  construct |= (bit << (pos - 1));
  (*ch) = construct;
  return carry;
} 

void insert_bit1(char *payload, char bit, int len, int pos) {
  int i;
  int vpos = pos / 8;
  int bitpos = pos % 8;
  char carry = insert_bit(&payload[vpos], bit, bitpos);
  for(i = vpos + 1; i < len; i++)
    carry = insert_bit(&payload[i], carry, 1);
  insert_bit(&payload[len], carry, 1);
} 

void init(char* remote,int remote_port);
void set_local_port(int port);
void set_remote(char* ip, int port);
int send_message(const msg* m);
int recv_message(msg* r);
//msg* receive_message_timeout(int timeout);

#endif

