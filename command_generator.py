import sys

instructions = open('headers/commands.inl', 'r')
compile_instructions_header = open('headers/CompileInstructions.hpp', 'w')

base_instruction = 'if (!strcmp("{instr_name}", current_instruction_name) && type == "{instr_type}") {{\n' \
                   '    current_instruction.instruction = {opcode};\n' \
                   '    current_instruction.lhv = 0;\n' \
                   '    current_instruction.rhv = 0;\n'

reg1 = '    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, \" \"));\n'
reg2 = '    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, \" \"));\n'

ftreg1 = '    current_instruction.lhv = current_instruction.RegisterToInt(strtok(nullptr, \" \"));\n'
ftreg2 = '    current_instruction.rhv = current_instruction.RegisterToInt(strtok(nullptr, \" \"));\n'

const1 = '    current_instruction.lhv = atoi(strtok(nullptr, \" \"));\n'
const2 = '    current_instruction.rhv = atoi(strtok(nullptr, \" \"));\n'

constF1 = '    current_instruction.lhv = atof(strtok(nullptr, \" \"));\n'
constF2 = '    current_instruction.rhv = atof(strtok(nullptr, \" \"));\n'

label1 = '    current_instruction.lhv = labels[strtok(nullptr, \" \")];\n'
label2 = '    current_instruction.rhv = labels[strtok(nullptr, \" \")];\n'

current_instruction = ''
instr_num = 0
instr_name = ''
is_function = False
arg1_t = '0'
arg2_t = '0'
line_num = -1
scopes_cnt = 0
for line in instructions:
    scopes_cnt += line.count("{")
    scopes_cnt -= line.count("}")
    line_num += 1
    if scopes_cnt == 0 and is_function:
        compile_instructions_header.write(
            current_instruction.format(instr_name=instr_name,
                                       instr_type=arg1_t[0] + arg2_t[0],
                                       opcode=instr_num))
        instr_num = 0
        is_function = False

    if '//' in line:
        instr_num = line[2:6]
        continue

    if 'void' in line and '(' in line and ')' in line:
        if instr_num == 0:
            print('no instruction number in line {}\n'.format(line_num - 1))
            raise BaseException
        instr_name = line[0:line.find('(')].split()[1]
        is_function = True
        args = line[line.find('(') + 1:line.find(')')].split()
        try:
            arg1_t = args[0]
        except:
            arg1_t = '0'
        try:
            arg2_t = args[2]
        except:
            arg2_t = '0'
        continue

    current_instruction = base_instruction

    if arg1_t != '0':
        if arg1_t == 'reg_t':
            current_instruction += reg1
        elif arg1_t == 'xmm_t':
            current_instruction += ftreg1
        elif arg1_t == 'num_t':
            current_instruction += const1
        elif arg1_t == 'ftnum_t':
            current_instruction += constF1
        elif arg1_t == 'label_t':
            current_instruction += label1

    if arg2_t != '0':
        if arg2_t == 'reg_t':
            current_instruction += reg2
        elif arg2_t == 'xmm_t':
            current_instruction += ftreg2
        elif arg2_t == 'num_t':
            current_instruction += const2
        elif arg2_t == 'ftnum_t':
            current_instruction += constF2
        elif arg2_t == 'label_t':
            current_instruction += label2

    current_instruction += \
        '    instructions.push_back(current_instruction);\n' \
        '    continue;\n}} '

compile_instructions_header.write(current_instruction.format(instr_name=instr_name,
                                                             instr_type=arg1_t[0] + arg2_t[0],
                                                             opcode=instr_num))

compile_instructions_header.close()
instructions.seek(0)

exec_instr_h = open('headers/executeInstructions.hpp', 'w')

base_instruction = '{\n'

label1 = '    label_t arg1 = instr.lhv;\n'
label2 = '    label_t arg1 = instr.rhv;\n'

num1 = '    num_t arg1 = instr.lhv;\n'
num2 = '    num_t arg2 = instr.rhv;\n'

ftnum1 = '    ftnum_t arg1 = instr.lhv;\n'
ftnum2 = '    ftnum_t arg2 = instr.rhv;\n'

reg1 = '    reg_t arg1 = instr.lhv;\n'
reg2 = '    reg_t arg2 = instr.rhv;\n'

ftreg1 = '    xmm_t arg1 = instr.lhv;\n'
ftreg2 = '    xmm_t arg2 = instr.rhv;\n'

current_instruction = base_instruction
instr_num = 0
instr_name = ''
is_function = False
arg1_t = '0'
arg2_t = '0'
line_num = -1
scopes_cnt = 0
for line in instructions:
    scopes_cnt += line.count("{")
    scopes_cnt -= line.count("}")
    line_num += 1
    if scopes_cnt == 0 and is_function:
        current_instruction += "    break;\n}"
        exec_instr_h.write("case {opcode}: {code}\n".format(opcode=instr_num, code=current_instruction))
        current_instruction = base_instruction
        is_function = False
    if '//' in line:
        instr_num = line[2:6]
        continue

    if 'void' in line and '(' in line and ')' in line:
        if instr_num == 0:
            print('no instruction number in line {}\n'.format(line_num - 1))
            raise BaseException
        instr_name = line[0:line.find('(')].split()[1]
        is_function = True
        args = line[line.find('(') + 1:line.find(')')].split()
        try:
            arg1_t = args[0]
        except:
            arg1_t = '0'
        try:
            arg2_t = args[2]
        except:
            arg2_t = '0'

        if arg1_t != '0':
            if arg1_t == 'reg_t':
                current_instruction += reg1
            elif arg1_t == 'xmm_t':
                current_instruction += ftreg1
            elif arg1_t == 'num_t':
                current_instruction += num1
            elif arg1_t == 'ftnum_t':
                current_instruction += ftnum1
            elif arg1_t == 'label_t':
                current_instruction += label1

        if arg2_t != '0':
            if arg2_t == 'reg_t':
                current_instruction += reg2
            elif arg2_t == 'xmm_t':
                current_instruction += ftreg2
            elif arg2_t == 'num_t':
                current_instruction += num2
            elif arg2_t == 'ftnum_t':
                current_instruction += ftnum2
            elif arg2_t == 'label_t':
                current_instruction += label2

        current_instruction += "    " + instr_name + "(state"
        if len(line.split('(')[1]) > 6:
            current_instruction += ', '
        if arg1_t == '0' and arg2_t == '0':
            current_instruction += ");\n"
        elif arg2_t == '0':
            current_instruction += "arg1);\n"
        else:
            current_instruction += "arg1, arg2);\n"
        continue


exec_instr_h.close()
instructions.seek(0)

commands = open('headers/commands.inl')
final_commands = open('headers/final_commands.hpp', 'w')
for line in commands:
    if '//' in line:
        continue
    if 'void' in line and '(' in line and ')' in line:
        modified = line.split('(')[0] + "(struct ExecutorState& state"
        if len(line.split('(')[1]) > 6:
            modified += ', '
        modified += line.split('(')[1]
        final_commands.write(modified)
        continue
    final_commands.write(line)
final_commands.close()
commands.seek(0)


