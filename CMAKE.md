# Guia de Build com CMake

Este documento explica como usar o CMake para compilar o projeto de Estruturas de Dados.

## Requisitos Mínimos

- **CMake** 3.10 ou superior
- **GCC**, **Clang** ou outro compilador C99+
- **Linux/Unix** ou **Windows (WSL/MinGW)**

### Instalação de Dependências

#### Ubuntu/Debian:
```bash
sudo apt-get install cmake gcc build-essential
```

#### macOS:
```bash
brew install cmake gcc
```

#### Windows (com WSL):
```bash
sudo apt-get install cmake gcc build-essential
```

---

## 🚀 Quick Start

```bash
# Clone/navegue para o projeto
cd Data-structures

# Crie um diretório de build
mkdir build && cd build

# Configure o projeto
cmake ..

# Compile
cmake --build .

# Pronto! As bibliotecas estão em build/lib/
ls lib/
```

---

## 📋 Estrutura de CMakeLists.txt

### Arquivo Principal (`CMakeLists.txt`)

```cmake
cmake_minimum_required(VERSION 3.10)
project(DataStructures C)

# Define o padrão C99 e flags de compilação
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

# Define onde colocar os arquivos compilados
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Inclui os subdiretórios
add_subdirectory(linked_lists)
add_subdirectory(stacks_queues/stacks)
add_subdirectory(stacks_queues/queues)
```

### Subdiretórios

Cada módulo tem seu próprio `CMakeLists.txt`:

- `linked_lists/CMakeLists.txt` - Define bibliotecas de listas
- `stacks_queues/stacks/CMakeLists.txt` - Define bibliotecas de pilhas
- `stacks_queues/queues/CMakeLists.txt` - Define bibliotecas de filas

---

## 🏗️ Compilação com CMake

### Build Padrão

```bash
cd build
cmake ..
cmake --build .
```

### Build com Tipo Específico

```bash
# Release (otimizado)
cmake -DCMAKE_BUILD_TYPE=Release ..

# Debug (com símbolos de debug)
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

### Usando Make Diretamente

```bash
cd build
cmake ..
make                    # Compilar tudo
make lista              # Compilar apenas biblioteca lista
make static_stack       # Compilar apenas static_stack
make clean              # Limpar objetos compilados
```

### Build Verbose (ver comandos executados)

```bash
cmake --build . --verbose
# Ou
make VERBOSE=1
```

---

## 🧹 Limpeza

### Remover Tudo e Reconstruir

```bash
# Método 1: Remover diretório de build
rm -rf build
mkdir build && cd build
cmake .. && make

# Método 2: Usar CMake para limpar
cd build
cmake --build . --target clean
```

---

## 📚 Gerando Documentação

Se tiver Doxygen, pode gerar documentação:

```bash
# Adicionar ao CMakeLists.txt principal:
find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doc ${DOXYGEN_EXECUTABLE})
endif()

# Depois compilar:
make doc
```

---

## 🔗 Vincular Bibliotecas em Outro Projeto

Se quiser usar as bibliotecas compiladas em outro projeto:

### Método 1: Com CMake

```cmake
# No seu CMakeLists.txt
link_directories(/caminho/para/Data-structures/build/lib)
include_directories(/caminho/para/Data-structures/linked_lists)

add_executable(meu_programa main.c)
target_link_libraries(meu_programa lista)
```

### Método 2: GCC Manual

```bash
gcc -I/caminho/para/Data-structures/linked_lists \
    meu_programa.c \
    /caminho/para/Data-structures/build/lib/liblista.a \
    -o meu_programa
```

---

## 🐛 Troubleshooting

### "cmake: command not found"
- **Ubuntu/Debian**: `sudo apt-get install cmake`
- **macOS**: `brew install cmake`

### "gcc/cc: command not found"
- **Ubuntu/Debian**: `sudo apt-get install build-essential`
- **macOS**: `xcode-select --install`

### Erro: "Cannot find source file: ..."
- Verifique se os caminhos em `CMakeLists.txt` estão corretos
- Use caminhos relativos da pasta do `CMakeLists.txt`

### Compilação lenta?
- Use build paralelo: `cmake --build . -j 4` (usa 4 cores)

### Recompilação completa necessária?
```bash
rm -rf build
mkdir build && cd build
cmake ..
cmake --build .
```

---

## 📝 Personalizando CMakeLists.txt

### Adicionar Novo Alvo (Target)

No `linked_lists/CMakeLists.txt`:

```cmake
# Nova biblioteca
add_library(minhas_funcoes minhas_funcoes.c)
target_include_directories(minhas_funcoes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Novo exercício
add_executable(meu_exercicio Exercicios/meu_exercicio.c)
target_link_libraries(meu_exercicio PRIVATE lista)
```

### Adicionar Flags de Compilação

```cmake
# No CMakeLists.txt principal
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -march=native")
```

### Condicional Baseado em Sistema Operacional

```cmake
if(WIN32)
    # Código específico do Windows
elseif(APPLE)
    # Código específico do macOS
else()
    # Código para Linux/Unix
endif()
```

---

## 📖 Recursos Adicionais

- [CMake Official Documentation](https://cmake.org/cmake/help/documentation.html)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [Modern CMake](https://cliutils.gitlab.io/modern-cmake/)

---

**Última atualização**: 2 de Março de 2026
