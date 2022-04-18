#include<jackie.h>
#include<stdbool.h>
#include<getopt.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<linux/wireless.h>
#include<linux/if.h>
#include<linux/if_addr.h>
#include<sys/ioctl.h>
#include<valgrind/valgrind.h>

	/*this is old. */

	/* @jacqka on twitter 			
			im straight up broke. */
		
struct local {
	
	struct sockaddr_in *cl;
	struct addrinfo *info;
	
	struct ieee80211_hdr *hdr;
	
};

struct iw_context {

	struct imreq *im;
	struct iwreq *iw;

	const char *name;

	struct hostent *host;
	
};

struct tcp_context {

	struct iw_context *cxt;
	struct local *cli;

	int sock;
	int s_ret;
		
	size_t *p;

	unsigned int port, host;
	long unsigned int host_v4;
	const unsigned char **localhost, **url;
					};


int tcpctl(struct iwreq *iw, int sock, int flag){

	int stat, i;
	char *data[1024];

	 if ( ioctl(sock,SIOCSIWESSID, iw->u.essid) < 0){
		err(-1, NULL); }

	 	ioctl(sock, SIOCGIWNAME, iw->u.name);

						/* loopback ? */

			stat = ioctl(sock, SIOCSIFATTACH, (caddr_t)iw->ifr, sizeof(iw->u.freq));
			stat = ioctl(sock, SIOCSIFADDR, (caddr_t)iw->ifr, sizeof(iw->u.freq));

			//	err(stat, "IW_MODE_AUTO (ioctl)");

		while(data[i] != NULL || i < 1024){

			if(!flag){
				printf("%c", data[i]); 
				}
			}
	

	return 0;

	}


int tcp_session_get_sockopts(struct tcp_context *tcp, struct sockaddr_in *client_p){

	/* SOCK_RAW for SO_BINDTODEVICE / SOCK_STREAM for SO_BROADCAST */
			
	struct iwreq *iw = malloc(sizeof(tcp->cxt->iw));
							
		
			int stat = setsockopt(tcp->sock, SOL_IP, IP_MULTICAST_IF, (struct imreq *)&iw->ifr_ifrn, sizeof(iw->ifr_ifrn));
				err(stat, "sockopt: IP_MULTICAST_IF");
	
				/* supposed to be in_addr * */	
			stat = getaddrinfo(tcp->host, client_p->sin_port, tcp->cli->info, sizeof(tcp->cli->info));
				err(stat, "getaddrinfo()");

			/* struct loop_device  ? */

		tcpctl(iw, tcp->sock, NULL);	
	
		return 0;
	}	




int tcp_session_get_data(struct tcp_context *tcp){

	long unsigned int *host_b = ntohl(tcp->host_v4);
		
			
			free(tcp->host_v4);

		struct sockaddr_in cli;


				struct sockaddr_in *client_p = &tcp->cli->cl;
		cli.sin_family = AF_INET	;
		cli.sin_port = htons(tcp->port);
		cli.sin_addr.s_addr = host_b;
			
			client_p = (void *)malloc(sizeof(tcp->cli->cl));
			
				memset(client_p, (struct sockaddr_in*)&cli, sizeof(cli));

			struct addrinfo *info = malloc(sizeof(tcp->cli->info));

				memset(info, 0, sizeof(info));

					info->ai_socktype = SOCK_STREAM;
					info->ai_flags = AI_ADDRCONFIG;						
					info->ai_protocol = IPPROTO_IP;
			
			int stat = setsockopt(tcp->sock, SOL_IP, IP_ADD_MEMBERSHIP, (struct in_addr *)client_p->sin_addr.s_addr, sizeof(tcp->cxt->im));
				//err(stat, "sockopt: IP_ADD_MEMBERSHIP");

				tcp_session_get_sockopts(tcp, (struct sockaddr_in *)client_p);

	return 0;

	}

int main(int argc, char *argv[]){

	struct tcp_context tcp;
		
		argchk(argc, "uhp");
		char ch;
		bool get;
	int i = 0;
	
	while((ch = getopt(argc, argv, "u:h:p:")) != EOF){
		
		switch(ch){
		
			case'u':
				tcp.url = optarg;
				break;

			case 'h':
				tcp.localhost = optarg;
				break;
			
			case 'p':
				tcp.port = atoi(optarg);
				break;
			}

	}

	tcp.sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	
	i++;
		tcp_session_get_data(&tcp);




	return 0;}
