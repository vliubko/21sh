cmake_minimum_required(VERSION 3.9)
project(21sh)

set(CMAKE_CXX_STANDARD 11)

include_directories(libft/includes includes) # header directories
link_directories(libft) # library directories

add_executable(21sh
        includes/ft_21sh.h
        src/main.c
        src/terminal_mode.c
        src/helpers.c
        includes/ft_21sh.h
        src/signals.c
        libft/src/ft_strjoin.c
        libft/src/ft_strsub.c
        src/line_editing/cursor_basic_moves.c
        includes/line_editing.h
        src/line_editing/insertion_deletion.c
        src/line_editing/line_edit_helpers.c
        src/line_editing/cursor_word_home_moves.c
        src/execution/check_bi.c includes/env.h
        src/builtins/bi_cd.c
        src/env/env_commands.c
        includes/builtins.h
        includes/execution.h src/builtins/bi_echo.c src/builtins/bi_clear.c src/builtins/bi_set_unset_env.c
        src/execution/pipes.c
        libft/src/ft_strchr.c
        libft/src/ft_strsplit_whitespaces.c libft/src/ft_convert_2dtab_to_3dtab.c)

target_link_libraries(21sh -lft -ltermcap)
