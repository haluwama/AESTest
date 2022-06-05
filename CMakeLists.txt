cmake_minimum_required(VERSION 3.0.0)
project(AesTest VERSION 0.1.0)

add_executable(AesTest main.cpp)

find_package(Boost 1.71 REQUIRED COMPONENTS program_options)
find_package(fmt CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 20)

target_link_libraries(AesTest PRIVATE OpenSSL::SSL OpenSSL::Crypto Boost::program_options fmt::fmt)