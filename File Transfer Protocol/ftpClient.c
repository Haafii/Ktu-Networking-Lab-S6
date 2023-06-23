#include<stdio.h>
#include<sys/types.h> 
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc , char * argv[]){
	char command[10]={0},fileName[10]={0},buffer[1024]={0};
	int sockfd , portno , n;
	portno = atoi(argv[1]);
	struct sockaddr_in serv_addr;
	
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port =htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	
	printf("Enter command:");
	scanf(" %s",command);
	printf("Enter file name:");
	scanf(" %s",fileName);
	
	connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
		
	n=write(sockfd,command,sizeof(command)); // send command to server
	if(n < 0)
	printf("Error");
	
	n=write(sockfd,fileName,sizeof(fileName)); //send file name to server
	if(n < 0)
		printf("Error");
	
	FILE *fp; 
	
	if(!strcmp(command,"get")){ // checking the command with string 'get'
		fp=fopen("newFileGet.txt","w");//open or create a file named newFileGet.txt in write mode
		n=read(sockfd,buffer,1023); // recive data from server and stored in buffer
		if(n < 0)
			printf("Error");
		fprintf(fp,"%s",buffer); //store data in buffer to the file we created
		fclose(fp); //closing file
	}else if(!strcmp(command,"put")){ //checking the command with string 'put'
		fp=fopen(fileName,"r");  //open enterd file in read mode 
		fgets(buffer, sizeof(buffer),fp); // read data from file and store in buffer
		n=write(sockfd,buffer,1023); // send buffer data into server
		if(n < 0)
			printf("Error");
		fclose(fp);
	}else{ 
		printf("Wrong command....!");
		exit(0);	
	}
}
