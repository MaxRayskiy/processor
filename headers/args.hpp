#pragma once

#include <cstdint>
#include <string>

///@warning first type must be NoneArg
enum Arg : uint64_t {
  NoneArg,
  Reg,
  Ftreg,
  Num,
  Ftnum,
  Label,
};

typedef uint8_t reg_t;
typedef int8_t  ftreg_t;
typedef int64_t num_t;
typedef double  ftnum_t;
typedef int32_t label_t;
/*
bool IsNumArg(const std::string& word) {
  for (char letter : word) {
    if (!('0' <= letter && letter <= '9')) {
      return false;
    }
  }
  return true;
}

bool IsFtnumArg(const std::string& word) {
  for (char letter : word) {
    if (!(('0' <= letter && letter <= '9') || letter == '.' || letter == '-')) {
      return false;
    }
  }
  return true;
}

bool IsFtregArg(const std::string& word) {
  return word[0] == 'x' && word[1] == 'm' && word[2] == 'm' &&
      (0 <= std::stoi(word.data() + 3) && std::stoi(word.data() + 3) <= 15);
}

bool IsRegArg(const std::string& word) {
  return word[0] == 'r' && (0 <= std::stoi(word.data() + 1) &&
      std::stoi(word.data() + 1) <= 15);
}

bool IsLabelArg(const std::string& word) {
  return true;
}
*/