#include <stdio.h>
#include <string.h>
#include "main.h"
#include "disk.h"

int main() {
    const char* msg = "hello filesystem!";
    int start_block = write_file(msg);
    printf("Arquivo gravado a partir do bloco %d\n\n", start_block);
    
    read_blocks();

    return 0;
}
