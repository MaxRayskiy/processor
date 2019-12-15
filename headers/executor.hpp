#pragma once

#include <vector>
#include <cstdint>
#include "stack.hpp"
#include <string>
#include <iostream>
#include <fstream>

#include <stack>

#include "args.hpp"
#include "instructions.hpp"

struct ExecutorState {
  ExecutorState() = default;
  label_t program_cnt = 0;
  bool ZF = false;
  bool SF = false;
  bool CF = false;
  bool OF = false;
  num_t int_reg[8] = {0};
  ftnum_t float_reg[8] = {0.f};
  union StackVal {
    num_t int_val;
    ftnum_t float_val;
    label_t label_val;
    explicit StackVal(const ftnum_t& float_val) : float_val(float_val) {}
    explicit StackVal(const num_t& int_val) : int_val(int_val) {}
    explicit StackVal(const label_t& label_val) : label_val(label_val) {}
  };
  DynamicStack<StackVal> stack;
};

static bool operator==(ExecutorState::StackVal lhs, ExecutorState::StackVal rhs) {
    return lhs.float_val == rhs.float_val;
}

class Executor {
 public:
    Executor();
    ~Executor();

    void ReadBinary(const std::string& file_name = "..//a.out");
    void Execute();

 private:
    std::fstream debug_info;
    size_t GetInstrCnt(std::FILE* file);
    void DumpDebugInfo();
    void DumpError();
    ExecutorState state;
    std::vector<Instruction> instructions;
};
