#include <stdio.h>
#include <string.h>
#include "main.h"
#include "disk.h"

int main() {
    const char* msg = "hello filesystem!";
    int inode = write_file("Aprendendo sistemas de arquivos!");
    read_file(inode);

    return 0;
}
