#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mountP.h>


int main(int argc, char *argv[]){

	
	struct block_device mnt;
		
		
		mnt.ctx = mnt_new_context();
		mnt.tb = mnt_new_table();

	
	size_t *tb = (struct libmnt_table *)malloc(sizeof(mnt.tb));
	
	bool new;
	unsigned char ch, **disk;

	while((ch = getopt(argc, argv, "d:")) != EOF){
		switch(ch){
			case 'd':
				disk = optarg;
				break;

			case 'n':	
				new = 1;		
		}
		
	memset(&mnt.blk_name, 0, sizeof(disk));
		
		if(!new){
			
			memset((char *)&mnt.blk_name, disk, sizeof(mnt.blk_name)); 
						
				}
			
				free(disk);
				
	mnt_context_new_table(mnt.cxt, tb);

		mnt.fstab = mnt_get_fstab_path();	
				
			block_dev_get_info(mnt.fstab);
	
	









