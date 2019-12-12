#pragma once

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include "text.hpp"
#include "command.gen.hpp"
#include "args.hpp"


void Compile(FILE* src, FILE* dest);

class Assembly {
  public:
    typedef char value_type;

  private:
    size_t pos;
    std::vector<value_type> data;
    std::unordered_map<std::string, size_t> labels_table;

  public:
    Assembly() : pos(0),
                 data(),
                 labels_table() {}

    void Parse(FILE* src);
    void Write(FILE* dest);

  private:
    void PreAssembly(const Text& text);

    void ParseLines(const Text& src);

    template <typename T>
    void Pack(T&& object);

    template <typename String>
    void PackArg(const String& arg, int type);
};
