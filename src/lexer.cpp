#include "msh/lexer.hpp"

#include <cctype>

namespace msh {

std::vector<Token> tokenize(const std::string& input)
{
    std::vector<Token> tokens;
    std::string word;

    auto flush_word = [&]() {
        if (!word.empty()) {
            tokens.push_back({TokenType::word, word});
            word.clear();
        }
    };

    for (std::size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];

        if (std::isspace(static_cast<unsigned char>(ch))) {
            flush_word();
        }
        else if (ch == '|') {
            flush_word();
            tokens.push_back({TokenType::pipe, "|"});
        }
        else if (ch == '<') {
            flush_word();
            tokens.push_back({TokenType::redirect_in, "<"});
        }
        else if (ch == '>') {
            flush_word();

            if (i + 1 < input.size() && input[i + 1] == '>') {
                tokens.push_back({TokenType::redirect_append, ">>"});
                ++i;
            }
            else {
                tokens.push_back({TokenType::redirect_out, ">"});
            }
        }
        else {
            word += ch;
        }
    }

    flush_word();
    return tokens;
}

}
