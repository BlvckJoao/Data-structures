# CMakeLists.txt para Filas (Queues)

# Definir o diretório de includes
set(QUEUE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/queue)

# Biblioteca de fila estática
add_library(static_queue src/static_queue.c)
target_include_directories(static_queue PUBLIC ${QUEUE_INCLUDE_DIR})

# Biblioteca de fila dinâmica
add_library(dynamic_queue src/dynamic_queue.c)
target_include_directories(dynamic_queue PUBLIC ${QUEUE_INCLUDE_DIR})

# Biblioteca de fila ligada
# NOTA: Será compilada quando a implementação estiver validada
# add_library(linked_queue src/linked_queue.c)
# target_include_directories(linked_queue PUBLIC ${QUEUE_INCLUDE_DIR})

# Executável de teste para fila estática (opcional)
# add_executable(test_static_queue test/test_static_queue.c)
# target_link_libraries(test_static_queue PRIVATE static_queue)

# Executável de teste para fila dinâmica (opcional)
# add_executable(test_dynamic_queue test/test_dynamic_queue.c)
# target_link_libraries(test_dynamic_queue PRIVATE dynamic_queue)
