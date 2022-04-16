cmake_minimum_required(VERSION 3.21)
project(ContactManagmentSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(ContactManagmentSystem main.cpp Contact.cpp Contact.h Name.cpp Name.h Address.cpp Address.h)
