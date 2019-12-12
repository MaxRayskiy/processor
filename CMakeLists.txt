cmake_minimum_required(VERSION 3.15)
project(processor)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(stack)

execute_process(COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/instructions_handler.py ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(headers)

add_executable(processor main.cpp
        headers/compiler.hpp
        src/compiler.cpp

                headers/text.hpp
                headers/args.hpp
                headers/executor.hpp
                #headers/final_commands.hpp
                #headers/executeInstructions.hpp
                #headers/instructions.hpp
                headers/instructionsDefines.h

                src/text.cpp
                src/executor.cpp)

