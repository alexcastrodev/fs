#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vsfs.h>

// Antes de criar um disco virtual, vamos simular
// Posição:    0      4KB   8KB    12KB   16KB    20KB    24KB
//          |------|------|------|------|------|------|------|
//          |Super |Inode |Block |Inode | Data | Data | Data |
//          |Block |Bitmap|Bitmap|Table |Blk 0 |Blk 1 |Blk 2 |
//          |  0   |  1   |  2   |  3   |  4   |  5   |  6   |
char disk[DISK_SIZE];
Superblock s;

void format() {
    memset(&s, 0, sizeof(Superblock));

    // ocupar os tres primeiros blocos
    for (int i = 0; i < 4; ++i) {
        s.block_bitmap[i] = 1;
    }
}

int write(const char* content) {
    int free_inode = -1;

    for (int i = 0; i < MAX_INODES; i++) {
        // procuro um inode disponivel
        if (s.inode_bitmap[i] == 0) {
            free_inode = i;
            break;
        }
    }

    if (free_inode == -1) {
        // Não tem inode livre
        return -1;
    }

    // Tamanho do conteudo
    const size_t content_length = strlen(content);
    // Aqui por exemplo, eu faço um ceil, por que não posso ocupar meio bloco
    // se o tamanho 7kb, vai acabar ocupando dois bloco de 4kb
    const int block_needed = ((int)content_length + BLOCK_SIZE - 1) / BLOCK_SIZE;

    if (block_needed > MAX_BLOCKS_PER_FILE) {
        return -1;
    }


    int allocated_blocks[MAX_BLOCKS_PER_FILE];
    int blocks_found = 0;

    for (int i = 5; i < BLOCK_COUNT && blocks_found < block_needed; ++i) {
        if (s.block_bitmap[i] == 0) {
            allocated_blocks[blocks_found++] = i;
            s.block_bitmap[i] = 1;
        }
    }

    if (blocks_found < block_needed) {
        // reverte alteração
        for (int i = 0; i < blocks_found; ++i) {
            s.block_bitmap[allocated_blocks[i]] = 0;
        }

        return -1;
    }


    // marco o inode como em uso
    s.inode_bitmap[free_inode] = 1;
    s.inode_table[free_inode].blocks = block_needed;
    s.inode_table[free_inode].size = (int)content_length;

    for (int i = 0; i < block_needed; ++i) {
        s.inode_table[free_inode].block[i] = allocated_blocks[i];
    }

    int bytes_written = 0;
    for (int i = 0; i < block_needed; ++i) {
        const int block_index = allocated_blocks[i];

        // vamos calcular a posição do disco
        const int disk_offset = DISK_OFFSET + (block_index * BLOCK_SIZE);

        int bytes_to_write = (int)content_length - bytes_written;
        if (bytes_to_write > BLOCK_SIZE) {
            bytes_to_write = BLOCK_SIZE;
        }

        memcpy(disk + disk_offset, content + bytes_written, bytes_to_write);
        bytes_written += bytes_to_write;
    }

    return free_inode;
}

char* read_file(const int inode_id) {
    const Inode* inode = &s.inode_table[inode_id];
    // aloca na memória para o buffer
    char* buffer = malloc(inode->size + 1);

    int bytes_read = 0;

    for (int i = 0; i < inode->blocks; ++i) {
        // calcula a posição do disco
        const int disk_offset = DISK_OFFSET + (inode->block[i] * BLOCK_SIZE);

        memcpy(buffer + bytes_read, disk + disk_offset, BLOCK_SIZE);
        bytes_read += BLOCK_SIZE;
    }

    buffer[inode->size] = '\0';

    return buffer;
}

int main() {
    format();
    const int inode = write("Alekito File System");
    char* content = read_file(inode);

    printf("Conteúdo: %s \n", content);
    free(content);
}