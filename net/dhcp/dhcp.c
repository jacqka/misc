#include<netinet/in.h>
#include<sys/types.h>
#include<sys/select.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<time.h>
					/* started 4/15/22 */
#include"dhcp.h"  

#define dhcp_port 67
#define nam_len 256
#define max_len (4096 * 4096)

int dhcp_serv_listen(int s_sock[], DHCP_SERVER *dhcp){
	

	while(dhcp){
		
		size_t *fd_ptr = (fd_set *)malloc(sizeof(dhcp->fd));
			
				FD_ZERO((fd_set *)fd_ptr);
				FD_SET(s_sock[1], (fd_set *)fd_ptr);
			
			int _select = select(s_sock[1]+1, fd_ptr, NULL, NULL, 5000);
	/*clear*/
		dhcp_serv_discover(s_sock[1], fd_ptr);
			//call recv in discover, then return and start transaction
	}


struct dhcp_server_cxt *config_serv_dhcp(const char *name[], unsigned int port){

		struct sockaddr_in serv;
			serv.sin_family = AF_UNIX;
			serv.sin_port = htons(port);
			serv.sin_addr.s_addr = htonl(INADDR_ANY);
		

		DHCP_SERVER *dhcp = calloc(1, sizeof(dhcp));
		
			memset(dhcp->serv, &serv, sizeof(serv));
			
				realloc(dhcp, sizeof(dhcp));

/*leak size_t */
		return dhcp;
}


int dhcp_init_sock(int name, int port){

	int s_sock[2];

		socketpair(AF_UNIX, SOCK_DGRAM, IPPROTO_UDP, s_sock);
			
			DHCP_SERVER *dhcp = config_serv_dhcp(name, port);

/* ioctl/bind on s_sock #2?  */	
	
			return 0; }



int main(int argc, char *argv[]){
	
	char ch;
	unsigned int port;
	char name;
	
	bool reset;

	while((ch = getopt(argc, argv, "rp:n:")) != EOF){
		switch(ch){
			case'r':
				reset = 1;
				break ;
			case 'p':
				port = atoi(optarg);
				break;
			case 'n':
				name = optarg;
				break;
		}
	}

	
		if (reset){

		//writefunction()
			};


	dhcp_init_sock(name, port);

/* return with structures and call waitfunction */
	return 0;}
	







