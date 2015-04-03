/*
 *  	Protocoale de comunicatii: 
 *  	Laborator 6: UDP
 *	client mini-server de backup fisiere
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
	fprintf(stderr,"Usage: %s ip_server port_server file\n",file);
	exit(0);
}

/*:
 *	Utilizare: ./client ip_server port_server nume_fisier_trimis
 */
int main(int argc,char**argv)
{	int sockfd = socket(PF_INET,SOCK_DGRAM,0);
	struct sockaddr_in addr;
	int fd;
	int rc;
	char buf[BUFLEN];
	int bytesRead;


	if (argc!=4) 
		usage(argv[0]);


	DIE((fd=open(argv[3],O_RDONLY))==-1,"open file");





	/*Setare struct sockaddr_in pentru a specifica unde trimit datele*/
	addr.sin_family = AF_INET;
	addr.sin_port = 1234;

	struct in_addr inaddr;	
	char *name = strdup("127.0.0.1");
	inet_aton(name,&inaddr); 
	addr.sin_addr = inaddr;



	do {
		bytesRead = read(fd,buf,BUFSIZE);  
		sendto(sockfd, buf, BUFSIZE,0, &addr, sizeof(struct sockaddr_in));
		//printf("bytesRead=%d\n",bytesRead);
		//printf("%s",buffer);
	} while (bytesRead != 0);
    	if (bytesRead == -1)
    		{
        	printf("Error in reading!\n");
        	exit(0);
    	}

	/* TODO 1 - close file */
	rc = close(fd);
	DIE(rc < 0, "close");

/*
	char *buff = (char *) malloc(10);
	strcpy(buff,"Hello!");
	printf("Trimit: %s\n", buff);
	sendto(sockfd, buff, 10,0, &addr, sizeof(struct sockaddr_in));
	printf("AM trimis");
*/


	rc = close(sockfd);
	DIE(rc < 0, "close socket");
	/*if (argc!=4)
	  usage(argv[0]);

	  int fd;
	  struct sockaddr_in to_station;
	  char buf[BUFLEN];


	/*Deschidere socket*/


	/* Deschidere fisier pentru citire */
	//DIE((fd=open(argv[3],O_RDONLY))==-1,"open file");

	/*Setare struct sockaddr_in pentru a specifica unde trimit datele*/



	/*
	 *  cat_timp  mai_pot_citi
	 *		citeste din fisier
	 *		trimite pe socket
	 */	


	/*Inchidere socket*/


	/*Inchidere fisier*/

	return 0;
}
