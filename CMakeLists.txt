cmake_minimum_required(VERSION 3.22)
project(simple_file_sharing C)

set(CMAKE_C_STANDARD 23)

add_executable(simple_file_sharing_client client/main.c client/network/network_connection.c client/network/network_connection.h utils/network/network_connection.c utils/network/network_connection.h)
add_executable(simple_file_sharing_server server/main.c server/network/network_connection.c server/network/network_connection.h utils/network/network_connection.c utils/network/network_connection.h)
