jfind.c                                                                                             0000664 0001750 0001750 00000007360 14222125030 011551  0                                                                                                    ustar   jackie                          jackie                                                                                                                                                                                                                 #include"jackie.h"
#include<stdbool.h>
#include<dirent.h>
#include<semaphore.h>
#include<pthread.h>

#define max_len 64
	
	/* like find, but where the math isnt good or finished */

struct name {

	int num_files;
	char *full_path[max_len];
	char *str;
	char *file;
	int str_sz;
	sem_t sem;	

	};

typedef struct concurrent_rddir {
		
		DIR *d2;
		struct dirent *d_two;
		size_t *fname;
		sem_t *sem;

} struct D2_CTX;


int second_thread_get_dir(pthread_t thread_two, sem_t safety,
				const char *d_name, struct name *nam){
	
		D2_CTX *d;
		sem_t sem;

		memset(sem, nam->sem, sizeof(d->sem));

			d->sem = (sem_t *)malloc(sizeof(sem));

				DIR *dir = opendir(nam->d_name);
					

		while(( d->d2 = readdir(dir))!= NULL){	
		
			sem_wait(saftey, 0, NULL);

			calloc(d->fname, sizeof(d->d2->d_name));

				memcpy(d->fname, d->d2->d_name, sizeof(d->f_name));

						if (d->fname == nam->str){

								printf("%s", d->d2->d_name);
									bool file = 1;

								}

					}
			
			free(d2);
					
	return d->fname;


				}


/* 
 * get_dir()/second_thread_get_dir on 1st/2nd thread respectively */

int new_thread(	struct dirent *d, DIR *dir){
		

	pthread_create(thread_two, PTHREAD_CREATE_JOINABLE, second_thread_get_dir, nam);
	
		pthread_t *thread_two;
		struct name nam;
					
			sem_open(nam.sem, 0, 0);
				/* open at 0. just for one thread */				
					while (sem){

							/* dir turn function */

										}

}

/* each file in working directory */

struct name *parsename(DIR *dir, int namlen, char *file){
		
	struct name nam;
		
	size_t *cur = (struct name *)malloc(sizeof(nam));
		
		if (nam.str != file){
				
				return NULL;}
	
	
				else{
		
						memset(nam.full_path, 0, sizeof(nam.full_path));
		
						snprintf(nam.full_path, (sizeof(cur)+1), "%s/%s", dir, file);		

				nam.file = (void *)&file;
	
	return (struct name *)cur;}
}		



struct name *get_dir(DIR *dir, struct dirent *d, char *str){
		
	int dir_files = 0;
	
	while((d = readdir(dir)) != NULL){	

			if(!strcmp(d->d_name, ".") && !strcmp(d->d_name, "..")){
						dir_files++;}
			}
	
		int i = 1, b;
				
		int str_sz = strlen(str);
		rewinddir(dir);

