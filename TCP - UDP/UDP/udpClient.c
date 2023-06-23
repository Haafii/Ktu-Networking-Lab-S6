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
	int sockfd,portno,i,j,k,len,sen1,sen2,rec1;
	struct sockaddr_in serv_addr;
	char buffer[256];
	
	sockfd =socket(AF_INET, SOCK_DGRAM,0);
	if (sockfd<0)  
		printf("error");
	portno = atoi(argv[1]);

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(portno);
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	
	
	printf("Please enter the first number: ");
	scanf("%d",&i);
	sen1 = sendto(sockfd, &i,sizeof(i),MSG_CONFIRM, (const struct sockaddr *) &serv_addr,sizeof(serv_addr));
	if (sen1<0)
     		printf("error");
     		
	printf("Please enter the second number: ");
	scanf("%d",&j);
	sen2 = sendto(sockfd, &j, sizeof(j),MSG_CONFIRM, (const struct sockaddr *) &serv_addr,sizeof(serv_addr));
    	if (sen2<0)
     		printf("error");
     		
        rec1 = recvfrom(sockfd,&k, sizeof(k), MSG_WAITALL, ( struct sockaddr *)&serv_addr,&len);
        if (rec1<0)
     		printf("error");
     	else
        	printf("sum = %d\n",k);

	return 0;
}
