cmake_minimum_required( VERSION 3.2 )

project(MIYA_CORE CXX)
add_subdirectory( ekp2p )
add_subdirectory( shared_components )


include_directories( ${OPENSSL_INCLUDE_DIRS} )


add_executable( server_ver_0 ./server.cpp )
target_link_libraries( server_ver_0 PRIVATE
                        EKP2P
                        SHARED_COMPONENTS)
target_compile_definitions( server_ver_0 PUBLIC )


add_definitions( -std=c++17 )
