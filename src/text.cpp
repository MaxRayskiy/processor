#include "text.hpp"

Text::Text()
    : input_stream(nullptr)
{}

void Text::UpdateBufferSize() {
    assert(input_stream != nullptr);

    int start_pos = ftell(input_stream);
    fseek(input_stream, 0, SEEK_END);
    buffer_size = ftell(input_stream);
    fseek(input_stream, start_pos, SEEK_SET);
}

void Text::ProcessInputStream() {
    std::string word;
    std::vector<std::string> line;
    bool second_sl = false;
    bool process = false;
    bool first_sl = false;

    int c = fgetc(input_stream);
    buffer.push_back(c);
    assert(c != -1);
    while (true) {
        if (c == EOF) {
            if (word.empty()) {
                continue;
            }
            line.push_back(word);
            word.erase();
            lines.push_back(line);
            line.clear();
            break;
        }
        if (c == '/') {
            if (second_sl) {
                word.clear();
                lines.push_back(line);
                line.clear();
                process = true;
                second_sl = false;
            } else {
                second_sl = true;
            }
        }

        word += (char)c;
        if (c == '\n') {
            word.pop_back();
            if (word.empty()) {
                c = fgetc(input_stream);
                buffer.push_back(c);
                continue;
            }
            line.push_back(word);
            word.erase();
            if (!process) {
                lines.push_back(line);
            }
            second_sl = false;
            process = false;
            line.clear();
        } else if (c == ' ') {
            word.pop_back();
            if (word.empty()) {
                c = fgetc(input_stream);
                buffer.push_back(c);
                continue;
            }
            line.push_back(word);
            word.erase();
        }
        c = fgetc(input_stream);
        buffer.push_back(c);
    }
}

std::vector<std::string>
GetWords(const char* line, size_t line_size) {

    std::vector<std::string> words;

    const char* current    = line;
    const char* word_start = current;
    const char* data_end   = current + line_size;

    while (current != data_end) {
        // Seek for begin.
        while (current != data_end && (*current == ' ' || *current == '\t')) {
            ++current;
        }

        word_start = current;

        // Seek for end.
        while (current != data_end && (*current != ' ' && *current != '\t')) {
            ++current;
        }

        size_t length = current - word_start;
        if (length != 0) {
            words.emplace_back(word_start);
        }
    }

    return words;
}

void Text::FillLines() {
    int cur_line_num = 0;

    const char* current    = buffer.data();
    const char* line_start = current;
    const char* data_end   = current + buffer.size();

    while (current != data_end) {
        // Seek for begin.
        while (current != data_end && (*current == '\0')) {
            ++current;
        }

        line_start = current;

        // Seek for end.
        while (current != data_end && (*current != '\0')) {
            ++current;
        }

        size_t length = current - line_start;
        if (length != 0) {
            std::vector<std::string> words = GetWords(line_start, length);
            if (words.size() != 0) {
                lines[cur_line_num++] = std::move(words);
            } else {
                lines.pop_back();
            }
        }
    }
}

void Text::AddInputStream(const std::string& file_name) {
  input_stream = std::fopen(file_name.data(),  "r");
  assert(input_stream != nullptr);

}

