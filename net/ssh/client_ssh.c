#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<libssh/libssh.h>
#include<getopt.h>
#include<sodium.h>					/* ~midnight 4/3/22 */
#include<openssl/ssl.h>				/* some things im confused about  but good start*/
#include<sys/socket.h>
#include<valgrind/valgrind.h>

#define IN 1
#define OUT 2
#define ERR 3

	

struct ssh_info {

	const unsigned char *known_hosts;
	const char **port, **host, **user;
		
	struct ssh_message *msg;

	};	


struct ssh_ev {

	struct ssh_connector *std[3];
	struct ssh_channel *cha[2];
	struct ssh_event *ev;
	
	int fd;
	char *buffy[64];
	
	};


struct ssh_context {
	
	struct ssh_ev ev;
	struct ssh_session *ssh;

	ssh_key key, *host_key;
	
	struct ssh_info info;



};

int config_connector_std(struct ssh_ev *ev, int i){

	if (i != ERR){

			if (i == IN){
	
					ssh_connector_set_in_channel(ev->std[IN], ev->cha[IN], SSH_CONNECTOR_BOTH);
					ssh_connector_set_in_fd(ev->std[IN], ev->fd);
			}

			else {			
					ssh_connector_set_out_channel(ev->std[OUT], ev->cha[OUT], SSH_CONNECTOR_BOTH);
					ssh_connector_set_out_fd(ev->std[OUT], ev->fd); 
			}			}
	else {
		
			ssh_connector_set_in_channel(ev->std[IN], ev->cha[ERR], SSH_CONNECTOR_STDERR);
			ssh_connector_set_in_fd(ev->std[IN], ev->fd);
		}	

	
	
		return 0; }


int get_session_connector(struct ssh_ev *ev, int i){

	if(i != ERR){

			if( i == IN ){
					ssh_event_add_connector(ev->ev, ev->std[IN]);
						config_connector_std(ev->std[IN], i);
							}
				else {
					ssh_event_add_connector(ev->ev, ev->std[OUT]);
					config_connector_std(ev->std[OUT], i); }
			}
	else {
		ssh_event_add_connector(ev->ev, ev->std[ERR]);
			config_connector_std(ev->std[IN], i); }

	}


int get_session_config_stdin(struct ssh_context *ctxt){
	
	unsigned int i =1;

	struct ssh_ev *ev_ptr = malloc(sizeof(ctxt->ev));
		
			for(i=1; i<=ERR; i++){
					
				struct ssh_connector *loop_ptr = calloc(1, sizeof(ev_ptr->std[i]));
				
							loop_ptr = ssh_channel_new(ctxt->ssh);

							ev_ptr->std[i] = realloc(loop_ptr, sizeof(loop_ptr));
					
						get_session_connector(ev_ptr, i);	
							
					}
		
	return 0;
		}


int get_session_init(struct ssh_context *ctxt){
		
		
	ssh_channel_get_session(ctxt->ev.cha[IN]);

	ssh_channel_request_env(ctxt->ev.cha[IN], ctxt->ssh, 3);

		/* request shell, do timeout, etc. */


		while ( ssh_is_connected(ctxt->ssh) > 0 ){

				ssh_event_dopoll(ctxt->ev.ev, 5000);
				ssh_channel_is_eof(ctxt->ev.cha[IN]);

		}
							


		ssh_event_remove_connector(ctxt->ev.ev, ctxt->ev.std[IN]); 
		ssh_event_remove_connector(ctxt->ev.ev, ctxt->ev.std[OUT]); 
		ssh_event_remove_connector(ctxt->ev.ev, ctxt->ev.std[ERR]); 
			

}




const char *passwd_auth(const char *pass[]){

		return pass;

	}


int auth_callb(struct ssh_context *ctxt){
			
				/* callback needs work */
					/* need callback_struct */

		ssh_pki_generate(SSH_KEYTYPE_RSA_CERT01, SSH_KEYTYPE_RSA1, ctxt->key);

			
			ssh_options_set(ctxt->ssh, SSH_OPTIONS_CIPHERS_S_C, ssh_get_kex_algo(ctxt->ssh));

			ssh_options_set(ctxt->ssh, SSH_OPTIONS_PASSWORD_AUTH, passwd_auth(ctxt->ev.buffy));
				
		
		ssh_options_set(ctxt->ssh, SSH_OPTIONS_HOSTKEYS, ssh_get_server_publickey(ctxt->ssh, ctxt->key));

				return 0;}



int get_session_user_data(const unsigned char *attr, int flag,
					struct ssh_session *ssh){

	if(flag!=3){
			if(flag==1){
					ssh_options_set(ssh, SSH_OPTIONS_HOST, attr);
											}
			if(flag == 2){
					ssh_options_set(ssh, SSH_OPTIONS_PORT_STR, attr); 
											}
		}
	else {
		ssh_options_set(ssh, SSH_OPTIONS_USER, attr);
			}

	return 0;
}

int get_session_gather_data(struct ssh_context *ctxt, struct ssh_session *ssh){

	unsigned int i = 1;

	const unsigned char *attrs[3] = { 'ctxt->host', 'ctxt->port', 'ctxt->user' };
	
		for(;i<=3;i++){
printf("ok\n");
			size_t *ptr = (const unsigned char *)malloc(sizeof(attrs[i]));

				get_session_user_data((const unsigned char *)ptr, i, ssh);

					
					
					}
		
		ssh_options_set(ssh, SSH_OPTIONS_PUBKEY_AUTH, auth_callb);					
		ssh_connect(ssh);
		
		

	get_session_config_stdin(ctxt);

		get_session_init(ctxt);

}

int main(int argc, char *argv[]){
	
	if(argc < 7){
			printf("usage: -h 'HOST' -p 'PORT' -u 'USER'\n");
			return -1;
		}	
	char ch;
	struct ssh_context ctxt;

		size_t *cxt_p = (struct ssh_context  *)malloc(sizeof(ctxt));

			memset((struct ssh_context *)cxt_p, 0, sizeof(cxt_p));
			
			
	
	while((ch = getopt(argc, argv, ":h:p:u")) != EOF){

		switch(ch){
			case 'h':
				ctxt.info.host = optarg;
				break;

			case 'p':
				ctxt.info.port = optarg;    // parse for ':' tag 
				break;
			case 'u':
				ctxt.info.user = optarg;
				break;
		}
	}
	

		struct ssh_session *ssh = malloc(sizeof(ctxt.ssh));
	
				memset(ssh, 0, sizeof(ssh));

						ssh = ssh_new();
									/* leaks known here i was messing with address.
									 above not so much */
			struct ssh_event *ev = malloc(sizeof(ctxt.ev.ev));

					ev = ssh_event_new();
							
						realloc(ev, sizeof(ev));
					
					free(ev);

				get_session_gather_data(&ctxt, ssh);


		return 0;
	}






	

