if (!strcmp("push", current_instruction_name) && type == "n0") {
    current_instruction.instruction = 0x10;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = atoi(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("push", current_instruction_name) && type == "r0") {
    current_instruction.instruction = 0x11;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("pop", current_instruction_name) && type == "r0") {
    current_instruction.instruction = 0x20;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("mov", current_instruction_name) && type == "rr") {
    current_instruction.instruction = 0x30;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("mov", current_instruction_name) && type == "rn") {
    current_instruction.instruction = 0x31;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = atoi(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fmov", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0x32;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fmov", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0x33;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    float constf = atof(strtok(nullptr, " "));
    current_instruction.rhv = *reinterpret_cast<uint32_t*>(&constf);
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("in", current_instruction_name) && type == "00") {
    current_instruction.instruction = 0x60;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("in", current_instruction_name) && type == "r0") {
    current_instruction.instruction = 0x61;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fin", current_instruction_name) && type == "f0") {
    current_instruction.instruction = 0x62;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("out", current_instruction_name) && type == "00") {
    current_instruction.instruction = 0x70;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("out", current_instruction_name) && type == "r0") {
    current_instruction.instruction = 0x71;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fout", current_instruction_name) && type == "f0") {
    current_instruction.instruction = 0x72;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("cmp", current_instruction_name) && type == "rr") {
    current_instruction.instruction = 0x80;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fcmp", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0x81;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("add", current_instruction_name) && type == "rr") {
    current_instruction.instruction = 0x40;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("add", current_instruction_name) && type == "rn") {
    current_instruction.instruction = 0x41;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = atoi(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fadd", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0x42;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fadd", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0x43;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    float constf = atof(strtok(nullptr, " "));
    current_instruction.rhv = *reinterpret_cast<uint32_t*>(&constf);
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("sub", current_instruction_name) && type == "rr") {
    current_instruction.instruction = 0xA0;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("sub", current_instruction_name) && type == "rn") {
    current_instruction.instruction = 0xA1;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = atoi(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fsub", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0xA2;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fsub", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0xA3;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    float constf = atof(strtok(nullptr, " "));
    current_instruction.rhv = *reinterpret_cast<uint32_t*>(&constf);
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("mul", current_instruction_name) && type == "rr") {
    current_instruction.instruction = 0x50;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("mul", current_instruction_name) && type == "rn") {
    current_instruction.instruction = 0x51;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = atoi(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fmul", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0x52;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fmul", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0x53;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    float constf = atof(strtok(nullptr, " "));
    current_instruction.rhv = *reinterpret_cast<uint32_t*>(&constf);
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fdiv", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0xC1;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    float constf = atof(strtok(nullptr, " "));
    current_instruction.rhv = *reinterpret_cast<uint32_t*>(&constf);
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fdiv", current_instruction_name) && type == "ff") {
    current_instruction.instruction = 0xC2;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("fsqrt", current_instruction_name) && type == "f0") {
    current_instruction.instruction = 0xD3;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("lnot", current_instruction_name) && type == "r0") {
    current_instruction.instruction = 0xD1;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("flnot", current_instruction_name) && type == "f0") {
    current_instruction.instruction = 0xD0;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("finf", current_instruction_name) && type == "f0") {
    current_instruction.instruction = 0xD2;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, " "));
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("jmp", current_instruction_name) && type == "l0") {
    current_instruction.instruction = 0x90;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = labels[strtok(nullptr, " ")];
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("jz", current_instruction_name) && type == "l0") {
    current_instruction.instruction = 0x91;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = labels[strtok(nullptr, " ")];
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("jnz", current_instruction_name) && type == "l0") {
    current_instruction.instruction = 0x92;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = labels[strtok(nullptr, " ")];
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("jl", current_instruction_name) && type == "l0") {
    current_instruction.instruction = 0x93;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = labels[strtok(nullptr, " ")];
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("jg", current_instruction_name) && type == "l0") {
    current_instruction.instruction = 0x94;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = labels[strtok(nullptr, " ")];
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("jle", current_instruction_name) && type == "l0") {
    current_instruction.instruction = 0x95;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = labels[strtok(nullptr, " ")];
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("jge", current_instruction_name) && type == "l0") {
    current_instruction.instruction = 0x96;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = labels[strtok(nullptr, " ")];
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("call", current_instruction_name) && type == "l0") {
    current_instruction.instruction = 0xE0;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = labels[strtok(nullptr, " ")];
    instructions.push_back(current_instruction);
    continue;
} if (!strcmp("call", current_instruction_name) && type == "l0") {
    current_instruction.instruction = 0;
    current_instruction.lhv = 0;
    current_instruction.rhv = 0;
    current_instruction.lhv = labels[strtok(nullptr, " ")];
    instructions.push_back(current_instruction);
    continue;
} 