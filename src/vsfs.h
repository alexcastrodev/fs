#ifndef VSFS_H
#define VSFS_H

#define BLOCK_SIZE (1024 * 4)
#define BLOCK_COUNT 64
// 4Kb é o mesmo que 15 inodes de 256 bytes  
#define MAX_BLOCKS_PER_FILE 15

// 15 * 5 (número de blocos para inodes)
#define MAX_INODES 80

// DISK_SIZE = 
//     Superblock // 4KB
//     Inode Bitmap // 4KB
//     Block Bitmap // 4KB
//     Inode Table // 20KB
//     Data Blocks // restante
#define DISK_SIZE BLOCK_SIZE * BLOCK_COUNT

// Começamos pelo quinto bloco (Data Blocks)
#define DISK_OFFSET 5 * BLOCK_SIZE

// TODO: como aplicar isso
// 512b é o que os discos costumam gravar 
// https://retrocomputing.stackexchange.com/questions/17309/how-did-512-bytes-come-to-be-the-most-common-sector-size


typedef struct {
    int blocks;
    int size;
    int block[MAX_BLOCKS_PER_FILE];
} Inode;

typedef struct {
    Inode inode_table[MAX_INODES];
    int inode_bitmap[MAX_INODES];
    int block_bitmap[BLOCK_COUNT];
} Superblock;

int write(const char* content);
char* read_file(int inode_id);
void read();
void read_blocks();
void format();

#endif