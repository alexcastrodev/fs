#define MAIN_H

#define BLOCK_SIZE 8
#define NUM_BLOCKS 10
#define DISK_SIZE (BLOCK_SIZE * NUM_BLOCKS)

int write_file(const char* content);
void read_blocks();