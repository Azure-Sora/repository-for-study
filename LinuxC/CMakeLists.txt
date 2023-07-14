cmake_minimum_required(VERSION 3.25)
project(LinuxC C)

set(CMAKE_C_STANDARD 11)

add_executable(LinuxC main.c a.txt aa.txt pthread.c fork.c atom.c threadsSort.c)

find_package(Threads)
target_link_libraries(LinuxC ${CMAKE_THREAD_LIBS_INIT})