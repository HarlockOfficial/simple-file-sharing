cmake_minimum_required(VERSION 3.22)
project(simple_file_sharing C)

set(CMAKE_C_STANDARD 23)

add_executable(simple_file_sharing_client "")
target_sources(simple_file_sharing_client
        PRIVATE
            client/main.c
            client/network/connection/network_connection.c
            client/network/auth/auth.c
            utils/network/network_connection.c
        PUBLIC
            client/network/connection/network_connection.h
            client/network/auth/auth.h
            utils/network/network_connection.h
            utils/tables/file.h
            utils/tables/user/user.h
            utils/tables/auth_token/auth_token.h
            utils/tables/user_file_share_permissions.h
        )

add_executable(simple_file_sharing_server "")
target_sources(simple_file_sharing_server
        PRIVATE
            server/main.c
            server/network/connection/network_connection.c
            server/network/authentication/authentication.c
            server/network/manager/network_manager.c
            server/storage/manager/storage_manager.c
            server/storage/database_wrapper/auth_token/auth_token_database.c
            server/storage/database_wrapper/user/user_database.c
            server/utils/close_thread.c
            utils/network/network_connection.c
            utils/file_manager/file_manager.c
            utils/tables/user/user.c
            utils/tables/auth_token/auth_token.c
            utils/thread_data/thread_data.c
        PUBLIC
            server/network/connection/network_connection.h
            server/network/authentication/authentication.h
            server/network/manager/network_manager.h
            server/storage/manager/storage_manager.h
            server/storage/database_wrapper/auth_token/auth_token_database.h
            server/storage/database_wrapper/user/user_database.h
            server/utils/close_thread.h
            utils/network/network_connection.h
            utils/file_manager/file_manager.h
            utils/tables/file.h
            utils/tables/user/user.h
            utils/tables/auth_token/auth_token.h
            utils/tables/user_file_share_permissions.h
            utils/thread_data/thread_data.h
        )
# project requires uuid/uuid.h (libuuid)