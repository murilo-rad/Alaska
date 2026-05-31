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
src/main.cpp
src/Ente.cpp
src/Entidade.cpp
src/Personagem.cpp
src/Inimigo.cpp
src/Jogador.cpp
src/Obstaculo.cpp
src/Ice_Spike.cpp
src/Plataforma.cpp
src/Graficos.cpp
src/Eventos.cpp
src/Colisoes.cpp
src/Fase.cpp
src/FaseNoite.cpp
src/Menu.cpp
src/Alaskapp.cpp)

set_target_properties(Alaska PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(Alaska PRIVATE include)
target_link_libraries(Alaska PRIVATE sfml-graphics sfml-window sfml-system)
if(WIN32)
    target_link_libraries(Alaska PRIVATE sfml-main)
endif()