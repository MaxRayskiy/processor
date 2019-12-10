#include "assembler.hpp"

void Compile(FILE* src, FILE* dest) {
    Assembly assembly;

    assembly.Parse(src);
    assembly.Write(dest);
}

template <typename String>
bool IsLabel(const String& word) {
    return word.back() == ':';
}

void Assembly::PreAssembly(const Text& text) {
    pos = 0;
    for (auto& line : text.GetLines()) {
        if (IsLabel(line[0])) {
            std::string label_name(line[0].data(), line[0].size() - 1);
            labels_table[label_name] = pos;
        }
        pos += sizeof(Command) + (line.size() - 1) * sizeof(Arg);
    }
}

void Assembly::Parse(FILE* src) {
    Text src_text(src);
    src_text.ProcessInputStream();

    PreAssembly(src_text);
    data.resize(pos);

    ParseLines(src_text);
}

void Assembly::Write(FILE* dest) {
    fwrite(data.data(), sizeof(value_type), data.size(), dest);
}

void Assembly::ParseLines(const Text& src_text) {
    pos = 0;
    for (const auto& line : src_text.GetLines()) {
        if (IsLabel(line[0])) {
            pos += sizeof(Command);
            return;
        }

        Command command(line);
        Pack(command);

        if (command.HasLeftArg()) {
            PackArg(line[1], command.left_arg_type);
        }
        if (command.HasRightArg()) {
            PackArg(line[2], command.right_arg_type);
        }
    }
}

template <typename T>
void Assembly::Pack(T&& object) {
    memmove(&data[pos], &object, sizeof(T));
    pos += sizeof(T);
}

template <typename String>
void Assembly::PackArg(const String& arg, int type) {
    switch(type) {
        case Reg:
            Pack((uint64_t)std::stoi(arg.data() + 1));
            break;
        case Ftreg:
            Pack((uint64_t)std::stoi(arg.data() + 3));
            break;
        case Num:
            Pack((int64_t)std::stoi(arg.data()));
            break;
        case Ftnum:
            Pack(std::stod(arg.data()));
            break;
        case Label:
            Pack((uint64_t)labels_table[arg]);
            break;
        default:
            std::cerr << "Incorrect args number";
    }
}

