#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<libssh/libssh.h>
#include<curl/curl.h>
#include<getopt.h>

/* define callb for library.
	callbacks ALWAYS take me forever. I wish i had someone i could shoot an email to see.
	Thats all i really want.. */


struct connectors {
								// memory leaks. geez.
	struct ssh_connector *in;
	struct ssh_connector *out;
	struct ssh_connector *err;
	
	struct ssh_channel *sin;


};

struct session_info {


	char **host, **port, **user;
	struct ssh_session *ssh;
	struct ssh_event *ev;


};

int config_connector(struct session_info *sess,
				struct connectors *cons){



	cons->sin = ssh_channel_new(sess->ssh);
	cons->in = ssh_connector_new(sess->ssh);
	cons->out = ssh_connector_new(sess->ssh);

 		ssh_event_add_connector(sess->ev, cons->in);
	
		ssh_connector_set_in_channel(cons->in, cons->sin, SSH_CONNECTOR_STDINOUT);
		ssh_connector_set_in_fd(cons->in, 3);
			
			ssh_event_add_connector(sess->ev, cons->out);
				
				ssh_connector_set_out_channel(cons->out, cons->sin, SSH_CONNECTOR_STDINOUT);
				ssh_connector_set_out_fd(cons->out, 3);

					ssh_event_add_connector(sess->ev, cons->err);
						
						ssh_connector_set_in_channel(cons->err,cons->sin, SSH_CONNECTOR_STDERR);
			

			
		return cons;}
	
int callback(const char *prompt[], char *buf, size_t len, int echo, int verify, 
								struct session_info *sess){
		


		printf("%s\n", prompt);	

			
				scanf("%s", buf);
		
				ssh_userauth_password(sess->ssh, sess->user, buf);

				return 0;
}

		

int init_session(struct session_info *sess, struct connectors *cons){

		
	
		ssh_channel_request_auth_agent(cons->sin);
				perror("request auth agent");
		
		ssh_set_agent_socket(sess->ssh, 3);
				perror("set auth agent");
			
				ssh_set_agent_channel(sess->ssh,cons->sin);
	
				ssh_set_fd_toread(sess->ssh);
					ssh_set_fd_towrite(sess->ssh);
						ssh_channel_open_auth_agent(cons->sin);	
	
					ssh_options_set(sess->ssh, SSH_OPTIONS_PASSWORD_AUTH, callback);

					sess->ssh=  ssh_finalize();
		
						ssh_channel_open_session(cons->sin);	
					
							struct ssg_message *msg;

		while((ssh_is_connected(sess->ssh))){

				ssh_event_dopoll(sess->ev, 5000); 
				ssh_channel_is_eof(cons->sin);
					ssh_message_channel_request_open_reply_accept(msg);
					ssh_message_channel_request_open_reply_accept_channel(msg, cons->sin);
					ssh_message_channel_request_reply_success(msg);

		}

			ssh_event_remove_connector(sess->ev, cons->in);

	
			return 0; }



int get_session(struct session_info *sess){

			
					struct connectors *cons;
		ssh_key *key;

			ssh_pki_generate(SSH_KEYTYPE_RSA_CERT01, SSH_KEYTYPE_RSA1, key);


		ssh_options_set(key , SSH_OPTIONS_PUBKEY_AUTH, ssh_get_pubkey(key));
			perror("SSH_OPTIONS_PUBKEY_AUTH");

	ssh_options_set(sess->ssh, SSH_OPTIONS_CIPHERS_S_C, ssh_get_kex_algo(sess->ssh));
			perror("CIPHERS");
		

			ssh_connect(sess->ssh);
			config_connector(sess, cons);

			ssh_options_set(sess->ssh, SSH_OPTIONS_SSH2, ssh_get_server_publickey(sess->ssh, key));
					perror("SSH_OPTIONS_HOSTKEYS");

			printf("CONNECTORS SET\n\n");

		init_session(sess, cons);

		}

int main(int argc, char *argv[]){

	char ch;
	struct session_info sess;

		sess.ssh = ssh_new();
		sess.ev = ssh_event_new();

		ssh_event_add_session(sess.ev, sess.ssh);

		if(argc < 7){

			printf("USAGE: -h 'HOST' -p 'PORT' -u 'USER'\n\n"); 
			return -1; 
		}

	while((ch = getopt(argc, argv, ":h:p:u:")) != EOF){

		switch(ch){

			case'h':
				sess.host = optarg;
				break;
			case'p':
				sess.port = optarg;
				break;
			case'u':
				sess.user = optarg;
				break;
			}
		}

	
	ssh_options_set(sess.ssh, SSH_OPTIONS_LOG_VERBOSITY_STR, "9");
		perror("verbose");

	ssh_options_set(sess.ssh, SSH_OPTIONS_HOST, sess.host);
		perror("SSH_OPTIONS_HOST");

	ssh_options_set(sess.ssh, SSH_OPTIONS_PORT_STR, sess.port);
		perror("SSH_OPTIONS_PORT_STR");

	ssh_options_set(sess.ssh, SSH_OPTIONS_USER, sess.user);
		perror("SSH_OPTIONS_USER");


		get_session(&sess);


return 0;
}
