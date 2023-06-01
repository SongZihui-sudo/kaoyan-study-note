cmake_minimum_required(VERSION 3.0.0)
project(mylibc VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(./include/)
add_executable(list ./list/list.c ./list/main.c)

add_executable(string ./string/string.c ./string/main.c)

add_executable(linklist ./linkList/linklist.c ./linkList/main.c ./list/list.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
