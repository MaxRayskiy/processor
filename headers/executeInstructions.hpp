case 0x10: {
    num_t arg1 = instr.lhv;
    push(state, arg1);
    break;
}
case 0x11: {
    reg_t arg1 = instr.lhv;
    push(state, arg1);
    break;
}
case 0x20: {
    reg_t arg1 = instr.lhv;
    pop(state, arg1);
    break;
}
case 0x30: {
    reg_t arg1 = instr.lhv;
    reg_t arg2 = instr.rhv;
    mov(state, arg1, arg2);
    break;
}
case 0x31: {
    reg_t arg1 = instr.lhv;
    num_t arg2 = instr.rhv;
    mov(state, arg1, arg2);
    break;
}
case 0x32: {
    ftreg_t arg1 = instr.lhv;
    ftreg_t arg2 = instr.rhv;
    fmov(state, arg1, arg2);
    break;
}
case 0x33: {
    ftreg_t arg1 = instr.lhv;
    ftnum_t arg2 = instr.lhv;
    fmov(state, arg1, arg2);
    break;
}
case 0x60: {
    in(state);
    break;
}
case 0x61: {
    reg_t arg1 = instr.lhv;
    in(state, arg1);
    break;
}
case 0x62: {
    ftreg_t arg1 = instr.lhv;
    fin(state, arg1);
    break;
}
case 0x70: {
    out(state);
    break;
}
case 0x71: {
    reg_t arg1 = instr.lhv;
    out(state, arg1);
    break;
}
case 0x72: {
    ftreg_t arg1 = instr.lhv;
    fout(state, arg1);
    break;
}
case 0x80: {
    reg_t arg1 = instr.lhv;
    reg_t arg2 = instr.rhv;
    cmp(state, arg1, arg2);
    break;
}
case 0x81: {
    ftreg_t arg1 = instr.lhv;
    ftreg_t arg2 = instr.rhv;
    fcmp(state, arg1, arg2);
    break;
}
case 0x40: {
    reg_t arg1 = instr.lhv;
    reg_t arg2 = instr.rhv;
    add(state, arg1, arg2);
    break;
}
case 0x41: {
    reg_t arg1 = instr.lhv;
    num_t arg2 = instr.rhv;
    add(state, arg1, arg2);
    break;
}
case 0x42: {
    ftreg_t arg1 = instr.lhv;
    ftreg_t arg2 = instr.rhv;
    fadd(state, arg1, arg2);
    break;
}
case 0x43: {
    ftreg_t arg1 = instr.lhv;
    ftnum_t arg2 = instr.lhv;
    fadd(state, arg1, arg2);
    break;
}
case 0xA0: {
    reg_t arg1 = instr.lhv;
    reg_t arg2 = instr.rhv;
    sub(state, arg1, arg2);
    break;
}
case 0xA1: {
    reg_t arg1 = instr.lhv;
    num_t arg2 = instr.rhv;
    sub(state, arg1, arg2);
    break;
}
case 0xA2: {
    ftreg_t arg1 = instr.lhv;
    ftreg_t arg2 = instr.rhv;
    fsub(state, arg1, arg2);
    break;
}
case 0xA3: {
    ftreg_t arg1 = instr.lhv;
    ftnum_t arg2 = instr.lhv;
    fsub(state, arg1, arg2);
    break;
}
case 0x50: {
    reg_t arg1 = instr.lhv;
    reg_t arg2 = instr.rhv;
    mul(state, arg1, arg2);
    break;
}
case 0x51: {
    reg_t arg1 = instr.lhv;
    num_t arg2 = instr.rhv;
    mul(state, arg1, arg2);
    break;
}
case 0x52: {
    ftreg_t arg1 = instr.lhv;
    ftreg_t arg2 = instr.rhv;
    fmul(state, arg1, arg2);
    break;
}
case 0x53: {
    ftreg_t arg1 = instr.lhv;
    ftnum_t arg2 = instr.lhv;
    fmul(state, arg1, arg2);
    break;
}
case 0xC1: {
    ftreg_t arg1 = instr.lhv;
    ftnum_t arg2 = instr.lhv;
    fdiv(state, arg1, arg2);
    break;
}
case 0xC2: {
    ftreg_t arg1 = instr.lhv;
    ftreg_t arg2 = instr.rhv;
    fdiv(state, arg1, arg2);
    break;
}
case 0xD3: {
    ftreg_t arg1 = instr.lhv;
    fsqrt(state, arg1);
    break;
}
case 0xD1: {
    reg_t arg1 = instr.lhv;
    lnot(state, arg1);
    break;
}
case 0xD0: {
    ftreg_t arg1 = instr.lhv;
    flnot(state, arg1);
    break;
}
case 0xD2: {
    ftreg_t arg1 = instr.lhv;
    finf(state, arg1);
    break;
}
case 0x90: {
    label_t arg1 = instr.lhv;
    jmp(state, arg1);
    break;
}
case 0x91: {
    label_t arg1 = instr.lhv;
    jz(state, arg1);
    break;
}
case 0x92: {
    label_t arg1 = instr.lhv;
    jnz(state, arg1);
    break;
}
case 0x93: {
    label_t arg1 = instr.lhv;
    jl(state, arg1);
    break;
}
case 0x94: {
    label_t arg1 = instr.lhv;
    jg(state, arg1);
    break;
}
case 0x95: {
    label_t arg1 = instr.lhv;
    jle(state, arg1);
    break;
}
case 0x96: {
    label_t arg1 = instr.lhv;
    jge(state, arg1);
    break;
}
case 0xE0: {
    label_t arg1 = instr.lhv;
    call(state, arg1);
    break;
}
