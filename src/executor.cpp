#include "executor.hpp"
#include <cassert>
#include <iostream>

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
//    std::cout << std::hex << instr.instruction << std::endl << std::dec;

    switch  (instr.instruction) {

        #include "executeInstructions.hpp"

        default: assert(false);
    }
    DumpDebugInfo();
      /*std::cout << state.program_cnt << std::endl;
      std::cout << std::hex << instr.instruction << ": " << std::dec;
      for (num_t reg : state.int_reg) {
          std::cout << reg << " ";
      }
      std::cout << std::endl;
*/
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
    debug_info << "flags:" << ZF << " " << SF << " " << CF << " " << OF << "\n";
    std::stack<ExecutorState::StackVal> check_st;
    /*while (!state.stack.empty()) {
        auto val = state.stack.top();
        state.stack.pop();
        check_st.push(val);
    }
    while(!check_st.empty()) {
        auto val = check_st.top();
        check_st.pop();
        state.stack.push(val);
    }*/
    debug_info << "reg : ";
    for (auto reg : r) {
        debug_info << reg << " ";
    }
    debug_info << "\n";
    debug_info << "xmm : ";
    for (auto reg : xmm) {
        debug_info << reg << " ";
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
