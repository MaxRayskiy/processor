#include <cstring>
#include "src/disassembler.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
  FILE* assembled    = fopen("asm/square_equation.prc.o", "r");
  FILE* disassembled = fopen("asm/square_equation.dis.asm", "w+");

  Disassembly(assembled, disassembled);

  fclose(assembled);
  fclose(disassembled);
  return 0;
}

