#pragma once

#include <cstring>
#include <unordered_map>
#include <vector>

#include "text.hpp"
#include "instructions.hpp"


class Compiler {
 public:
    Compiler() = default;
    Compiler(const Compiler&) = delete;
    void SetSource(const std::string& file_name);
    void SetExecutable(const std::string& executable = "..//a.out");
    void Compile();
    void WriteBinary();
    size_t GetLabelPos(const std::string& label) { return labels[label];};

 private:
    std::string GetArgsType(std::vector<std::string> splited_lines);
    std::string source_name;
    std::string executable_name = "a.out";
    std::unordered_map<std::string, size_t> labels;
    Text source;
    std::vector<Instruction> instructions;
};
