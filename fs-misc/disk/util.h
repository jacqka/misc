#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mountP.h>
#include<sys/ioctl.h>

#define MB 0x001f
#define GB 0x0020


typedef unsigned int (sz_callback *)(struct statvfs *blk_dev);

struct disk_space {

	const unsigned int free;
	const unsigned int total;

	const char *type;
	};


typedef struct disk_space (*sz_unit);


struct blkdev_info {

	sz_unit mb, gb;	

	struct statvfs *dev;

	const unsigned int blocks;
	const unsigned int total;

	bool v_ns;
}

struct block_device {
		
	struct libmnt_context *ctx;
	struct libmnt_table *tb;

	const unsigned char *blk_name = NULL;
	const unsigned char fstab;
	
	uint16_t flag;

	sz_callback *unit_conv;
};



struct blkdev_info *blkdev_get_info(const unsigned char *node);
		
unsigned const *blkdev_info_conv_to_metric(struct blkdev_info *info);

unsigned const *blkdev_info_blocks_to_mb(struct blkdev_info *info);

unsigned const *blkdev_info_blocks_to_gb(struct blkdev_info *info);


unsigned const *blkdev_info_conv_to_blocks(struct blkdev_info *info);




