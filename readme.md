# Sistema de Arquivos Personalizado - Projeto Acadêmico

## Objetivo

Desenvolver um sistema de arquivos simples para compreender os conceitos fundamentais de gerenciamento de armazenamento, organização de dados e estruturas de metadados utilizadas em sistemas operacionais modernos.

## Competências Desenvolvidas

- Compreensão de estruturas de dados para sistemas de arquivos
- Implementação de algoritmos de alocação e gerenciamento de blocos
- Programação em linguagem C/C++
- Documentação técnica e apresentação de resultados

## Especificações do Projeto

### Componentes Obrigatórios
- **Superbloco**: Contém metadados sobre o sistema de arquivos
- **Inodes**: Estruturas que armazenam informações sobre arquivos e diretórios
- **Blocos de dados**: Onde o conteúdo real dos arquivos é armazenado
- **Bitmap de blocos**: Rastreia quais blocos estão livres ou ocupados

### Funcionalidades Mínimas
1. **Formatação do sistema** (`format`)
2. **Criação de arquivos** (`create`)
3. **Remoção de arquivos** (`delete`)
4. **Leitura de arquivos** (`read`)
5. **Escrita de arquivos** (`write`)
6. **Listagem de diretório** (`ls`)

## Etapas de Desenvolvimento

### Milestone 1: Estrutura Base (25%)
- Definição das estruturas de dados
- Implementação do superbloco e sistema de inodes
- Criação do bitmap de controle de blocos

### Milestone 2: Operações Básicas (35%)
- Formatação do sistema de arquivos
- Criação e remoção de arquivos
- Sistema básico de diretórios

### Milestone 3: I/O de Dados (25%)
- Implementação de leitura e escrita
- Gerenciamento de blocos de dados
- Tratamento de fragmentação

### Milestone 4: Testes e Documentação (15%)
- Bateria de testes automatizados
- Documentação técnica completa
- Análise de performance

## Entregáveis

1. **Código fonte** completo com comentários
2. **Makefile** para compilação
3. **README** com instruções de uso
4. **Relatório técnico** (máximo 10 páginas)
5. **Apresentação** (15 minutos + 5 para perguntas)

## Recursos Recomendados

- Linguagem: C/C++
- Ambiente: Linux/Unix
- Controle de versão: Git
- Documentação: Markdown ou LaTeX

## Considerações Importantes

- Sempre mantenha consistência entre metadados e dados
- Implemente verificações de integridade
- Considere casos extremos e tratamento de erros
- Documente bem as estruturas de dados utilizadas
