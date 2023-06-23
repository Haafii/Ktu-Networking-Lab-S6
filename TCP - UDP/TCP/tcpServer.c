#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void main(int argc,char * argv[]){
	int serv_sockfd,portno,client,newsockfd,n;
	char buffer[256] , rev[256];
	portno=atoi(argv[1]);
	struct sockaddr_in serv_addr,client_addr;
	serv_sockfd =socket(AF_INET, SOCK_STREAM, 0);
	
	if(serv_sockfd<0)
		printf("ERROR");
		
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port =htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	bind(serv_sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	listen(serv_sockfd,5);
	client=sizeof(client_addr);
	newsockfd=accept(serv_sockfd,(struct sockaddr*)&client_addr,&client);
	bzero(buffer,256);
	bzero(rev,256);
	n=read(newsockfd,buffer,256);
	printf("the message : %s\n",buffer);
	int i, j , len = strlen(buffer);

	for(i = len -1,j = 0 ; i>=0;i--,j++)
		rev[j] = buffer[i];

	
	n=write(newsockfd,rev,256);

}

