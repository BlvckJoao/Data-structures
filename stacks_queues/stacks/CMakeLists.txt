# CMakeLists.txt para Pilhas (Stacks)

# Definir o diretório de includes
set(STACK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/stack)

# Biblioteca de pilha estática
add_library(static_stack src/static_stack.c)
target_include_directories(static_stack PUBLIC ${STACK_INCLUDE_DIR})

# Biblioteca de pilha dinâmica
add_library(dynamic_stack src/dynamic_stack.c)
target_include_directories(dynamic_stack PUBLIC ${STACK_INCLUDE_DIR})

# Biblioteca de pilha ligada
# NOTA: Há conflitos de assinatura de funções em linked_stack.c
# Será compilada quando a API for compatibilizada
# add_library(linked_stack src/linked_stack.c)
# target_include_directories(linked_stack PUBLIC ${STACK_INCLUDE_DIR})

# Executável de teste para pilha estática (opcional)
# add_executable(test_static_stack test/test_static_stack.c)
# target_link_libraries(test_static_stack PRIVATE static_stack)

# Executável de teste para pilha dinâmica (opcional)
# add_executable(test_dynamic_stack test/test_dynamic_stack.c)
# target_link_libraries(test_dynamic_stack PRIVATE dynamic_stack)
