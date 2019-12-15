#pragma once

#include <cstdint>
#include <string>
#include "instructions.hpp"


typedef uint8_t reg_t;
typedef int64_t  xmm_t;
typedef int32_t num_t;
typedef double  ftnum_t;
typedef size_t label_t;

static bool IsNumArg(const std::string& word) {
  for (char letter : word) {
    if (!('0' <= letter && letter <= '9')) {
      return false;
    }
  }
  return true;
}

static bool IsFtnumArg(const std::string& word) {
  for (char letter : word) {
    if (!(('0' <= letter && letter <= '9') || letter == '.' || letter == '-')) {
      return false;
    }
  }
  return true;
}

static bool IsFtregArg(const std::string& word) {
  return word[0] == 'x' && word[1] == 'm' && word[2] == 'm' &&
      (0 <= std::stoi(word.data() + 3) && std::stoi(word.data() + 3) <= 15);
}

static bool IsRegArg(const std::string& word) {
  return (map_r.find(word) != map_r.end());
}

