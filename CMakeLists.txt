cmake_minimum_required(VERSION 3.27)

project(dumpcerts LANGUAGES CXX)

add_executable(dumpcerts dumpcerts.cpp)

target_compile_definitions(dumpcerts PRIVATE UNICODE _UNICODE)
target_link_libraries(dumpcerts PRIVATE  crypt32)

install(TARGETS dumpcerts)
