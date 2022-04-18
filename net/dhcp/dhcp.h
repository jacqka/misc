#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<getopt.h>


typedef struct dhcp_server_cxt {
	
	struct sockaddr_in *serv;

	FILE *fstream, *ftemp;
	fd_set fd;
	
	time_t start, end;
	double elapsed; 
	
	const char fipaddr[50];
	char stline[50], rmline[1], ipcount[5];

	} DHCP_SERVER;



int err(int stat, char *msg[]){

	if(!stat || stat < 0){
	
		if(!msg){
			exit(-1);	
				}
			
			perror(msg);
				exit(-1);	
				
			}
	return 0;}

