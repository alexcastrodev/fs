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


# Modelo do Sistema de arquivos

## Bloco de dados

O bloco de dados terá 4kb cada. Cada bloco vai apontar endereços de 0 a N - 1 ( 0 a 7, 8 a 15, e por ai vai).

## Medados

Iremos usar blocos para metadados - já que queremos saber do tamanho, quem pertence, acesso, e outros tipo de dados - e outro para os dados.

## Representação dos dados

Para guardar o array de dados, usaremos uma estrutura chamada inode, e para guardar quais inodes pertencem a um bloco

## Estrutura de mapeamento

Começaremos com 4kb para a informação do superbloco.

Usaremos 2 bitmaps de 4kb, um para inode - onde teremos se tem nó de dados livre ou não - e outro para a tabela de inodes - onde dirá se o bloco está livre ou ocupado -.

## Desenho

![VSFS](/.resources/3.png)
