# CMakeLists.txt para Listas Ligadas

# Biblioteca da lista ligada
add_library(lista lista.c)
target_include_directories(lista PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Exemplo de uso com exercício q1
# NOTA: O exercício q1.c requer que a estrutura Node seja exposta no header lista.h
# Por enquanto, está comentado até que a API seja refatorada
# add_executable(lista_exercicio Exercicios/q1.c)
# target_link_libraries(lista_exercicio PRIVATE lista)
# target_include_directories(lista_exercicio PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
