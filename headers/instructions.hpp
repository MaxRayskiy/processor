#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <unordered_map>

static std::unordered_map<std::string, uint8_t> map1 = {{"eax", 0},
                                                        {"ecx", 1},
                                                        {"edx", 2},
                                                        {"ebx", 3},
                                                        {"esp", 4},
                                                        {"ebp", 5},
                                                        {"esi", 6},
                                                        {"edi", 7}};

struct Instruction {
  uint32_t instruction;
  uint64_t lhv;
  uint64_t rhv;

  uint8_t RegisterToInt(const char *reg_name) {
      if (map1.find(reg_name) != map1.end()) {
          return map1[reg_name];
      } else {
          return reg_name[3];
      }
  }

};