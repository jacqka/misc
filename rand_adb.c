#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ioctl.h>
#include<pwd.h>
#include<sys/select.h>
#include<fcntl.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/signal.h>
#include<sys/socket.h>
#include<linux/if_addr.h>
#include<linux/magic.h>
#include<memory.h>
#include<libburn.h>
#include<libisofs/libisofs.h>

enum FD_CXT_FLAGS {

	CONTXT_GRP,
	CONTXT_USR,
	CONTXT_MODE,
	CONTXT_NEXT,
	CONTXT_ALG,
	CONTXT_COMPRESS_MECH,
	CONTXT_MAX_RECURSE,
	CONTXT_VIRTNS,
	CONTXT_DBI,
	CONTXT_QUER,

}fd_context_op;


typedef const uint16_t (relay_t);
typedef uint16_t (pass_t);
#define max_len 1024

struct destination {

	relay_t mark;
		
	const char *dev;

	size_t *filedesc_addr;

	size_t *data_addr;

	unsigned long *data[max_len];
};


typedef struct file_descriptor_struct {

	pass_t mark_op;

	struct loop_info *lod;
	struct sockaddr_un unix_fd;
	
	int sock, fd;

	FILE *fp;

	int cmd;

	struct passwd *pwd;
	struct group *group;

} struct filedesc_context;

typedef struct pass_handler_context {

	const pass_t node;

	bool handle_max;
	bool term;

	size_t *right_next;
	const data[max_len][max_len];
	size_t *left_next;

	unsigned int generations;
	

}struct pass_context;



struct filedesc_context *filedesc_context_new(const char *dev, int flag){
	struct sockaddr_un fd_unix;
			size_t *path_ptr = (char *)calloc(1, sizeof(fd_unix.path));

					
	fd_unix.sun_family = AF_UNIX;
	fd_unix.sun_port = htons(port);
	memset(path_ptr, dev, sizeof(dev));		
		struct filedesc_context fd_contxt;

		memset((char *)path, path_ptr, sizeof(path_ptr));

			fd_contxt.sock = socket(AF_UNIX, SOCK_DGRAM, 0);
			fd_contxt.fd = open(dev, O_RDWR);

			int fd = open(path_ptr, O_RDWR );

				

				i



int get_rand_fd(struct destination *dest){

		


	

int main(int argc, char *argv[]){

	const char dev;
	char ch;

	while((ch = getopt(argc, argv, ":d:")) != EOF){

		switch(ch){

			case'd':
				memset((char *)&dev, optarg, sizeof(optarg));
				break;

			}
	}
		
	struct destination dest;

	size_t *dest_ptr = (struct destination *)calloc(1, sizeof(dest));
		

			dest.dev = device;
			
			memset(&device, 0, sizeof(&device));

		get_rand_fd((struct destination *)dest_ptr);

			free(dest_ptr);
