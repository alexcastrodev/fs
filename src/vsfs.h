#ifndef VSFS_H
#define VSFS_H

#define BLOCK_SIZE 1024 * 4
#define BLOCK_COUNT 64
// 4Kb é o mesmo que 15 inodes de 256 bytes  
#define MAX_BLOCKS_PER_FILE 15

// 15 * 5 (número de blocos para inodes)
#define MAX_INODES 80

// DISK_SIZE = 
//     Superblock   // 4KB
//     Inode Bitmap // 4KB
//     Block Bitmap // 4KB
//     Inode Table // 4KB
//     Data Blocks // restante
#define DISK_SIZE BLOCK_SIZE * BLOCK_COUNT

// Para calcular posição de nós
// 512b é o que os discos costumam gravar 
// https://retrocomputing.stackexchange.com/questions/17309/how-did-512-bytes-come-to-be-the-most-common-sector-size
#define DISK_OFFSET 1024 * 512

typedef struct {
    int blocks[4];
    int block[MAX_BLOCKS_PER_FILE]
} Inode;

typedef struct {
    int inode_table[MAX_INODES]
} Superblock;

void write();
void read();
void read_file();
void read_blocks();

#endif