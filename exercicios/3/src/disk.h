#define DISK_H

#define BLOCK_SIZE 8
#define NUM_BLOCKS 10
#define DISK_SIZE (BLOCK_SIZE * NUM_BLOCKS)

#define MAX_BLOCKS_PER_FILE 10
#define MAX_FILES 10

int write_file(const char* content);
void read_blocks(void);
void read_file(int inode);