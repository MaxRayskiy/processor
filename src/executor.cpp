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

void Executor::DumpDebugInfo() {
    debug_info << "pc=" << pc << "\n";
    debug_info << "flags:" << ZF << " " << SF << " " << CF << " " << OF << "\n";
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

}

Executor::Executor() {
    debug_info.open ("..//debug", std::fstream::out | std::fstream::trunc);
    debug_info << "executing...\n";
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
