#include<stdio.h>
#include<sys/types.h> 
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc , char * argv[]){
	int serv_sockfd,portno,client,newsockfd,n;
	char command[10]={0} , fileName[10]={0} , buffer[1024]={0};
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
	n=read(newsockfd,command,sizeof(command));//read command from client
	if(n < 0)
		printf("Error");
	n=read(newsockfd,fileName,sizeof(fileName));//read file name from client
	if(n < 0)
		printf("Error");
	
	FILE *fp; 
	if(!strcmp(command,"get")){ //checking the command is 'get' 
		fp=fopen(fileName,"r"); //open enterrd file in read mode
		fgets(buffer, sizeof(buffer),fp); //store data in file into buffer
		n=write(newsockfd,buffer,1023); //send buffer content into client
		if(n < 0)
			printf("Error");
		fclose(fp); //close the file
	}else if(!strcmp(command,"put")){ //checking the command is 'put' 
		fp=fopen("newFilePut.txt","w"); // create or open  a file with name newFilePut.txt in write mode
		n=read(newsockfd,buffer,1023); // read data from client into buffer
		if(n < 0)
			printf("Error");
		fprintf(fp,"%s",buffer); // write buffer content into opened file
		fclose(fp);
	}else{
		printf("Wrong command....!");
		exit(0);	
	}
}
