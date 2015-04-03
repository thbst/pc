/*
*  	Protocoale de comunicatii: 
*  	Laborator 6: UDP
*	mini-server de backup fisiere
*/




#include "helpers.h"
#include <sys/socket.h>
#include<stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFLEN 32
#define BUFSIZE 32

#define DIE(assertion, call_description)				\
	do {								\
		if (assertion) {					\
			fprintf(stderr, "(%s, %d): ",			\
					__FILE__, __LINE__);		\
			perror(call_description);			\
			exit(EXIT_FAILURE);				\
		}							\
	} while(0)

void usage(char*file)
{
	fprintf(stderr,"Usage: %s server_port file\n",file);
	exit(0);
}

/*
*	Utilizare: ./server server_port nume_fisier
*/
int main(int argc,char**argv)
{
	struct sockaddr_in from_station, addr ;
	int sockfd = socket(PF_INET,SOCK_DGRAM,0);
	if (argc!=4) 
		usage(argv[0]);

	fd = open(argv[3], O_CREAT | O_RDWR, 0644);
	DIE(fd < 0, "open destination_file");

	DIE((fd=open(argv[3],O_RDONLY))==-1,"open file");
		
		addr.sin_family = AF_INET;
		addr.sin_port = 1234;
	
		struct in_addr inaddr;	
		char *name = strdup("127.0.0.1");
		inet_aton(name,&inaddr); 
		addr.sin_addr = inaddr;
		
		bind(sockfd, &addr, sizeof(struct sockaddr_in));
		int addrlen;
		char *buff = (char *) malloc(10);
		printf("\n NU am primit inca\n");
		recvfrom(sockfd, buff, 10,0, &from_station, &addrlen);
		printf("Am primit: %s\n", buff);

		write(fd,buff,sizeof(buff));  
	close(sockfd);
	//char buf[BUFLEN];


	/*Deschidere socket*/
	
	
	/*Setare struct sockaddr_in pentru a asculta pe portul respectiv */

	
	/* Legare proprietati de socket */

	
	
	/* Deschidere fisier pentru scriere */
	//DIE((fd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644))==-1,"open file");
	
	/*
	*  cat_timp  mai_pot_citi
	*		citeste din socket
	*		pune in fisier
	*/


	/*Inchidere socket*/	

	
	/*Inchidere fisier*/

	return 0;
}
