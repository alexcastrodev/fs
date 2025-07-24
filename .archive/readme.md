# File System

Este repositório contém implementações práticas e anotações teóricas desenvolvidas durante meus estudos de mestrado na área de **sistemas operacionais**, com foco específico em **sistemas de arquivos**.

---

## 📚 Objetivo

Explorar o funcionamento interno de sistemas de arquivos — desde conceitos básicos como blocos e metadados até estruturas mais complexas como inodes, diretórios, journaling e gerenciamento de espaço.

---

## Como começar

Cada dia de prática, vai estar dentro de exercícios numerados.

| Exercício | Tópico | Link |
|-----------|--------|------|
| 1 | Fundamentos de Sistemas de Arquivos | [exercicios/1/readme.md](./exercicios/1/readme.md)             |
| 2 | Blocos, Inodes e Operações de Escrita e Leitura | [exercicios/2/readme.md](./exercicios/2/readme.md) |
| 3 | Leitura de arquivos  | [exercicios/3/readme.md](./exercicios/3/readme.md) |


# Debug

Eu adicionei isso a partir do exercício 3

```
make debug
lldb build/fs
breakpoint set --file src/disk.c --line 105
(lldb) run
Process 21436 launched: '/Users/alexandrocastro/study/fs/exercicios/3/build/fs' (arm64)
Process 21436 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = breakpoint 1.1
    frame #0: 0x0000000100000a7c fs`read_file(inode_index=0) at disk.c:105:9
   102  }
   103 
   104  void read_file(int inode_index) {
-> 105      if (inode_index < 0 || inode_index >= MAX_FILES || inode_bitmap[inode_index] == 0) {
   106          printf("Erro: Inode %d inválido ou não alocado.\n", inode_index);
   107          return;
   108      }
Target 0: (fs) stopped.
(lldb) print inode_index
(int) 0
```

## Breakpoints

- `read_file`: Verifica se o arquivo existe, lê os blocos associados e retorna o conteúdo.

OBS: Neste projeto to usando LLDB, ao invés de GDB, para depurar o código.

### IDE

Eu tenho usado o CLion pra testar também.

![Debug](/.resources/2.png)

## 📖

Meu GPT é isso:

![Livro](/.resources/1.png)