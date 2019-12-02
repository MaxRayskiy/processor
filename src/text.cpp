#include "text.hpp"

Text::Text(FILE* input_stream)
    : words_count(0)
    , lines_count(0)
    , input_stream(input_stream)
{
    UpdateBufferSize();
}

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

    int c = fgetc(input_stream);
    assert(c != -1);
    while (c != EOF) {
        buffer.push_back(c);
        if (c == '\n') {
            line.push_back(word);
            word.erase();
            lines.push_back(line);
            line.clear();
            ++words_count;
            ++lines_count;
        } else if (c == ' ') {
            line.push_back(word);
            word.erase();
            ++words_count;
        }
        c = fgetc(input_stream);
    }
    //FormatBufferAndCount();
}

static inline
void UpdateCount(int& cur_length, size_t& count) {
    if (cur_length != 0) {  // Do not count if empty.
        ++count;
        cur_length = 0;
    }
}

void Text::FormatBufferAndCount() {
    bool freeze = false;
    int cur_line_length = 0;
    int cur_word_length = 0;

    for (int pos = 0; pos < buffer_size; ++pos) {
        // If see comment, freeze counters until \n.
        if (buffer[pos] == '#') {
            UpdateCount(cur_line_length, lines_count);
            UpdateCount(cur_word_length, words_count);
            freeze = true;
        } else
        if (buffer[pos] == '\n') {
            freeze = false;
        }

        if (!freeze) {
            // Count.
            if ((buffer[pos] == ' ' || buffer[pos] == '\n')) {
                UpdateCount(cur_word_length, words_count);
            } else {
                ++cur_word_length;
            }
            if (buffer[pos] == '\n') {
                UpdateCount(cur_line_length, lines_count);
            } else {
                ++cur_line_length;
            }
            // Format.
            if (buffer[pos] == '\n') {
                buffer[pos] = '\0';
            }
        } else {
            buffer[pos] = '\0';
        }
    }

    UpdateCount(cur_word_length, words_count);
    UpdateCount(cur_line_length, lines_count);
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
            std::vector<std::string_view> words = GetWords(line_start, length);
            if (words.size() != 0) {
                lines[cur_line_num++] = std::move(words);
            } else {
                --lines_count;
                lines.pop_back();
            }
        }
    }
}


