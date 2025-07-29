# Introdução

Neste projeto, eu implemento uma sistema de arquivo conhecido como VSFS (Very Simple File System), baseado no livro Operating Systems: Three Easy Pieces de Remzi Arpaci-Dusseau.

Este livro traz boas questões para estudantes de Ciência da Computação como:

Como podemos construir um sistema de arquivos simples? 

Quais estruturas são necessárias no disco? O que elas precisam rastrear? Como são acessadas?

Segundo Remzi, para sistemas de arquivos, seu modelo mental deve eventualmente incluir respostas para perguntas como:

- Quais estruturas em disco armazenam os dados e metadados do sistema de arquivos? 

- O que acontece quando um processo abre um arquivo? 

- Quais estruturas em disco são acessadas durante uma leitura ou escrita? 

Ao trabalhar e aprimorar seu modelo mental, você desenvolve uma compreensão abstrata do que está acontecendo, em vez de apenas tentar entender os detalhes específicos de algum código de sistema de arquivos.

![VSFS](/.resources/3.png)

# Modelo do Sistema de arquivos

O modelo mental desse sistema de arquivos é simples. Uma série de blocos, e cada um são 4 KB.

O sistema possui a seguinte organização:
- 1 bloco (4KB) para Superblock
- 1 bloco (4KB) para Inode Bitmap
- 1 bloco (4KB) para Block Bitmap
- 5 blocos (20KB) para Inode Table
- Restante para Data Blocks

1 bloco de 4KB suporta 16 inodes (cada inode sendo 256 bytes), portanto 5 blocos de inode table suportam 80 inodes total. Cada inode possui 15 ponteiros de 4 bytes cada (unsigned 32 bit little-endian integer).

Com 5 blocos dedicados à inode table, temos um total de **20KB de inode table** que podem armazenar até 80 inodes simultâneos.

![Divisao](/.resources/4.png)

TODO: falar sobre quantos dados 1 inode pode referenciar.

![capacidade](/.resources/5.png)

