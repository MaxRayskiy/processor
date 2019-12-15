#include <cassert>
#include <iostream>

#include "executor.hpp"
#include "final_commands.hpp"


void Executor::ReadBinary(const std::string& file_name) {
  instructions.clear();
  FILE* bin = fopen(file_name.c_str(), "r");
  assert(bin != nullptr);
  instructions.resize(GetInstrCnt(bin));
  std::fread(instructions.data(), sizeof(Instruction), instructions.size(), bin);
  fclose(bin);
}

void Executor::Execute() {
  while (state.program_cnt < instructions.size()) {
    Instruction instr = instructions[state.program_cnt];

    switch  (instr.instruction) {

        #include "executeInstructions.hpp"

        default: assert(false);
    }
    DumpDebugInfo();
    ++state.program_cnt;
  }
}

size_t Executor::GetInstrCnt(std::FILE* file) {
  assert(file != nullptr);
  std::fseek(file, 0, SEEK_END);
  size_t instr_cnt = std::ftell(file) / sizeof(Instruction);
  std::fseek(file, 0, SEEK_SET);
  return instr_cnt;
}
#include <stack>
void Executor::DumpDebugInfo() {
    debug_info.open("..//debug", std::fstream::out | std::fstream::app);
    debug_info << "pc=" << pc << "\n";
    debug_info << instructions[pc].instruction << "\n";
    debug_info << "flags:" << ZF << " " << SF << " " << CF << " " << OF << "\n";
    std::stack<ExecutorState::StackVal> check_st;
    debug_info << "reg : ";
    for (auto reg : r) {
        debug_info << reg << " ";
    }
    debug_info << "\n";
    debug_info << "xmm : ";
    for (auto reg : xmm) {
        debug_info << reg << " ";
    }
    debug_info << "\nstack:";
    StaticStack<ExecutorState::StackVal> alt;
    while (!state.stack.empty()) {
        alt.push(state.stack.top());
        state.stack.pop();
    }
    while (!alt.empty()) {
        state.stack.push(alt.top());
        debug_info << alt.top().int_val << " ";
        alt.pop();
    }
    debug_info << "\n\n";
    debug_info.close();
}

Executor::Executor() {
    debug_info.open ("..//debug", std::fstream::out | std::fstream::trunc);
    debug_info << "executing...\n";
    debug_info.close();
}

Executor::~Executor() {
    debug_info.close();
}

void Executor::DumpError() {
    debug_info << "RE: no such instruction\n";
    debug_info << "  pc=" << pc << "\n";
    debug_info << "  flags:" << ZF << " " << SF << " " << CF << " " << OF << "\n";
    debug_info << "  reg : ";
    for (auto reg : r) {
        debug_info << reg << " ";
    }
    debug_info << "\n";
    debug_info << "  xmm : ";
    for (auto reg : xmm) {
        debug_info << reg << " ";
    }
    debug_info << "\n\n";
}