			int *namelen[dir_files];
			char *files[dir_files];
	
	
	while((d = readdir(dir)) != NULL){
	
			memset(files[i], 0, sizeof(files[i]));
		
					if(!strcmp(d->d_name, ".") && !strcmp(d->d_name, "..")){
			
								files[i] = d->d_name;
			
								namelen[i] = strlen(d->d_name);

							if(namelen[i] == str_sz){
					
					struct name *nam = parsename(dir, namelen[i], files[i]); 
						
						if(str != nam->file){
									
									free(nam);
				
										continue; }
			else {
				
							nam->str = str;
							nam->num_files = dir_files;
							nam->str_sz = str_sz;

				return nam; }


		}}}
		

int main(int argc, char *argv[]){

		struct dirent *d;
		DIR *dir;
		
		argchk(argc, "p", 0);
		bool find;
		
		char ch, **path, **str;
		int str_sz;
		size_t *path_ptr;


	while((ch = getopt(argc, argv, ":p:s:")) != EOF){
		switch(ch){

			case'p':
					path = optarg;
					break;
			case's':		
					find = true;
					str = optarg;
					str_sz = strlen(optarg);
					break;

			}
		}


	
		dir = opendir(path);
		
			free(path);
	
	struct name *nam = get_dir(dir, d, str);
   
    pthread_t *thread_two;

	DIR *re;

		if(find){
		
			while(str != nam->file){
			
					rewinddir(dir);
			
				for(; i <= (nam->num_files) ; i++){
						d = readdir(dir);
				

						if (d->d_type == DT_DIR)
						{ 			new_thread(thread_two);}

								calloc(re, sizeof(re));
							
										memset(&re-re, d->d_name, sizeof(d->d_name));
			
											pthread_join(&thr, NULL)
						
										closedir(dir);
					
								memset(dir, 0, sizeof(dir));		
						
						dir = opendir(re);
								
			nam = get_dir(dir, d, str);
							
				};	
			}}}

	

return 0;}	

			

				
					
						}

                                                                                                                                                                                                                                                                                net/                                                                                                0000775 0001750 0001750 00000000000 14222127171 011103  5                                                                                                    ustar   jackie                          jackie                                                                                                                                                                                                                 net/parse_html/                                                                                     0000775 0001750 0001750 00000000000 14222127225 013241  5                                                                                                    ustar   jackie                          jackie                                                                                                                                                                                                                 net/parse_html/poshmark.c                                                                           0000664 0001750 0001750 00000007664 14222125670 015250  0                                                                                                    ustar   jackie                          jackie                                                                                                                                                                                                                 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<sys/socket.h>
#include<curl/curl.h>
#include<netinet/in.h>
#include<netdb.h>
#include<openssl/ssl.h>

		/* not an asshole 
		 * just dont know html tags as well as i should ... */

struct memmy {

	size_t *memory;
	char *data[256];

	};

struct args {

	char *link;
	char *time;
	unsigned int port;
	unsigned int countd; 
};

struct curling {
	
	struct args *a;

	CURL *c;
	CURLcode res;
	
	struct sockaddr_in *c_cli;
	struct curl_sockaddr *curl;
	int sock, fd;
	
	struct addrinfo **info;


	char *header[256];

};


int err(int stat, const char *msg[] ){


 	if( stat < 0 || !stat || !msg ){
		
		if(!stat || !msg){
		
				perror("(no name inputted) Function"); 
				exit(-1);	 
				}	
		else {
			printf("\n------- STDERR --------\n");
			perror(msg); 
			exit(-1);	
				}
		}

	return 0; }


