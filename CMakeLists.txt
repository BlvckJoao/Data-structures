cmake_minimum_required(VERSION 3.10)
project(DataStructures C)

# Configurar o padrão C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

# Criar diretório de saída para binários e bibliotecas
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Adicionar subdiretórios
add_subdirectory(linked_lists)
add_subdirectory(stacks_queues/stacks)
add_subdirectory(stacks_queues/queues)

# Mensagem de sucesso
message(STATUS "✓ Data Structures Project configured successfully")
message(STATUS "Build directory: ${CMAKE_BINARY_DIR}")
