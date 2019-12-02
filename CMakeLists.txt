cmake_minimum_required(VERSION 3.15)
project(processor)

set(CMAKE_CXX_STANDARD 14)

execute_process(COMMAND python3.8 ${CMAKE_CURRENT_SOURCE_DIR}/command_generator.py ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(processor main.cpp src/args.hpp src/assembler.hpp src/assembly_reader.hpp src/command.gen.hpp
               src/disassembler.hpp src/processor.hpp  src/text.hpp)

