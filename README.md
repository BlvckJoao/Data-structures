# Estruturas de Dados

Repositório com implementações de estruturas de dados fundamentais em C, desenvolvido como estudos pessoais da disciplina de Estruturas de Dados.

## 📋 Conteúdo do Projeto

### 1. Listas Ligadas (`linked_lists/`)

Implementação completa de listas ligadas com operações essenciais.

#### Arquivos:
- **`lista.h`** - Header com interfaces das funções
- **`lista.c`** - Implementação das operações

#### Funcionalidades:

| Função | Descrição |
|--------|-----------|
| `createNode(int info)` | Cria um novo nó com informação inteira |
| `insertFront()` | Insere elemento no início da lista |
| `insertBack()` | Insere elemento no final da lista |
| `insertIn()` | Insere elemento em posição específica |
| `searchInfo()` | Busca nó por valor |
| `searchIndex()` | Busca nó por índice |
| `removeInfo()` | Remove nó por valor |
| `removeIndex()` | Remove nó por índice |
| `sortList()` | Ordena a lista |
| `printList()` | Exibe todos os elementos |
| `freeList()` | Libera memória alocada |

#### Exercícios (`linked_lists/Exercicios/`)
- **`q1.c`** - Problemas práticos com listas ligadas
  - `comprimento()` - Calcula o tamanho da lista
  - `maiores_que_n()` - Conta elementos maiores que N
  - `last()` - Retorna o último nó

---

### 2. Pilhas - Stacks (`stacks_queues/`)

Duas implementações de pilhas (LIFO - Last In, First Out):

#### **Stack Estática** (`static_stack.c`)
- Tamanho fixo: `MAX_SIZE`
- Array contíguo na memória
- Simples e rápido
- Uso limitado a pré-alocações

##### Operações:
| Função | Descrição |
|--------|-----------|
| `stack_create()` | Aloca e inicializa pilha |
| `stack_push()` | Insere elemento no topo |
| `stack_pop()` | Remove e retorna elemento do topo |
| `stack_top()` | Retorna elemento do topo sem remover |
| `stack_is_empty()` | Verifica se pilha está vazia |
| `stack_is_full()` | Verifica se pilha está cheia |
| `stack_size()` | Retorna quantidade de elementos |
| `stack_free()` | Libera memória |

#### **Stack Dinâmica** (`dynamic_stack.c`)
- Tamanho variável com redimensionamento automático
- Dobra de tamanho quando cheia
- Reduz para metade quando 1/4 ocupada
- Mais flexível que estática

**Características especiais:**
- Realokação automática com `realloc()`
- Gerenciamento eficiente de memória
- Suporta crescimento ilimitado (limitado pela RAM)

---

### 3. Filas - Queues (`stacks_queues/`)

Duas implementações de filas (FIFO - First In, First Out):

#### **Queue Estática** (`static_queue.c`)
- Tamanho fixo: `QUEUE_SIZE`
- Implementação circular (usa modulo aritmético)
- Evita perda de espaço com ponteiros `start` e `end`

##### Operações:
| Função | Descrição |
|--------|-----------|
| `queue_create()` | Aloca e inicializa fila |
| `queue_insert()` | Insere elemento no final |
| `queue_remove()` | Remove elemento do início |
| `queue_is_empty()` | Verifica se fila está vazia |
| `queue_is_full()` | Verifica se fila está cheia |
| `queue_size()` | Retorna quantidade de elementos |
| `queue_print()` | Exibe todos os elementos |
| `queue_free()` | Libera memória |

#### **Queue Dinâmica** (`dynamic_queue.c`)
- Fila circular com redimensionamento automático
- Cresce quando atinge capacidade máxima
- Redimensiona para baixo quando subutilizada
- Implementação otimizada

**Características:**
- Capacidade inicial de 10 elementos
- Dobra quando cheia
- Reduz quando ocupação ≤ 25%
- Mantém tamanho mínimo (`INITIAL_MAX`)

---

## 🔧 Compilação e Uso

### Compilar individual:
```bash
# Lista ligada
gcc -c linked_lists/lista.c -o lista.o

# Stack estática
gcc -c stacks_queues/static_stack.c -o static_stack.o

# Stack dinâmica
gcc -c stacks_queues/dynamic_stack.c -o dynamic_stack.o

# Queue estática
gcc -c stacks_queues/static_queue.c -o static_queue.o

# Queue dinâmica
gcc -c stacks_queues/dynamic_queue.c -o dynamic_queue.o
```

### Exemplo de uso (Lista Ligada):
```c
#include "linked_lists/lista.h"

int main() {
    node* list = NULL;
    
    insertBack(&list, 10);
    insertBack(&list, 20);
    insertBack(&list, 30);
    
    printList(list);
    
    freeList(&list);
    return 0;
}
```

---

## 📁 Estrutura do Projeto

```
Data-structures/
├── README.md
├── linked_lists/
│   ├── lista.h
│   ├── lista.c
│   └── Exercicios/
│       └── q1.c
└── stacks_queues/
    ├── stack.h
    ├── queue.h
    ├── static_stack.c
    ├── dynamic_stack.c
    ├── static_queue.c
    └── dynamic_queue.c
```

---

## 📚 Conceitos Abordados

- ✅ Alocação dinâmica de memória (`malloc`, `free`, `realloc`)
- ✅ Ponteiros e referências
- ✅ Estruturas (structs) em C
- ✅ Operações em listas ligadas (inserção, remoção, busca)
- ✅ Pilhas (LIFO)
- ✅ Filas (FIFO)
- ✅ Implementações estáticas vs. dinâmicas
- ✅ Redimensionamento automático
- ✅ Filas circulares
- ✅ Galheria de exercícios práticos

---

## 🎯 Objectivos de Aprendizado

Este projeto consolidou o conhecimento em:
- Gerenciamento eficiente de memória
- Implementação de estruturas de dados abstratas
- Trade-offs entre performance e flexibilidade
- Boas práticas em C

---

## 📝 Notas de Implementação

- Todas as funções retornam valores de erro para tratamento
- Uso de `typedef` para ocultar detalhes de implementação
- Headers bem definidos para modularização
- Compatível com compiladores C99 ou superior

---

**Último commit:** 28 de Fevereiro de 2026
