#pragma once

#include <vector>
#include <cstdint>
#include <stack>
#include <string>

#include "args.hpp"
#include "instructions.hpp"

struct ExecutorState {
  ExecutorState() = default;
  size_t program_cnt = 0;
  bool ZF = false;
  bool SF = false;
  bool CF = false;
  bool OF = false;
  num_t int_reg[8] = {0};
  ftnum_t float_reg[8] = {0.f};
  union StackVal {
    num_t int_val;
    ftnum_t float_val;
    explicit StackVal(const ftnum_t& float_val) : float_val(float_val) {}
    explicit StackVal(const num_t& int_val) : int_val(int_val) {}
  };
  std::stack<StackVal> stack;
};

class Executor {
 public:
    Executor() = default;
    void ReadBinary(const std::string& file_name = "..//a.out");
    void Execute();

 private:
    size_t GetInstrCnt(std::FILE* file);
    ExecutorState state;
    std::vector<Instruction> instructions;
};
