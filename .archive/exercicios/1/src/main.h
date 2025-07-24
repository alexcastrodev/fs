#ifndef MAIN_H
#define MAIN_H

#define BLOCK_SIZE 8
#define NUM_BLOCKS 10
#define DISK_SIZE (BLOCK_SIZE * NUM_BLOCKS)

unsigned char disk[10];

int write(char* content);
void read();

#endif