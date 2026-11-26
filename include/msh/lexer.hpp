#pragma once

#include <string>
#include <vector>

namespace msh {

enum class TokenType {
    word,
    pipe,
    redirect_in,
    redirect_out,
    redirect_append
};

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(const std::string& input);

}
