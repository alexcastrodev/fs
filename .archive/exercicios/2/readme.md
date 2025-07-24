# Blocos, Inodes e Operações de Escrita e Leitura

Neste exercício, eu fiz uma implementação simples de escrita em disco, utilizando memcpy para simular a escrita de blocos em um disco. 

A leitura do disco é da pior forma, onde lemos o disco inteiro e depois buscamos o bloco desejado. Mas a nivel de aprendizado, é suficiente.

Uma coisa interessante é que eu aprendi usar o `memcpy` para copiar blocos de dados, e uma curioridade que aprendi:

##### Curiosidade

Sistemas reais usam técnicas mais eficientes:

Bitmaps reais (1 bit por bloco), não inteiros

Grupos de blocos (ext2/ext4) → melhora o desempenho

Árvores B ou AVL para rastrear espaços livres

Cache de blocos livres para não varrer tudo sempre

# Inodes

Vou separar na pasta 2-1