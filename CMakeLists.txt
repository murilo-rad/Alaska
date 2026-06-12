cmake_minimum_required(VERSION 3.22)

project(Alaska CXX)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(Alaska 
    #src
    src/main.cpp
    src/Ente.cpp
    src/Menu.cpp
    src/Alaskapp.cpp
    src/Fundo.cpp

    #Entidades
    src/Entidades/Entidade.cpp
    src/Entidades/Chao.cpp
    src/Entidades/Bola_de_Neve.cpp
    src/Entidades/Obstaculos/Obstaculo.cpp
    src/Entidades/Obstaculos/Conjunto_Estalagmites.cpp
    src/Entidades/Obstaculos/Gelo.cpp
    src/Entidades/Obstaculos/Plataforma.cpp
    src/Entidades/Personagens/Nevoso.cpp
    src/Entidades/Personagens/Personagem.cpp
    src/Entidades/Personagens/Inimigo.cpp
    src/Entidades/Personagens/Jogador.cpp
    src/Entidades/Personagens/Lobo.cpp 
    src/Entidades/Personagens/Abominavel.cpp
    
    #Gerenciadores
    src/Gerenciadores/Gerenciador_Grafico.cpp
    src/Gerenciadores/Gerenciador_Eventos.cpp
    src/Gerenciadores/Gerenciador_Colisoes.cpp
    
    #Fases
    src/Fases/Fase.cpp
    src/Fases/Tundra.cpp
    src/Fases/Caverna.cpp

    #Listas
    src/Listas/ListaEntidades.cpp
)

set_target_properties(Alaska PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/fonts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/imgs DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(Alaska PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Entidades/
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Entidades/Personagens/
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Entidades/Obstaculos/
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Gerenciadores/
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Fases/
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Listas/
)
target_link_libraries(Alaska PRIVATE sfml-graphics sfml-window sfml-system)
if(WIN32)
    target_link_libraries(Alaska PRIVATE sfml-main)
endif()