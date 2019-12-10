#include <iostream>
#include "compiler.hpp"
#include "executor.hpp"

int main() {
  Compiler compiler;
  compiler.SetSource("..//asm/factorial");
  compiler.SetExecutable();
  compiler.Compile();
  compiler.WriteBinary();

  Executor executor;
  executor.ReadBinary();
  executor.Execute();

  return 0;
}

