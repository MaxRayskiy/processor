#include "compiler.hpp"
#include <string>

int main(int argc, char* argv[]) {
    std::string file_name = "../asm/factorial", exec_name;
    if (argc > 1) {
        file_name = argv[1];
    } else if(argc > 2) {
        exec_name = argv[2];
    }

    Compiler compiler;
    compiler.SetSource(file_name);
    compiler.SetExecutable();
    compiler.Compile();
    compiler.WriteBinary();
    return 0;
}
