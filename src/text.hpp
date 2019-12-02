#ifndef TEXT_HPP
#define TEXT_HPP

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

    size_t words_count;
    size_t lines_count;

  public:
    Text(FILE* input_stream);
    Text(const Text& other) = delete;
    Text(Text&& other) = delete;
    Text& operator=(const Text& other) = delete;
    Text& operator=(Text&& other) = delete;


    void ProcessInputStream();

    std::vector<std::vector<std::string>> GetLines() const { return lines; }

    size_t Size() const { return buffer_size; }

    char*       Data()       { return const_cast<char*>(buffer.data()); }
    const char* Data() const { return buffer.data(); }

    size_t CountWords() const { return words_count; }
    size_t CountLines() const { return lines_count; }

  private:
    FILE* input_stream;

    void UpdateBufferSize();
    void FormatBufferAndCount();
    /// Replace \n with \0 in the buffer for next lines construction and count
    /// words and lines number.
};


#endif // TEXT_HPP
