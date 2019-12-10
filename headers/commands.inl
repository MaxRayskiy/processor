#pragma once

#include <cmath>
#include <limits>

#include "args.hpp"
#include "instructionsDefines.h"
//0x10
void push(num_t num) {
    PUSH(num);
}

//0x11
void push(reg_t reg_num) {
  PUSH(r[reg_num]);
}

//0x20
void pop(reg_t reg_num) {
    r[reg_num] = ITOP();
}

//0x30
void mov(reg_t reg1, reg_t reg2) {
  r[reg1] = r[reg2];
}

//0x31
void mov(reg_t reg1, num_t num) {
  r[reg1] = num;
}

//0x32
void fmov(ftreg_t freg1, ftreg_t freg2) {
  xmm[freg1] = xmm[freg2];
}

//0x33
void fmov(ftreg_t freg1, ftnum_t num) {
  xmm[freg1] = num;
}

//0x60
void in() {
  StackVal value = 0;
  scanf("%lu", &value);
  PUSH(value);
}

//0x61
void in(reg_t reg) {
  scanf("%ld", &r[reg]);
}

//0x62
void fin(ftreg_t freg) {
  scanf("%lf", &xmm[freg]);
}

//0x70
void out() {
  printf("%ld\n", ITOP());
  POP();
}

//0x71
void out(reg_t reg) {
  printf("%ld\n", r[reg]);
}

//0x72
void fout(ftreg_t freg) {
  printf("%.2f\n", xmm[freg]);
}

//0x80
void cmp(reg_t reg1, reg_t reg2) {
  num_t num1 = r[reg1];
  num_t num2 = r[reg2];
  num1 -= num2;
  ZF = 0;
  SF = 0;
  CF = 0;
  OF = 0;
  if (num1 == 0) {
    ZF = 1;
  } else if (num1 < 0) {
    SF = 1;
  }
}

//0x81
void fcmp(ftreg_t reg1, ftreg_t reg2) {
    ftnum_t num1 = r[reg1];
    ftnum_t num2 = r[reg2];
    num1 -= num2;
    ZF = 0;
    SF = 0;
    CF = 0;
    OF = 0;
    if (num1 == 0) {
        ZF = 1;
    } else if (num1 < 0) {
        SF = 1;
    }
}

//0x40
void add(reg_t reg1, reg_t reg2) {
  r[reg1] += r[reg2];
}

//0x41
void add(reg_t reg, num_t num) {
  r[reg] += num;
}

//0x42
void fadd(ftreg_t freg1, ftreg_t freg2) {
  xmm[freg1] += xmm[freg2];
}

//0x43
void fadd(ftreg_t freg, ftnum_t num) {
  xmm[freg] += num;
}

//0xA0
void sub(reg_t reg1, reg_t reg2) {
 r[reg1] -= r[reg2];
}

//0xA1
void sub(reg_t reg, num_t num) {
  r[reg] -= num;
}

//0xA2
void fsub(ftreg_t freg1, ftreg_t freg2) {
  xmm[freg1] -= xmm[freg2];
}

//0xA3
void fsub(ftreg_t freg, ftnum_t num) {
  xmm[freg] -= num;
}

//0x50
void mul(reg_t reg1, reg_t reg2) {
  r[reg1] *= r[reg2];
}

//0x51
void mul(reg_t reg, num_t num) {
  r[reg] *= num;
}

//0x52
void fmul(ftreg_t freg1, ftreg_t freg2) {
  xmm[freg1] *= xmm[freg2];
}

//0x53
void fmul(ftreg_t freg, ftnum_t num) {
  xmm[freg] *= num;
}

//0xC1
void fdiv(ftreg_t freg, ftnum_t num) {
  xmm[freg] /= num;
}

//0xC2
void fdiv(ftreg_t freg1, ftreg_t freg2) {
  xmm[freg1] /= xmm[freg2];
}

//0xD3
void fsqrt(ftreg_t freg) {
  xmm[freg] = std::sqrt(xmm[freg]);
}

//0xD1
void lnot(reg_t reg) {
  r[reg] = ~r[reg];
}

//0xD0
void flnot(ftreg_t freg) {
  uint64_t tmp = ~reinterpret_cast<uint64_t&>(xmm[freg]);
  xmm[freg] = reinterpret_cast<double&>(tmp);
}

//0xD2
void finf(ftreg_t freg) {
  xmm[freg] = std::numeric_limits<double>::infinity();
}

//0x90
void jmp(label_t pos) {
  pc = pos - 1;
}

//0x91
void jz(label_t pos) {
  if (ZF == 1) {
      pc = pos - 1;
  }
}

//0x92
void jnz(label_t pos) {
  if (ZF == 0) {
      pc = pos - 1;
  }
}

//0x93
void jl(label_t pos) {
  if (SF == 1) {
      pc = pos - 1;
  }
}

//0x94
void jg(label_t pos) {
  if (SF == 0) {
      pc = pos - 1;
  }
}

//0x95
void jle(label_t pos) {
  if (ZF == 1 || SF == 1) {
      pc = pos - 1;
  }
}

//0x96
void jge(label_t pos) {
  if (ZF == 1 || SF == 0) {
      pc = pos - 1;
  }
}

//0xE0
void call(label_t pos) {
    PUSH((num_t) pc);
    pc = pos - 1;
}

