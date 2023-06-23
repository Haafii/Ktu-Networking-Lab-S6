#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc , char * argv[]){

	int sockfd , portno , n;
	char buffer[255] , result[255];
	portno = atoi(argv[1]);
	struct sockaddr_in serv_addr;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port =htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	
	bzero(buffer,256);
	bzero(result,256);
	printf("Enter message:");
	scanf("%s",buffer);
	
	n=write(sockfd,buffer,255);
	printf("Reply is:");
	n=read(sockfd,result,255);
	printf("%s",result);
	
}

