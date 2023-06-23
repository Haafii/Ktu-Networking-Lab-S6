#include<stdio.h>
#include<sys/types.h> 
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int serv_sockfd,portno,clilen,newsockfd,rec1,i,j,rec2,k=0,sen1;
	struct sockaddr_in serv_addr,cli_addr;
	char buffer[256];
	
	serv_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	portno = atoi(argv[1]);
     	serv_addr.sin_family = AF_INET;
     	serv_addr.sin_addr.s_addr = INADDR_ANY;
     	serv_addr.sin_port = htons(portno);
     	
     	bind(serv_sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr));
     	
     	listen(serv_sockfd,5);
     	clilen = sizeof(cli_addr);
     	
     	rec1= recvfrom(serv_sockfd,&i, sizeof(i), MSG_WAITALL, ( struct sockaddr *)&cli_addr,&clilen);
     		printf( "Received num = %d\n",i);
     	if (rec1<0)
     		printf("error");

        	
     	rec2= recvfrom(serv_sockfd,&j, sizeof(j), MSG_WAITALL, ( struct sockaddr *)&cli_addr,&clilen);
     	if (rec1<0)
     		printf("error");

     	printf( "Received num = %d\n",j);
     	
     	k=i+j;
     	sen1=sendto(serv_sockfd, &k, sizeof(k),MSG_CONFIRM, (const struct sockaddr *) &cli_addr,clilen);
     	if (sen1<0)
     		printf("error");
	return 0;
}
  
