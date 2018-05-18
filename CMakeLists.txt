cmake_minimum_required(VERSION 3.9)
project(21sh)

set(CMAKE_CXX_STANDARD 11)

include_directories(libft/includes includes) # header directories
link_directories(libft) # library directories

add_executable(21sh
        src/main.c src/terminal_mode.c src/helpers.c includes/21sh.h)

target_link_libraries(21sh -lft -ltermcap)
