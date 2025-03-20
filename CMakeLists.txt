cmake_minimum_required(VERSION 3.30)
project(rule_of_three)

set(CMAKE_CXX_STANDARD 20)

add_executable(rule_of_three main.cpp
        person.cpp
        person.h
        linked_node.cpp
        linked_node.h)
