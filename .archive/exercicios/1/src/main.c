//
//  main.c
//  fs
//
//  Created by Alexandro castro on 16/07/2025.
//
#include <stdio.h>
#include <string.h>
#include "main.h"

char disk[DISK_SIZE];

int write(char* content) {
    size_t length = strlen(content);

    // Verifico o tamanho do conteudo
    if (length > DISK_SIZE) {
        printf("Content must be lower than %d bytes (%d blocks of %d bytes)\n", DISK_SIZE, NUM_BLOCKS, BLOCK_SIZE);
        return 1;
    }

    for(size_t i = 0; i < length; i++) {
        if (content[i] == '\n') break;
        printf("%c", content[i]);
        disk[i] = content[i];
    }

    return 0;
}

void read() {
    printf("Reading blocks...\n");
    
    for (int i = 0; i < NUM_BLOCKS; i++) {
        printf("block %d: ", i);

        for (int j = 0; j < BLOCK_SIZE; j++) {
            printf("%c", disk[i * BLOCK_SIZE + j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < DISK_SIZE; i++) {
        printf("%c", disk[i]);
    }
}

int main(void) {
    int choose;
    // Pra já, vamos manter na Stack
    char input[DISK_SIZE];

    while (1) {
        printf("*********************** \n");
        printf("0 - Read blocks \n");
        printf("1 - Write Data \n");
        printf("2 - Exit \n");
        printf("*********************** \n");
        
        scanf("%d", &choose);
        getchar();

        switch (choose) {
            case 0:
                read();
            break;
            case 1:
                printf("Write: \n");
                if(fgets(input, sizeof(input) + 1, stdin) != NULL) {
                    write(input);
                }
            break;
            default:
                printf("Exiting...");
                return 0;
            break;
        }
    }

    return 0;
}


// Look into my eyes, and see, what you mean to me whaaaat is truuuuuuuuuuuue everything i dooooooooooooooooooooooo Look into my eyes, and see, what you mean to me whaaaat is truuuuuuuuuuuue everything i dooooooooooooooooooooooo