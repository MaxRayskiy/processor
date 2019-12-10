#include "executor.hpp"
#include <cassert>

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
