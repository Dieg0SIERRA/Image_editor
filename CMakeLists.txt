cmake_minimum_required(VERSION 3.5)

project(Image_Editor)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_COMPILER "g++")

# For visual studio compiler
#add_compile_options(/Zc:__cplusplus   /permissive-)  
#add_compile_options(/permissive-)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.2/mingw_64/lib/cmake")

if (MSVC) # Configuración para MSVC    
    set(CMAKE_CXX_COMPILER "cl")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else()
    # Configuración para otros compiladores (como g++)
    set(CMAKE_CXX_COMPILER "g++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Agrega tus archivos fuente aquí
set(SOURCES
    src/main.cpp
    src/widget.cpp
    src/tools.cpp
)

# Agrega tus archivos de encabezado aquí
set(HEADERS
    inc/widget.h
	inc/tools.h
)

set(FORMS
    ui/widget.ui
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
