#pragma once

#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <fstream>

int GetFileSize(FILE* input_file);

class Text {
  protected:
    size_t buffer_size;
    std::string buffer;
    std::vector<std::vector<std::string>> lines;

  public:
    Text();

    Text(const Text& other) = delete;
    Text(Text&& other) = delete;
    Text& operator=(const Text& other) = delete;
    Text& operator=(Text&& other) = delete;

    void AddInputStream(const std::string& file_name);
    void ProcessInputStream();

    std::string Line(size_t i) {
      std::string res;
      for (auto word : lines[i]) {
        res += word;
        res += ' ';
      }
      res.pop_back();
      return res;
    }

    std::vector<std::string> GetLine(int num) const { return lines[num]; }
    std::vector<std::vector<std::string>> GetLines() const { return lines; }

    size_t Size() const { return buffer_size; }
    size_t LinesCnt() const { return lines.size(); }

  private:
    FILE* input_stream;

    void UpdateBufferSize();
    void FormatBufferAndCount();
    void FillLines();
};
