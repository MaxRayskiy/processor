#include "executor.hpp"
#include <string>

int main(int argc, char* argv[]) {
    Executor executor;
    if (argc > 1) {
        executor.ReadBinary(argv[1]);
    } else {
        executor.ReadBinary();
    }
    executor.Execute();
}
