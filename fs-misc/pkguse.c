#include<stdio.h>
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
	
	free(pwd);

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

		/* conditionally size buffer maybe idk */
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

	


				
