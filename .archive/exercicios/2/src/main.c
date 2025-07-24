#include <stdio.h>
#include <string.h>
#include "main.h"

// Disco virtual em memória
char disk[DISK_SIZE];

 // 0 = livre, 1 = ocupado
int block_bitmap[NUM_BLOCKS];

int main() {
    // 17 bytes
    const char* msg = "hello filesystem!";
    int start_block = write_file(msg);
    printf("Arquivo gravado a partir do bloco %d\n\n", start_block);
    
    read_blocks();

    return 0;
}

int write_file(const char *content)
{
    // Adicionamos +1 pra contar com o \0
    int total_bytes = strlen(content) + 1;
    // No calculo pra saber quantos blocos precisamos, precisamos fazer arredondamento pra cima (ceil)
    // Por que 17 / 8 da 2,125 mas como não existe 0,125 bloco, precisamos que seja 38
    // 17 + 8 - 1 / 8 => 17 + 7 / 8 => 24/8 => 3
    int blocks_needed = (total_bytes + BLOCK_SIZE - 1) / BLOCK_SIZE;

    int blocks_found = 0;
    int block_index[blocks_needed];

    for (int i = 0; i < NUM_BLOCKS && blocks_found < blocks_needed ;i++) {
        if (block_bitmap[i] == 0) {
            block_index[blocks_found++] = i;
        }

    }
    
    if (blocks_found < blocks_needed) {
        printf("Erro: Sem espaço \n");
        return -1;
    }
    
    int pos = 0;
    for (int i = 0; i < blocks_needed ;i++) {
        int block = block_index[i];
        int offset = i * BLOCK_SIZE;
        int bytes_to_copy = BLOCK_SIZE;

        if (total_bytes - pos < BLOCK_SIZE) {
            bytes_to_copy = total_bytes - pos;
        }
        
        memcpy(&disk[offset], &content[pos], bytes_to_copy);
        block_bitmap[block] = 1;
        pos += bytes_to_copy;
    }
}

void read_blocks()
{
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (block_bitmap[i] == 0) continue;
        printf("Bloco %d: ", i);

        int offset = i * BLOCK_SIZE;
        for (int j = 0; j < NUM_BLOCKS; j++) {
            printf("%c", disk[offset + j]);
        }
        printf("\n");
    }
}
