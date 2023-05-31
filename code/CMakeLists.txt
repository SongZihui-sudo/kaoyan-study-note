cmake_minimum_required(VERSION 3.0.0)
project(mylibc VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(./include/)
add_executable(list ./LinearTable/List/list.c ./LinearTable/List/main.c)

add_executable(string ./String/string.c ./String/main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