curl_socket_t snipersockopts(struct curling *c, curlsocktype purpose,
						struct curl_sockaddr *curl){
		
	struct addrinfo *info;
	int s;
		
		c->info = (struct addrinfo *)malloc(sizeof(info));
	
			memset(&c->info, 0, sizeof(info));

		c->info.ai_flags  = AI_ADDRCONFIG;
		c->info.ai_protocol = IPPROTO_IP;
		c->info.ai_socktype = SOCK_STREAM;


	s = setsockopt(c->sock, SOL_IP, IP_ADD_MEMBERSHIP, (struct addrinfo *)&c->info, sizeof(&c->info));
			err(s, "sockopt (SOL_IP) - IP_ADD_MEMBERSHIP");

	s = setsockopt(c->sock, SOL_SOCKET, SO_BROADCAST, (struct addrinfo *)&c->info, sizeof(&c->info));
			err(s, "sockopt (SOL_SOCKET)- SO_BROADCAST");
			
				calloc(&c->info, sizeof(c->info);
			
			free(info);

		return c->sock;
		
}

curl_socket_t snipersock(struct curling *args, curlsocktype purpose, 
					struct curl_sockaddr){
	
	unsigned int *link = inet_addr(args->link);
		
		long unsigned *host = ntohl(link);
		
	

	curl_socket_t sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in cli;

		args->c_cli = (struct sockaddr *)malloc(sizeof(cli));

		memset(args->c_cli, 0, sizeof(args->c_cli));

		cli.sin_family = AF_INET;
		cli.sin_port = htons(args->port);
		cli.sin_addr.s_addr = link;

			calloc(c->c_cli, sizeof(curl));	
				
			memcpy(curl->addr, (struct sockaddr *)&cli, sizeof(curl->addr)); 

		return sock;}

char *what_did_i_want_on_ebay_again(void *data, struct memmy *mem, 
						struct curl_sockaddr *curl){

	realloc(mem->data, sizeof(data));

		memset(mem->data, data, sizeof(mem->data));
		
			calloc(mem->data, sizeof(mem->data));
		
		free(data);

	return mem->data; }


int ebaysnipe_2(struct curling *c){

	struct memmy *mem;
		
	int stat = curl_easy_setopt(c->c, CURLOPT_SOCKOPTDATA, c);
			err(stat, "Curl option - SOCKOPTDATA");	
		
		stat = curl_easy_setopt(c->c, CURLOPT_SOCKOPTFUNCTION, snipersockopts);
			err(stat, "Curl option - SOCKOPTFUNCTION");

		curl_easy_setopt(c->c, CURLOPT_WRITEDATA, (struct memmy *)&mem);	
				
		curl_easy_setopt(c->c, CURLOPT_WRITEFUNCTION, what_did_i_want_on_ebay_again);

		curl_easy_setopt(c->c, CURLOPT_URL, ntohl(c->link));

			return 0;}

int ebaysnipe(const unsigned char **link, 
			const unsigned char **time){

	struct curling c;
	
	c.c = curl_easy_init();

		struct data *args;
	
	args->link = (const unsigned char *)malloc(sizeof(link));

		calloc(args-link, sizeof(args->link));

			memset(args->lin, 0, sizeof(args));
		

	curl_easy_setopt(c.c, CURLOPT_VERBOSE, 1);
			perror("OPTION - Verbose");				
	curl_easy_setotp(c.c, CURLOPT_FTP_AUTH, CURL_FTP_AUTHSSL);				perror("OPTION - FTP Auth to try SSL"); 

		curl_easy_setopt(c.c, CURLOPT_OPENSOCKETDATA, args);

	if (curl_easy_setopt(c.c, CURLOPT_OPENSOCKETFUNCTION,snipersock) < 0){
			
			perror("Curl Options: OPENSOCKETFUNCTION");
			exit(-1); }

		ebaysnipe_2(c);
		
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



                                                                            net/parse_html/README.txt                                                                           0000664 0001750 0001750 00000000107 14222125577 014745  0                                                                                                    ustar   jackie                          jackie                                                                                                                                                                                                                 *EBAY* snipe.

not that id actually ever scalp stuff i swear to god.


                                                                                                                                                                                                                                                                                                                                                                                                                                                         net/tcp_ioctl.c                                                                                     0000664 0001750 0001750 00000006213 14222125030 013221  0                                                                                                    ustar   jackie                          jackie                                                                                                                                                                                                                 #include<jackie.h>
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

	/* @jacqka on twitter 
			im straight up broke. */
		
struct local {
	
	struct sockaddr_in *cl;
	struct addrinfo *info;

	
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

			stat = ioctl(/**/, IW_IOCTL_IDX(IW_FREQ_AUTO), iw->u.freq);

			stat = ioctl(/**/, IW_IOCTL_IDX(IW_MODE_AUTO), iw->u.mode);
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

				memset(&info-(sizeof(info)), 0, sizeof(info));

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
                                                                                                                                                                                                                                                                                                                                                                                     net/ssh_client.c                                                                                    0000664 0001750 0001750 00000007705 14221663173 013421  0                                                                                                    ustar   jackie                          jackie                                                                                                                                                                                                                 #include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<linux/wireless.h>
#include<sys/ioctl.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<libssh/libssh.h>
#include<curl/curl.h>
#include<arpa/inet.h>
#include<netdb.h>


#define ERR 1
#define STDIN 2
#define STDOUT 3


struct connectors {

	struct ssh_connector *con;
	struct ssh_channel *cha;

	};

struct session_info {

	const char *host;
	const unsigned char *port, *user;

	};

ssh_key *session_exchange(struct ssh_session *ssh){

	ssh_key *key;
				/* need an auth callback charlie brown 
					and maybe return a struct for the keys*/
					
	ssh_pki_generate(SSH_KEYTYPE_RSA_CERT01, SSH_KEYTYPE_RSA1, key);

	ssh_options_set(ssh, SSH_OPTIONS_PUBKEY_AUTH, ssh_get_pubkey(key));
	perror("Get PUBKEY from Keypair");

	ssh_options_set(ssh, SSH_OPTIONS_HOSTKEYS, ssh_get_server_publickey(ssh, key));
		perror("SSH_OPTIONS_HOSTKEYS");

		return key;}



int setopts(struct ssh_session *ssh, 
		char **host, char **port, char **user){


		
	ssh_options_set(ssh, SSH_OPTIONS_LOG_VERBOSITY_STR, "9");
							/* set log verbosity and host/port */
	ssh_options_set(ssh, SSH_OPTIONS_HOST, host);
		perror("SSH_OPTIONS_HOST()");
	
	ssh_options_set(ssh, SSH_OPTIONS_PORT_STR, port);
		perror("SSH_OPTIONS_PORT");
	ssh_options_set(ssh, SSH_OPTIONS_USER, user);
	
	/* initiate diffie helman key exchange */
	ssh_options_set(ssh, SSH_OPTIONS_CIPHERS_S_C, ssh_get_kex_algo(ssh));
	

		; /* ****** magnets, how do they work */
		curl_easy_setopt(c, CURLOPT_OPENSOCKETFUNCTION, some_callback);
	

	;
	ssh_connect(ssh);	
	session_exchange(ssh, key);
	


	ssh_options_set(ssh, SSH_OPTIONS_BINDADDR, sock);
		

		return 0;}


int config_connector_stdin(struct connectors *one){

		

		ssh_connector_set_in_channel(one->con, one->cha, SSH_CONNECTOR_BOTH);
			perror("SSH set connector for STDIN");
		ssh_connector_set_in_fd(one->con, 3);
				perror("SSH set fd for STDIN");
				/* set connectors for stdin/stdout/stderr */

	return 0; }

int config_connector_stdout(struct connectors *one){

	ssh_connector_set_out_channel(one->con, one->cha, SSH_CONNECTOR_BOTH);
		
	ssh_connector_set_out_fd(one->con, 3);

			};


int config_connector_stderr(struct connectors *one){


	ssh_connector_set_in_channel(one->con, one->cha, SSH_CONNECTOR_STDERR);

	ssh_connector_set_in_fd(one->con, 3);
		


}

int get_connect(struct connectors *in, int flag){


	if(flag != ERR){
		
		if (flag == STDIN){
				
			config_connector_stdin(in);

				}
		
		if (flag == STDOUT){

			config_connector_stdout(in);

					}
			}
	
	else {
		config_connector_stderr(in);

			}

		return 0;

}





int get_session(struct ssh_session *ssh,
			struct ssh_event *ev){
	int i = ERR;	
	struct connectors std[3];
	
	for(; i<=STDOUT; i++){

		size_t *mine = (void *)malloc(sizeof(std[i]));
		
		std[i]->con = ssh_connector_new(ssh);
		ssh_event_add_connector(ev, std[i]->con);
		get_connect(std[i], i);
			
			realloc(mine, (sizeof(mine)+sizeof(std[i]));
			
			
			}

			ssh_channel_open_session(std[STDIN]->con);
			ssh_channel_request_shell(std[STDIN]->con);
			ssh_channel_request_env(ssh, std[STDIN]->con, 1);

		while(( ssh_is_connected(ssh) > 0)){
			
			ssh_event_dopoll(ev, 1000);
			ssh_channel_is_eof(inout->cha_out);

		}

		ssh_event_remove_connector(ev, std[STDERR]->con);
		
		ssh_event_remove_connector(ev, std[STDOUT]->con);
		ssh_event_remove_connector(ev, std[STDIN]->con);

}

int main(int argc, char *argv[]){

	argchk(argc, "hup")
	struct session_info faq;
	char ch;

	while((ch = getopt(argc, argv, "h:u:p:")) != EOF){

		switch(ch){
			case 'h':
				faq.host = optarg;
				break;
			case 'p':
				faq.port = optarg;
				break;
		
			case 'u':
				faq.user = optarg;
				break;
			}
		}

	struct ssh_event *ev = ssh_event_new();
		
	struct ssh_session *ssh = ssh_new();
		
		calloc(ssh, sizeof(ssh));

	ssh_event_add_session(ev, ssh);

		setopts(ssh, faq.host, faq.port, faq.user);
			ssh_options_set(ssh, SSH_OPTIONS_TIMEOUT, 1000);
		get_session(ssh, ev);	


	return 0;
}



                                                           pkguse.c                                                                                            0000664 0001750 0001750 00000003321 14222125030 011746  0                                                                                                    ustar   jackie                          jackie                                                                                                                                                                                                                 #include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<sys/stat.h>
#include<grp.h>
#include<pwd.h>
#include<fcntl.h>
#include<assert.h>



	
/* old gentoo thing */

int err(int flag){
	

	if (flag != 6) {
		printf("Please run as root !\n\n");}

	printf("\nUSAGE: -l 'category' -p 'PKG NAME' (-a 'ADD' || -r 'REMOVE')\n"); 
}

int permiss(FILE *fp, const char *newuse[], int flag){

	struct passwd *pwd;
	struct group *grp;
	
	gid_t *gid;
	uid_t *uid;
	uid_t *euid;

	uid = getpwuid(pwd);
	

	size_t *ptr = (void *)malloc(sizeof(pwd));
	
	int fd = open(newuse, O_RDWR);

	int stat = fchown(fd, uid, 1001);
		if (stat<0){
			perror("");
			err(NULL);}
	fclose(fd);
	
	free(&pwd);

	return 0;

}
	


int main(int argc, char *argv[]){
int stat;
	if ( (stat = geteuid()) != 0 || argc < 6 ){
		err(argc);
		return 1;}

	char chh;
	bool op = 1 || 0;
	const char **usepkg, **add, **remove, **lib;


while((chh = getopt(argc, argv, ":l:p:ar:")) != EOF){

	switch(chh){
		case'l':
			lib = argv[2];
			break;

		case'p':
			usepkg = argv[4];
			break;
				
		case'a':
			add = argv[6];
			op = 1;
			break;

		case'r':
			remove = argv[6];
			op = 0;
			break;
			}	
		}



FILE *fp;
char prefix[] = "/etc/portage/package.use/";
char *buffy[64], *newuse[64];

size_t **y = (void *)malloc(sizeof(buffy));
	
	memset(y, 0, sizeof(y));

	snprintf(newuse, sizeof(newuse), "%s/%s\0", prefix, usepkg);

	
	fp = fopen(newuse, "w");

		if(op){
			snprintf(y, 64, "%s/%s",lib, usepkg);}

		else{
			snprintf(y, 64, "%s/%s -",lib, usepkg);}
 
	
	fprintf(fp, "%s %s", y, argv[6]);
	permiss(fp, newuse, NULL);
	
	fclose(fp);
		printf("SUCCESSFUL!\n");	  
		printf("Good. Done. Probably..\n");
	
		return 0; }

	


				
                                                                                                                                                                                                                                                                                                               README.md                                                                                           0000664 0001750 0001750 00000000055 14221640233 011572  0                                                                                                    ustar   jackie                          jackie                                                                                                                                                                                                                 is things to make things a lil less annoying
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   