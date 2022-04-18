#include<stdio.h>
#include<string.h>   /* Jackie Kauffman  4/2/22  started*/
#include<stdlib.h>			
#include<sys/ioctl.h>				/* no i dont use poshmark */
#include<sys/socket.h>
#include<curl/curl.h>
#include<netinet/in.h>
#include<netdb.h>
#include<openssl/ssl.h>
#include<getopt.h>


#define head_max_l 1024
#define max_l (1024 * 1024)
		
		/* im not cheating at ebay  
		 * just dont know html tags as well as i should ... */

struct memmy {

	size_t *memory;
	char head[head_max_l];
	char data[max_l];


	};

struct args {

	char *time;
	unsigned int port;
	unsigned int countd; 
};

struct curling {
	
	struct args *a;

	CURL *c;
	CURLcode res;
	
	struct sockaddr_in cli;
	struct curl_sockaddr *curl;
	curl_socket_t sock, fd;
	int port;	
	struct addrinfo *info;

	char *host;
	char *header[256];

};


int err(int stat, const char *msg[] ){


 	if( stat < 0 || !stat || !msg ){
		
		if(!stat || !msg){
		
				perror("(no name inputted) Function"); 
				exit(-1);	 
				}	
		else {
			printf("\n------- ERR --------\n");
			perror(msg); 
			exit(-1);	
				}
		}

	return 0; }


curl_socket_t snipersockopts(struct curling *c, //CURLSOCKTYPE_IPCXN,
						struct curl_sockaddr *curl){
		
	purpose = CURLSOCKTYPE_IPCXN;
	struct addrinfo *info;
	int s;
		

				c->info = realloc(info, sizeof(info));


			info->ai_flags  = AI_ADDRCONFIG;
			info->ai_protocol = IPPROTO_IP;
			info->ai_socktype = SOCK_STREAM;

	/* yeah.. this is supposed to take in_addr * for arg :( */
	s = setsockopt(c->sock, SOL_IP, IP_ADD_MEMBERSHIP, (struct addrinfo *)&c->info, sizeof(&c->info));
			err(s, "sockopt (SOL_IP) - IP_ADD_MEMBERSHIP");
	
	s = setsockopt(c->sock, SOL_SOCKET, SO_BROADCAST, (struct addrinfo *)&c->info, sizeof(&c->info));
			err(s, "sockopt (SOL_SOCKET)- SO_BROADCAST");
			
			
			free(info);
								
		return c->sock;				/* atleast socketpair regardless */
		
}

curl_socket_t snipersock(struct curling *c, curlsocktype purpose, 
					struct curl_sockaddr *curl){
	
	
	purpose = CURLSOCKTYPE_IPCXN;
	
	unsigned int host_v4 = inet_addr(c->host);

	curl_socket_t sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in *cli_p;

	cli_p = (struct sockaddr_in *)calloc(1, sizeof(c->cli));


		cli_p->sin_family = AF_INET;
		cli_p->sin_port = htons(c->port);
		cli_p->sin_addr.s_addr = c->host;

				memset((struct sockaddr_in *)&c->cli, cli_p, sizeof(cli_p));

				free(cli_p);
		return sock;} 
						
char *what_did_i_want_on_ebay_again(void *data, struct memmy *mem,  
						struct curl_sockaddr *curl){
	
					memset(mem->data, 0, sizeof(mem->data));
			
						memset(mem->data, data, sizeof(mem->data));

						free(data);					
	
											
		return mem->data; }
 		        							
int ebaysnipe_2(struct curling *c){
	struct memmy *mem;
	
	int stat = curl_easy_setopt(c->c, CURLOPT_SOCKOPTDATA, c);
			err(stat, "Curl option - SOCKOPTDATA");	
		
		stat = curl_easy_setopt(c->c, CURLOPT_SOCKOPTFUNCTION, snipersockopts);
			err(stat, "Curl option - SOCKOPTFUNCTION");
													/* maam this is a wendys */

		curl_easy_setopt(c->c, CURLOPT_WRITEDATA, (struct memmy *)&mem);	
				
		curl_easy_setopt(c->c, CURLOPT_WRITEFUNCTION, what_did_i_want_on_ebay_again);

		curl_easy_setopt(c->c, CURLOPT_URL, c->host);

			return 0;}

int ebaysnipe(const unsigned char **link, 
			const unsigned char **time){

	struct curling c;
							/* bottoms up! or.. down?*/
	c.c = curl_easy_init();
		struct data *args;

		c.host = realloc(link, sizeof(c.host));
			
					free(link);
		
	curl_easy_setopt(c.c, CURLOPT_VERBOSE, 1);
			perror("OPTION - Verbose");				
	curl_easy_setopt(c.c, CURLOPT_FTPSSLAUTH, CURLFTPAUTH_SSL);	
	perror("OPTION - FTP Auth to try SSL"); 

		curl_easy_setopt(c.c, CURLOPT_OPENSOCKETDATA, args);

	if (curl_easy_setopt(c.c, CURLOPT_OPENSOCKETFUNCTION,snipersock) < 0){
			
			perror("Curl Options: OPENSOCKETFUNCTION");
			exit(-1); }

		ebaysnipe_2(&c);
		
}

		
			

int main(int argc, char *argv[]){


	const unsigned char **link, **time;
	unsigned char ch;

	while((ch = getopt(argc, argv, "l:t:")) != EOF){

		switch(ch){

				case'l':
					link = optarg;
					break;

				case't':
					time = optarg;
					break; }
			}
		


	
	ebaysnipe(link, time);


return 0; }



