#pragma once

#include "commands.inl"
#include "../tmp/processor.inl"
#include "../tmp/processor_execute_command.gen.inl"


#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include "text.hpp"
#include "../tmp/assembly_reader.hpp"
#include "../tmp/command.gen.hpp"
#include "../src/disassembler.hpp"
#include "args.hpp"

void Run(FILE* assembled, FILE* listing);


// Heap is much greater than stack.
template <int FullMemorySize = 100000000, int StackSize = 1000000,
          typename StackValueType = uint64_t>
class Processor {

  private:

/*
          Memory structure:

    [data, text, __ram__, __stack]

    pc ---^
    stack_frame --------^       ^------ sp
*/

    char* memory;
    char* data;
    char* text;
    char* ram;
    char* stack_frame;

    char* sp;
    /// Program counter.
    char* pc;

    /// 12 64-bit registers. 13th is for special use.
    int64_t r[13];
    /// 8 64-bit floating point registers.
    double xmm[8];

    /// Flags.
    bool ZF;
    bool SF;
    bool CF;
    bool OF;

  public:
    Processor();
    ~Processor();

    void LoadProgram(FILE* assembled);
    void Execute(FILE* listing = nullptr);

 private:
    void PrintArgValue(FILE* listing, uint64_t arg, int arg_type);
    void PrintToListing(FILE* listing, Command& command,
                        uint64_t left_arg, uint64_t right_arg, char* pc);
};


