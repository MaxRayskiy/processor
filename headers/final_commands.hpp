#pragma once

#include <cmath>
#include <limits>

#include "args.hpp"
#include "instructionsDefines.h"
void push(struct ExecutorState& state, num_t num) {
    PUSH(num);
}

void push(struct ExecutorState& state, reg_t reg_num) {
  PUSH(r[reg_num]);
}

void push(struct ExecutorState& state, ftnum_t num) {
    PUSH(num);
}

void push(struct ExecutorState& state, xmm_t reg_num) {
    PUSH(xmm[reg_num]);
}

void pop(struct ExecutorState& state, reg_t reg_num) {
    r[reg_num] = ITOP();
}

void pop(struct ExecutorState& state, xmm_t reg_num) {
    xmm[reg_num] = FTOP();
}

void mov(struct ExecutorState& state, reg_t reg1, reg_t reg2) {
  r[reg1] = r[reg2];
}

void mov(struct ExecutorState& state, reg_t reg1, num_t num) {
  r[reg1] = num;
}

void fmov(struct ExecutorState& state, xmm_t freg1, xmm_t freg2) {
  xmm[freg1] = xmm[freg2];
}

void fmov(struct ExecutorState& state, xmm_t freg1, ftnum_t num) {
  xmm[freg1] = num;
}

void in(struct ExecutorState& state) {
  StackVal value = 0;
  scanf("%lu", &value);
  PUSH(value);
}

void in(struct ExecutorState& state, reg_t reg) {
  scanf("%ld", &r[reg]);
}


void fin(struct ExecutorState& state) {
    StackVal value = 0;
    scanf("%f", &value);
    PUSH(value);
}

void fin(struct ExecutorState& state, xmm_t freg) {
  scanf("%lf", &xmm[freg]);
}

void out(struct ExecutorState& state) {
  printf("%ld\n", ITOP());
  POP();
}

void out(struct ExecutorState& state, reg_t reg) {
  printf("%ld\n", r[reg]);
}

void fout(struct ExecutorState& state, xmm_t freg) {
  printf("%.2f\n", xmm[freg]);
}

void cmp(struct ExecutorState& state, reg_t reg1, reg_t reg2) {
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

void cmp(struct ExecutorState& state, reg_t reg1, num_t num2) {
    num_t num1 = r[reg1];
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

void fcmp(struct ExecutorState& state, xmm_t reg1, xmm_t reg2) {
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

void fcmp(struct ExecutorState& state, xmm_t reg1, ftnum_t num2) {
    ftnum_t num1 = r[reg1];
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

void add(struct ExecutorState& state, reg_t reg1, reg_t reg2) {
  r[reg1] += r[reg2];
}

void add(struct ExecutorState& state, reg_t reg, num_t num) {
  r[reg] += num;
}

void fadd(struct ExecutorState& state, xmm_t freg1, xmm_t freg2) {
  xmm[freg1] += xmm[freg2];
}

void fadd(struct ExecutorState& state, xmm_t freg, ftnum_t num) {
  xmm[freg] += num;
}

void sub(struct ExecutorState& state, reg_t reg1, reg_t reg2) {
 r[reg1] -= r[reg2];
}

void sub(struct ExecutorState& state, reg_t reg, num_t num) {
  r[reg] -= num;
}

void fsub(struct ExecutorState& state, xmm_t freg1, xmm_t freg2) {
  xmm[freg1] -= xmm[freg2];
}

void fsub(struct ExecutorState& state, xmm_t freg, ftnum_t num) {
  xmm[freg] -= num;
}

void mul(struct ExecutorState& state, reg_t reg1, reg_t reg2) {
  r[reg1] *= r[reg2];
}

void mul(struct ExecutorState& state, reg_t reg, num_t num) {
  r[reg] *= num;
}

void fmul(struct ExecutorState& state, xmm_t freg1, xmm_t freg2) {
  xmm[freg1] *= xmm[freg2];
}

void fmul(struct ExecutorState& state, xmm_t freg, ftnum_t num) {
  xmm[freg] *= num;
}

void fdiv(struct ExecutorState& state, xmm_t freg, ftnum_t num) {
  xmm[freg] /= num;
}

void fdiv(struct ExecutorState& state, xmm_t freg1, xmm_t freg2) {
  xmm[freg1] /= xmm[freg2];
}

void fsqrt(struct ExecutorState& state, xmm_t freg) {
  xmm[freg] = std::sqrt(xmm[freg]);
}

void lnot(struct ExecutorState& state, reg_t reg) {
  r[reg] = ~r[reg];
}

void flnot(struct ExecutorState& state, xmm_t freg) {
  uint64_t tmp = ~reinterpret_cast<uint64_t&>(xmm[freg]);
  xmm[freg] = reinterpret_cast<double&>(tmp);
}

void finf(struct ExecutorState& state, xmm_t freg) {
  xmm[freg] = std::numeric_limits<double>::infinity();
}

void jmp(struct ExecutorState& state, label_t pos) {
  pc = pos - 1;
}

void jz(struct ExecutorState& state, label_t pos) {
  if (ZF == 1) {
      pc = pos;
  }
}

void jnz(struct ExecutorState& state, label_t pos) {
  if (ZF == 0) {
      pc = pos;
  }
}

void jl(struct ExecutorState& state, label_t pos) {
  if (SF == 1) {
      pc = pos - 1;
  }
}

void jg(struct ExecutorState& state, label_t pos) {
  if (ZF == 0 && SF == 0) {
      pc = pos - 1;
  }
}

void jle(struct ExecutorState& state, label_t pos) {
  if (ZF == 1 || SF == 1) {
      pc = pos - 1;
  }
}

void jge(struct ExecutorState& state, label_t pos) {
  if (ZF == 1 || SF == 0) {
      pc = pos - 1;
  }
}

void call(struct ExecutorState& state, label_t pos) {
    PUSH((num_t) pc);
    pc = pos;
}

