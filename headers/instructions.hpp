#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <cassert>

static std::unordered_map<std::string, uint8_t> map_r = {{"eax", 0},
                                                         {"ecx", 1},
                                                         {"edx", 2},
                                                         {"ebx", 3},
                                                         {"esp", 4},
                                                         {"ebp", 5},
                                                         {"esi", 6},
                                                         {"edi", 7}};

static std::unordered_map<std::string, uint8_t> map_f = {{"xmm0", 0},
                                                         {"xmm1", 1},
                                                         {"xmm2", 2},
                                                         {"xmm3", 3},
                                                         {"xmm4", 4},
                                                         {"xmm5", 5},
                                                         {"xmm6", 6},
                                                         {"xmm7", 7}};

struct Instruction {
  uint8_t instruction;
  int64_t lhv;
  int64_t rhv;

  uint8_t RegisterToInt(const char *reg_name) {
      if (map_r.find(reg_name) != map_r.end()) {
          return map_r[reg_name];
      } else if (map_f.find(reg_name) != map_f.end()) {
          return map_f[reg_name];
      }
      assert(false);
      return -1;
  }

};