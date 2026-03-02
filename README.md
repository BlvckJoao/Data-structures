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

### Requisitos
- **CMake** 3.10 ou superior
- **GCC** ou Clang (compilador C99 ou superior)
- **Linux/Unix** ou **Windows (WSL/MSYS2)**

**📖 Para um guia detalhado sobre CMake, veja [CMAKE.md](CMAKE.md)**

### Opção 1: Compilação com CMake (Recomendado)

#### Configure e compile:
```bash
# 1. Criar diretório de build
mkdir build
cd build

# 2. Configurar o projeto
cmake ..

# 3. Compilar
cmake --build .

# Ou usar make diretamente
make
```

#### Resultado:
- Bibliotecas compiladas em `build/lib/`
- Executáveis em `build/bin/`

#### Executar exercícios:
```bash
./build/bin/lista_exercicio
```

### Opção 2: Compilação Manual (GCC)

#### Compilar individual:
```bash
# Lista ligada
gcc -c linked_lists/lista.c -o lista.o

# Stack estática
gcc -c stacks_queues/stacks/src/static_stack.c -o static_stack.o

# Stack dinâmica
gcc -c stacks_queues/stacks/src/dynamic_stack.c -o dynamic_stack.o

# Queue estática
gcc -c stacks_queues/queues/src/static_queue.c -o static_queue.o

# Queue dinâmica
gcc -c stacks_queues/queues/src/dynamic_queue.c -o dynamic_queue.o
```

#### Compilar com exercício:
```bash
gcc -Wall -Wextra linked_lists/lista.c linked_lists/Exercicios/q1.c -o lista_exercicio
./lista_exercicio
```

### Limpeza dos arquivos compilados

#### Com CMake:
```bash
# Remover diretório de build
rm -rf build

# Ou reconstruir do zero
rm -rf build && mkdir build && cd build && cmake .. && make
```

#### Com compilação manual:
```bash
rm -f *.o *.a lista_exercicio
```

### Estrutura de Saída do Build

Após compilar com CMake, a estrutura será:

```
build/
├── lib/                          # Bibliotecas compiladas
│   ├── liblista.a
│   ├── libstatic_stack.a
│   ├── libdynamic_stack.a
│   ├── libstatic_queue.a
│   └── libdynamic_queue.a
├── bin/                          # Executáveis (se houver)
└── CMakeFiles/                   # Arquivos internos do CMake
```

### Uso das Bibliotecas

Para usar as bibliotecas em seus próprios projetos:

```cmake
# No seu CMakeLists.txt
link_directories(${CMAKE_CURRENT_LIST_DIR}/Data-structures/build/lib)
target_link_libraries(seu_projeto liblista libstatic_stack libdynamic_queue)
```

Ou em compilação manual:

```bash
gcc -I./Data-structures/linked_lists \
    -I./Data-structures/stacks_queues/stacks/include/stack \
    seu_programa.c \
    ./Data-structures/build/lib/liblista.a \
    ./Data-structures/build/lib/libstatic_stack.a \
    -o seu_programa
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
├── CMakeLists.txt                    # Configuração CMake principal
├── README.md
├── linked_lists/
│   ├── CMakeLists.txt
│   ├── lista.h
│   ├── lista.c
│   └── Exercicios/
│       └── q1.c
└── stacks_queues/
    ├── stacks/
    │   ├── CMakeLists.txt
    │   ├── include/
    │   │   └── stack/
    │   │       └── stack.h
    │   └── src/
    │       ├── static_stack.c
    │       └── dynamic_stack.c
    └── queues/
        ├── CMakeLists.txt
        ├── include/
        │   └── queue/
        │       └── queue.h
        └── src/
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

## �️ Desenvolvimento

### Estrutura do Build com CMake
- **CMakeLists.txt** na raiz coordena os submódulos
- **CMakeLists.txt** em cada módulo define suas bibliotecas
- As bibliotecas são compiladas com seus headers inclusos
- Exercícios são vinculados às suas respectativas bibliotecas

### Status das Implementações

**Compilando com sucesso:**
- ✅ Lista ligada (`lista.c`)
- ✅ Pilha estática (`static_stack.c`)
- ✅ Pilha dinâmica (`dynamic_stack.c`)
- ✅ Fila estática (`static_queue.c`)
- ✅ Fila dinâmica (`dynamic_queue.c`)

**Em desenvolvimento (comentadas no CMakeLists):**
- 🔧 Pilha ligada (`linked_stack.c`) - Conflitos de assinatura de funções
- 🔧 Fila ligada (`linked_queue.c`) - Pendente de validação
- 🔧 Exercícios com Lista Ligada (`q1.c`) - Requer refatoração da API

### Adicionar novos exercícios
1. Criar arquivo `.c` em `linked_lists/Exercicios/`
2. Adicionar ao `CMakeLists.txt` de `linked_lists/`:
   ```cmake
   add_executable(seu_exercicio Exercicios/seu_exercicio.c)
   target_link_libraries(seu_exercicio PRIVATE lista)
   ```
3. Executar `cmake --build build` para compilar

---

## 📝 Notas de Implementação

- Todas as funções retornam valores de erro para tratamento
- Uso de `typedef` para ocultar detalhes de implementação
- Headers bem definidos para modularização
- Compatível com compiladores C99 ou superior
- Headers localizados em diretórios `include/` para melhor organização

---

**Último commit:** 2 de Março de 2026
