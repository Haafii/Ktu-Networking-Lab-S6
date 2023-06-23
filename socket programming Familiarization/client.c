#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


void main(int argc,char * argv[]){
	int sockfd,portno,n;
	portno=atoi(argv[1]);
	//char buffer[256];
	struct sockaddr_in serv_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(socket<0)
		printf("ERROR");
		
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port =htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	n=write(sockfd,"buffer",6);
}

