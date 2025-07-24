#include <stdio.h>
#include <string.h>
#include <disk.h>

char disk[DISK_SIZE];

typedef struct {
    int size;
    int block_count;
    int blocks[MAX_BLOCKS_PER_FILE];
} Inode;

// vetor de inodes
Inode inode_table[MAX_FILES];

/*
| Componente    | Função                              |
|---------------|-------------------------------------|
| block_bitmap  | Gerenciar o espaço livre do disco  |
| inode_table   | Dizer qual arquivo usa quais blocos|
*/
int inode_bitmap[MAX_FILES];
int block_bitmap[NUM_BLOCKS];


int write_file(const char *content)
{
    int inode_index = -1;

    for (int i = 0; i < MAX_FILES; i++) {
        if (inode_bitmap[i] == 0) {
            inode_index = i;
            break;
        }
    }

    if (inode_index == -1) {
        printf("Erro: Sem inodes disponíveis \n");
        return -1;
    }
    // Preenche o bitmap
    inode_bitmap[inode_index] = 1;

    // Esse trecho é da pasta ./exercicios/2
    int total_bytes = strlen(content) + 1;
    int blocks_needed = (total_bytes + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int block_index[blocks_needed];
    int blocks_found = 0;

    for (int i = 0; i < NUM_BLOCKS && blocks_found < blocks_needed; i++) {
        if (block_bitmap[i] == 0) {
            block_index[blocks_found++] = i;
        }
    }

    inode_table[inode_index].size = total_bytes;
    inode_table[inode_index].block_count = blocks_needed;

    int pos = 0;

    for (int i = 0; i < blocks_needed ;i++) {
        inode_table[inode_index].blocks[i] = block_index[i];
        block_bitmap[block_index[i]] = 1;
        
        // block_index[i] é o indice real do disco
        int offset = block_index[i] * BLOCK_SIZE;
        int bytes_to_copy = BLOCK_SIZE;

        if (total_bytes - pos < BLOCK_SIZE) {
            bytes_to_copy = total_bytes - pos;
        }

        memcpy(&disk[offset], &content[pos], bytes_to_copy);
        pos += bytes_to_copy;
    }

    return inode_index;
}

void read_blocks()
{
    for (int i = 0; i < MAX_FILES; i++) {
        if (inode_bitmap[i] == 0) continue;

        printf("Arquivo %d (tamanho %d bytes): \n", i, inode_table[i].size);

        int remaining = inode_table[i].size;

        for (int j = 0; j < inode_table[i].block_count; j++) {
            int block = inode_table[i].blocks[j];
            int offset = block * BLOCK_SIZE;

            printf("Bloco %d: ", block);
            int bytes_to_read = (remaining < BLOCK_SIZE) ? remaining : BLOCK_SIZE;

            for (int k = 0; k < bytes_to_read; k++) {
                printf("%c", disk[offset + k]);
            }
            printf("\n");
        }
    }
}

void read_file(int inode_index) {
    if (inode_index < 0 || inode_index >= MAX_FILES || inode_bitmap[inode_index] == 0) {
        printf("Erro: Inode %d inválido ou não alocado.\n", inode_index);
        return;
    }

    Inode file = inode_table[inode_index];
    printf("Arquivo %d (tamanho %d bytes):\n", inode_index, file.size);

    int remaining = file.size;

    for (int i = 0; i < file.block_count; i++) {
        int block = file.blocks[i];
        int offset = block * BLOCK_SIZE;

        printf("Bloco %d: ", block);

        int bytes_to_read = (remaining < BLOCK_SIZE) ? remaining : BLOCK_SIZE;
        for (int j = 0; j < bytes_to_read; j++) {
            printf("%c", disk[offset + j]);
        }

        remaining -= bytes_to_read;
        printf("\n");
    }
}
