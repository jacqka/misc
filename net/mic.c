#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<linux/wireless.h>
#include<linux/if_addr.h>
#include<linux/if.h>
#include<linux/ethtool.h>
#include<arpa/inet.h>
#include<netinet/in.h>




int err(int stat, const char *msg[]){


	if (!stat || stat< 0){

			perror(msg);
			exit(-1);
					}
	
	else {
		return 0;}

}



	
struct iwreq *get_sock_ioctl_data(struct sockaddr_in *cli, int sock){
	
		struct iwreq iw;
		
		snprintf(&iw.ifr_ifrn, sizeof(iw.ifr_ifrn), "wlan0", NULL);
		size_t *freq_ptr = (void *)malloc(sizeof(iw.u.freq));
		int stat = ioctl(sock, SIOCSIFADDR, sizeof(struct ifreq), (struct ifreq *)&iw.ifr_ifrn);
			stat = ioctl(sock, SIOCSIWESSID, sizeof(struct ifreq), (struct ifreq *)&iw.u.essid);
				err(stat, "SIOCSIFADDR");	

			stat = ioctl(sock, SIOCSIWFREQ, sizeof(struct ifreq), (struct ifreq *)&iw.u.freq);
				err(stat, "SIOCSIWFREQ");	

			stat = ioctl(sock, SIOCSIWMODE, sizeof(struct ifreq), (struct ifreq *)&iw.u.mode);
				err(stat, "SIOCSIWMODE");	
			

		return (struct iwreq *)&iw; }		


int get_sock_session_data(struct sockaddr_in *cli, 
					int sock){

		
		struct iwreq *iw = get_sock_ioctl_data(cli, sock);

			int stat = setsockopt(sock, SOL_IP, IP_ADD_MEMBERSHIP, (struct in_addr *)&iw->ifr_ifrn, sizeof(iw->ifr_ifrn));
			
					err(stat, "IP_ADD_MEMBERSHIP");

			stat = setsockopt(sock, SOL_IP, IP_MULTICAST_IF, (struct in_addr *)&iw->ifr_ifrn, sizeof(iw->ifr_ifrn));

					err(stat, "IP_MULTICAST_IF");



}		




int main(int argc, char *argv[]){

	if(argc<5){
		printf("USAGE: -h 'HOST' -p 'PORT'\n");
		return 0;}

		char ch;
		const char **host, **port;

		while((ch = getopt(argc, argv, "h:p:")) != EOF){

			switch(ch){

				case 'h':
					host = optarg;
					break;

				case 'p':
					port = optarg;
					break; 
					

			}
		}

		int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

	struct sockaddr_in cli;

		cli.sin_family = AF_INET;
		cli.sin_port = htons(argv[2]);
		cli.sin_addr.s_addr = ntohl(INADDR_ANY);



		get_sock_session_data(sock, (void *)&cli);


		return 0;}
