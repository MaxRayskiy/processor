#include <vector>
#include <iostream>

#include "args.hpp"
#include "compiler.hpp"

void Compiler::SetSource(const std::string& file_name) {
    labels.clear();
    instructions.clear();
    source.AddInputStream(file_name);
    source_name = file_name;
    source.ProcessInputStream();
}

void Compiler::SetExecutable(const std::string& executable) {
    executable_name = executable;
}

void Compiler::Compile() {
    if (source_name.empty()) {
        return;
    }

    for (size_t i = 0, j = 0; i < source.LinesCnt(); ++i) {
        if (source.Line(i)[source.Line(i).size() - 1] == ':') {
            labels[source.Line(i).substr(0, source.Line(i).size() - 1)] = j;
        } else {
            ++j;
        }
    }

    for (size_t i = 0; i < source.LinesCnt(); ++i) {
        if (source.Line(i)[source.Line(i).size() - 1] == ':') {
            continue;
        }

        char* non_constant_string = const_cast<char*>(source.Line(i).data());
        char* current_instruction_name = strtok(non_constant_string, " ");
        Instruction current_instruction = {0, 0};
        std::string type = GetArgsType(source.GetLine(i));
        //std::cout << current_instruction_name << " " << type << std::endl;
        #include "CompileInstructions.hpp"

        assert(false);
    }
}

void Compiler::WriteBinary() {
    FILE* bin = std::fopen(executable_name.c_str(), "w");
    std::fwrite(instructions.data(), sizeof(Instruction), instructions.size(), bin);
    fclose(bin);
}

std::string Compiler::GetArgsType(std::vector<std::string> splited_lines) {
    if(splited_lines.empty()) {
        return "";
    }
    if(splited_lines.size() == 1) {
        return "00";
    }
    bool new_s = true;
    if(splited_lines.size() == 2) {
        std::string word = splited_lines[1];
        if (IsRegArg(word)) {
            return "r0";
        } else if (IsFtregArg(word)) {
            return "x0";
        } else if (labels.find(word) != labels.end()) {
            return "l0";
        } else if (IsNumArg(word)) {
            return "n0";
        } else if (IsFtnumArg(word)) {
            return "f0";
        }
    } else if(splited_lines.size() == 3) {
        std::string res;
        for (auto word: splited_lines) {
            if (IsRegArg(word)) {
                res.push_back('r');
            } else if (IsFtregArg(word)) {
                res.push_back('x');
            } else if (labels.find(word) != labels.end()) {
                res.push_back('l');
            } else if (IsNumArg(word)) {
                res.push_back('n');
            } else if (IsFtnumArg(word)) {
                res.push_back('f');
            } else {
                assert(new_s || false);
            }
            if (new_s) {
                new_s = false;
                res.clear();
            }
        }
        return res;
    }
    assert(false);
    return "0";
}


