#pragma once

#include "compiler.hpp"
#include "args.hpp"
#define POS(x) state.GetLabelPos(x)

typedef ftnum_t StackVal;
#define TOINT(x) reinterpret_cast<const uint32_t&>(x)
#define TOFLOAT(x) reinterpret_cast<const float&>(x)
#define VAL(x) ExecutorState::StackVal(x)
#define ITOP() state.stack.top().int_val
#define FTOP() state.stack.top().float_val
#define PUSH(x) state.stack.push(ExecutorState::StackVal(x))
#define POP state.stack.pop
#define pc state.program_cnt

#define r state.int_reg
#define xmm state.float_reg
#define ZF state.ZF
#define SF state.SF
#define CF state.CF
#define OF state.OF