
cmake_minimum_required(VERSION 3.26)
project(gobang)

find_package(raylib REQUIRED)
add_executable(gobang GOBANG.c search.h search.c judge.h judge.c evaluate.h evaluate.c click.c)
#add_executable(evaluate evaluate.c)
#add_executable(search search.c)
#add_executable(judge judge.c)


target_link_libraries(gobang raylib)