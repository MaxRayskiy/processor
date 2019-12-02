void ExecuteCommand(Command& command, uint64_t left_arg, uint64_t right_arg) {
  switch (command.type) {
    case CommandType::push:
      if (command.GetLeftArgType() == Num &&
          command.GetRightArgType() == NoneArg)
        push(reinterpret_cast<num_t&>(left_arg));
      else
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == NoneArg)
        push(reinterpret_cast<reg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::pop:
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == NoneArg)
        pop(reinterpret_cast<reg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::mov:
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Num)
        mov(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<num_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Reg)
        mov(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<reg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::fmov:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftnum)
        fmov(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftnum_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftreg)
        fmov(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftreg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::in:
      if (command.GetLeftArgType() == NoneArg &&
          command.GetRightArgType() == NoneArg)
        in();
      else
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == NoneArg)
        in(reinterpret_cast<reg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::fin:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == NoneArg)
        fin(reinterpret_cast<ftreg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::out:
      if (command.GetLeftArgType() == NoneArg &&
          command.GetRightArgType() == NoneArg)
        out();
      else
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == NoneArg)
        out(reinterpret_cast<reg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::fout:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == NoneArg)
        fout(reinterpret_cast<ftreg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::cmp:
      if (command.GetLeftArgType() == Num &&
          command.GetRightArgType() == Num)
        cmp(reinterpret_cast<num_t&>(left_arg), reinterpret_cast<num_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Num)
        cmp(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<num_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Reg)
        cmp(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<reg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::fcmp:
      if (command.GetLeftArgType() == Ftnum &&
          command.GetRightArgType() == Ftnum)
        fcmp(reinterpret_cast<ftnum_t&>(left_arg), reinterpret_cast<ftnum_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftnum)
        fcmp(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftnum_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftreg)
        fcmp(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftreg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::add:
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Num)
        add(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<num_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Reg)
        add(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<reg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::fadd:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftnum)
        fadd(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftnum_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftreg)
        fadd(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftreg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::sub:
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Num)
        sub(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<num_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Reg)
        sub(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<reg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::fsub:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftnum)
        fsub(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftnum_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftreg)
        fsub(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftreg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::mul:
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Num)
        mul(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<num_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == Reg)
        mul(reinterpret_cast<reg_t&>(left_arg), reinterpret_cast<reg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::fmul:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftnum)
        fmul(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftnum_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftreg)
        fmul(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftreg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::fdiv:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftnum)
        fdiv(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftnum_t&>(right_arg));
      else
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == Ftreg)
        fdiv(reinterpret_cast<ftreg_t&>(left_arg), reinterpret_cast<ftreg_t&>(right_arg));
      else
        assert(false);
      break;
    case CommandType::fsqrt:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == NoneArg)
        fsqrt(reinterpret_cast<ftreg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::lnot:
      if (command.GetLeftArgType() == Reg &&
          command.GetRightArgType() == NoneArg)
        lnot(reinterpret_cast<reg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::flnot:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == NoneArg)
        flnot(reinterpret_cast<ftreg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::finf:
      if (command.GetLeftArgType() == Ftreg &&
          command.GetRightArgType() == NoneArg)
        finf(reinterpret_cast<ftreg_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::jmp:
      if (command.GetLeftArgType() == Label &&
          command.GetRightArgType() == NoneArg)
        jmp(reinterpret_cast<label_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::jz:
      if (command.GetLeftArgType() == Label &&
          command.GetRightArgType() == NoneArg)
        jz(reinterpret_cast<label_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::jnz:
      if (command.GetLeftArgType() == Label &&
          command.GetRightArgType() == NoneArg)
        jnz(reinterpret_cast<label_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::jl:
      if (command.GetLeftArgType() == Label &&
          command.GetRightArgType() == NoneArg)
        jl(reinterpret_cast<label_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::jg:
      if (command.GetLeftArgType() == Label &&
          command.GetRightArgType() == NoneArg)
        jg(reinterpret_cast<label_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::jle:
      if (command.GetLeftArgType() == Label &&
          command.GetRightArgType() == NoneArg)
        jle(reinterpret_cast<label_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::jge:
      if (command.GetLeftArgType() == Label &&
          command.GetRightArgType() == NoneArg)
        jge(reinterpret_cast<label_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::call:
      if (command.GetLeftArgType() == Label &&
          command.GetRightArgType() == NoneArg)
        call(reinterpret_cast<label_t&>(left_arg));
      else
        assert(false);
      break;
    case CommandType::ret:
      if (command.GetLeftArgType() == NoneArg &&
          command.GetRightArgType() == NoneArg)
        ret();
      else
        assert(false);
      break;
    case CommandType::end:
      if (command.GetLeftArgType() == NoneArg &&
          command.GetRightArgType() == NoneArg)
        end();
      else
        assert(false);
      break;
    default:
      assert(false);
  }
}

