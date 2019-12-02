#ifndef COMMANDS_GEN_HPP
#define COMMANDS_GEN_HPP

#include <cassert>
#include "args.hpp"

enum CommandType {
  push,
  pop,
  mov,
  fmov,
  in,
  fin,
  out,
  fout,
  cmp,
  fcmp,
  add,
  fadd,
  sub,
  fsub,
  mul,
  fmul,
  fdiv,
  fsqrt,
  lnot,
  flnot,
  finf,
  jmp,
  jz,
  jnz,
  jl,
  jg,
  jle,
  jge,
  call,
  ret,
  end,
};

struct Command {
  uint8_t left_arg_type : 4;
  uint8_t right_arg_type : 4;
  uint8_t type : 8;

  template <typename Line>
  explicit Command(const Line& line)
    : type(0),
    left_arg_type(NoneArg),
    right_arg_type(NoneArg)
  {
    if (line[0] == "push") {
      type = push;
      if (IsNumArg(line[1])) {
        left_arg_type = Num;
      } else if (IsRegArg(line[1])) {
        left_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "pop") {
      type = pop;
      if (IsRegArg(line[1])) {
        left_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "mov") {
      type = mov;
      if (IsRegArg(line[1]) && IsNumArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Num;
      } else if (IsRegArg(line[1]) && IsRegArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "fmov") {
      type = fmov;
      if (IsFtregArg(line[1]) && IsFtnumArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftnum;
      } else if (IsFtregArg(line[1]) && IsFtregArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "in") {
      type = in;
      if (line.size() == 1) {
        return;
      } else if (IsRegArg(line[1])) {
        left_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "fin") {
      type = fin;
      if (IsFtregArg(line[1])) {
        left_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "out") {
      type = out;
      if (line.size() == 1) {
        return;
      } else if (IsRegArg(line[1])) {
        left_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "fout") {
      type = fout;
      if (IsFtregArg(line[1])) {
        left_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "cmp") {
      type = cmp;
      if (IsNumArg(line[1]) && IsNumArg(line[2])) {
        left_arg_type = Num;
        right_arg_type = Num;
      } else if (IsRegArg(line[1]) && IsNumArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Num;
      } else if (IsRegArg(line[1]) && IsRegArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "fcmp") {
      type = fcmp;
      if (IsFtnumArg(line[1]) && IsFtnumArg(line[2])) {
        left_arg_type = Ftnum;
        right_arg_type = Ftnum;
      } else if (IsFtregArg(line[1]) && IsFtnumArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftnum;
      } else if (IsFtregArg(line[1]) && IsFtregArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "add") {
      type = add;
      if (IsRegArg(line[1]) && IsNumArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Num;
      } else if (IsRegArg(line[1]) && IsRegArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "fadd") {
      type = fadd;
      if (IsFtregArg(line[1]) && IsFtnumArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftnum;
      } else if (IsFtregArg(line[1]) && IsFtregArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "sub") {
      type = sub;
      if (IsRegArg(line[1]) && IsNumArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Num;
      } else if (IsRegArg(line[1]) && IsRegArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "fsub") {
      type = fsub;
      if (IsFtregArg(line[1]) && IsFtnumArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftnum;
      } else if (IsFtregArg(line[1]) && IsFtregArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "mul") {
      type = mul;
      if (IsRegArg(line[1]) && IsNumArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Num;
      } else if (IsRegArg(line[1]) && IsRegArg(line[2])) {
        left_arg_type = Reg;
        right_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "fmul") {
      type = fmul;
      if (IsFtregArg(line[1]) && IsFtnumArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftnum;
      } else if (IsFtregArg(line[1]) && IsFtregArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "fdiv") {
      type = fdiv;
      if (IsFtregArg(line[1]) && IsFtnumArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftnum;
      } else if (IsFtregArg(line[1]) && IsFtregArg(line[2])) {
        left_arg_type = Ftreg;
        right_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "fsqrt") {
      type = fsqrt;
      if (IsFtregArg(line[1])) {
        left_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "lnot") {
      type = lnot;
      if (IsRegArg(line[1])) {
        left_arg_type = Reg;
      } else {
        assert(false);
      }
    } else if (line[0] == "flnot") {
      type = flnot;
      if (IsFtregArg(line[1])) {
        left_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "finf") {
      type = finf;
      if (IsFtregArg(line[1])) {
        left_arg_type = Ftreg;
      } else {
        assert(false);
      }
    } else if (line[0] == "jmp") {
      type = jmp;
      if (IsLabelArg(line[1])) {
        left_arg_type = Label;
      } else {
        assert(false);
      }
    } else if (line[0] == "jz") {
      type = jz;
      if (IsLabelArg(line[1])) {
        left_arg_type = Label;
      } else {
        assert(false);
      }
    } else if (line[0] == "jnz") {
      type = jnz;
      if (IsLabelArg(line[1])) {
        left_arg_type = Label;
      } else {
        assert(false);
      }
    } else if (line[0] == "jl") {
      type = jl;
      if (IsLabelArg(line[1])) {
        left_arg_type = Label;
      } else {
        assert(false);
      }
    } else if (line[0] == "jg") {
      type = jg;
      if (IsLabelArg(line[1])) {
        left_arg_type = Label;
      } else {
        assert(false);
      }
    } else if (line[0] == "jle") {
      type = jle;
      if (IsLabelArg(line[1])) {
        left_arg_type = Label;
      } else {
        assert(false);
      }
    } else if (line[0] == "jge") {
      type = jge;
      if (IsLabelArg(line[1])) {
        left_arg_type = Label;
      } else {
        assert(false);
      }
    } else if (line[0] == "call") {
      type = call;
      if (IsLabelArg(line[1])) {
        left_arg_type = Label;
      } else {
        assert(false);
      }
    } else if (line[0] == "ret") {
      type = ret;
      if (line.size() == 1) {
        return;
      } else {
        assert(false);
      }
    } else if (line[0] == "end") {
      type = end;
      if (line.size() == 1) {
        return;
      } else {
        assert(false);
      }
    } else {
      assert(false);
    }
  }

  bool HasLeftArg() { return left_arg_type != NoneArg ; }
  int GetLeftArgType() { return left_arg_type; }
  bool HasRightArg() { return right_arg_type != NoneArg ; }
  int GetRightArgType() { return right_arg_type; }

  std::string GetStringName() {
    switch (type) {
      case push:
        return "push";
      case pop:
        return "pop";
      case mov:
        return "mov";
      case fmov:
        return "fmov";
      case in:
        return "in";
      case fin:
        return "fin";
      case out:
        return "out";
      case fout:
        return "fout";
      case cmp:
        return "cmp";
      case fcmp:
        return "fcmp";
      case add:
        return "add";
      case fadd:
        return "fadd";
      case sub:
        return "sub";
      case fsub:
        return "fsub";
      case mul:
        return "mul";
      case fmul:
        return "fmul";
      case fdiv:
        return "fdiv";
      case fsqrt:
        return "fsqrt";
      case lnot:
        return "lnot";
      case flnot:
        return "flnot";
      case finf:
        return "finf";
      case jmp:
        return "jmp";
      case jz:
        return "jz";
      case jnz:
        return "jnz";
      case jl:
        return "jl";
      case jg:
        return "jg";
      case jle:
        return "jle";
      case jge:
        return "jge";
      case call:
        return "call";
      case ret:
        return "ret";
      case end:
        return "end";
      default:
        assert(false);
    }
  }
};

#endif // COMMANDS_GEN_HPP

