cmake_minimum_required(VERSION 3.26)
project(nyarchive LANGUAGES C)

# emit compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

# C config
message("Configuring C")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -rdynamic -D_GNU_SOURCE")

# Include directories
include_directories(src/include)
include_directories(src/utils)

FILE(GLOB LIB src/lib/*.c)

# Libraries
message("Configuring libraries")
add_library(crashtrace STATIC src/utils/crashtrace.c)
add_library(nyarchive STATIC ${LIB})
